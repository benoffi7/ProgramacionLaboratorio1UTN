/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 110
    Prof. Matias Pascual
*/

/**
    CLASE 6:
        . UTILIZACION DE PILAS CON VARIABLES
        . EJEMPLO: sumar elementos de una pila
        . EJEMPLO: buscar elemento y finalizar la busqueda al encontrarlo
        . UTILIZACION DE ARCHIVOS .C PARA ORGANIZAR EJERCICIOS
        . BREVE EXPLICACION DE ARCHIVOS .H
*/

/// ------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "Librerias/pila.h"

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

    /// ------------------------------------------------------------------------

    /// BREVE EXPLICACION DE ARCHIVOS .H
    /**
        Un archivo .h , tambien llamado archivo de cabecera, es un archivo que
        contiene los prototipos de funciones y definiciones que seran utilizados
        en otro archivo .c , que tendra las funciones escritas y que son las que
        utilizamos en nuestro programa.

        A veces necesitamos incluir un mismo archivo .h en diferentes archivos de
        nuestro proyecto. Debido a que C no nos permite redefinir dos veces una misma
        palabra (sea variable, funcion, etc.) necesitamos una forma de evitar que
        se incluyan los archivos si ya estan incluidos.

        Para esto utilizamos los siguientes comandos:

            #ifndef NOMBRE_H_INCLUDED
            #define NOMBRE_H_INCLUDED

            aca va todo nuestro codigo
            aca va todo nuestro codigo
            aca va todo nuestro codigo
            aca va todo nuestro codigo
            aca va todo nuestro codigo

            #endif

        Con esto le estamos diciendo a C que, si el nombre del archivo ya esta incluido,
        no lo vuelva a incluir.

        Todo esto se hace automaticamente cuando utilizamos File/New File y seleccionamos
        C/C++ Header, para luego ponerle un nombre.
    */

    return 0;
}
