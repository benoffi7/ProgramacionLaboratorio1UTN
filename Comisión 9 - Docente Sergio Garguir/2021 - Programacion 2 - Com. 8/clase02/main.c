#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "domicilio.h"
#include "pilaDomicilios.h"

int main()
{
    char *char1=NULL;


    appendString(&char1, " Hola Andres");
    printf("\n %s", char1);

    appendString(&char1, " Chau Andres");
    printf("\n %s", char1);

    appendString(&char1, " ");

    appendString(&char1, getLocalidad());
    printf("\n %s", char1);

    appendString(&char1, " ");

    appendString(&char1, getCalle());
    printf("\n %s", char1);

    pilaDomicilios p;
    inicPila(&p);

    stDomicilio domicilios[100];
    int vDomicilios = 0;

    vDomicilios = cargaDomicilios(domicilios, 10);
    muestraDomicilios(domicilios, vDomicilios);

    for(int i=0;i<10;i++){
        apilar(&p, domicilios[i]);
    }

    muestraPilaDomicilios(p);

    printf("\n DomiciliosToString\n");
    muestraDomiciliosToString(domicilios, vDomicilios);
    printf("\n DomiciliosToCsv\n");
    muestraDomiciliosToCsv(domicilios, vDomicilios);
    csv2archi("domicilios.csv",domicilios, vDomicilios);

    return 0;
}

int cargaDomicilios(stDomicilio d[], int dim){
    int i;
    for(i=0;i<dim;i++){
        d[i]=cargaUnDomicilio();
    }
    return i;
}

void muestraDomicilios(stDomicilio d[], int v){
    for(int i=0;i<v;i++){
        muestraUnDomicilio(d[i]);
    }
}

void muestraDomiciliosToString(stDomicilio d[], int v){
    for(int i=0;i<v;i++){
        printf("%s", domicilioToString(d[i]));
    }
}

void muestraDomiciliosToCsv(stDomicilio d[], int v){
    for(int i=0;i<v;i++){
        printf("%s", domicilioToCsv(d[i]));
    }
}

void csv2archi(char archivo[], stDomicilio d[], int v){
    FILE *archi = fopen(archivo, "a");
    if(archi){  /// if(archi!=NULL)
        for(int i=0;i<v;i++){
            fputs(domicilioToCsv(d[i]),archi);
        }
        fclose(archi);
    }
}

void muestraPilaDomicilios(pilaDomicilios p){
    while(!pilavacia(&p)){
        muestraUnDomicilio(desapilar(&p));
    }
}

void appendString(char **a, char *b){
    if(*a){
        (*a)=(char*)realloc((*a), strlen(*a)+strlen(b)+1);
        strcat((*a), b);
    }else{
        (*a)=(char*)malloc(strlen(b)+1);
        strcpy((*a), b);
    }
}
