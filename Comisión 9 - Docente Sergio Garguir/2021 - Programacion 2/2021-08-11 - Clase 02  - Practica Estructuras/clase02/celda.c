#include <stdio.h>
#include <stdlib.h>
#include "celda.h"

int alta(stCelda adl[], stEmpleado e, int validos){
    nodo* nuevo = crearNodo(e);
    int pos = buscarPosEmpleado(adl, validos, e.cargo);

    if(pos == -1){
        validos = agregarEnArreglo(adl, validos, e.cargo);
        pos = validos - 1;
    }

    adl[pos].listaEmpleados = agregarAlPrincipio(adl[pos].listaEmpleados, nuevo);

    return validos;
}

int buscarPosEmpleado(stCelda adl[], int validos, char cargo[]){
    int rta = -1;
    int i=0;

    while(i<validos && rta == -1){
        if(strcmp(adl[i].cargo, cargo)==0){
            rta = i;
        }
        i++;
    }

    return rta;
}

int agregarEnArreglo(stCelda adl[], int validos, char cargo[]){
    strcpy(adl[validos].cargo,cargo);
    adl[validos].listaEmpleados = inicLista();
    validos++;
    return validos;
}

