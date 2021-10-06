#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(int dato){
    nodoArbol* nuevo = (nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

nodoArbol* agregarArbol(nodoArbol* arbol, nodoArbol* nuevo){
    if(arbol==NULL){
        arbol = nuevo;
    }else{
        if(nuevo->dato < arbol->dato){
            arbol->izq = agregarArbol(arbol->izq, nuevo);
        }else{
            arbol->der = agregarArbol(arbol->der, nuevo);
        }
    }

    return arbol;
}

nodoArbol* agregarArbolSinRepetidos(nodoArbol* arbol, nodoArbol* nuevo){
    if(arbol==NULL){
        arbol = nuevo;
    }else{
        if(nuevo->dato < arbol->dato){
            arbol->izq = agregarArbolSinRepetidos(arbol->izq, nuevo);
        }else{
            if(nuevo->dato > arbol->dato){
                arbol->der = agregarArbolSinRepetidos(arbol->der, nuevo);
            }
        }
    }

    return arbol;
}

void preOrden(nodoArbol* arbol){
    if(arbol){
        printf("%d - ", arbol->dato);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void enOrden(nodoArbol* arbol){
    if(arbol){
        enOrden(arbol->izq);
        printf("%d - ", arbol->dato);
        enOrden(arbol->der);
    }
}

void postOrden(nodoArbol* arbol){
    if(arbol){
        postOrden(arbol->izq);
        postOrden(arbol->der);
        printf("%d - ", arbol->dato);
    }
}

nodoArbol* buscaNodoArbol(nodoArbol* arbol, int dato){
    nodoArbol *respuesta = NULL;
    if(arbol == NULL){
        respuesta = NULL;
    }else{
        if(arbol->dato == dato){
            respuesta = arbol;
        }else{
            if(dato < arbol->dato){
                respuesta = buscaNodoArbol(arbol->izq, dato);
            }else{
                respuesta = buscaNodoArbol(arbol->der, dato);
            }
        }
    }

    return respuesta;
}
