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

#endif // LISTADOBLEEMPLEADOS_H_INCLUDED
