#include <stdio.h>
#include <string.h>

void ejemplo_arreglosDinamicos()
{
    /// su tamaño es definido en tiempo de ejecucion

    int cantidad = 10;
    int* arregloDinamico = (int*) malloc(cantidad * sizeof(int));

    /// ----------------------------------------------

    /// pidiendole al usuario que ingrese la cantidad de elementos

    printf("ingrese la cantidad de elementos \n");

    int cantidadElementos;

    fflush(stdin);

    scanf("%d", &cantidadElementos);

    int* arregloElementos = (int*) malloc(cantidadElementos * sizeof(int));

    /// ----------------------------------------------

    /// diferencia entre malloc y calloc

    /// usando el arreglo dinamico

    printf("%d \n", arregloElementos[0]);
    printf("%d \n", arregloElementos[1]);
    printf("%d \n", arregloElementos[2]);
    printf("%d \n", arregloElementos[3]);

    /// usando calloc
    int* otroArregloDinamico = (int*) calloc(10, sizeof(int));

    printf("----------------------- \n");

    printf("%d \n", otroArregloDinamico[0]);
    printf("%d \n", otroArregloDinamico[1]);
    printf("%d \n", otroArregloDinamico[2]);
    printf("%d \n", otroArregloDinamico[3]);

    /// calloc asigna cero en el lugar reservado, malloc no lo hace.
    /// ademas se diferencian en sus parametros

    /// ----------------------------------------------

    /// realloc permite reasginar la memoria asignada a un puntero

    /// asignamos 10 bytes para usar en 'palabra'
    /// char (1 byte) * 10 = 10 bytes

    char* palabra = (char*) malloc(10 * sizeof(char));

    /// reasginamos el tamaño a utilizar

    realloc(palabra, 20 * sizeof(int));

    /// liberamos la memoria
    free(otroArregloDinamico);
    free(palabra);
    free(arregloDinamico);
}

void ejemplo_arreglosParalelos()
{
    /**
        Para una persona que tiene:
            legajo
            nombre
            promedio
    */

    int matricula[100];
    char nombre[100][30];
    float promedio[100];

    int numeroAlumno_Garcia = 0;

    matricula[numeroAlumno_Garcia] = 23132;
    strcpy(nombre[numeroAlumno_Garcia], "juan garcia");
    promedio[numeroAlumno_Garcia] = 8.9F;

    /// mostrando el alumno
    printf("matricula: %d \n", matricula[numeroAlumno_Garcia]);
    printf("nombre: %s \n", nombre[numeroAlumno_Garcia]);
    printf("promedio: %.2f \n", promedio[numeroAlumno_Garcia]);
}
