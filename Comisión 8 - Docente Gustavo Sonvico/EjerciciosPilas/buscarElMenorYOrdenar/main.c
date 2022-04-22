#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../pila.h"

void cargarPilaRandom(Pila * p)
{
    int i=0;
    for(i=0; i<10; i++)
    {
        apilar(p, (rand()%100) + 1);
    }
}

void pasarPila(Pila * pOrigen, Pila * pDestino)
{
    while(!pilavacia(pOrigen))
    {
        apilar(pDestino, desapilar(pOrigen));
    }
}

int buscarMenor(Pila * p)
{
    int elMenorParaRetornar;
    Pila menor, aux;
    inicpila(&menor);
    inicpila(&aux);

    apilar(&menor, desapilar(p));

    while(!pilavacia(p))
    {
        if(tope(p)<tope(&menor))
        {
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(p));
        }
        else
        {
            apilar(&aux, desapilar(p));
        }
    }

    pasarPila(&aux, p);

    elMenorParaRetornar=tope(&menor);

    return elMenorParaRetornar;
}

void ordenarPorSeleccionUnaPila(Pila * origen, Pila * destino)
{
    int unValor=0;

    while(!pilavacia(origen))
    {
        unValor=buscarMenor(origen);

        apilar(destino, unValor);
    }
}

void insertarEnOrden(Pila * p, int valor)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p) && tope(p)>valor)
    {

        apilar(&aux, desapilar(p));
    }

    apilar(p, valor);

    pasarPila(&aux, p);
}

void ordenarPorInsercionUnaPila(Pila * origen, Pila * destino)
{
    int aInsertar=0;

    while(!pilavacia(origen))
    {
        aInsertar=desapilar(origen);
        insertarEnOrden(destino, aInsertar);
    }
}

int main()
{

    srand(time(NULL));

    Pila dada, aux;
    Pila ordenada;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&ordenada);

    cargarPilaRandom(&dada);
    puts("pila dada post carga");
    mostrar(&dada);

    // ordenarPorSeleccionUnaPila(&dada, &ordenada);

//   puts("pila dada luego de ordenar");
//   mostrar(&dada);

//    puts("pila ordenada");
//    mostrar(&ordenada);

    ordenarPorInsercionUnaPila(&dada, &ordenada);

    puts("pila ordenada luego ordenarla por insercion);
    mostrar(&ordenada);


    return 0;
}
