/**
1.	Sumar los elementos de una pila (usar variables)
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
    int total = 0;

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
        total = total + tope(&dada);
        apilar(&aux, desapilar(&dada));
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }


    printf("\n\n La suma total de los datos de la pila dada es: %d", total);
    return 0;
}
