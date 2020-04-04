/**
14. Determinar si la cantidad de elementos de la pila DADA es par.
Si es par, pasar el elemento del tope de la pila AUX a la pila
PAR y si es impar pasar el tope a la pila IMPAR.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    srand(time(NULL));
    Pila dada, aux, par, impar;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&par);
    inicpila(&impar);

    char opcion;

    /// Cargamos la pila dada

    for(int i=0;i<15;i++){
        apilar(&dada, rand()%10);
    }

    do{
        printf("\n\n Cargando pila dada ....... \n");
        leer(&dada);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    printf("\n\n Pila dada ....... ");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        apilar(&aux, desapilar(&dada));
        if(!pilavacia(&dada)){
            apilar(&aux, desapilar(&dada));
        }
        else{
            apilar(&impar, desapilar(&aux));
        }
    }

    /// si pila impar no esta vacia significa que la pila dada tenia cantidad de datos impares

    if(!pilavacia(&impar)){
        printf("\n\n La pila dada tiene cantidad de datos impares");
    }
    else{
        apilar(&par, desapilar(&aux));
        printf("\n\n La pila dada tiene cantidad de datos pares");
    }

    /// regreso los datos a dada

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }

    return 0;
}
