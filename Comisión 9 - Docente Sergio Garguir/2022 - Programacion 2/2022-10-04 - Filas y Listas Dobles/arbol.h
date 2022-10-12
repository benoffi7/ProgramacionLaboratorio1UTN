#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

typedef struct _nodoArbol{
    stPersona dato;
    struct _nodoArbol* izq;
    struct _nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stPersona dato);
nodoArbol* agregarNodoArbol(nodoArbol* arbol, stPersona dato);
nodoArbol* agregarNodoArbolSinRepetidos(nodoArbol* arbol, stPersona dato);
void preOrden(nodoArbol* arbol);
void inOrden(nodoArbol* arbol);
void postOrden(nodoArbol* arbol);
nodoArbol* buscaNodoArbol(nodoArbol* arbol, int id);

#endif // ARBOL_H_INCLUDED
