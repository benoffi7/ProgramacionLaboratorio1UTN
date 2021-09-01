#ifndef LISTAEMPLEADOS_H_INCLUDED
#define LISTAEMPLEADOS_H_INCLUDED

#include "empleado.h"

typedef struct _nodo{
    stEmpleado dato;
    struct _nodo *siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stEmpleado e);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
nodo* buscaUltimo(nodo* lista);
nodo* buscaEmpleado(nodo* lista, char apellido[]);

#endif // LISTAEMPLEADOS_H_INCLUDED
