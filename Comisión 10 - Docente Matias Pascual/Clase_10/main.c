/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 10:
        . FUNCIONES (tercera parte)

        . ACOMPLAMIENTO
            _ de datos
            _ de control
            _ acoplamiento externo
            _ patologico (explicado en clase)

        . COHESION
            _ ejemplo de cohesion aceptable
            _ ejemplo de cohesion poco aceptable

        . CODIGO DE EJEMPLO DE ORDENAMIENTO POR INSERCION

        . BREVE EXPLICACION DE PARAMETROS ILIMITADOS
            _ ejemplo de sumar muchos numeros

        . BREVE EXPLICACION DE ARREGLOS
*/

#include <stdio.h>
#include <stdlib.h>
#include "Librerias/pila.h"
#include <stdarg.h>

void ejemploIngresarEnOrder();
void ejemploAcoplamiento();
void ejemploAcoplamiento_2();
void ejemploArreglo();
void ejemploCohesion();

/// para explicar acoplamiento externo
int variableGlobal = 0;

int main()
{
    return 0;
}

void ejemploAcoplamiento()
{
    /// estos dos arreglos nos permiten ingresar guardar un nombre y un apellido
    char nombre[50] = "";
    char apellido[50] = "";

    /// pasar el & en un arreglo es redundante (explicado en clase)
    /// pero de momento vamos a dejar el &
    cargarNombreApellido(&nombre, &apellido);

    printf("\n\nUsted es: %s %s \n\n", nombre, apellido);
}

void ejemploAcoplamiento_2()
{
    char nombre[50] = "";
    char apellido[50] = "";

    int error = cargarConControlDeCarga(&nombre, &apellido, 0);

    if (error == 0)
    {
        printf("\n\nUsted es: %s %s \n\n", nombre, apellido);
    }
}

void ejemploIngresarEnOrder()
{
    Pila pila;
    inicpila(&pila);

    apilar(&pila, 50);
    apilar(&pila, 40);
    apilar(&pila, 30);
    apilar(&pila, 20);
    apilar(&pila, 10);

    mostrar(&pila);

    ingresarEnOrden(&pila, 21);
    ingresarEnOrden(&pila, 1);
    ingresarEnOrden(&pila, 61);

    mostrar(&pila);
}

void ejemploArreglo()
{
    char nombre[50];
    char* puntero;

    nombre[0] = 33;

    printf("nombre: \n");
    printf("= %X \n", nombre);
    printf("& %X \n", &nombre);
    printf("[0] %d \n", nombre[0]);

    puntero = nombre;

    printf("\npuntero -> nombre: \n");
    printf("= %X \n", puntero);
    printf("* %d \n", *puntero);
    printf("[0] %d \n", puntero[0]);

    puntero = &nombre;

    printf("\npuntero -> &nombre: \n");
    printf("= %X \n", puntero);
    printf("* %d \n", *puntero);
    printf("[0] %d \n", puntero[0]);
}

void ejemploCohesion()
{
    int sumaTotal = sumarMuchosNumeros(4,2,3,4,5);
    int sumaTotal_v2 = sumarMuchosNumeros_v2();

    printf("Resultados\n\tv1. La suma total es: %d \n", sumaTotal);
    printf("\tv2. La suma total es: %d \n", sumaTotal_v2);
}
