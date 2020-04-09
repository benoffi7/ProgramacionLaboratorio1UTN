#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    ///   8) Eliminar un elemento de una pila.

    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);

    Pila descarte;
    inicpila(&descarte);

    char control;

    do
    {
        leer(&dada);
        printf("Desea continuar? s/n ");
        printf("%c", control = getch());
        printf("\n");
    }
    while(control == 's');


    int elemento;

    printf("Ingrese un elemento a eliminar en la pila dada: ");
    scanf("%d", &elemento);

/// recorro la pila mientras no se vacie y no encuentre el elemento

    while (!pilavacia(&dada) && tope(&dada)!=elemento)
    {
        apilar(&aux, desapilar(&dada));
    }

    /// si la pila no se vacio
    /// es porque el while anterior "corto" por la segunda condicion
    /// osea que el elemento que esta en el tope de dada es el que buscamos
    if(!pilavacia(&dada))
    {
        /// lo sacamos
        apilar(&descarte, desapilar(&dada));
    }

    while (!pilavacia(&aux))
    {
        /// y volvemos a poner todo el resto en dadad
        apilar(&dada, desapilar(&aux));
    }

    printf("\nPila dada");
    mostrar(&dada);

    printf("\nPila descarte");
    mostrar(&descarte);
    system("pause");

/// Ejercicio 10
    /// Dadas dos pilas A y B que simulan conjuntos (cada conjunto no
    ///tiene elementos repetidos sobre sí mismo), realizar un programa
    /// que calcule en la pila C la operación de unión
    printf("Hello world!\n");
    Pila ord1, ord2, ordFinal;
    inicpila(&ord1);
    inicpila(&ord2);
    inicpila(&ordFinal);

    /// cargamos las pilas ordenadas de forma creciente

    while(!pilavacia(&ord1) && !pilavacia(&ord2))
    {
        if(tope(&ord1)<tope(&ord2))
        {
            apilar(&ordFinal, desapilar(&ord1));
        }
        else
        {
            apilar(&ordFinal, desapilar(&ord2));
        }
    }

    if(!pilavacia(&ord1))
    {
        while(!pilavacia(&ord1))
        {
            apilar(&ordFinal, desapilar(&ord1));
        }
    }
    else
    {
        while(!pilavacia(&ord2))
        {
            apilar(&ordFinal, desapilar(&ord2));
        }
    }


    /// mostrar las pilas para finalizar

    return 0;
}
