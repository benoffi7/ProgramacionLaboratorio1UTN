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

    /// resuelto unicamente con secuencia y sin validar contenido de la pila
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

    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));
    apilar(&aux1, desapilar(&dada));


    apilar(&aux2, desapilar(&dada));
    apilar(&aux2, desapilar(&dada));

    printf("dada");
    mostrar(&dada);
    printf("aux1");
    mostrar(&aux1);
    printf("aux2");
    mostrar(&aux2);


    return 0;
}
