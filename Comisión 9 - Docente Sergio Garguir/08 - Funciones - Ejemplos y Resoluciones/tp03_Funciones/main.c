#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

void cargaPila(Pila *p);
void pasaPila(Pila *origen, Pila *destino);
void copiaPila(Pila origen, Pila *destino);
void cargaPilaRandom(Pila *p, int cantidad, int minimo, int maximo);

int randomRango(int min, int max);

int main()
{
    Pila temperaturas, horas, aux;
    inicpila(&temperaturas);
    inicpila(&horas);
    inicpila(&aux);

    cargaPila(&temperaturas);
    printf("\n Pila temperaturas\n");
    mostrar(&temperaturas);

    cargaPila(&horas);
    printf("\n Pila horas\n");
    mostrar(&horas);

    copiaPila(temperaturas, &aux);
    printf("\n Pila temperaturas\n");
    mostrar(&temperaturas);
    printf("\n Pila aux\n");
    mostrar(&aux);

    return 0;
}


/// 1. Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el usuario.
void cargaPila(Pila *p){
    char opcion;
    int e;

    do{
        printf("\n Ingrese una temperatura: ");
        scanf("%d",&e);
        apilar(p,e);

        printf("\n\n ESC para salir .......");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);
}

int randomRango(int min, int max){
    return rand()%(max-min)+min;
}

void cargaPilaRandom(Pila *p, int cantidad, int minimo, int maximo){
    int i;
    for(i=0;i<cantidad;i++){
        apilar(p, randomRango(minimo, maximo);
    }
}

/// 2. Hacer una función que pase todos los elementos de una pila a otra.
void pasaPila(Pila *origen, Pila *destino){
    while(!pilavacia(origen)){
        apilar(destino, desapilar(origen));
    }
}

void pasaPilaEnOrden(Pila *origen, Pila *destino){
    Pila aux;
    inicpila(&aux);

    pasaPila(origen, &aux);
    pasaPila(&aux, destino);
}

/// Copiar los elementos de una pila en otra
void copiaPila(Pila origen, Pila *destino){
    Pila aux;
    inicpila(&aux);

    pasaPila(&origen, &aux);
    /**while(!pilavacia(&origen)){
        apilar(&aux, desapilar(&origen));
    }*/
    pasaPila(&aux, destino);
    /**while(!pilavacia(&aux)){
        apilar(destino, desapilar(&aux));
    }*/
}
