#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

nodo * iniciLista(){
    return NULL;
}

nodo * crearNodo(stPersona dato){
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo * agregarAlPpio(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista=nuevo;
    }else{
        nuevo->siguiente=lista;
        lista = nuevo;
    }
    return lista;
}

nodo * agregarAlPrincipioPro(nodo* lista, nodo* nuevo){
    nuevo->siguiente = lista;
    return nuevo;
}

void muestraLista(nodo* lista){
    nodo* seg = lista;
    while(seg!=NULL){
        muestraNodo(seg);
        seg=seg->siguiente;
    }
}

void muestraNodo(nodo* n){
    printf("\n Nodo: %p", n);
    muestraUnaPersona(n->dato);
    printf("\n Nodo->sig: %p", n->siguiente);
}


