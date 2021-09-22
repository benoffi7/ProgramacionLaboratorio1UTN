#ifndef LISTADOBLEEMPLEADOS_H_INCLUDED
#define LISTADOBLEEMPLEADOS_H_INCLUDED

#include "empleado.h"

typedef struct _nodoDoble{
    stEmpleado dato;
    struct _nodoDoble* anterior;
    struct _nodoDoble* siguiente;
}nodoDoble;

nodoDoble* inicListaDoble();
nodoDoble* crearNodoDoble(stEmpleado dato);
nodoDoble* agregarAlPrincipioDoble(nodoDoble* lista, nodoDoble* nuevo);
void muestraListaDoble(nodoDoble* lista);
void muestraUnNodoDoble(nodoDoble* nodo);
void muestraListaDobleDirecciones(nodoDoble* lista);
stEmpleado verPrimeroDoble(nodoDoble* lista);
stEmpleado verPrimeroDobleT(nodoDoble* lista);
nodoDoble* borrarPrimerNodoDoble(nodoDoble* lista);
nodoDoble* buscaUltimoDoble(nodoDoble* lista);
nodoDoble* agregarAlFinalDoble(nodoDoble* lista, nodoDoble* nuevo);

#endif // LISTADOBLEEMPLEADOS_H_INCLUDED
