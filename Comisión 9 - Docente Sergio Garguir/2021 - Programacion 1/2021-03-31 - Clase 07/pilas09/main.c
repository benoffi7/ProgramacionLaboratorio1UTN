#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.
*/
int main()
{
    Pila a, b, auxA, auxB;
    inicpila(&a);
    inicpila(&b);
    inicpila(&auxA);
    inicpila(&auxB);

    for(int i=0;i<10;i++){
        apilar(&a, rand()%15);
    }

    for(int i=0;i<15;i++){
        apilar(&b, rand()%10);
    }

    printf("\n Pila a recien cargada ");
    mostrar(&a);

    printf("\n Pila b reci%cn cargada ", 130);
    mostrar(&b);

    while(!pilavacia(&a) && !pilavacia(&b)){
        apilar(&auxA, desapilar(&a));
        apilar(&auxB, desapilar(&b));
    }

    if(pilavacia(&a) && pilavacia(&b)){
        printf("\n Las dos pilas tienen la misma cantidad de elementos");
    }else{
        if(!pilavacia(&a)){
            printf("\n La pila a tiene mas elementos que la pila b");
        }else{
            printf("\n La pila b tiene mas elementos que la pila a");
        }
    }

    while(!pilavacia(&auxA)){
        apilar(&a, desapilar(&auxA));
    }

    while(!pilavacia(&auxB)){
        apilar(&b, desapilar(&auxB));
    }

    printf("\n Pila a al final ");
    mostrar(&a);

    printf("\n Pila b al final");
    mostrar(&b);

    printf("Hello world!\n");
    return 0;
}
