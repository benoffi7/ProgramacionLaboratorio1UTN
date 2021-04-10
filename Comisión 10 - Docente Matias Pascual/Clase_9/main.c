/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 9:
        . FUNCIONES (segunda parte)
        . EJEMPLO DE NOMBRES DE FUNCIONES
            _ adecuados
            _ ambiguos

        . ORDEN DE LOS PARAMETROS
            _ ejemplo de orden en los parametros
            _ ejemplo de parametros ambiguos

        . CODIGO DE EJEMPLO DE ORDENAR UNA PILA
            _ en seccion "pasos para escribir un subprograma"

        . PASOS PARA ESCRIBIR UN SUBPROGRAMA
            _ definir el problema a resolver
            _ nombrar el subprograma (funcion) correctamente
            _ testear su funcionamiento
            _ escribir la cabecera de la funcion (prototipado o declaracion)
            _ buscar el algoritmo adecuado para su funcionamiento
            _ escribir comentarios de los pasos principales
            _ escribir el codigo de cada comentario
            _ revisar el codigo
*/

#include <stdio.h>
#include <stdlib.h>
#include "Librerias/pila.h"

void ejemploBuscarMenor();
void ejemploPilaOrdenada();

int main()
{

    return 0;
}

void ejemploBuscarMenor()
{
    Pila pila;
    inicpila(&pila);

    apilar(&pila, 11);
    apilar(&pila, 1);
    apilar(&pila, 50);
    apilar(&pila, -10);
    apilar(&pila, 30);

    printf("%d", buscarMenorElemento_v5(&pila));
}

void ejemploPilaOrdenada()
{
    Pila pila;
    inicpila(&pila);

    apilar(&pila, 11);
    apilar(&pila, 1);
    apilar(&pila, 50);
    apilar(&pila, -10);
    apilar(&pila, 30);

    mostrar(&pila);

    ordenarPila(&pila);

    mostrar(&pila);
}
