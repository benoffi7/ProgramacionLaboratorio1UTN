#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "domicilio.h"

void muestraUnDomicilio(stDomicilio d){
    printf("\nId..............: %d", d.id);
    printf("\nCalle...........: %s", d.calle);
    printf("\nNumero..........: %s", d.nro);
    printf("\nLocalidad.......: %s", d.localidad);
    printf("\nCodigo Postal...: %s", d.cpos);
    printf("\nProvincia.......: %s", d.provincia);
    printf("\n---------------------------------------");
}

stDomicilio getDomicilio(){
    stDomicilio d;
    static int id = 0;
    id++; /// id+=1 /// id = id + 1
    d.id = id;
    strcpy(d.calle, "San Lorenzo");
    strcpy(d.nro, "1525");
    strcpy(d.localidad, "Mar del Plata");
    strcpy(d.cpos, "7600");
    strcpy(d.provincia, "Buenos Aires");

    return d;
}

void domicilioToString(stDomicilio d, char s[150]){
    sprintf(s, "\nId: %6d - Calle: %s - Nro: %s - Localidad: %s - Codigo Postal: %s - Provincia: %s", d.id, d.calle, d.nro, d.localidad, d.cpos, d.provincia);
}

char* domicilioToStringPuntero(stDomicilio d){
    char *s = (char *)malloc(sizeof(char)*150);
    sprintf(s, "\nId: %6d - Calle: %s - Nro: %s - Localidad: %s - Codigo Postal: %s - Provincia: %s", d.id, d.calle, d.nro, d.localidad, d.cpos, d.provincia);
    return s;
}

char* domicilioToCsv(stDomicilio d){
    char *s = (char *)malloc(sizeof(char)*150);
    sprintf(s, "%6d; %s; %s; %s; %s; %s\n", d.id, d.calle, d.nro, d.localidad, d.cpos, d.provincia);
    return s;
}

char* domicilioToJson(stDomicilio d){
    char *s = (char *)malloc(sizeof(char)*150);
    sprintf(s, "\n\t{\"id\":\"%6d\",\n\t\"Calle\":\"%s\",\n\t\"Nro\":\"%s\",\n\t\"Localidad\":\"%s\",\n\t\"Codigo Postal\":\"%s\",\n\t\"Provincia\":\"%s\"\n\t}", d.id, d.calle, d.nro, d.localidad, d.cpos, d.provincia);
    return s;
}

void saludo(){
    printf("\nHola\n");
}


