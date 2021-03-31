/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 4:
        . INTRODUCCION A LA ESTRUCTURA DE DATOS PILA
        . COMO AGREGAR LA ESTRUCTURA PILA AL PROYECTO
        . UTILIZACION
            CREAR
            INICIALIZAR
            APILAR
            LEER
            DESAPILAR
            TOPE
            PILA VACIA
            MOSTRAR

        . EJEMPLO: como pasar datos de una pila a otra
        . EJERCICIO 1 DE LA GUIA DE PILAS
*/

/// ------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "Librerias/pila.h" /// incluimos el archivo pila.h que esta dentro
                            /// de la carpeta librerias

int main()
{
    /// INTRODUCCION A LA ESTRUCTURA DE DATOS PILA
    /**
        Utiliza el modo de acceso LIFO (Last in first out),
        es decir El ultimo que llega es el primer que sale.

        Igual que una pila de platos o la ropa en un canasto.
    */

    /// --------------------------------------------------------------------------

    /**
        PILA como tipo de dato
        Creando una variable de tipo Pila
    */

    Pila pila;

    /// --------------------------------------------------------------------------

    /**
        INICPILA
        Iniciar una pila
    */

    inicpila(&pila);

    /// --------------------------------------------------------------------------

    /**
        APILAR
        Siempre apilamos "desde arriba". El ultimo elemento que apilamos, es el que
        esta mas arriba en la pila.
     */

    apilar(&pila, 10);
    apilar(&pila, 20);

    int variableA = 30;
    apilar(&pila, variableA);

    /**
        En el ejemplo anterior, el orden de los elementos quedaria:

            30  -> el ultimo elemento apilado, es el que queda en el tope
            20
            10  -> este fue el primer numero que apilamos
    */

    /// --------------------------------------------------------------------------

    /**
        LEER
        Esta funcion pide que se ingrese un valor por teclado, lo lee y lo apila
    */

    leer(&pila);

    /// --------------------------------------------------------------------------

    /**
        DESAPILAR
        "Saca" el elemento que esta en el tope de la lista.

        Al quitar un elemento de la pila, se devuelve o retorna (cuando veamos
        funciones esto tendra mas sentido), por lo que deberemos guardar ese
        valor en alguna variable para no perderlo.
    */

    int numeroDesapilado = desapilar(&pila);

    desapilar(&pila); /// si lo usamos de esta forma, el numero se pierde.

    /// Podemos apilar en una pila lo que desapilamos de otra pila
    Pila otraPila;
    inicpila(&otraPila);

    apilar(&otraPila, 10);
    apilar(&otraPila, 20);
    apilar(&otraPila, 30);

    apilar(&pila, desapilar(&otraPila));

    /// --------------------------------------------------------------------------

    /**
        TOPE
        Nos da el valor del elemento que esta en el tope de la pila, sin
        eliminarlo.
    */

    int valorDelTope = tope(&pila);

    /// --------------------------------------------------------------------------

    /**
        PILA VACIA
        Nos dice si la pila contiene o no elementos
    */

    if (pilavacia(&pila))
    {
        printf("la pila esta vacia");
    }
    else
    {
        printf("la pila aun contiene elementos");
    }

    /// --------------------------------------------------------------------------

    /**
        MOSTRAR
        muestra los elementos de la pila
    */

    mostrar(&pila);

    /// --------------------------------------------

    /// EJEMPLO: como pasar datos de una pila a otra

    Pila pilaA;
    inicpila(&pilaA);

    Pila pilaB;
    inicpila(&pilaB);

    apilar(&pilaA, 10);
    apilar(&pilaA, 20);
    apilar(&pilaA, 30);
    apilar(&pilaA, 40);

    while(!pilavacia(&pilaA))
    {
        apilar(&pilaB, desapilar(&pilaA));
    }

    /**
        Este codigo dice:
            mientras la pila A no este vacia,
            apilar en la pila B,
            lo que desapilo de la pila A.
    */

    return 0;
}
