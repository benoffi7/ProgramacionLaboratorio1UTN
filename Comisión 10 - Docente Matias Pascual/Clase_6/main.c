/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 6:
        . UTILIZACION DE PILAS CON VARIABLES
        . EJEMPLO: sumar elementos de una pila
        . EJEMPLO: buscar elemento y finalizar la busqueda al encontrarlo       
*/

/// ------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "matias.h"

int main()
{
    /// UTILIZACION DE PILAS CON VARIABLES
    /**
        Hasta ahora estuvimos trabajando con pilas sin variables.

        En estos ejercicios comenzaremos a utilizar variables para operar con
        las pilas.

        Si nos fijamos en el archivo de cabecera pila.h veremos que hay funciones
        que devuelven un valor int. Nos damos cuenta de esto al analizar el prototipado
        de la funcion y ver su valor de retorno.

        Ejemplos:
            int desapilar(P_Pila p);
            int tope(P_Pila p);
            int pilavacia(P_Pila p);

        El "int" adelante del nombre de la funcion, nos esta diciendo que esa funcion
        nos dara un numero entero como resultado.

        Este numero podemos guardarlo en una variable de la siguiente manera:

            int variableA = desapilar(&pila);

        Tambien podemos escribir:

            int variableA;
            variableA = desapilar(&pila);
    */

    /// ------------------------------------------------------------------------

    /// EJEMPLO: sumar elementos de una pila

    sumarElementosDePila(); /// esta funcion esta escrita en ejemplos.c

    /// ------------------------------------------------------------------------

    /// EJEMPLO: buscar elemento y finalizar la busqueda al encontrarlo

    buscarElementoYFinalizar(); /// esta funcion esta escrita en ejemplos.c

    return 0;
}
