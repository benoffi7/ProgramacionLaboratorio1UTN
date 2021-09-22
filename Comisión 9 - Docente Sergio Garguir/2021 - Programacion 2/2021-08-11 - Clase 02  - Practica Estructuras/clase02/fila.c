#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicFila(Fila* fila){
    fila->inicio = inicListaDoble();
    fila->fin    = inicListaDoble();
}

void mostrarFila(Fila* fila){
    muestraListaDoble(fila->inicio);
}

void agregar(Fila* fila, stEmpleado dato){
    nodoDoble* nuevo = crearNodoDoble(dato);
    fila->fin = agregarAlFinalDoble(fila->fin, nuevo);
    if(fila->inicio == NULL){
        fila->inicio = fila->fin;
    }
    fila->fin = nuevo;
}

stEmpleado extraer(Fila* fila){
    stEmpleado e;
    if(fila->inicio){
        e = verPrimeroDobleT(fila->inicio);
        fila->inicio = borrarPrimerNodoDoble(fila->inicio);
        if(fila->inicio == NULL){
            fila->fin = inicListaDoble();
        }
    }
    return e;
}

stEmpleado verPrimeroFila(Fila* fila){
    stEmpleado e;
    if(fila->inicio){
        e = verPrimeroDobleT(fila->inicio);
    }
    return e;
}

int filaVacia(Fila* fila){
    return (fila->inicio)? 0 : 1;
}
