#include <stdio.h>
#include <string.h>
#include <string.h>
#include <malloc.h>
#include "domicilio.h"
#include "persona.h"

void muestraUnaPersona(stPersona p){
    printf("\nApellido y Nombre..........: %s, %s", p.apellido, p.nombre);
    printf("\nDNI........................: %s", p.dni);
    printf("\nGenero.....................: %s", (p.genero=='M')?"Masculino":"Femenino");
    muestraUnDomicilio(p.domicilio);
}
