#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargarPila(Pila * punteroPila);

void pasarPila(Pila * pOrigen, Pila * pDestino);

int main()
{
    printf("Hello funciones con pilas!\n");

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

///1- hacer una funcion que cargue la pila con intervencion del usr
void cargarPila(Pila * punteroPila)
{
    char control;

    printf("Cargando la pila desde la funcion:\n");
    do
    {
        leer(punteroPila);
        printf("Desea continuar? s/n ");
        printf("%c", control = getch());
        printf("\n");
    }
    while(control == 's');
}

/// 2 -Hacer una función que pase todos los elementos de una pila a otra.
void pasarPila(Pila * pOrigen, Pila * pDestino)
{
    while(!pilavacia(pOrigen))
    {
        apilar(pDestino, desapilar(pOrigen));
    }
}
