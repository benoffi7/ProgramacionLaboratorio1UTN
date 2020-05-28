#include <stdio.h>
#include <stdlib.h>

/// declaracion de la estructura
typedef struct
{
    int idEmpleado;
    char nombre[50];
    char direccion[50];
    long telefono;
    float sueldo;
} empleado;


int cargaArregloEmpleados(empleado E[], int dimension);

void mostraArregloEmpleados(empleado E[], int validos);

void mostrarUnEmpleado(empleado e);


int main()
{
    printf("Hello world structs!\n");

    empleado emple1;

    printf("Ingrese los datos del empleado: \n");

    printf("Id: ");
    scanf("%d", &emple1.idEmpleado);

    printf("Nombre: ");
    fflush(stdin);
    scanf("%s", emple1.nombre);

    printf("Direccion: ");
    fflush(stdin);
    scanf("%s", emple1.direccion);

    printf("Telefono: ");
    scanf("%ld", &emple1.telefono);

    printf("Sueldo: ");
    scanf("%f", &emple1.sueldo);

    printf("\nLos datos del empleado cargado son:\n");

    mostrarUnEmpleado(emple1);


    empleado emple2= {1234, "pepe grillo", "no se 1200", 345678, 234567.09};

    emple1=emple2;

    system("pause");

    printf("\nLos datos del empleado cargado son:\n");

    mostrarUnEmpleado(emple2);

    printf("\nUn empleado pesa %d\n", sizeof(emple1));


    empleado empleAdministracion[10];
    int cantEmple=0;

    cantEmple=cargaArregloEmpleados(empleAdministracion, 10);

    printf("La cantidad de empleados que se cargaron fueron %d\n", cantEmple);


    mostraArregloEmpleados(empleAdministracion, cantEmple);
    return 0;
}

int cargaArregloEmpleados(empleado E[], int dimension)
{
    int i=0;
    char control='s';

    printf("Cargando el arreglo de empleados: \n");

    while(i<dimension && control=='s')
    {
        // E[i].idEmpleado=1000+i;

        printf("Id: ");
        scanf("%d", &E[i].idEmpleado);

        printf("Nombre: ");
        fflush(stdin);
        gets(E[i].nombre);

        printf("Direccion: ");
        fflush(stdin);
        gets(E[i].direccion);

        printf("Telefono: ");
        scanf("%ld", &E[i].telefono);

        printf("Sueldo: ");
        scanf("%f", &E[i].sueldo);

        printf("Desea continuar cargando empleados? s/n \n");

        fflush(stdin);
        scanf("%c", &control);

        i++;
    }

    return i;
}

void mostrarUnEmpleado(empleado e)
{
    printf("       Id: %d\n", e.idEmpleado);
    printf("   Nombre: %s\n", e.nombre);
    printf("Direccion: %s\n", e.direccion);
    printf(" Telefono: %ld\n", e.telefono);
    printf("   Sueldo: $%.2f\n", e.sueldo);
}

void mostraArregloEmpleados(empleado E[], int validos)
{
    int i=0;

    printf("El contenido del arreglo de emplados es:\n");
    printf("-----------\n");

    for(i=0;i<validos;i++)
    {
        mostrarUnEmpleado(E[i]);
        printf("-----------\n");
    }

}


