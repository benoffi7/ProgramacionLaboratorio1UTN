#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

void cargarPila(Pila * p)
{
    int i;

    for(i=0; i<10; i++)
    {
        apilar(p, rand()%100);
    }
}

void pasarPila(Pila * origen, Pila * destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}

int main()
{
    srand(time(NULL));

    Pila pilita, pilota;

    inicpila(&pilita);
    inicpila(&pilota);

    cargarPila(&pilita);
 //   cargarPila(&pilota);

    puts("desde el main pilita");
    mostrar(&pilita);

    pasarPila(&pilita, &pilota);

    puts("desde el main pilita");
    mostrar(&pilita);

    puts("desde el main pilota");
    mostrar(&pilota);
    return 0;
}
