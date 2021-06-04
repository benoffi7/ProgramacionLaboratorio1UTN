#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char articulosString[100][200];

typedef struct{
    int id;
    int codigo;
    int rubro; /// 1 - Televisores / 2 - Lavarropas / 3 - Cocinas / 4 - Calefactores
    char marca[30];
    char modelo[30];
    float precio;
} stArticulo;

void getRubro(int nro, char rubro[]);
void muestraUnArticulo(stArticulo a);

#endif // ARTICULO_H_INCLUDED
