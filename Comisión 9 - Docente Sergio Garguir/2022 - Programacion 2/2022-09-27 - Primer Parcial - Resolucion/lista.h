#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "persona.h"

typedef struct nodo{
    stPersona dato;
    struct nodo * siguiente;
}nodo;

nodo * iniciLista();
nodo * crearNodo(stPersona dato);
nodo * agregarAlPrincipio(nodo* lista, nodo* nuevo);
nodo* agregarEnOrdenPorEdad(nodo* lista, nodo* nuevo);
void agregarEnOrdenPorApellido(nodo** lista, nodo* nuevo);
void muestraLista(nodo* lista);
void muestraNodo(nodo* n);
nodo* buscarUltimo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
int sumaEdades(nodo* lista);
int sumaEdadesRecursiva(nodo* lista);
int sumaEdadesRecursivaTernario(nodo* lista);
nodo* buscaMenorEdad(nodo* lista);
int cuentaNodosRecursivo(nodo* lista, int edad);

#endif // LISTA_H_INCLUDED
