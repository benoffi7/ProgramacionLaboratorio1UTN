#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///pedir a un usuario de cargar 10 valores enteros
///en una pila y luego eliminar solo los pares.

int main()
{
    Pila mipila;
    Pila aux;
    int descarte;
    inicpila(&mipila);
    inicpila(&otrapila);
    for (int i = 1; i<=10 ;i++)
    {
        leer(&mipila);
    }
    printf("Pila luego de cargarla\n");
    mostrar(&mipila); /// nos muestra los valores que hay en la pila por consola
    while (!pilavacia(&mipila))
    {

        if (tope(&mipila) % 2 == 0)
        {
            descarte = desapilar(&mipila);
        }
        else
        {
          apilar(&otrapila,desapilar(&mipila));
        }

    }
    printf("Pila luego de descargarla\n");
    mostrar(&mipila);
    printf("Pila otra cargada\n");
    mostrar(&otrapila);

    while (!pilavacia(&otrapila))
    {
        apilar(&mipila,desapilar(&otrapila));
    }
    printf("Pila mipila luego de pasar los elementos desde otrapila\n");
    mostrar(&mipila);
    printf("Pila otrapila\n");
    mostrar(&otrapila);


    return 0;
}
