#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

/* 3.	Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS
 todos aquellos elementos distintos al valor 8*/


int main()
{
    Pila dada, distintos, descarte;
    inicpila(&dada);
    inicpila(&distintos);
    inicpila(&descarte);

    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);

    while(!pilavacia(&dada))
    {
        if (tope(&dada)!=8)
        {
            apilar(&distintos, desapilar(&dada));
        }
        else
        {
            apilar(&descarte, desapilar(&dada));
        }
    }

    printf("Pila distintos\n");
    mostrar(&distintos);
    printf("Pila descarte\n");
    mostrar((&descarte));


    return 0;
}
