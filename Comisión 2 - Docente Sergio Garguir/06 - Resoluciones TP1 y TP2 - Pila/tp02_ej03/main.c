/**
3.	Calcular el promedio de los datos de la pila dada (usar variables)
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
    int total = 0;
    float promedio;

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
        cont++;
    }

    promedio = (float) total / cont;

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }


    printf("\n\n La cantidad de elementos de la pila dada es: %d el total es: %d y el promedio es: %.2f", cont, total, promedio);
    return 0;
}
