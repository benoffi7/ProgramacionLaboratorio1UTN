/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 12:
	. RESOLUCION DE EJERCICIOS
        . GUIA DE FUNCIONES CON PILAS
        . EJEMPLOS DE FUNCIONES SIMPLES
*/

#include "Librerias/pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void funcionEjemplo(Pila* a)
{
    inicpila(a);
    apilar(a,30);
    apilar(a,20);
    apilar(a,10);
}

void copiarValores(Pila* original, Pila* copia)
{
    Pila auxOriginal;
    inicpila(&auxOriginal);

    Pila auxCopia;
    inicpila(&auxCopia);

    while(!pilavacia(original))
    {
        apilar(&auxCopia, tope(original));
        apilar(&auxOriginal, desapilar(original));
    }

    while(!pilavacia(&auxOriginal))
    {
        apilar(copia, desapilar(&auxOriginal));
    }

    /// devolviendo la pila a su estado original
    while(!pilavacia(&auxCopia))
    {
        apilar(original, desapilar(&auxCopia));
    }
}

/**
    Hacer una función que permita ingresar varios
    elementos a una Pila,
*/

/// facil -> dificil
/// conocido -> desconocido

void leerDatos(Pila* pila)
{/// tantos como quiera el usuario.

    const int TECLA_SALIR = 27;  /// tecla escape
    int teclaUsuario = 0;

    printf("para salir presione ESC, sino cualquier tecla \n");
    while(teclaUsuario != TECLA_SALIR)
    {
        leer(pila);

        /// preguntarle si quiere continuar

        fflush(stdin);
        teclaUsuario = getch();
    }
}

/**
    Hacer una función que
    encuentre el menor elemento de una pila
    y lo retorne.
    La misma debe eliminar ese dato de la pila
*/

int buscarYeliminarMenor(Pila*);

int main()
{
    Pila pila;
    inicpila(&pila);

    apilar(&pila, -20);
    apilar(&pila, 10);
    apilar(&pila, 20);

    int menorElemento = buscarYeliminarMenor(&pila);

    printf("el menor elemento es: %d", menorElemento);

    mostrar(&pila);

    return 0;
}

int buscarYeliminarMenorModularizado(Pila* pila)
{
    /// encuentre el menor elemento de una pila
    int menorElemento = encontrarMenor(pila);

    /// La misma debe eliminar ese dato de la pila
    eliminarElemento(pila, menorElemento);

    /// y lo retorne.
    return menorElemento;
}

void eliminarElemento(Pila* pila, int elemento)
{
    Pila aux;
    inicpila(&aux);

    int flag = 0;

    while(!pilavacia(pila) && flag == 0)
    {
        if (elemento == tope)
        {
            flag = 1;
            desapilar(pila);
        }

        apilar(&aux, desapilar(pila));
    }

    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }
}

int encontrarMenor(Pila* pila)
{
    Pila aux;
    inicpila(&aux);

    int menor = tope(pila);

    int flag = 0;
    while(!pilavacia(pila) && flag == 0)
    {
        if (tope(pila) < menor)
        {
            menor = tope(pila);
        }

        apilar(&aux, desapilar(pila));
    }

    while(!pilavacia(pila))
    {
        apilar(&aux, desapilar(pila));
    }

    return menor;
}


int buscarYeliminarMenor(Pila* pila)
{
    int menorElemento = 0;

    Pila auxRecorrido;
    inicpila(&auxRecorrido);

    Pila auxMenor;
    inicpila(&auxMenor);

    apilar(&auxMenor, desapilar(pila));

    /// encuentre el menor elemento de una pila
    while(!pilavacia(pila))
    {
        if (tope(pila) < tope(&auxMenor))
        {
            apilar(&auxRecorrido, desapilar(&auxMenor));
            apilar(&auxMenor, desapilar(pila));
        }
        else
        {
            apilar(&auxRecorrido, desapilar(pila));
        }
    }

    while(!pilavacia(&auxRecorrido))
    {
        apilar(pila, desapilar(&auxRecorrido));
    }

    /// La misma debe eliminar ese dato de la pila
    menorElemento = tope(&auxMenor);

    /// y lo retorne.
    return menorElemento;
}
