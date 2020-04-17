#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "pila.h"
#include "fPila.h"

int main()
{
    Pila dada, otra, auxDada, desordenada;
    inicpila(&dada);
    inicpila(&otra);
    inicpila(&auxDada);
    inicpila(&desordenada);
    printf("\n\n Direccion de memoria de la pila dada %p\n\n",&dada);
/**
    cargaPila(&dada,"Ingrese una temperatura");
    cargaPilaRandom(&otra,25);
    printf("\n\n Mostrando Temperaturas ");
    mostrar(&dada);
    system("pause");

    pasaPila(&dada,&auxDada);
    printf("\n\n Mostrando pila dada ");
    mostrar(&dada);
    printf("\n\n Mostrando pila auxDada ");
    mostrar(&auxDada);
    system("pause");

    copiaPila(auxDada, &dada);
    printf("\n\n Mostrando pila dada ");
    mostrar(&dada);
    printf("\n\n Mostrando pila auxDada ");
    mostrar(&auxDada);

    cargaPila(&otra, "Ingrese otra cosa");

    printf("\n\n Mostrando pila otra ");
    mostrar(&otra);
*/

    cargaPilaRandom(&desordenada,15);

    printf("\n Pila desordenada ..........\n");
    mostrar(&desordenada);
    system("pause");
/**
    ordenaPorSeleccion(&desordenada);
    printf("\n Pila desordenada ORDENADA ..........\n");
    mostrar(&desordenada);
*/
    ordenaPorInsercion(&desordenada);
    printf("\n Pila desordenada ORDENADA ..........\n");
    mostrar(&desordenada);

    return 0;
}
