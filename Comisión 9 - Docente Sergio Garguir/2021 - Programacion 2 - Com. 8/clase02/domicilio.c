#include <stdio.h>
#include "domicilio.h"
#include <string.h>

void muestraUnDomicilio(stDomicilio d){
    printf("\nId.................: %d", d.id);
    printf("\nCalle..............: %s", d.calle);
    printf("\nNumero.............: %s", d.nro);
    printf("\nLocalidad..........: %s", d.localidad);
    printf("\nCodigo Postal......: %s", d.cpos);
    printf("\nProvincia..........: %s", d.provincia);
    printf("\n-----------------------------------------------");
}

stDomicilio cargaUnDomicilio(){
    stDomicilio d;
    static int id = 0;
    id++;

    d.id = id;
    strcpy(d.calle, getCalle());
    strcpy(d.nro, "3482");
    strcpy(d.localidad, getLocalidad());
    strcpy(d.cpos, "7600");
    strcpy(d.provincia, "Buenos Aires");

    return d;
}

char* getCalle(){
    char *calle = (char*)malloc(sizeof(char)*31);
    char calles[][30]={"San Lorenzo","Rivadavia","Funes","Dorrego","Belgrano","Don Orione","Cordoba","Moreno","Color","San Juan","Luro","Alberti"};
    strcpy(calle, calles[rand()%(sizeof(calles)/30)]);

    return calle;
}

char* getLocalidad(){
    char *localidad = (char*)malloc(sizeof(char)*31);
    char localidades[1001][30];
    int v = 0;

    v = csv2arregloBis(30, "mocks/localidades.csv", localidades, 1001);

    strcpy(localidad, localidades[rand()%v]);

    return localidad;
}
Rivadavia\n
char* domicilioToString(stDomicilio d){
    char *toString = (char*)malloc(sizeof(char)*150);
    sprintf(toString, "\nId: %6d - Calle: %s - Nro: %s - Localidad: %s - Codigo Postal: %s - Provincia: %s", d.id, d.calle, d.nro, d.localidad, d.cpos, d.provincia);

    return toString;
}

char* domicilioToCsv(stDomicilio d){
    char *toString = (char*)malloc(sizeof(char)*150);
    sprintf(toString, "%d; %s; %s; %s; %s; %s\n", d.id, d.calle, d.nro, d.localidad, d.cpos, d.provincia);

    return toString;
}

int csv2arreglo(int col, char archivo[], char a[][col], int dim){
    FILE *archi = fopen(archivo, "r");
    int i=0;
    if(archi){
        while((fscanf(archi, "%s", a[i])==1) && (i < dim)){
            i++;
        }
        fclose(archi);
    }
    return i;
}

int csv2arregloBis(int col, char archivo[], char a[][col], int dim){
    FILE *archi = fopen(archivo, "r");
    int i=0;
    if(archi){
        while((fgets(a[i], col, archi)) && (i < dim)){
            a[i][strlen(a[i])-1] = '\0';
            i++;
        }
        fclose(archi);
    }
    return i;
}
