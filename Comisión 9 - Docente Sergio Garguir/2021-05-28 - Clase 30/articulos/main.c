#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "articulo.h"

const char AR_ART[]="articulos.dat";

void muestraArchivo(char archivo[]);
void muestraArchiRubro(char archivo[], int rubro);
void muestraArchiMarca(char archivo[], char marca[]);
void aumentaPrecios(char archivo[], int aumento);
int articulosToString(char archivo[], char toString[][200], int dim);
void muestraArregloToString(char toString[][200], int v);

int main()
{
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
    int cont=0;

    if(pArchi){
        while(fread(&a, sizeof(stArticulo), 1, pArchi)>0){
            a.precio = a.precio + (a.precio * (float)aumento / (float)100);

            fseek(pArchi, -1 * sizeof(stArticulo), SEEK_CUR);
            fwrite(&a, sizeof(stArticulo), 1, pArchi);
            cont++;
            fseek(pArchi, sizeof(stArticulo)*cont, SEEK_SET);
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





