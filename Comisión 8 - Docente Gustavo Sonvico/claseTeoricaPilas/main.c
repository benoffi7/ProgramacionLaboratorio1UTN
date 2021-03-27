#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{

    printf("Hello pilas!\n");

//    int unNumero;
//    unNumero=0;

    Pila pilita, pilota;
    inicpila(&pilita);
    inicpila(&pilota);

//    unNumero=0;
//
//    /// es similar a la asignacion por = de una variable
//    apilar(&pilita, 1);
//    apilar(&pilita, 2);
//    apilar(&pilita, 3);
//    apilar(&pilita, 4);
//    apilar(&pilita, 5);
//    apilar(&pilita, 6);
//    apilar(&pilita, 7);
//    apilar(&pilita, 8);
//
//    printf("Ingrese un valor a la variable: ");
//    scanf("%d", &unNumero);
//
//    /// es similar a realizar un scanf en una variable
//    leer(&pilita);
//    leer(&pilita);
//    leer(&pilita);
//    leer(&pilita);
//    leer(&pilita);
//    leer(&pilita);
//    leer(&pilita);
//    leer(&pilita);



    int i=0, aux;

    for(i=0;i<5;i++)
    {
        leer(&pilita);
    }

    printf("Contenido de pilita\n");
    mostrar(&pilita);

    printf("Contenido de pilota\n");
    mostrar(&pilota);

    while(!pilavacia(&pilita))
    {
        aux=desapilar(&pilita);

        apilar(&pilota, aux);
    }

    printf("Contenido de pilita\n");
    mostrar(&pilita);

    printf("Contenido de pilota\n");
    mostrar(&pilota);



    return 0;
}
