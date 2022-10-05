#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

typedef struct nodoDoble{
    stPersona dato;
    struct nodoDoble* anterior;
    struct nodoDoble* siguiente;
}nodoDoble;

nodoDoble* inicListaD();
nodoDoble* crearNodoD(stPersona dato);
nodoDoble* agregarAlPrincipioD(nodoDoble* listaDoble, nodoDoble* nuevo);
void muestraListaD(nodoDoble* listaDoble);
void muestraUnNodoD(nodoDoble* listaDoble);
stPersona verPrimeroD(nodoDoble* listaDoble);
nodoDoble* borrarPrimeroD(nodoDoble* listaDoble);
nodoDoble* buscarUltimoD(nodoDoble* listaDoble);
nodoDoble* agregarAlFinalD(nodoDoble* listaDoble, nodoDoble* nuevo);
#endif // LISTADOBLE_H_INCLUDED
