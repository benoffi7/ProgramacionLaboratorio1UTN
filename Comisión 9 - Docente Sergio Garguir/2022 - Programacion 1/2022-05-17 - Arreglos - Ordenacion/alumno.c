#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

stAlumno cargaUnAlumno(){
    stAlumno a;

    printf("Matricula.......: ");
    scanf("%d", &a.matricula);

    fflush(stdin);
    printf("Nombre..........: ");
   // gets(a.nombre);
    getNombre(a.nombre);

    fflush(stdin);
    printf("Apellido........: ");
    gets(a.apellido);

    printf("Nota............: ");
    scanf("%d", &a.nota);

    return a;
}

void muestraUnAlumno(stAlumno alumno){
    printf("\n Matricula..........: %d", alumno.matricula);
    printf("\n Apellido y Nombres.: %s, %s", alumno.apellido, alumno.nombre);
    printf("\n Nota...............: %d", alumno.nota);
    printf("\n===================================================");
}

void getNombre(char n[]){
    char nombres[][20]={"Pedro", "Pablo", "Ana"};
    strcpy(n, nombres[rand()%(sizeof(nombres)/20)]);
}
