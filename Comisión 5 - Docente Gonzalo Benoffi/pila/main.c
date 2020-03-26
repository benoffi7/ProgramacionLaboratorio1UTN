#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    printf("Hello world!\n");

    Pila pilin,otraPila; //creacion de una pila
    Pila pilote; //creacion de otra pila

    int tope1;

    inicpila(&pilin);
    inicpila(&otraPila); //inicializo una pila. SI o SI
    inicpila(&pilote);

    apilar(&pilin,4);
    apilar(&pilin,5);
    apilar(&pilin,6);

    //(tope) 6-5-4 (base)

    leer(&pilin);
    leer(&pilin);
    leer(&pilin);


    mostrar(&pilin);

    tope1 = tope(&pilin);
    printf("el tope es %d\n",tope1); //NO elimina el valor
    if (tope1 == 5)
    {
        //
    }

    int numero = desapilar(&pilin);

    mostrar(&pilin);

    return 0;
}
