#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

#define CANTIDAD_CARTAS 9
/**
8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.
*/

int main()
{
    srand(time(NULL));
    Pila mazo;
    Pila jug1;
    Pila jug2;

    inicpila(&mazo);
    inicpila(&jug1);
    inicpila(&jug2);

    for(int i=0;i<CANTIDAD_CARTAS;i++){
        apilar(&mazo, (rand()%13)+1);
    }

    printf("\n <<<<<<<< Mazo >>>>>>>>>");
    mostrar(&mazo);

    while(!pilavacia(&mazo)){
        apilar(&jug1, desapilar(&mazo));
        if(!pilavacia(&mazo)){
            apilar(&jug2, desapilar(&mazo));
        }
    }

    printf("\n <<<<<<<< Mazo >>>>>>>>>");
    mostrar(&mazo);

    printf("\n <<<<<<<< Jugador 1 >>>>>>>>>");
    mostrar(&jug1);

    printf("\n <<<<<<<< Jugador 2 >>>>>>>>>");
    mostrar(&jug2);

    while(!pilavacia(&jug1) && !pilavacia(&jug2)){
        apilar(&mazo, desapilar(&jug1));
        apilar(&mazo, desapilar(&jug2));
    }

    printf("\n <<<<<<<< Mazo >>>>>>>>>");
    mostrar(&mazo);

    printf("\n <<<<<<<< Jugador 1 >>>>>>>>>");
    mostrar(&jug1);

    printf("\n <<<<<<<< Jugador 2 >>>>>>>>>");
    mostrar(&jug2);


    return 0;
}
