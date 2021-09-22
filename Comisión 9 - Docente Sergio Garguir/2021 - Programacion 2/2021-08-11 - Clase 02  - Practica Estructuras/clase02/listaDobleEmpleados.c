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

stEmpleado verPrimeroDoble(nodoDoble* lista){
    stEmpleado rta;
    if(lista){
        rta=lista->dato;
    }
    return rta;
}

stEmpleado verPrimeroDobleT(nodoDoble* lista){
    stEmpleado e;
    return (lista)?lista->dato:e;
}

nodoDoble* borrarPrimerNodoDoble(nodoDoble* lista){
    if(lista){
        nodoDoble* aux=lista;
        lista = lista->siguiente;
        if(lista){
            lista->anterior=NULL;
        }
        free(aux);
    }
    return lista;
}

nodoDoble* buscaUltimoDoble(nodoDoble* lista){
    nodoDoble* seg = lista;
    if(seg){
        while(seg->siguiente!=NULL){
            seg=seg->siguiente;
        }
    }
    return seg;
}

nodoDoble* agregarAlFinalDoble(nodoDoble* lista, nodoDoble* nuevo){
    if(lista == NULL){
        lista = nuevo;
    }else{
        nodoDoble* ultimo = buscaUltimoDoble(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }

    return lista;
}
