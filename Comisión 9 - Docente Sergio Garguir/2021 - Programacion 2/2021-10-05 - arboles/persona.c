#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

void muestraUnaPersona(stPersona p){
    printf("\nLegajo......: %d", p.legajo);
    printf("\nNombre......: %s", p.nombre);
    printf("\nEdad........: %d", p.edad);
    printf("\n______________________________________");
}
