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
    strcpy(d.localidad, "Mar del Plata");
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
