/// Las dos primeras lineas que dicen #ifndef y #define, y la ultima que dice #endif,
/// estan incluidas para poder trabajar con el archivo de ejemplo del ejercicio 1.
/// Uds no necesitan hacer esto para resolver la guia.

#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#define Pila struct _Pila
#define P_Pila struct _Pila *

struct _Pila
{
    int *valores;
    int postope;
};

void inicpila(P_Pila p);
void apilar(P_Pila p, int dato);
void apilar(P_Pila p, int dato);
int desapilar(P_Pila p);
int tope(P_Pila p);
int pilavacia(P_Pila p);
void leer (P_Pila p);
void mostrar(P_Pila p);

#endif // PILA_H_INCLUDED
