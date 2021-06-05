#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    int codigo;
    int rubro; /// 1 - Televisores / 2 - Lavarropas / 3 - Cocinas / 4 - Calefactores
    char marca[30];
    char modelo[30];
    float precio;
} stArticulo;

int artToString(char archivo[], char toString[][200], int dim);
void impToString(char toString[][200], int v);

int main()
{
    char marcaModelo[100][70];
    int validos=0;
    char toString[100][200];
    int vToString=0;


   /* printf("Listado de articulos! \n");
    muestraArchivo("articulos.dat");
*/
    vToString = artToString("articulos.dat", toString, 200);
    impToString(toString, vToString);

    return 0;
}

void muestraArchivo(char archivo[]){
    stArticulo a;
    FILE *pArch = fopen(archivo, "rb");

    if(pArch){
        while(fread(&a, sizeof(stArticulo), 1, pArch)>0){
            muestraUnArticulo(a);
        }
        fclose(pArch);
    }
}

void muestraUnArticulo(stArticulo a){
    char rubro[20];
    getRubro(a.rubro, rubro);

    printf("\n Id..................: %d", a.id);
    printf("\n Codigo..............: %d", a.codigo);
    printf("\n Rubro...............: %d (%s)", a.id, rubro);
    printf("\n Marca...............: %s", a.marca);
    printf("\n Modelo..............: %s", a.modelo);
    printf("\n Precio..............: %.2f", a.precio);
    printf("\n----------------------------------------");
}

void getRubro(int codigo, char rubro[]){
    switch(codigo){
        case 1: strcpy(rubro, "Televisores");
                break;
        case 2: strcpy(rubro, "Lavarropas");
                break;
        case 3: strcpy(rubro, "Cocinas");
                break;
        case 4: strcpy(rubro, "Calefactores");
    }
}

void aumentaPrecios(char archivo[], int aumento){
    stArticulo a;

    FILE *pArchi = fopen(archivo, "r+b");
    int cont=0;

    if(pArchi){
        while(fread(&a, sizeof(stArticulo), 1, archivo)>0){
            a.precio = a.precio + (a.precio * (float)aumento / (float)100);
            fseek(pArchi, -1 * sizeof(stArticulo), SEEK_CUR);
            fwrite(&a, sizeof(stArticulo), 1, pArchi);
            cont++;
            fseek(pArchi, sizeof(stArticulo)*cont, SEEK_SET);
        }
        fclose(pArchi);
    }
}

stArticulo buscaArticuloMasBarato(char archivo[]){
    stArticulo a;
    stArticulo masBarato;
    FILE *pArchi = fopen(archivo, "rb");

    if(pArchi){
        fread(&masBarato, sizeof(stArticulo), 1, pArchi);

        while(fread(&a, sizeof(stArticulo), 1, pArchi) > 0){
            if(a.precio < masBarato.precio){
                masBarato = a;
            }
        }
        fclose(pArchi);
    }

    return masBarato;
}

int concatenar (char archivo[],char marcaModel[][200], int dim)
{
    stArticulo a;
    int v=0;
    FILE *pArch = fopen(archivo, "rb");
    if (pArch)
    {
        while(v<dim && fread(&a,sizeof(stArticulo),1,pArch)>0)
        {
            strcat(marcaModel[v],a.marca);
            strcat(marcaModel[v]," - ");
            strcat(marcaModel[v],a.modelo);
            v++;
        }
        fclose(pArch);
    }
    return v;
}

int artToString(char archivo[], char toString[][200], int dim){
    int i=0;
    stArticulo a;
    char rubro[15];
    FILE *pArch = fopen(archivo, "rb");

    if(pArch){
        while(i<dim && fread(&a, sizeof(stArticulo), 1, pArch)>0){
            getRubro(a.rubro, rubro);
            sprintf(toString[i],"\nId: %3d - Codigo: %4d - Rubro: %2d (%-13s) - Marca: %-20s - Modelo: %-8s - Precio: %8.2f", a.id, a.codigo, a.rubro, rubro, a.marca, a.modelo, a.precio);
            i++;
        }

        fclose(pArch);
    }
    return i;
}

void impToString(char toString[][200], int v){
    for(int i=0;i<v;i++){
        printf(toString[i]);
    }
}

















