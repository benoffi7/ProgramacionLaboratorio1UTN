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
int cuentaNodosPorEdad(nodo* lista, int edad);
int cuentaNodosPorEdadRec(nodo* lista, int edad);
int cuentaNodosRec(nodo* lista);
int cuentaNodosRecTernario(nodo* lista);
int sumaNodosPorEdad(nodo* lista, int edad);
int sumaNodosPorEdadRec(nodo* lista, int edad);
int sumaNodosPorEdadRecTern(nodo* lista, int edad);
void muestraListaRec(nodo* lista);
stPersona verPrimero(nodo* lista);
stPersona verPrimero1(nodo* lista);
nodo* borrarPrimero(nodo* lista);
nodo* buscaNodoPorNombre(nodo* lista, char nombre[]);
nodo* borrarNodoPorNombre(nodo* lista, char nombre[]);
nodo* invertirLista(nodo* lista);
#endif // LISTA_H_INCLUDED
