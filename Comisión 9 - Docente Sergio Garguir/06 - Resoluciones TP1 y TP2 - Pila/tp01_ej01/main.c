/**
1. Cargar desde el teclado una pila DADA con 5 elementos.
Pasar los tres primeros elementos a la pila AUX1 y los dos restantes a la pila AUX2, ambas pilas inicializadas en vacío.
*/
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    int i;
    Pila dada,aux1,aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    /// Cargo 5 datos en DADA por teclado
    for(i=0;i<5;i++){
        leer(&dada);
        system("cls");
    }
    /// Muestro el contenido de la pila DADA
    printf("\n\n Pila dada .........");
    mostrar(&dada);

    i=0; /// inicializo el contador porque sino no entra al while
    while((!pilavacia(&dada))&&(i<3)){
        apilar(&aux1,desapilar(&dada));  /// paso a AUX1 los 3 primeros elementos de DADA
        i++;
    }

    i=0;
    while((!pilavacia(&dada))&&(i<2)){
        apilar(&aux2,desapilar(&dada)); /// paso a AUX2 los 2 elementos siguientes de DADA
        i++;
    }

    printf("\n\n Pila dada .........");
    mostrar(&dada);

    printf("\n\n Pila aux1 .........");
    mostrar(&aux1);

    printf("\n\n Pila aux2 .........");
    mostrar(&aux2);

    return 0;
}
