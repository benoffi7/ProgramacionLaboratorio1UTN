#include <conio.h>
#include "pila.h"
#include "fPila.h"


/// 1. Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el usuario.
void cargaPila(Pila *p, char texto[]){
    char opcion;
    int e;

    do{
        printf("\n %s", texto);
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
        apilar(p, randomRango(minimo, maximo));
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

/// Buscar el menor elemento en una pila sin quitarlo y retornarlo
/// Corre por cuenta del programador verificar que la pila tenga datos antes de usar esta funcion
int buscaMenor(Pila p){
    Pila aux;
    inicpila(&aux);
    int menor;

    if(!pilavacia(&p)){
        menor = desapilar(&p);
        while(!pilavacia(&p)){
            if(tope(&p)<menor){
                menor = desapilar(&p);
            }
            else{
                apilar(&aux, desapilar(&p));
            }
        }
    }
    return menor;
}

/// Buscar el menor elemento en una pila eliminandolo y retornandolo
/// Corre por cuenta del programador verificar que la pila tenga datos antes de usar esta funcion
int buscaMenorEliminandolo(Pila *p){
    Pila aux;
    inicpila(&aux);
    int menor;

    if(!pilavacia(p)){
        menor = desapilar(p);
        while(!pilavacia(p)){
            if(tope(p)<menor){
                apilar(&aux, menor);
                menor = desapilar(p);
            }
            else{
                apilar(&aux, desapilar(p));
            }
        }
        pasaPila(&aux, p);
    }
    return menor;
}

/// Ordena una pila por seleccion
/*
void ordenaPorSeleccion(Pila origen, Pila *ordenada){
    while(!pilavacia(&origen)){
        apilar(ordenada, buscaMenorEliminandolo(&origen));
    }
}
*/
void ordenaPorSeleccion(Pila origen, Pila *ordenada){
    int menor;
    while(!pilavacia(&origen)){
        menor = buscaMenorEliminandolo(&origen);
        apilar(ordenada, menor);
    }
}

/// Inserta un elemento un una pila ordeana
void insertaElemento(Pila *p, int e){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p) && tope(p)>e){
        apilar(&aux, desapilar(p));
    }
    apilar(p, e);
    pasaPila(&aux, p);
}

/// Ordena por Insercion
void ordenaPorInsercion(Pila origen, Pila *ordenada){
    int e;
    while(!pilavacia(&origen)){
        e = desapilar(&origen);
        insertaElemento(ordenada, e);
        /// insertaElemento(ordenada, desapilar(&origen));
    }
}

/// Ordena por Insercion
void ordenaPorInsercion2(Pila *origen){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(origen)){
        insertaElemento(&aux, desapilar(origen));
        /// insertaElemento(ordenada, desapilar(&origen));
    }
    pasaPila(&aux, origen);
}
