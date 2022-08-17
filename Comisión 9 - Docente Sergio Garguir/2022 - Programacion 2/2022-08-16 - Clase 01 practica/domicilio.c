#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domicilio.h"

void muestraUnDomicilio(stDomicilio d){
    printf("\n ID...............: %d", d.id);
    printf("\n Calle............: %s", d.calleNombre);
    printf("\n Numero...........: %s", d.calleNumero);
    printf("\n Localidad........: %s", d.localidad);
    printf("\n Codigo Postal....: %s", d.cpos);
    printf("\n Provincia........: %s", d.provincia);
    printf("\n _________________________________________________________________");
}

stDomicilio getDomicilio(){
    stDomicilio d;
    static int id = 0;
    id++;

    d.id = id;
    strcpy(d.calleNombre, "San Martin");
    strcpy(d.calleNumero, "1525");
    strcpy(d.localidad, "Mar del Plata");
    strcpy(d.cpos, "GOD7601C");
    strcpy(d.provincia, "Buenos Aires");

    return d;
}

void domicilioToString(stDomicilio d, char s[]){
    sprintf(s,"\nId: %d - Calle: %s - Numero: %s - Localidad: %s - Codigo Postal: %s - Provincia: %s", d.id, d.calleNombre, d.calleNumero, d.localidad, d.cpos, d.provincia);
}

char* domicilioToString2(stDomicilio d){
    char *s = (char *)malloc(sizeof(char)*200);
    sprintf(s,"\nId: %d - Calle: %s - Numero: %s - Localidad: %s - Codigo Postal: %s - Provincia: %s", d.id, d.calleNombre, d.calleNumero, d.localidad, d.cpos, d.provincia);
    return s;
}

