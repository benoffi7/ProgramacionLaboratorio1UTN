#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"


int main()
{

    /* 14. Determinar si la cantidad de elementos de la pila DADA es par.
    Si es par, pasar el elemento del tope de la pila AUX a la pila PAR
    y si es impar pasar el tope a la pila IMPAR. */



    Pila dada, aux, par, impar;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&par);
    inicpila(&impar);

    apilar(&dada, 1);
    apilar(&dada, 2);
    apilar(&dada, 3);
    apilar(&dada, 4);
    apilar(&dada, 5);
    //apilar(&dada, 6);

    printf("\nPila dada");
    mostrar(&dada);


    while (!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));          // saca 1 elemento de la pila

        if(!pilavacia(&dada))                    // se fija si no esta vacia..
            apilar(&aux, desapilar(&dada));      // desapila otro (se supone
        // q la pila es par)

        else
            apilar(&impar, desapilar(&aux));     // si no se cumple el if sup..
    }                                            // la pila es impar.....

    if(!pilavacia(&impar))
        printf("\nLa pila es impar");
    else
        printf("\nLa pila es par");



    return 0;
}
