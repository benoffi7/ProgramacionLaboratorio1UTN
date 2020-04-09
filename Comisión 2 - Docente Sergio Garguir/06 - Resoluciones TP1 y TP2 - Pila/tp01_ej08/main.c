/**
8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.
*/


#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila MAZO, J1, J2;
    inicpila(&MAZO);
    inicpila(&J1);
    inicpila(&J2);

    int limite = rand()%48+1;

    for(int i=0;i<limite;i++){
        apilar(&MAZO,rand()%50);
    }

    printf("\n Pila MAZO ..........");
    mostrar(&MAZO);

    while(!pilavacia(&MAZO)){  /// reparto los elementos de MAZO a J1 y J2 en el mismo ciclo
        apilar(&J1, desapilar(&MAZO));
        if(!pilavacia(&MAZO)){        /// compruebo que MAZO tenga elementos antes de desapilar por segunda vez
            apilar(&J2, desapilar(&MAZO));
        }
    }

    printf("\n Pila MAZO ..........");
    mostrar(&MAZO);

    printf("\n Pila J1 ............");
    mostrar(&J1);

    printf("\n Pila J2 ............");
    mostrar(&J2);

    printf("Hello world!\n");
    return 0;
}
