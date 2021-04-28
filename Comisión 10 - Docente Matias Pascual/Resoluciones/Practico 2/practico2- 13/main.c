#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila mazo, jugador1, jugador2, puntosjug1, puntosjug2, aux;
    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);
    inicpila(&puntosjug1);
    inicpila(&puntosjug2);
    inicpila(&aux);

    printf("Ingrese las cartas\n");
    leer(&mazo);
    leer(&mazo);
    leer(&mazo);
    leer(&mazo);
    leer(&mazo);
    leer(&mazo);
    leer(&mazo);
    leer(&mazo);

    printf("Pila mazo");
    mostrar(&mazo);

    while(!pilavacia(&mazo))
    {
        apilar(&jugador1, desapilar(&mazo));
        apilar(&jugador1, desapilar(&mazo));

        apilar(&jugador2, desapilar(&mazo));
        apilar(&jugador2, desapilar(&mazo));
    }

    int puntosJugador1=0;
    int puntosJugador2=0;

    while(!pilavacia(&jugador1)&&!pilavacia(&jugador2))
    {
        puntosJugador1 += tope(&jugador1);
        puntosJugador2 += tope(&jugador2);

        apilar(&aux, desapilar(&jugador1));
        apilar(&aux, desapilar(&jugador2));
    }

    if (puntosJugador1>=puntosJugador2)
    {
        while(!pilavacia(&aux))
        {
            apilar(&puntosjug1, desapilar(&aux));
        }
    }
    else
    {
        while(!pilavacia(&aux))
        {
            apilar(&puntosjug2, desapilar(&aux));
        }
    }

    printf("Pila puntos jugador 1: %d", puntosJugador1);
    mostrar(&puntosjug1);

    printf("Pila puntos jugador 2: %d", puntosJugador2);
    mostrar(&puntosjug2);


    return 0;
}
