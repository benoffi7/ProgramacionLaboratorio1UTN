#include "empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stEmpleado cargarUnEmpleado(){
    stEmpleado e;
    static int id=0;
    id++;

    e.id = id;
    strcpy(e.nombre, "Pepe");
    strcpy(e.apellido, "Argento");
    e.edad = 45;

    return e;
}


void muestraUnEmpleado(stEmpleado e){
    printf("\n ID....................: %d", e.id);
    printf("\n Nombre................: %s", e.nombre);
    printf("\n Apellido..............: %s", e.apellido);
    printf("\n Edad..................: %d", e.edad);
    printf("\n____________________________________________________");
}
