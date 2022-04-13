#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


int main()
{
    Pila dada, aux, copiaInvertida, auxCopia;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&copiaInvertida);
    inicpila(&auxCopia);

    apilar(&dada, 1);
    apilar(&dada, 2);
    apilar(&dada, 3);
    apilar(&dada, 4);
    apilar(&dada, 5);
    apilar(&dada, 6);
    apilar(&dada, 5);
    apilar(&dada, 4);
    apilar(&dada, 3);
    apilar(&dada, 2);
    apilar(&dada, 1);

    printf("\n <<<<<<<<<<<<<<< Pila dada >>>>>>>>>>>>>");
    mostrar(&dada);

    /// copio la pila dada en copiaInvertida
    while(!pilavacia(&dada)){
        apilar(&copiaInvertida, tope(&dada));
        apilar(&aux, desapilar(&dada));
    }

    /// paso aux a dada
    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }

    while(!pilavacia(&dada) && !pilavacia(&copiaInvertida) && tope(&dada)==tope(&copiaInvertida)){
        apilar(&aux, desapilar(&dada));
        apilar(&auxCopia, desapilar(&copiaInvertida));
    }

    if(pilavacia(&dada) && pilavacia(&copiaInvertida)){
        printf("\n la pila dada es capicua");
    }else{
        printf("\n la pila dada No es capicua\n");
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }

    printf("\n <<<<<<<<<<<<<<< Pila dada >>>>>>>>>>>>>");
    mostrar(&dada);
    printf("\n <<<<<<<<<<<<<<< Pila copiaInvertida >>>>>>>>>>>>>");
    mostrar(&copiaInvertida);



    return 0;
}
