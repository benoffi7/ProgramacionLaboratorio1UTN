/**
4.	Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables, solo pilas)
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila dada, aux, menor;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&menor);

    char opcion;

    for(int i=0;i<20;i++){
        apilar(&dada, rand()%100);
    }

    do{
        printf("\n\n Cargando pila dada\n");
        leer(&dada);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    printf("\n\n Pila dada");
    mostrar(&dada);

    if(!pilavacia(&dada)){
        apilar(&menor, desapilar(&dada));

        while(!pilavacia(&dada)){
            if(tope(&dada)<tope(&menor)){
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&dada));
            }
            else{
                apilar(&aux, desapilar(&dada));
            }
        }

        while(!pilavacia(&aux)){
            apilar(&dada, desapilar(&aux));
        }

        printf("\n\n El menor elemento de la pila es %d", tope(&menor));
    }


    return 0;
}
