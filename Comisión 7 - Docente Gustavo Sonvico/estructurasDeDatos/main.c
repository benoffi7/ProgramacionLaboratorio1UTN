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

void mostrarUnEmpleado(empleado e);

int main()
{
    printf("Hello world strucs !\n");

    empleado emple1;

    empleado emple2 = {1234, "pepe", "gaboto 2344", 4954348, 4538.9};

    emple1=emple2;

    mostrarUnEmpleado(emple2);

    system("pause");

   /* printf("Ingrese el id del empleado ");
    scanf("%d", &emple1.idEmpleado);

    printf("Ingrese el nombre del empleado ");
    fflush(stdin);
    scanf("%s", emple1.nombre);

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

*/

    empleado empleAdministracion[10];
    int cantEmpleados=0;

    cantEmpleados=cargarEmpleados(empleAdministracion, 10);

    printf("\nSe cargaron %d empleados a la nomina\n", cantEmpleados);


    mostrarEmpleados(empleAdministracion, cantEmpleados);
   /* empleAdministracion[0].idEmpleado=1;
    empleAdministracion[0].sueldo=456781;
    empleAdministracion[0].telefono=4567811; */





    return 0;
}

int cargarEmpleados(empleado E[], int dimension)
{
    int i=0;
    char control='s';

    printf("Cargando el arreglo de empleados\n\n");

    while(i<dimension && control=='s')
    {
        printf("Ingrese el id del empleado: ");
        scanf("%d", &E[i].idEmpleado);

        printf("Ingrese el nombre del empleado: ");
        fflush(stdin);
        gets(E[i].nombre);

        printf("Ingrese la dir del empleado: ");
        fflush(stdin);
        gets(E[i].direccion);

        printf("Ingrese el telefono del empleado: ");
        scanf("%ld", &E[i].telefono);

        printf("Ingrese el sueldo del empleado: ");
        scanf("%f", &E[i].sueldo);


        printf("Desea continuar la carga de empleados? s/n \n");
        fflush(stdin);
        scanf("%c", &control);

        system("cls");

        i++;
    }

    return i;
}

void mostrarUnEmpleado(empleado e)
{
    printf("IdEmpleado: %d\n", e.idEmpleado);
    printf("Nombre:     %s\n", e.nombre);
    printf("Direccion:  %s\n", e.direccion);
    printf("Telefono:   %ld\n", e.telefono);
    printf("Sueldo:     $%.2f\n", e.sueldo);
}

void mostrarEmpleados(empleado E[], int validos)
{
     int i=0;
     empleado aux;

     printf("Contenido del arreglo de empleados\n");
     printf("-------------\n");

     for(i=0;i<validos;i++)
     {
         aux=E[i];
         mostrarUnEmpleado(aux);
         printf("-------------\n");
     }
}
