#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// declaracion de nuevo tipo de dato
typedef struct
{
    /// caracteristicas de la estructura
    int idEmpleado;
    char nombre[50];
    char direccion[50];
    long telefono;
    float sueldo;

} empleado; /// nombre de la estrutura

int cargarEmpleados(empleado E[], int dimension);

void mostrarEmpleados(empleado E[], int validos);

int main()
{
    printf("Hello world strucs !\n");

    empleado emple1;

    empleado emple2 = {1234, "pepe", "gaboto 2344", 4954348, 4538.9};


    emple1=emple2;

    printf("IdEmpleado: %d\n", emple2.idEmpleado);
    printf("Nombre:     %s\n", emple2.nombre);
    printf("Direccion:  %s\n", emple2.direccion);
    printf("Telefono:   %ld\n", emple2.telefono);
    printf("Sueldo:     $%.2f\n", emple2.sueldo);

    printf("Ingrese el id del empleado ");
    scanf("%d", &emple1.idEmpleado);

    printf("Ingrese el nombre del empleado ");
    fflush(stdin);
    scanf("%s", &emple1.nombre);

    printf("Ingrese la dir del empleado ");
    fflush(stdin);
    gets(emple1.direccion);

    printf("Ingrese el telefono del empleado ");
    scanf("%ld", &emple1.telefono);

    printf("Ingrese el sueldo del empleado ");
    scanf("%f", &emple1.sueldo);


    printf("IdEmpleado: %d\n", emple1.idEmpleado);
    printf("Nombre:     %s\n", emple1.nombre);
    printf("Direccion:  %s\n", emple1.direccion);
    printf("Telefono:   %ld\n", emple1.telefono);
    printf("Sueldo:     $%.2f\n", emple1.sueldo);


    empleado empleAdministracion[10];


    empleAdministracion[0].idEmpleado=1;
    empleAdministracion[0].sueldo=456781;
    empleAdministracion[0].telefono=4567811;



    return 0;
}

int cargarEmpleados(empleado E[], int dimension)
{
    int i=0;
    char control='s';

    while(i<dimension && control=='s')
    {
        printf("Ingrese el id del empleado ");
        scanf("%d", &E[i].idEmpleado);


       /// ... falta completar la carga del los demas atributos de la estructura


    }

    return i;
}
