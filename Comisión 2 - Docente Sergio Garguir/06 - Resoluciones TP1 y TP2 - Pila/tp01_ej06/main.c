/**
6. Pasar el primer elemento (tope) de la pila DADA a su última
posición (base), dejando los restantes elementos en el mismo orden.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila dada, tope, aux;
    inicpila(&dada);
    inicpila(&tope);
    inicpila(&aux);

    char opcion;

    /// Ciclo de carga de datos continúa mientras no presione la tecla ESC
    do{
        leer(&dada);

        printf("\n\n ESC para salir ........... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    /// FIN CICLO DE CARGA

    printf("\n\n Pila dada ....... ");
    mostrar(&dada);

    if(!pilavacia(&dada)){ /// trabajo solo si dada tiene elementos
        apilar(&tope, desapilar(&dada)); /// quito el tope de dada y lo paso a la pila tope

        while(!pilavacia(&dada)){
            apilar(&aux, desapilar(&dada)); /// paso resto del contenido de la pila dada a la pila aux
        }

        if(!pilavacia(&tope)){
            apilar(&dada, desapilar(&tope)); /// paso el dato almacenado en la pila tope a la pila dada
        }

        while(!pilavacia(&aux)){
            apilar(&dada, desapilar(&aux)); /// vuelvo a poner todos los datos de aux en dada
        }
    }

    printf("\n\n Pila dada ....... ");
    mostrar(&dada);


    return 0;
}
