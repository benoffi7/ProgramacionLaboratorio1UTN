#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///6. Pasar el primer elemento (tope)
///de la pila DADA a su última posición (base), dejando los restantes elementos en el mismo orden.

int main()
{
    Pila DADA;
    Pila AUX;
    int numero;
    inicpila(&AUX);
    inicpila(&DADA);
    char seguir;
    do
    {
        leer(&DADA);
        printf("Desea seguir ingresando valores? s/n \n");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    while(seguir == 's');

    if (!pilavacia(&DADA))
    {
        numero = desapilar(&DADA);
    }
    while (!pilavacia(&DADA))
    {
        apilar(&AUX, desapilar(&DADA));
    }

    apilar(&DADA,numero);
    while (!pilavacia(&AUX))
    {
        apilar(&DADA,desapilar(&AUX));
    }



    return 0;
}
