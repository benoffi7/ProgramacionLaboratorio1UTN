/**
2.	Contar los elementos de una pila (usar variables)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "pila.h"

#define ESC 27


int main()
{
    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);
    int cont = 0;

    char opcion;

    do{
        printf("\n\n Cargando Pila Dada\n");
        leer(&dada);

        printf("\n\n\t ESC para salir...");
        opcion=getch();
    }while(opcion!=ESC);

    printf("\n\n Pila Dada");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        apilar(&aux, desapilar(&dada));
        cont++;
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }


    printf("\n\n La cantidad de elementos de la pila dada es: %d", cont);
    return 0;
}
