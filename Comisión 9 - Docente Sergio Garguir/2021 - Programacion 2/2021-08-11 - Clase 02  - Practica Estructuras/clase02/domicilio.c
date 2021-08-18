#include <stdio.h>
#include <string.h>
#include <string.h>
#include <malloc.h>
#include "domicilio.h"

void muestraUnDomicilio(stDomicilio d){
    printf("\nCalle y nro................: %s %s", d.calle, d.nro);
    printf("\nCodigo Postal - Localidad..: %s %s", d.cpos, d.localidad);
    printf("\nProvincia..................: %s", d.provincia);
    printf("\n_____________________________________________________");
}

char *domicilioToString(stDomicilio d){
    char *s = (char *)malloc(sizeof(char)*200);
    sprintf(s, "Id: %d - Calle: %s - Nro: %s - Cod Postal: %s - Localidad: %s - Provincia: %s", d.id, d.calle, d.nro, d.cpos, d.localidad, d.provincia);
    return s;
}

char *domicilioToCsv(stDomicilio d){
    char *s = (char *)malloc(sizeof(char)*200);
    sprintf(s, "%06d; %s; %s; %s; %s; %s\n", d.id, d.calle, d.nro, d.cpos, d.localidad, d.provincia);
    return s;
}

char *domicilioToJson(stDomicilio d){
    char *s = (char *)malloc(sizeof(char)*200);
    sprintf(s, "\n\t{\n\t\"id\":\"%d\",\n\t\"calle\":\"%s\",\n\t\"nro\":\"%s\",\n\t\"codpos\":\"%s\",\n\t\"localidad\":\"%s\",\n\t\"provincia\":\"%s\"\n\t}", d.id, d.calle, d.nro, d.cpos, d.localidad, d.provincia);
    return s;
}

stDomicilio addDomicilio(){
    static int id = 0;
    id += 1;
    stDomicilio d;
    d.id = id;
    strcpy(d.calle, "San Martin");
    strcpy(d.nro, "1256");
    strcpy(d.cpos, "7600");
    strcpy(d.localidad, "Mar del Plata");
    strcpy(d.provincia, "Buenos Aires");

    return d;
}
