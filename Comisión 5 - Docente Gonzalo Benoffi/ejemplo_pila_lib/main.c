#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    printf("Hello world!\n");
    Pila pilita;
    Pila pilon;
    Pila otraPila;

    inicpila(&pilita);
    inicpila(&pilon);
    inicpila(&otraPila);

    apilar(&pilita,4);
    apilar(&pilita,5);
    apilar(&pilita,6);

    int topeDeUnaPila = desapilar(&pilita);

    if (topeDeUnaPila == 5)
    {

    }

    apilar(&pilon,topeDeUnaPila);

/*

    leer(&pilita);
    leer(&pilita);
    leer(&pilita);
    */

     mostrar(&pilita);
     mostrar(&pilon);

    return 0;
}
