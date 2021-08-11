#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domicilio.h"

int cargaDomicilios(stDomicilio d[], int dim);
void muestraDomicilios(stDomicilio d[], int v);
void muestraToStringDomicilios(stDomicilio d[], int v);
void muestraToStringDomiciliosPuntero(stDomicilio d[], int v);
void muestraToCsvDomicilios(stDomicilio d[], int v);
void domiciliosToArch(stDomicilio d[], int v);
void muestraToJsonDomicilios(stDomicilio d[], int v);
char * agregaEnString(char *a, char *b);
char * agregaEnStringP(char **a, char *b);
void domicilios2archivo(stDomicilio d[], int v, char archivo[]);

int main()
{
    saludo();
/**
    int cantRegistros = cuentaRegistros("archiDomicilios.dat");
    stDomicilio* d = (stDomicilio*)malloc(sizeof(stDomicilio)*cantRegistros);
    fread(d, sizeof(stDomicilio), cantRegistros, pArchi);
 */

    stDomicilio domicilios[100];
    int vDomicilios = 0;

    vDomicilios = cargaDomicilios(domicilios, 10);


    printf("\n Listado de Domicilios %d", vDomicilios);
    muestraDomicilios(domicilios, vDomicilios);

    printf("\n Listado de ToStringDomcilios");
    muestraToStringDomicilios(domicilios, vDomicilios);

    printf("\n Listado de ToStringDomciliosPuntero");
    muestraToStringDomiciliosPuntero(domicilios, vDomicilios);

    printf("\n Listado de ToCsvDomcilios");
    muestraToCsvDomicilios(domicilios, vDomicilios);

    printf("\n Listado de ToJSONDomcilios");
    muestraToJsonDomicilios(domicilios, vDomicilios);

    domiciliosToArch(domicilios, vDomicilios);
    domicilios2archivo(domicilios, vDomicilios, "domicilios.dat");

    return 0;
}

int cargaDomicilios(stDomicilio d[], int dim){
    int i;
    for(i=0; i<dim; i++){
        d[i] = getDomicilio();
    }
    return i;
}

void muestraDomicilios(stDomicilio d[], int v){
    for(int i = 0; i<v; i++){
        muestraUnDomicilio(d[i]);
    }
}

void muestraToStringDomicilios(stDomicilio d[], int v){
    char s[150];

    for(int i = 0; i<v; i++){
        domicilioToString(d[i], s);
        printf("%s", s);
    }
}

void muestraToStringDomiciliosPuntero(stDomicilio d[], int v){
    char *s = (char *)malloc(sizeof(char)*150);

    for(int i = 0; i<v; i++){
        s = domicilioToStringPuntero(d[i]);
        printf("%s", s);
    }
}

void muestraToCsvDomicilios(stDomicilio d[], int v){
    char *s = (char *)malloc(sizeof(char)*150);

    for(int i = 0; i<v; i++){
        s = domicilioToCsv(d[i]);
        printf("%s", s);
    }
}

void domiciliosToArch(stDomicilio d[], int v){
    char *s = (char *)malloc(sizeof(char)*150);
    FILE *archi = fopen("domicilios.csv", "a");
    if(archi) {/// if(archi!=NULL)
        for(int i = 0; i<v; i++){
            s = domicilioToCsv(d[i]);
            fputs(s, archi);
        }
        fclose(archi);
    }
}

void muestraToJsonDomicilios(stDomicilio d[], int v){
    char *s = (char *)malloc(sizeof(char)*150);

    for(int i = 0; i<v; i++){
        s = domicilioToJson(d[i]);
        printf("%s", s);
    }
}

void domicilios2archivo(stDomicilio d[], int v, char archivo[]){
    FILE* archi = fopen(archivo, "ab");
    if(archi){
        for(int i=0; i<v; i++){
            fwrite(&d[i], sizeof(stDomicilio), 1, archi);
        }
        fclose(archi);
    }
}
