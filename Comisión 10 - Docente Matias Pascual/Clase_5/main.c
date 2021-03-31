/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 5:
        . EJEMPLO DEL OPERADOR MODULO
        . EJEMPLO DE MODULO USANDO PILA
        . COMO QUITAR UN NUMERO DE LA PILA
        . IDEM. EL USUARIO INGRESA EL NUMERO A SACAR DE LA PILA
*/

/// ------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "Librerias/pila.h"

int main()
{
    /// MODULO: devuelve el resto de una division de enteros

    printf("Ejemplo de modulo: \n");

    printf("%d \n", 3 % 2);    /// esto devolveria 1
    printf("%d \n", 2 % 2);    /// esto devolveria 0

    /**
        Es muy util cuando queremos saber si un numero es par o no.
        Si el numero % 2 == 0, entonces es par.

        Ejemplo:
            if (unNumero % 2 == 0)
            {
                printf("el numero es par");
            }
    */

    /// -----------------------------------------------------------

    /// EJEMPLO: cada vez que un numero de la pila sea par,
    ///          nos lo dice en pantalla

    /** nota: en este ejemplo no aparece que numero es */

    Pila pila;
    inicpila(&pila);

    apilar(&pila, 10);
    apilar(&pila, 23);
    apilar(&pila, 30);
    apilar(&pila, 45);

    while(!pilavacia(&pila))
    {
        if (desapilar(&pila) % 2 == 0)
        {
            printf("la pila tiene un numero par \n");
        }
    }

    /// -----------------------------------------------------------

    /// EJEMPLO: quitar de la pila el numero 30

    Pila pila2;
    inicpila(&pila2);

    apilar(&pila2,10);
    apilar(&pila2,20);
    apilar(&pila2,30);
    apilar(&pila2,40);
    apilar(&pila2,50);

    Pila aux;
    inicpila(&aux);

    printf("\n\nSacando el 30 de la pila \n");

    /// la pila original
    printf("\npila original: \n");
    mostrar(&pila2);

    while(!pilavacia(&pila2))
    {
        if (tope(&pila2) != 30)
        {
            apilar(&aux, desapilar(&pila2));
        }
        else
        {
            desapilar(&pila2);
        }
    }

    /// volvemos a dejar la pila ordenada
    while(!pilavacia(&aux))
    {
        apilar(&pila2, desapilar(&aux));
    }

    /// la pila luego de sacar el 30
    printf("\npila sin el 30: \n");
    mostrar(&pila2);

    /// -----------------------------------------------------------

    /// VERSION PROPUESTA POR UN ALUMNO:
    /** El usuario ingresa el numero que hay que sacar */

    Pila pila3;
    inicpila(&pila3);

    apilar(&pila3,50);
    apilar(&pila3,40);
    apilar(&pila3,30);
    apilar(&pila3,20);
    apilar(&pila3,10);

    /// la pila original
    printf("\npila original: \n");
    mostrar(&pila3);

    Pila aux2;
    inicpila(&aux2);

    printf("que numero desea sacar de la pila \n");

    int numeroASacar;
    scanf("%d", &numeroASacar);

    /// quitamos el numero que diga el usuario
    while(!pilavacia(&pila3))
    {
        if (tope(&pila3) != numeroASacar)
        {
            apilar(&aux2, desapilar(&pila3));
        }
        else
        {
            desapilar(&pila3);
        }
    }

    /// volvemos a dejar la pila ordenada
    while(!pilavacia(&aux2))
    {
        apilar(&pila3, desapilar(&aux2));
    }

    /// la pila luego de sacar el numero
    printf("\npila sin el %d: \n", numeroASacar);
    mostrar(&pila3);

    return 0;
}
