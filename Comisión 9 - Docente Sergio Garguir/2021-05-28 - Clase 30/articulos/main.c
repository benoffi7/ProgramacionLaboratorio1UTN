#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "articulo.h"
#include "pila.h"

const char AR_ART[]="articulos.dat";

void muestraArchivo(char archivo[]);
void muestraArchiRubro(char archivo[], int rubro);
void muestraArchiMarca(char archivo[], char marca[]);
void aumentaPrecios(char archivo[], int aumento);
int articulosToString(char archivo[], char toString[][200], int dim);
void muestraArregloToString(char toString[][200], int v);
void precios2pila(char archivo[], Pila *p, int tope);
void fStrDelPosChar(char c[], int pos);
void fStrLTrim(char c[]);
void fStrRTrim(char c[]);

int main()
{
    Pila precios;
    inicpila(&precios);
    char nombre1[] = "Maradona";
    char nombre[] = "    Maradona    ";


    printf("\n ---%s---", nombre1);
    fStrDelPosChar(nombre1, 20);
    //fStrLTrim(nombre);
    //fStrRTrim(nombre);
    printf("\n ---%s---", nombre);
    printf("\n");
    system("pause");

    precios2pila(AR_ART, &precios, 5000);
    mostrar(&precios);
    system("pause");

    char artToString[100][200];
    int vArt=0;

    char marcaModelo[100][200];
    int vMarcaModelo=0;

    printf("\nListado de articulos! %d\n", sizeof(stArticulo));
    muestraArchivo(AR_ART);

    aumentaPrecios(AR_ART, 10);

    printf("\nListado de articulos con aumento!\n");
    muestraArchivo(AR_ART);

    printf("\nListado de articulos del rubro Cocinas!\n");
    muestraArchiRubro(AR_ART, 3);
    printf("\nListado de articulos de la marca Bosch!\n");
    muestraArchiMarca(AR_ART, "Bosch");

    vArt = articulosToString(AR_ART, artToString, 100);
    muestraArregloToString(artToString, vArt);

    vMarcaModelo = marcaModeloToString(AR_ART, marcaModelo, 100);
    muestraArregloToString(marcaModelo, vArt);

    return 0;
}

void muestraArchivo(char archivo[]){
    stArticulo a;
    FILE *pArchi = fopen(archivo, "rb");

    if(pArchi){  /// if(pArchi!=NULL)
        while(fread(&a, sizeof(stArticulo), 1, pArchi)>0){
            muestraUnArticulo(a);
        }

        fclose(pArchi);
    }
}

void muestraArchiRubro(char archivo[], int rubro){
    stArticulo a;
    FILE *pArchi = fopen(archivo, "rb");

    if(pArchi && rubro > 0 && rubro <= 4){
        while(fread(&a, sizeof(stArticulo), 1, pArchi)>0){
            if (a.rubro==rubro){
               muestraUnArticulo(a);
            }
        }
        fclose(pArchi);
    }
}

void muestraArchiMarca(char archivo[], char marca[]){
    stArticulo a;
    FILE *pArchi = fopen(archivo, "rb");

    if(pArchi){
        while(fread(&a, sizeof(stArticulo), 1, pArchi)>0){
            if (strcmp(a.marca, marca)==0){
               muestraUnArticulo(a);
            }
        }
        fclose(pArchi);
    }
}

void aumentaPrecios(char archivo[], int aumento){
    stArticulo a;
    FILE *pArchi = fopen(archivo, "r+b");

    if(pArchi){
        while(fread(&a, sizeof(stArticulo), 1, pArchi)>0){
            a.precio = a.precio + (a.precio * (float)aumento / (float)100);

            fseek(pArchi, -1 * sizeof(stArticulo), SEEK_CUR);
            fwrite(&a, sizeof(stArticulo), 1, pArchi);

            fseek(pArchi, sizeof(stArticulo), SEEK_CUR);
        }
        fclose(pArchi);
    }
}

stArticulo buscaArtMenorPrecio(char archivo[]){
    stArticulo a;
    stArticulo menorPrecio;
    FILE *pArchi = fopen(archivo, "rb");

    if(pArchi){
        if(fread(&menorPrecio, sizeof(stArticulo), 1, pArchi)>0){}

        while(fread(&a, sizeof(stArticulo), 1, pArchi)>0){
            if(a.precio < menorPrecio.precio){
                menorPrecio = a;
            }
        }
        fclose(pArchi);
    }

    return menorPrecio;
}

stArticulo retornaArticulo(char archivo[], int pos){
    stArticulo a;
    FILE *pArch = fopen(archivo, "rb");

    if(pArch && pos >= 0 && pos <= cuentaRegistros(archivo, sizeof(stArticulo))){
        fseek(pArch, sizeof(stArticulo)*pos, 0);
        fread(&a, sizeof(stArticulo), 1, pArch);

        fclose(pArch);
    }

    return a;
}

int cuentaRegistros(char archivo[], int tamanio){
    int cant = 0;
    FILE *pArch = fopen(archivo, "rb");

    if(pArch){
        fseek(pArch, 0, SEEK_END);
        cant = ftell(pArch)/tamanio; /// tamanio es sizeof(stArticulo)

        fclose(pArch);
    }
    return cant;
}

int articulosToString(char archivo[], char toString[][200], int dim){
    stArticulo a;
    char rubro[20];
    int i=0;
    FILE *pArchi = fopen(archivo, "rb");

    if(pArchi){  /// if(pArchi!=NULL)
        while(i<dim && fread(&a, sizeof(stArticulo), 1, pArchi)>0){
       /*
          strcat(toString[i], "Id: ");
          strcat(toString[i], itoa(a.id);
          strcat(toString[i], " Codigo: ");
        */
            getRubro(a.rubro, rubro);
            sprintf(toString[i],"Id: %4d, Codigo: %5d, Rubro: %d - %-15s, Marca: %-15s, Modelo: %-10s, Precio: %6.2f",a.id, a.codigo, a.rubro, rubro, a.marca, a.modelo, a.precio);
            i++;
        }

        fclose(pArchi);
    }
    return i;
}

void muestraArregloToString(char toString[][200], int v){
    for(int i=0;i<v;i++){
        printf("\n %s", toString[i]);
    }
}

int marcaModeloToString(char archivo[], char toString[][200], int dim){
    stArticulo a;
    int i=0;
    FILE *pArchi = fopen(archivo, "rb");

    if(pArchi){  /// if(pArchi!=NULL)
        while(i<dim && fread(&a, sizeof(stArticulo), 1, pArchi)>0){
          strcat(toString[i], "Marca: ");
          strcat(toString[i], a.marca);
          strcat(toString[i], " Modelo: ");
          strcat(toString[i], a.modelo);
          i++;
        }

        fclose(pArchi);
    }
    return i;
}

void precios2pila(char archivo[], Pila *p, int tope){
    stArticulo a;
    FILE *pArch = fopen(archivo, "rb");
    int cont=0;

    if(pArch){
        while(cont < 50 && fread(&a, sizeof(stArticulo), 1, pArch)>0){
            if(a.precio > tope){
                apilar(p, (int)a.precio);
                cont++;
            }
        }

        fclose(pArch);
    }
}

/// Elimina el carácter ubicado en la posición dada
void fStrDelPosChar(char c[], int pos){
    int v = strlen(c)-1;
    int i;
    if(pos < v){
        for(i=pos; i<v; i++){
                c[i]=c[i+1];
        }
        c[i]='\0';
    }
}

/// Elimina espacios en blanco a la izquierda de la cadena
void fStrLTrim(char c[]){
    int i = 0;
    int v = strlen(c);
    int flag = 0;

    while(i < v && flag == 0){
        if(isblank(c[i])){     /// if(c[i]==' ')
            fStrDelPosChar(c, i);
            v--;
        }else{
            flag = 1;
        }
    }
}

/// Elimina espacios en blanco a la derecha de la cadena
void fStrRTrim(char c[]){
    int flag = 0;
    int v = strlen(c);
    int i = v -1;

    while(i >= 0 && flag == 0){
        if(isblank(c[i])){
            c[i]='\0';
            i--;
        }else{
            flag = 1;
        }
    }
}
