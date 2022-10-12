#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "listaDoble.h"

typedef struct{
    struct nodoDoble* inicio;
    struct nodoDoble* fin;
}Fila;

void inicFila(Fila* fila);
void muestraFila(Fila* fila);
void agregarFila(Fila* fila, stPersona dato);
stPersona verPrimeroFila(Fila* fila);
stPersona extraerFila(Fila* fila);
int filaVacia(Fila* fila);
int cuentaMayoresDeEdad(Fila* fila, int edad);
void pasaFila(Fila* origen, Fila* destino);

#endif // FILA_H_INCLUDED
