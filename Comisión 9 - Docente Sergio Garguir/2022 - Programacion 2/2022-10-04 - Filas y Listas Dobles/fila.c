#include "fila.h"

void inicFila(Fila* fila){
    fila->inicio    = inicListaD();
    fila->fin       = inicListaD();
}

void muestraFila(Fila* fila){
    muestraListaD(fila->inicio);
}

void agregarFila(Fila* fila, stPersona dato){
    nodoDoble* nuevo = crearNodoD(dato);
    fila->fin = agregarAlFinalD(fila->fin, nuevo);
    if(!fila->inicio){
        fila->inicio = fila->fin;
    }
    fila->fin=nuevo;
}

stPersona verPrimeroFila(Fila* fila){
    stPersona p;
    if(fila->inicio){
        p=verPrimeroD(fila->inicio);
    }
    return p;
}

stPersona extraerFila(Fila* fila){
    stPersona p;
    if(fila->inicio){
        p = verPrimeroD(fila->inicio);
        fila->inicio = borrarPrimeroD(fila->inicio);
        if(!fila->inicio){
            fila->fin = inicListaD();
        }
    }

    return p;
}

int filaVacia(Fila* fila){
    return (fila->inicio)?0:1;
}

int cuentaMayoresDeEdad(Fila* fila, int edad){
    return cuentaMayoresDeEdadDoble(fila->inicio, edad);
}

void pasaFila(Fila* origen, Fila* destino){
    while(!filaVacia(origen)){
        agregarFila(destino, extraerFila(origen));
    }
}
