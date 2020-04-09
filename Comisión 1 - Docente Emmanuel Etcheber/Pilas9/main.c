#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
int main()
{
    Pila A, B, AUX;
    char carga='s';

    inicpila(&A);
    inicpila(&B);
    inicpila(&AUX);

    while (carga=='s')
    {
        printf("\n");
        leer(&A);
        printf("Para continuar cargando presione S ");
        fflush(stdin);
        scanf("%c",&carga);
    }
    carga='s';
    while (carga=='s')
    {
        printf("\n");
        leer(&B);
        printf("Para continuar cargando presione S ");
        fflush(stdin);
        scanf("%c",&carga);
    }

    while (!pilavacia(&A) && !pilavacia(&B))
    {
        apilar(&AUX,desapilar(&A));
        apilar(&AUX,desapilar(&B));
    }

    if (!pilavacia(&B))
    {
        printf("La pila A tiene menos elementos que la pila B");
    }
    else
    {
        if (!pilavacia(&A))
            printf("La pila B tiene menos elementos que la pila A");
        else
            printf("Ambas pilas tienen la misma cantidad de elementos");
    }

    return 0;
}
