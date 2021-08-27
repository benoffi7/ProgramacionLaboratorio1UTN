#ifndef PILADOMICILIOS_H_INCLUDED
#define PILADOMICILIOS_H_INCLUDED

#include "domicilio.h"

typedef struct{
    stDomicilio *dato;
    int v;
    int dim;
}pilaDomicilios;

void inicPila(pilaDomicilios *p);
void apilar(pilaDomicilios *p, stDomicilio dato);
stDomicilio desapilar(pilaDomicilios *p);
stDomicilio tope(pilaDomicilios *p);
int pilavacia(pilaDomicilios *p);

#endif // PILADOMICILIOS_H_INCLUDED
