#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*
1. Hacer una función que permita ingresar varios elementos a una Pila,
tantos como quiera el usuario.
*/
void cargarPila(Pila * punteroPila);

/*
2. Hacer una función que pase todos los elementos de una pila a otra.
*/
void pasarPila (Pila * pOrigen, Pila * pDestino);

int main()
{
    printf("Hello funciones!\n");

    Pila pilita, pilota;
    inicpila(&pilita);
    inicpila(&pilota);

    cargarPila(&pilita);

    printf("Pila pilita cargada: \n");
    mostrar(&pilita);

    pasarPila(&pilita, &pilota);

    printf("Pila pilita vacia: \n");
    mostrar(&pilita);

    printf("Pila pilota con los datos pasados: \n");
    mostrar(&pilota);

    return 0;
}

void cargarPila(Pila * punteroPila)
{

    char control;

    printf("Vamos a cargar la pila desde la funcion: \n");
    do
    {
        leer(punteroPila);
        printf("Desea continuar? s/n ");
        printf("%c", control = getch());
        printf("\n");
    }
    while(control == 's');
}

void pasarPila (Pila * pOrigen, Pila * pDestino)
{

    while (!pilavacia(pOrigen))
    {
        apilar(pDestino, desapilar(pOrigen));
    }

}
