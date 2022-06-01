#include "empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

stEmpleado cargaUnEmpleado(){
    stEmpleado e;
    static int i=0;

    i++;

    e.id = i;

    printf("\n");
    printf("Legajo Nro............: ");
    scanf("%d", &e.legajo);

    printf("Nombre................: ");
    fflush(stdin);
    gets(e.nombre);

    printf("Apellido..............: ");
    fflush(stdin);
    gets(e.apellido);

    printf("DNI...................: ");
    fflush(stdin);
    gets(e.dni);

    return e;
}

void muestraUnEmpleado(stEmpleado e){
    printf("\n ID................: %d", e.id);
    printf("\n Legajo Nro........: %d", e.legajo);
    printf("\n Nombre............: %s", e.nombre);
    printf("\n Apellido..........: %s", e.apellido);
    printf("\n DNI...............: %s", e.dni);
    printf("\n =========================================================");
}
