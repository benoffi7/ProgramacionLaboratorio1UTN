#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    printf("Hello world!\n");
    Pila pilin;
    Pila destino;
    Pila otraPila;

    inicpila(&pilin);
    inicpila(&destino);
    inicpila(&otraPila);

    apilar(&pilin,4);
    apilar(&pilin,5);
    apilar(&pilin,6);

    mostrar(&pilin);

    apilar(&destino,desapilar(&pilin));

    int desapile = desapilar(&pilin);

    apilar(&destino,desapile);

    desapile = desapilar(&pilin);

    apilar(&destino,desapile);

    mostrar(&destino);

    if (pilavacia(&pilin)) //verdadero si esta VACIA (NO tiene datos)
    {
            printf("esta vacia pilin\n");
           // int otro = desapilar(&pilin); NO SE PUEDE HACER
          //  printf("%d",otro);
    }
    else //Lo falso es bueno por tiene elementos
    {
        printf("NO esta vacia pilin\n");
    }


    if (!pilavacia(&destino))
    {
        printf("NO esta vacia destino\n");
    }

    while (!pilavacia(&destino))
    {
        desapile = desapilar(&destino);
        apilar(&pilin,desapile);
         mostrar(&pilin);
    }

    mostrar(&pilin);


    return 0;
}
