#ifndef CELDA_H_INCLUDED
#define CELDA_H_INCLUDED

#include "materia.h"
#include "lista.h"

typedef struct {
    stMateria dato;
    nodoDoble * listaDeNotas;
} celda;

void muestraUnaCelda(celda c);
#endif // CELDA_H_INCLUDED
