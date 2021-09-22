#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "listaDobleEmpleados.h"

typedef struct{
    struct _nodoDoble* inicio;
    struct _nodoDoble* fin;
}Fila;

void inicFila(Fila* fila);
void mostrarFila(Fila* fila);
void agregar(Fila* fila, stEmpleado dato);
stEmpleado extraer(Fila* fila);
stEmpleado verPrimeroFila(Fila* fila);
int filaVacia(Fila* fila);

#endif // FILA_H_INCLUDED
