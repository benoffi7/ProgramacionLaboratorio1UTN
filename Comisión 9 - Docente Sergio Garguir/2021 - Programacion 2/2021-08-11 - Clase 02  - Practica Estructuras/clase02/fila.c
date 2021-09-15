#include "fila.h"

void inicFila(Fila* fila){
    fila->inicio = inicListaDoble();
    fila->fin    = inicListaDoble();
}

