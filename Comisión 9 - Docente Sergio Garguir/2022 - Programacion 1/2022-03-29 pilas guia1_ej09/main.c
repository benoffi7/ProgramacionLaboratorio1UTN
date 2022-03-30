#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main()
{
    Pila a;
    Pila b;
    Pila auxA;
    Pila auxB;

    inicpila(&a);
    inicpila(&b);
    inicpila(&auxA);
    inicpila(&auxB);

    for(int i=0;i<0;i++){
        apilar(&a, rand()%15);
    }

    for(int i=0;i<3;i++){
        apilar(&b, rand()%15);
    }

    printf("\n<<<<<<<<<<<< Pila a >>>>>>>>>>>>>");
    mostrar(&a);
    printf("\n<<<<<<<<<<<< Pila b >>>>>>>>>>>>>");
    mostrar(&b);

    while(!pilavacia(&a) && !pilavacia(&b)){
        apilar(&auxA, desapilar(&a));
        apilar(&auxB, desapilar(&b));
    }

    if(pilavacia(&a) && pilavacia(&b)){
        printf("Las dos pilas tienen la misma cantidad de elementos");
    }else if(!pilavacia(&a)){
        printf("La pila a tiene mas elementos que la pila b");
    }else{
        printf("La pila b tiene mas elementos que la pila a");
    }

    printf("\n Hello world!\n");
    return 0;


}
