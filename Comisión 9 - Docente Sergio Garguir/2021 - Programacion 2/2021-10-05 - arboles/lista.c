#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

nodoLista* inicLista(){
    return NULL;
}

nodoLista* crearNodoLista(int dato){
    nodoLista* nuevo = (nodoLista*)malloc(sizeof(nodoLista));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}

nodoLista* agregarAlPrincipio(nodoLista* lista, nodoLista* nuevo){
    nuevo->sig = lista;
    return nuevo;
}

void muestraLista(nodoLista* lista){
    nodoLista* aux = lista;
    while(aux){
        muestraNodo(aux);
        aux = aux->sig;
    }
}

void muestraNodo(nodoLista* nodo){
    printf("%d - ", nodo->dato);
}
