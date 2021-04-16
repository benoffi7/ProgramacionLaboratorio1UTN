#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

int main()
{
    /* 6.Pasar el primer elemento (tope) de la pila DADA a su última posición (base),
    dejando los restantes elementos en el mismo orden*/


    Pila dada, aux1, aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);

    mostrar(&dada);
    if (!pilavacia(&dada))
        apilar(&aux1, desapilar(&dada)); // aca tomo el primer elemento de dada y lo pongo en una pidla auxiliar

    while(!pilavacia(&dada))
    {
        apilar(&aux2, desapilar(&dada));
    }

    if(!pilavacia(&aux1))
        apilar(&dada, desapilar(&aux1));

    while(!pilavacia(&aux2))
    {
        apilar(&dada, desapilar(&aux2));
    }

    mostrar(&dada);
    return 0;
}
