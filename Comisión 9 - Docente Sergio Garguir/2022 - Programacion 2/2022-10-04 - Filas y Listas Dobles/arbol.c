#include "arbol.h"

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(stPersona dato){
    nodoArbol* nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

nodoArbol* agregarNodoArbol(nodoArbol* arbol, stPersona dato){
    if(!arbol){
        arbol = crearNodoArbol(dato);
    }else{
        if(dato.id > arbol->dato.id){
            arbol->der = agregarNodoArbol(arbol->der, dato);
        }else{
            arbol->izq = agregarNodoArbol(arbol->izq, dato);
        }
    }

    return arbol;
}

nodoArbol* agregarNodoArbolSinRepetidos(nodoArbol* arbol, stPersona dato){
    if(!arbol){
        arbol = crearNodoArbol(dato);
    }else{
        if(dato.id > arbol->dato.id){
            arbol->der = agregarNodoArbol(arbol->der, dato);
        }else{
            if(dato.id < arbol->dato.id){
                arbol->izq = agregarNodoArbol(arbol->izq, dato);
            }
        }
    }

    return arbol;
}

void preOrden(nodoArbol* arbol){
    if(arbol){
        muestraUnaPersona(arbol->dato);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(nodoArbol* arbol){
    if(arbol){
        inOrden(arbol->izq);
        muestraUnaPersona(arbol->dato);
        inOrden(arbol->der);
    }
}

void postOrden(nodoArbol* arbol){
    if(arbol){
        postOrden(arbol->izq);
        postOrden(arbol->der);
        muestraUnaPersona(arbol->dato);
    }
}

nodoArbol* buscaNodoArbol(nodoArbol* arbol, int id){
    nodoArbol* buscado = NULL;
    if(arbol->dato.id == id){
        buscado = arbol;
    }else{
        if(id > arbol->dato.id){
            buscado = buscaNodoArbol(arbol->der, id);
        }else{
            buscado = buscaNodoArbol(arbol->izq, id);
        }
    }

    return buscado;
}
