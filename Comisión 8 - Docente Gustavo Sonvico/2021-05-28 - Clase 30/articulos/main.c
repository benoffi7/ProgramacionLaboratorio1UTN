#include <stdio.h>
#include <stdlib.h>

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
    printf("Listado de articulos!\n");
    muestraArchivo("articulos.dat");
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
