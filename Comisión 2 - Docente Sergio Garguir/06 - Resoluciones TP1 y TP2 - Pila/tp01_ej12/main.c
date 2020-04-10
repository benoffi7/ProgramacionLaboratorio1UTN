/**
12. Suponiendo la existencia de una pila MODELO (vacía o no), eliminar
de la pila DADA todos los elementos que existan en MODELO.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila modelo, dada, auxDada, basura, auxModelo;
    inicpila(&dada);
    inicpila(&modelo);
    inicpila(&auxDada);
    inicpila(&basura);
    inicpila(&auxModelo);

    char opcion;

    for(int i=0;i<40;i++){
        apilar(&modelo, rand()%10);
    }

    do{
        leer(&modelo);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
    }while(opcion!=ESC);

    for(int i=0;i<40;i++){
        apilar(&dada, rand()%10);
    }

    printf("\n\n Pila Modelo ....... ");
    mostrar(&modelo);

    printf("\n\n Pila Dada ....... ");
    mostrar(&dada);

    while(!pilavacia(&modelo)){
        while(!pilavacia(&dada)){
            if(tope(&modelo) == tope(&dada)){
                apilar(&basura, desapilar(&dada));
            }
            else{
                apilar(&auxDada, desapilar(&dada));
            }
        }

        while(!pilavacia(&auxDada)){
            apilar(&dada, desapilar(&auxDada));
        }
        apilar(&auxModelo, desapilar(&modelo));
    }

    while(!pilavacia(&auxModelo)){
        apilar(&modelo, desapilar(&auxModelo));
    }


    printf("\n\n Pila Modelo ....... ");
    mostrar(&modelo);

    printf("\n\n Pila Dada ....... ");
    mostrar(&dada);


    printf("Hello world!\n");
    return 0;
}

