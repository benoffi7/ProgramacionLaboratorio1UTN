#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila aux;
    int menor;
    Pila dada;
    Pila ordenada;
    inicpila(&aux);
    inicpila(&ordenada);
    inicpila(&dada);
    apilar(&dada,2);
    apilar(&dada,5);
    apilar(&dada,7);
    apilar(&dada,1);
    apilar(&dada,9);
///algoritmo de ordenacion por seleccion
    while (!pilavacia(&dada))
    {
        menor = desapilar(&dada);
///proceso de seleccion del menor
        while(!pilavacia(&dada))
        {
            if(tope(&dada)<= menor)
            {
                apilar(&aux, menor);
                menor = desapilar(&dada);
            }
            else
            {
                apilar(&aux, desapilar(&dada));
            }
        }
///proceso de apilar el dato seleccionado
        apilar(&ordenada,menor);
        // paso los elementos de aux a dada
        while (!pilavacia(&aux))
        {
            apilar(&dada, desapilar(&aux));
        }
    }




    printf("Pila dada ahora");
    mostrar(&dada);
    printf("Menor elemento de dada");
    mostrar(&ordenada);
    return 0;
}
