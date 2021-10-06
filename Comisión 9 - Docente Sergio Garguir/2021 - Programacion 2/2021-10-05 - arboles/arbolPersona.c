#include <stdio.h>
#include <stdlib.h>
#include "arbolPersona.h"


nodoArbolPersona* inicArbolPersona(){
    return NULL;
}

nodoArbolPersona* crearNodoArbolPersona(stPersona dato){
    nodoArbolPersona* nuevo = (nodoArbolPersona*)malloc(sizeof(nodoArbolPersona));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

nodoArbolPersona* agregarArbolPersona(nodoArbolPersona* arbol, nodoArbolPersona* nuevo){
    if(arbol==NULL){
        arbol = nuevo;
    }else{
        if(nuevo->dato.legajo < arbol->dato.legajo){
            arbol->izq = agregarArbolPersona(arbol->izq, nuevo);
        }else{
            arbol->der = agregarArbolPersona(arbol->der, nuevo);
        }
    }

    return arbol;
}

nodoArbolPersona* agregarArbolPersonaSinRepetidos(nodoArbolPersona* arbol, nodoArbolPersona* nuevo){
    if(arbol==NULL){
        arbol = nuevo;
    }else{
        if(nuevo->dato.legajo < arbol->dato.legajo){
            arbol->izq = agregarArbolPersonaSinRepetidos(arbol->izq, nuevo);
        }else{
            if(nuevo->dato.legajo > arbol->dato.legajo){
                arbol->der = agregarArbolPersonaSinRepetidos(arbol->der, nuevo);
            }
        }
    }

    return arbol;
}

void preOrdenPersona(nodoArbolPersona* arbol){
    if(arbol){
        muestraNodoArbolPersona(arbol);
        preOrdenPersona(arbol->izq);
        preOrdenPersona(arbol->der);
    }
}

void enOrdenPersona(nodoArbolPersona* arbol){
    if(arbol){
        enOrdenPersona(arbol->izq);
        muestraNodoArbolPersona(arbol);
        enOrdenPersona(arbol->der);
    }
}

void postOrdenPersona(nodoArbolPersona* arbol){
    if(arbol){
        postOrdenPersona(arbol->izq);
        postOrdenPersona(arbol->der);
        muestraNodoArbolPersona(arbol);
    }
}

void muestraNodoArbolPersona(nodoArbolPersona* nodo){
    muestraUnaPersona(nodo->dato);
}

nodoArbolPersona* buscaNodoArbolPersona(nodoArbolPersona* arbol, int legajo){
    nodoArbolPersona* respuesta = NULL;
    if(arbol){
        if(arbol->dato.legajo == legajo){
            respuesta = arbol;
        }else{
            if(legajo < arbol->dato.legajo){
                respuesta = buscaNodoArbolPersona(arbol->izq, legajo);
            }else{
                respuesta = buscaNodoArbolPersona(arbol->der, legajo);
            }
        }
    }

    return respuesta;
}

nodoArbolPersona* buscaNodoArbolPersonaPorNombre(nodoArbolPersona* arbol, char nombre[]){
    nodoArbolPersona* respuesta = NULL;
    if(arbol){
        if(strcmp(nombre, arbol->dato.nombre)==0){
            respuesta = arbol;
        }else{
            respuesta = buscaNodoArbolPersonaPorNombre(arbol->izq, nombre);
            if(respuesta == NULL){
                respuesta = buscaNodoArbolPersonaPorNombre(arbol->der, nombre);
            }
        }
    }

    return respuesta;
}
