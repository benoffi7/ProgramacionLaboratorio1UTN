#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct _nodoArbol{
    int dato;
    struct _nodoArbol* izq;
    struct _nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(int dato);
nodoArbol* agregarArbol(nodoArbol* arbol, nodoArbol* nuevo);
nodoArbol* agregarArbolSinRepetidos(nodoArbol* arbol, nodoArbol* nuevo);
void preOrden(nodoArbol* arbol);
void enOrden(nodoArbol* arbol);
void postOrden(nodoArbol* arbol);

#endif // ARBOL_H_INCLUDED
