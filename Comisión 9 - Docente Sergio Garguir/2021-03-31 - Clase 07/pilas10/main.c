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

    int flag=0;

    apilar(&a, 1);
    apilar(&a, 1);
    apilar(&a, 1);
    apilar(&a, 1);
    apilar(&b, 1);
    apilar(&b, 1);
    apilar(&b, 1);
    apilar(&b, 2);


    printf("\n Pila a recien cargada ");
    mostrar(&a);

    printf("\n Pila b reci%cn cargada ", 130);
    mostrar(&b);

    while(!pilavacia(&a) && !pilavacia(&b)&&flag==0){
        if(tope(&a)==tope(&b)){
            apilar(&auxA, desapilar(&a));
            apilar(&auxB, desapilar(&b));
        }else{
            flag=1;
        }
    }

    if(!pilavacia(&a) || !pilavacia(&b)){
        printf("\n Las dos pilas NO son iguales");
    }else{
        printf("\n Las dos pilas son iguales");
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
