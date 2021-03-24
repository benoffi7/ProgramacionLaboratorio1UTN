/**
    Cargar desde el teclado una pila DADA con 5 elementos.

    Pasar los tres primeros elementos a la pila AUX1

    y los dos restantes a la pila AUX2,

    ambas inicialidadas en vacio.

*/

#include "Librerias/pila.h"

void ejercicio1()
{
    printf("ejercicio 1 de la guia de pilas \n\n");

    /// Cargar desde el teclado una pila DADA con 5 elementos
    Pila dada;
    inicpila(&dada);

    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);

    /// Pasar los tres primeros elementos a la pila AUX1
    Pila aux1;
    inicpila(&aux1);

    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));


    /// y los dos restantes a la pila AUX2
    Pila aux2;
    inicpila(&aux2);

    apilar(&aux2, desapilar(&dada));
    apilar(&aux2, desapilar(&dada));

    printf("fin del ejercicio 1 de la guia de pilas \n\n");
}
