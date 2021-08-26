#include "stdio.h"
#include "stdlib.h"
#include "listaEmpleados.h"

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stEmpleado dato){
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo){
    nuevoNodo->siguiente = lista;
    return nuevoNodo;
}

void mostrarLista(nodo* lista){
    nodo* seg = lista;
    while(seg!=NULL){
        muestraUnEmpleado(seg->dato);
        seg = seg->siguiente;
    }
}
