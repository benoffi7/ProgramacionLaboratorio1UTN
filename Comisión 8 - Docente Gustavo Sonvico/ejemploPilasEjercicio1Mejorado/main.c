#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    /*
    Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres primeros
    elementos a la pila AUX1 y los dos restantes a la pila AUX2, ambas pilas
    inicializadas en vacío.
    */
    printf("Hello world pilas!\n");

    Pila dada, aux1, aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    char control;
    int i=0;

/// bucle de carga de la pila
    do
    {
        leer(&dada);

        printf("Desea continuar? s/n ");

        fflush(stdin);
        scanf("%c", &control);

    }
    while(control=='s');

    printf("dada");
    mostrar(&dada);

    i=0;
    /// paso 3 elementos de dada a aux1
    while(!pilavacia(&dada) && i < 3 )
    {

        apilar(&aux1, desapilar(&dada));

        i++;

    }


    i=0;
    /// paso 2 elementos de dada a aux1
    while(!pilavacia(&dada) && i<2)
    {

        apilar(&aux2, desapilar(&dada));

        i++;

    }



    printf("dada");
    mostrar(&dada);
    printf("aux1");
    mostrar(&aux1);
    printf("aux2");
    mostrar(&aux2);




    return 0;
}
