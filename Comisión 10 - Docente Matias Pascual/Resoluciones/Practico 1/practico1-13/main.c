#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

int main()
{
    /*13.	Suponiendo la existencia de una pila LIMITE, pasar los elementos de
    la pila DADA que sean mayores o iguales que el tope de LIMITE a
    la pila MAYORES, y los elementos que sean menores a la pila MENORES.*/

    Pila limite, dada, mayores, menores;

    inicpila(&limite);
    inicpila(&dada);
    inicpila(&mayores);
    inicpila(&menores);

    apilar(&limite, 5);

    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);

    printf("\npila limite");
    mostrar(&limite);

    printf("\npila dada");
    mostrar(&dada);

    while(!pilavacia(&dada))
    {
        if(tope(&dada)>=tope(&limite))
            apilar(&mayores, desapilar(&dada));
        else
            apilar(&menores, desapilar(&dada));
    }

    printf("\npila limite");
    mostrar(&limite);

    printf("\npila mayores");
    mostrar(&mayores);

    printf("\npila menores");
    mostrar(&menores);

    return 0;
}
