#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"


int main()
{
    srand(time(NULL));
    Pila dada;
    Pila modelo;
    Pila aux;
    Pila auxModelo;
    Pila basura;

    inicpila(&dada);
    inicpila(&modelo);
    inicpila(&aux);
    inicpila(&auxModelo);
    inicpila(&basura);

    int limite;

    limite = rand()%25;
    for(int i=0; i<limite; i++)
    {
        apilar(&dada, rand()%10);
    }

    limite = rand()%20;
    for(int i=0; i<limite; i++)
    {
        apilar(&modelo, rand()%10);
    }

    printf("<<<<<<<<<<<<<<< pila dada >>>>>>>>>>>>>>>>>>>");
    mostrar(&dada);

    printf("<<<<<<<<<<<<<<< pila modelo >>>>>>>>>>>>>>>>>>>");
    mostrar(&modelo);

    while(!pilavacia(&modelo))
    {
        while(!pilavacia(&dada))
        {
            if(tope(&modelo)==tope(&dada))
            {
                apilar(&basura, desapilar(&dada));
            }
            else
            {
                apilar(&aux, desapilar(&dada));
            }
        }

        while(!pilavacia(&aux))
        {
            apilar(&dada, desapilar(&aux));
        }
        apilar(&auxModelo, desapilar(&modelo));
    }

    while(!pilavacia(&auxModelo))
    {
        apilar(&modelo, desapilar(&auxModelo));
    }

    printf("<<<<<<<<<<<<<<< pila dada >>>>>>>>>>>>>>>>>>>");
    mostrar(&dada);

    printf("<<<<<<<<<<<<<<< pila modelo >>>>>>>>>>>>>>>>>>>");
    mostrar(&modelo);

    return 0;
}
