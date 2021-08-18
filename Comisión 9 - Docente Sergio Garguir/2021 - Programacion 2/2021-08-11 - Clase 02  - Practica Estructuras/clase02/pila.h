#include <stdio.h>
#include <malloc.h>
#include "empleado.h"

typedef struct
{
    stEmpleado *e;
    int v;
    int dim;
}Pila;

void inicpila(Pila *p);
void apilar(Pila *p, stEmpleado dato);
stEmpleado desapilar(Pila *p);
stEmpleado tope(Pila *p);
int pilavacia(Pila *p);


