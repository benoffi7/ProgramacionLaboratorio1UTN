#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

void cargaPila(Pila *p);
void pasaPila(Pila *origen, Pila *destino);


int main()
{
    Pila dada, otra, auxDada;
    inicpila(&dada);
    inicpila(&otra);
    inicpila(&auxDada);

    cargaPila(&dada);

    printf("\n\n Mostrando pila dada ");
    mostrar(&dada);
    system("pause");

    pasaPila(&dada,&auxDada);
    printf("\n\n Mostrando pila dada ");
    mostrar(&dada);
    printf("\n\n Mostrando pila auxDada ");
    mostrar(&auxDada);
    system("pause");

    copiaPila(auxDada, &dada);
    printf("\n\n Mostrando pila dada ");
    mostrar(&dada);
    printf("\n\n Mostrando pila auxDada ");
    mostrar(&auxDada);

    cargaPila(&otra);

    printf("\n\n Mostrando pila otra ");
    mostrar(&otra);

    printf("Hello world!\n");
    return 0;
}


void cargaPila(Pila *p){
    char opcion;

    do{
        printf("\n Cargando pila ....... \n");
        leer(p);

        printf("\n\n ESC para salir ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);
}

void pasaPila(Pila *origen, Pila *destino){
    while(!pilavacia(origen)){
        apilar(destino, desapilar(origen));
    }
}

void copiaPila(Pila origen, Pila *destino){
    Pila aux;
    inicpila(&aux);
    pasaPila(&origen, &aux);                /// paso la pila usando la funcion

    /*while(!pilavacia(&origen)){           /// paso la pila usando un while
        apilar(&aux, desapilar(&origen));
    }*/

    pasaPila(&aux, destino);
    /*while(!pilavacia(&aux)){
        apilar(destino, desapilar(&aux));
    }*/
}
