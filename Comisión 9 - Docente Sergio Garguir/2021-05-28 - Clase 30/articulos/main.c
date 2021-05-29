#include <stdio.h>
#include <stdlib.h>

const char AR_ART[]="articulos.dat";

typedef struct{
    int id;
    int codigo;
    int rubro; /// 1 - Televisores / 2 - Lavarropas / 3 - Cocinas / 4 - Calefactores
    char marca[30];
    char modelo[30];
    float precio;
} stArticulo;

int main()
{
    printf("\nListado de articulos!\n");
    muestraArchivo(AR_ART);

    aumentaPrecios(AR_ART, 10);

    printf("\nListado de articulos con aumento!\n");
    muestraArchivo(AR_ART);

    printf("\nListado de articulos del rubro Cocinas!\n");
    muestraArchiRubro(AR_ART, 3);
    printf("\nListado de articulos de la marca Bosch!\n");
    muestraArchiMarca(AR_ART, "Bosch");
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

void muestraUnArticulo(stArticulo a){
    char rubro[15];
    getRubro(a.rubro, rubro);

    printf("\n Id...................: %d", a.id);
    printf("\n Codigo...............: %d", a.codigo);
    printf("\n Rubro................: %d (%s)", a.rubro, rubro);
    printf("\n Marca................: %s", a.marca);
    printf("\n Modelo...............: %s", a.modelo);
    printf("\n Precio...............: %.2f", a.precio);
    printf("\n------------------------------------------------");
}

void getRubro(int nro, char rubro[]){
    switch(nro){
        case 1: strcpy(rubro, "Televisores");
                break;
        case 2: strcpy(rubro, "Lavarropas");
                break;
        case 3: strcpy(rubro, "Cocinas");
                break;
        case 4: strcpy(rubro, "Calefactores");
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
            if (strcmp(a.marca,marca)==0){
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
        }
        fclose(pArchi);
    }
}















