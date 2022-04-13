#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


void imprimeEntero(int x);

int main()
{
    int nroA = 15;
    int nroB = 20;

    intercambioPorValor(nroA, nroB);
    system("pause");
    printf("\n En la funcion MAIN - a: %d - b:%d \n", nroA, nroB);
    intercambioPorReferencia(&nroA, &nroB);
    system("pause");
    printf("\n En la funcion MAIN - a: %d - b:%d \n", nroA, nroB);
    return 0;
}

void imprimeEntero(int x){
    x = x - 2;
    printf("\n %d \n", x);
}

void intercambioPorValor(int a, int b){
    int aux = a;
    a = b;
    b = aux;
    system("pause");
    printf("\n En la funcion intercambio - a: %d - b:%d\n", a, b);
}

void intercambioPorReferencia(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
    printf("\n En la funcion intercambio - a: %p - b:%p\n", a, b);
}
