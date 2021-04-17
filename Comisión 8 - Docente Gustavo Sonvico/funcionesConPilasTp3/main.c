#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargarPila (Pila *);
void pasarPila(Pila *, Pila *);

int main()
{
    Pila pilita, pilota;
    inicpila(&pilita);
    inicpila(&pilota);

    cargarPila(&pilita);

    printf("La pila pilita\n");
    mostrar(&pilita);

    pasarPila(&pilita, &pilota);

    printf("La pila pilita ahora\n");
    mostrar(&pilita);

    printf("La pila pilota\n");
    mostrar(&pilota);

    return 0;
}


void cargarPila(Pila * p)
{
    char control;

    printf("Vamos a cargar la pila\n");

    do
    {
        leer(p);

        printf("Desea continuar? s/n ");
        fflush(stdin);
        scanf("%c", &control);
    }
    while(control=='s');
}


void pasarPila(Pila * origen, Pila * destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino,desapilar(origen));
    }
}


