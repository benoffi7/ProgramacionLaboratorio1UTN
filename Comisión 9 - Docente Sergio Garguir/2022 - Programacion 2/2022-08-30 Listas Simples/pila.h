#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define Pila nodo*

void inicPila(Pila* pila);
int pilavacia(Pila* pila);
stPersona tope(Pila* pila);
stPersona desapilar(Pila* pila);
void apilar(Pila* pila, stPersona dato);
void mostrar(Pila* pila);

#endif // PILA_H_INCLUDED
