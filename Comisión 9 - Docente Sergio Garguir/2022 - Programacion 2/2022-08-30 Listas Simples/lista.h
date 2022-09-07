#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "persona.h"

typedef struct nodo{
    stPersona dato;
    struct nodo * siguiente;
}nodo;


nodo * iniciLista();
nodo * crearNodo(stPersona dato);
nodo * agregarAlPpio(nodo* lista, nodo* nuevo);
void muestraLista(nodo* lista);
void muestraNodo(nodo* n);
nodo * agregarAlPrincipioPro(nodo* lista, nodo* nuevo);
nodo* buscarUltimo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
nodo* agregarEnOrdenPorEdad(nodo* lista, nodo* nuevo);

#endif // LISTA_H_INCLUDED
