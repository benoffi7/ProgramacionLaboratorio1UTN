#include <stdio.h>
#include <stdlib.h>

#include "listaDobleEmpleados.h"

nodoDoble* inicListaDoble(){
    return NULL;
}

nodoDoble* crearNodoDoble(stEmpleado dato){
    nodoDoble* nuevo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodoDoble* agregarAlPrincipioDoble(nodoDoble* lista, nodoDoble* nuevo){
    nuevo->siguiente = lista;
    if(lista){
        lista->anterior = nuevo;
    }

    return nuevo;
}

void muestraListaDoble(nodoDoble* lista){
    nodoDoble* copia = lista;
    while(copia){
        muestraUnNodoDoble(copia);
        copia = copia->siguiente;
    }
}

void muestraUnNodoDoble(nodoDoble* nodo){
    muestraUnEmpleado(nodo->dato);
}

void muestraListaDobleDirecciones(nodoDoble* lista){
    nodoDoble* copia = lista;
    while(copia){
        printf("\n<-- ante: %p - actual: %p - sig: %p -->", copia->anterior, copia, copia->siguiente);
        copia = copia->siguiente;
    }
}

