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

nodo* buscarUltimo(nodo* lista){
    nodo* seg = lista;
    while(seg->siguiente != NULL){
        seg = seg->siguiente;
    }
    return seg;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        nodo* ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}

nodo* agregarEnOrdenPorEdad(nodo* lista, nodo* nuevo){
    /// Si la lista esta vacia le asigno el nuevo nodo
    if(!lista){
        lista = nuevo;
    }else{
        /// si el nuevo nodo es menor al primero de la lista, agrego a principio
        if(nuevo->dato.edad <= lista->dato.edad){
            lista = agregarAlPpio(lista, nuevo);
        }else{
            /// buscamos el lugar donde insertar
            nodo* ante = lista;
            nodo* seg = lista;
            while(seg && (nuevo->dato.edad > seg->dato.edad)){
                ante = seg;
                seg = seg->siguiente;
            }
            /// insertar el nuevo nodo en la lista de manera ordenada
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}

nodo* intercalarListas(nodo* listaA, nodo* listaB, nodo* listaFinal){
    nodo* aux = NULL;
    while(listaA && listaB){ /// while(listaA != NULL && listaB != NULL)
        if(listaA->dato.edad < listaB->dato.edad){
            aux = listaA;
            listaA = listaA->siguiente;
        }else{
            aux = listaB;
            listaB = listaB->siguiente;
        }
        aux->siguiente = NULL;
        listaFinal = agregarAlFinal(listaFinal, aux);
    }
    if(listaA){
        listaFinal = agregarAlFinal(listaFinal, listaA);
    }else if(listaB){
        listaFinal = agregarAlFinal(listaFinal, listaB);
    }

    return listaFinal;
}











