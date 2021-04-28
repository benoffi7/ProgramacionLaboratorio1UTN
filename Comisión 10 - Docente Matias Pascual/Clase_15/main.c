/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 15:
        MATRICES
            * Declaracion
            * Utilizacion
            * Recorriendo una matriz

        STRING (cadena de caracteres)
            * Utilizacion
            * Principales funciones para el manejo de strings

        MATRICES y STRINGS
            * Entendiendo los arreglos de strings
*/


#include <stdio.h>
#include <stdlib.h>

void cambiarVariable(int* localA)
{/// localA = &mainA
    *localA = 10;
}

int main()
{
    int mainA = 30;
    cambiarVariable(&mainA);

    printf("%d", mainA);

    //ejemplo_matriz();
    //ejemplo_string();
    //ejemplo_operacionesConString();
    //ejemplo_arreglosString();

    return 0;
}

