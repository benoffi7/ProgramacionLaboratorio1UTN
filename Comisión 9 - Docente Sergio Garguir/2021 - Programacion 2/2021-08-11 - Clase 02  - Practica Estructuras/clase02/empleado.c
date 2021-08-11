#include <stdio.h>
#include <string.h>
#include <string.h>
#include <malloc.h>

#include "empleado.h"

void muestraUnEmpleado(stEmpleado e){
    printf("\nId.........................: %6d", e.id);
    printf("\nLegajo.....................: %6d", e.legajo);
    printf("\nCargo......................: %s", e.cargo);
    muestraUnaPersona(e.persona);
    printf("\nDomicilio laboral:");
    muestraUnDomicilio(e.domicilioLaboral);
}
