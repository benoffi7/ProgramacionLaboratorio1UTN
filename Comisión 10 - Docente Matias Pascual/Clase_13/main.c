/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 13:
        . RESOLUCION DE EJERCICIOS CON FUNCIONES Y PILAS
        . ALGORITMIA vs MODULARIZACION
*/

#include <stdio.h>
#include <stdlib.h>
#include "Librerias/pila.h"

void pasarPila (Pila *origen, Pila *destino);
int devuelveMenor (Pila *dada);
void pasarPilaOrdenada(Pila * origen, Pila *destino);

float promedio();

int main()
{
    Pila pila;
    inicpila(&pila);

    apilar(&pila, -10);
    apilar(&pila, 20);
    apilar(&pila, 30);
    apilar(&pila, -40);
    apilar(&pila, 30);
    apilar(&pila, 40);
    apilar(&pila, 56);
    apilar(&pila, -27);
    apilar(&pila, 65);
    apilar(&pila, 57);
    apilar(&pila, 50);

    Pila pila2;
    inicpila(&pila2);

    pasarPila(&pila, &pila2);

    return 0;
}

void pasarPila (Pila *origen, Pila *destino)
{
    while (!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}

int devuelveMenor (Pila *dada)
{
    Pila aux, menor;
    inicpila(&aux);
    inicpila(&menor);

    apilar(&menor, desapilar(dada));

    while(!pilavacia(dada))
    {
        if (tope(dada)<tope(&menor))
        {
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(dada));
        }
        else
        {
            apilar(&aux, desapilar(dada));
        }
    }

    pasarPila(&aux, dada);

    return tope(&menor);
}

/** 5.
    Hacer una función que pase los elementos de una pila a otra,
    de manera que se genere una nueva pila ordenada.
    Usar la función del ejercicio 4 */

void pasarPilaOrdenada(Pila * origen, Pila *destino)
{
    Pila orden;
    inicpila(&orden);
    while (!pilavacia(origen))
    {
        apilar(&orden, devuelveMenor(origen));
    }

    pasarPila(&orden, destino);
}

/**
    6. Hacer una función que inserte en una pila ordenada un nuevo
    elemento, conservando el orden...

ejemplo:
    pila
    9
    8   <- entre  el dato iria entre el 8 y el 6
    6
    5
    4
    3

        dato: 7
*/

void insertarDatoOrdenado(Pila* pila, int dato)
{
    Pila aux;
    inicpila(&aux);

    /// primera situacion: el dato es el mayor de la pila
    if (dato > tope(pila))
    {
        apilar(pila, dato);
    }
    /// segunda situacion: el dato no es el mayor
    else
    {
        int flag = 0;   /// busco el lugar donde debo ingresar el dato
        while(flag == 0 && !pilavacia(pila))
        {
            if (dato < tope(pila))
            {
                /// recorro la pila
                apilar(&aux, desapilar(pila));
            }
            else
            {
                apilar(pila, dato);
                flag = 1;   /// el dato fue ingresado
            }
        }

        /// si no pude ingresar el dato, entonces el dato va al principio de la pila
        if (flag == 0)
        {
            apilar(pila, dato);
        }
    }

    /// vuelvo la pila a su estado original
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }
}

void insertaEnOrden (Pila *dada, Pila *dato)
{
    Pila aux;
    inicpila(&aux);

    while ((!pilavacia(dada)) && (tope(dato)<tope(dada)))
    {
        apilar(&aux, desapilar(dada));
    }
    apilar(dada, desapilar(dato));

    while (!pilavacia(&aux))
    {
        apilar(dada, desapilar(&aux));
    }
}

/** 7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
nueva pila ordenada. Usar la función del ejercicio 6.*/

void insertarPilaEnOtraPilaOrdenada (Pila *dada, Pila *datos)
{
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(datos))
    {
        apilar(&aux, desapilar(datos));
        insertaEnOrden(dada, &aux);
    }
}
