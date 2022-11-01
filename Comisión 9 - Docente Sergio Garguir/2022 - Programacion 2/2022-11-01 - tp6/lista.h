#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "notaAlumno.h"

typedef struct nodoDoble{
    stNotaAlumno dato;
    struct nodoDoble* anterior;
    struct nodoDoble* siguiente;
}nodoDoble;

nodoDoble* inicListaD();
nodoDoble* crearNodoD(stNotaAlumno dato);
nodoDoble* agregarAlPrincipioD(nodoDoble* listaDoble, nodoDoble* nuevo);
void muestraListaD(nodoDoble* listaDoble);
void muestraUnNodoD(nodoDoble* listaDoble);
stNotaAlumno verPrimeroD(nodoDoble* listaDoble);
nodoDoble* borrarPrimeroD(nodoDoble* listaDoble);
nodoDoble* buscarUltimoD(nodoDoble* listaDoble);
nodoDoble* agregarAlFinalD(nodoDoble* listaDoble, nodoDoble* nuevo);
int cuentaNotasMayoresDoble(nodoDoble* lista, int nota);

#endif // LISTA_H_INCLUDED
