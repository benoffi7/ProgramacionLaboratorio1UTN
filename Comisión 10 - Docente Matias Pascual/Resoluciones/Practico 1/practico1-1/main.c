#include <stdio.h>
#include <stdlib.h>

/*
1.Cargar desde el teclado una pila DADA con 5 elementos.
Pasar los tres primeros elementos a la pila aux1 y los dos restantes a la pila aux2,
ambas pilas inicializadas en vacío.
*/

#include "pila.h"

int main()
{
    Pila dada;
    Pila aux1;
    Pila aux2;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    apilar(&dada, 20);
    apilar(&dada, 30);
    apilar(&dada, 17);
    apilar(&dada, 2);
    apilar(&dada, 67);


    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));
    apilar(&aux2, desapilar(&dada));
    apilar(&aux2, desapilar(&dada));

    printf("Pila aux1\n");
    mostrar(&aux1);
    printf("Pila aux2\n");
    mostrar(&aux2);
}
