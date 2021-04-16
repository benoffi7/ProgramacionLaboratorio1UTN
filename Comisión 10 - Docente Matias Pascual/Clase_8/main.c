/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 8:
        . FUNCIONES (primera parte)
        . DEFINICION
        . TIPOS DE FUNCIONES

        . ¿CUANDO UTILIZAR UNA FUNCION?
            _ Evitar codigo duplicado
            _ Disminuir cantidad de lineas de codigo
            _ Reducir complejidad del programa
            _ Mejorar la legibilidad del codigo

        . PROTOTIPADO DE FUNCIONES
            _ Declaracion vs Definicion

        . PARAMETROS
            _ Formales
            _ Actuales

        . PASAJE DE PARAMETROS
            _ Por valor
            _ Por referencia

        . BREVE INTRODUCCION A PUNTEROS
            (necesario para entender el pasaje de parametros
             por referencia)

        . AMBITO DE VIDA DE LAS VARIABLES EN FUNCIONES
            _ Variables locales a la funcion
            _ Variables globales

        . UTILIZACION DE FUNCIONES CON PILAS

        . ALGORITMOS
            _ codigo de ejemplo de busqueda
            _ codigo de ejemplo de pila capicua

            _ explicacion de ordenamiento por seleccion (hablado en clase)
            _ explicacion de ordenamiento por insercion (hablado en clase)
*/

#include <stdio.h>
#include <stdlib.h>
#include "Librerias/pila.h"

/// PROTOTIPADO DE FUNCIONES (declaracion de funciones)
/// ---------------------------------------------------------

void ejemplo_pilaCapicua();
void holaMundo();
float sumarFloats(float, float);    /// durante el prototipado o declaracion de funciones
                                    /// no es necesario escribir el nombre del parametro

/// funciones de ejemplo sin definir
void pedirNombre();
void saludarUsuario();
void finalizar();

/// ---------------------------------------------------------

/// esto es una variable global
int variableGlobal = 30;
/**
    las variables globales se declaran arriba del main, por ejemplo,
    y se pueden usar en cualquier parte del proyecto

    son una practica muy desaconsejada debido a la dificultad de
    su seguimiento durante la depuracion de errores
*/

 /// ---------------------------------------------------------

/// FUNCION MAIN
int main()
{
    int variable = 10;

    printf("%d", variable);




    //{ oculto
    /// PARAMETROS ACTUALES DE UNA FUNCION

    /// en este ejemplo, 10.5F y 1.0F son los parametros actuales
    float resultado = sumarFloats(10.5F, 1.0F);
    printf("resultado: %.2f", resultado);

    /// ---------------------------------------------------------

    /// EJEMPLOS DEL USO DE PUNTEROS

    int variableA = 20; /// declaro una variable
    int* puntero;       /// declaro un puntero

    puntero = &variableA;   /// le asigno a puntero la direccion de memoria de
                            /// la variableA

    /// mostrando por pantalla...
    printf("&puntero: %X \n", &puntero); /// direccion de memoria de puntero

    printf("valor de puntero: %X \n", puntero); /// valor del puntero

    printf("&variableA: %X \n", &variableA); /// direccion de memoria de variableA

    printf("valor variableA: %d \n", variableA); /// valor de la variableA

    /// valor que se encuentra en la direccion a la que apunta el puntero
    printf("valor en la direccion a la que apunta puntero: %d", *puntero);

    /**
        Nota:
            podriamos traducir el simbolo & como "la direccion de memoria de".

            de esta forma, leer &variableA, seria como leer "la direccion de
            memoria de la variableA"

            de igual forma, podriamos traducir el simbolo *, de la siguiente
            manera: "el valor que se encuentra en la direccion de memoria
            a la que apunta el puntero", o tambien "el valor de la direccion
            de memoria a la que apunta el puntero".

            asi, si leemos *puntero = 10; estamos diciendo "asignar un 10 como
            valor en la direccion de memoria a la que apunta el puntero"
    */

    /// ---------------------------------------------------------

    /// PILAS Y PUNTEROS
    Pila pilaA;
    inicpila(&pilaA);

    /// pasamos la direccion de memoria de la pilaA
    cargarElementosEnPila(3, &pilaA);
    mostrar(&pilaA);

    /// mostramos si un elemento fue encontrado o no
    printf("%d", buscarElemento(10, &pilaA));

    /// ---------------------------------------------------------

    /// EJEMPLO DE CARGA DE PILAS CON FUNCIONES

    cargarPilaUsandoTeclaSalir(&pilaA);
//    cargarElementosEnPila(4, &pila);

    /// ---------------------------------------------------------

    /// EJEMPLO DE MODULARIZACION DE UN PROBLEMA

    Pila pilaNueva;
    inicpila(&pilaNueva);

//    cargarPila(&pilaNueva);
    mostrar(&pilaNueva);

    /// estas funciones no estan definidas, son solo un ejemplo
//    pedirNombre();
//    saludarUsuario();
//    finalizar();

    //}
    return 0;
}
/// FIN DEL MAIN

/// ---------------------------------------------------------

/// DEFINICION DE FUNCIONES

void holaMundo()
{
    printf("hola mundo!");
}

/// en este ejemplo, numA y numB son los parametros formales de la funcion
float sumarFloats(float numA, float numB)
{
    return numA + numB;
}

/// ---------------------------------------------------------

/// ejemplo de como saber si una pila es capicua
void ejemplo_pilaCapicua()
{
    /// creamos una copia invertida de la pila
    /// comparamos sus topes

    Pila pilaOriginal;
    inicpila(&pilaOriginal);

    apilar(&pilaOriginal, 10);
    apilar(&pilaOriginal, 20);
    apilar(&pilaOriginal, 30);
    apilar(&pilaOriginal, 20);
    apilar(&pilaOriginal, 10);

    /// copiamos la pila
    Pila pilaCopia;
    inicpila(&pilaCopia);

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&pilaOriginal))
    {
        apilar(&pilaCopia, tope(&pilaOriginal));
        apilar(&aux, desapilar(&pilaOriginal));
    }

    while(!pilavacia(&aux))
    {
        apilar(&pilaOriginal, desapilar(&aux));
    }

    int flag = 0;
    while(!pilavacia(&pilaOriginal) && flag == 0)
    {
        if (tope(&pilaOriginal) != tope(&pilaCopia))
        {
            flag = 1;
        }
        else
        {
            apilar(&aux, desapilar(&pilaOriginal));
            desapilar(&pilaCopia);
        }
    }

    if (flag == 1)
    {
        printf("la pila no es capicua \n");
    }
    else
    {
        printf("la pila es capicua \n");
    }

    while(!pilavacia(&aux))
    {
        apilar(&pilaOriginal, desapilar(&aux));
    }
}

