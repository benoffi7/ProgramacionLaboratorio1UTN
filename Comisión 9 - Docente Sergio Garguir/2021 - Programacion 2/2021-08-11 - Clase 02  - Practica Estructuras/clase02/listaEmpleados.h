#ifndef LISTAEMPLEADOS_H_INCLUDED
#define LISTAEMPLEADOS_H_INCLUDED

#include "empleado.h"

typedef struct{
    stEmpleado dato;
    struct nodo *siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stEmpleado e);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);

#endif // LISTAEMPLEADOS_H_INCLUDED
