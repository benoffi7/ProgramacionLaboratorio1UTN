#ifndef ARBOLPERSONA_H_INCLUDED
#define ARBOLPERSONA_H_INCLUDED

#include "persona.h"

typedef struct _nodoArbolPersona{
    stPersona dato;
    struct _nodoArbolPersona* izq;
    struct _nodoArbolPersona* der;
}nodoArbolPersona;

nodoArbolPersona* inicArbolPersona();
nodoArbolPersona* crearNodoArbolPersona(stPersona dato);
nodoArbolPersona* agregarArbolPersona(nodoArbolPersona* arbol, nodoArbolPersona* nuevo);
nodoArbolPersona* agregarArbolPersonaSinRepetidos(nodoArbolPersona* arbol, nodoArbolPersona* nuevo);
void preOrdenPersona(nodoArbolPersona* arbol);
void enOrdenPersona(nodoArbolPersona* arbol);
void postOrdenPersona(nodoArbolPersona* arbol);

#endif // ARBOLPERSONA_H_INCLUDED
