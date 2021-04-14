/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 11:
        . FUNCIONES CON PILAS
        . EJEMPLOS DE FUNCIONES CON PILAS
        . EJERCICIO 9 DE GUIA DE FUNCIONES
        . FUNCIONES QUE LLAMAN A OTRAS FUNCIONES
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Librerias/pila.h"

/**
Ejercicio 9:
        Hacer una función que calcule el promedio de los elementos de una pila,
        para ello hacer también una función que calcule la suma,
        otra para la cuenta y otra que divida.

        En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3.
*/

/// prototipado de funciones

/// calculamos el promedio de los elementos de la pila
float promedio(Pila* pila);

/// para eso necesitamos tres funciones...

/// una funcion que sume el valor de todos los elementos de la pila
int sumarElementos(Pila* pila);

/// una funcion que cuente la cantidad de elementos de la pila
int cantidadElementos(Pila* pila);

/// una funcion que calcule la division de la suma por la cantidad de elementos
/// recordemos que: promedio = sumaElementos / cantidadElementos
float division(int suma, int cantidad);

/// ----------------------------------------------

int main()
{
    Pila pila;
    inicpila(&pila);

    apilar(&pila, 7);
    apilar(&pila, 8);
    apilar(&pila, 9);

    float promedioCalculado = promedio(&pila);

    printf("promedio: %.2f", promedioCalculado);

    return 0;
}

/// ----------------------------------------------

/// definicion de funciones

float promedio(Pila* pila)
{
    /// suma de los elementos
    int suma = sumarElementos(pila);

    /// cantidad elementos
    int cantidad = cantidadElementos(pila);

    /// division
    float promedio = division(suma, cantidad);

    return promedio;
}

/// ----------------------------------------------

int sumarElementos(Pila* pila)
{
    int suma = 0;

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pila))
    {
        suma += tope(pila);
        apilar(&aux, desapilar(pila));
    }

    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return suma;
}

/// ----------------------------------------------

int cantidadElementos(Pila* pila)
{
    int cantidad = 0;

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pila))
    {
        apilar(&aux, desapilar(pila));
        cantidad++;
    }

    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return cantidad;
}

/// ----------------------------------------------

float division(int suma, int cantidad)
{
    float resultado = (float) suma / cantidad;

    return resultado;
}
