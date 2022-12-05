#include <stdio.h>
#include <string.h>
#include <string.h>
#include <malloc.h>
#include "persona.h"

void muestraUnaPersona(stPersona p){
    printf("\nID.........................: %d", p.id);
    printf("\nApellido y Nombre..........: %s, %s", p.apellido, p.nombre);
    printf("\nDNI........................: %s", p.dni);
    printf("\nGenero.....................: %s", (p.genero=='M')?"Masculino":"Femenino");
    printf("\n_____________________________________________________________");
}

stPersona cargaUnaPersona(){
    stPersona p;
    p.id = getId();
    strcpy(p.nombre, getNombre());
    strcpy(p.apellido, getApellido());
    itoa(getDni(),p.dni,10);
    p.genero=(p.nombre[strlen(p.nombre)-1]=='a')?'m':'f';
    return p;
}
