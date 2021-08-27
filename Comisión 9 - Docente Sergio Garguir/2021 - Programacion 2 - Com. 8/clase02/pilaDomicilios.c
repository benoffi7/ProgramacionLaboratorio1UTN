#include <stdio.h>
#include <stdlib.h>

#include "pilaDomicilios.h"

void inicPila(pilaDomicilios *p){
    p->dim = 50;
    p->dato = (stDomicilio*)malloc(sizeof(stDomicilio)*p->dim);
    p->v = 0;
}

void apilar(pilaDomicilios *p, stDomicilio dato){
    if(p->v==p->dim){
        p->dim+=25;  /// p->dim = p->dim + 25;
        p->dato = (stDomicilio *)realloc(p->dato, sizeof(stDomicilio)*p->dim);
    }
    p->dato[p->v] = dato;
    p->v++;
}

stDomicilio desapilar(pilaDomicilios *p){
    stDomicilio d = p->dato[p->v-1];
    if(p->v > 0){
        p->v--;
    }
    return d;
}

stDomicilio tope(pilaDomicilios *p){
    return p->dato[p->v-1];
}

int pilavacia(pilaDomicilios *p){
    return (p->v==0) ? 1 : 0;
}
