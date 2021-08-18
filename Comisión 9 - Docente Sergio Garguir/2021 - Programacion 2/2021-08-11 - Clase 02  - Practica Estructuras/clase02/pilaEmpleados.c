#include "pilaEmpleados.h"

void inicpila(Pila *p)
{
       p->dim = 50;
       p->e = (stEmpleado *)malloc(p->dim*sizeof(stEmpleado));
       p->v = 0;
}

void apilar(Pila *p, stEmpleado dato)
{
    if(p->v == p->dim){
        p->dim+=50;  /// p->dim = p->dim + 50;
        p->e = (stEmpleado *)realloc(p->e, p->dim * sizeof(stEmpleado));
    }
    p->e[p->v] = dato;
    p->v++;
}

stEmpleado desapilar(Pila *p)
{
   stEmpleado z = p->e[p->v -1];
   p->v--;
   return z;
}

stEmpleado tope(Pila *p)
{
    return p->e[p->v - 1];
}

int pilavacia(Pila *p)
{
    return (p->v == 0) ? 1 : 0;
}
