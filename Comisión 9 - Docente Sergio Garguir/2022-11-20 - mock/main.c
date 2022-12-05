#include <stdio.h>
#include <stdlib.h>

#include "autoCarga.h"
#define DIM 10

int cargaArregloPersonas(stPersona p[], int v, int dim);
void muestraArregloPersonas(stPersona p[], int v);

int main()
{
    stPersona personas[DIM];
    int vPersonas = 0;
    vPersonas = cargaArregloPersonas(personas, vPersonas, DIM);
    muestraArregloPersonas(personas, vPersonas);

    printf("\nHello world!\n");
    return 0;
}

int cargaArregloPersonas(stPersona p[], int v, int dim){
    for(;v<dim;v++){
        p[v]=cargaUnaPersona();
    }
    return v;
}

void muestraArregloPersonas(stPersona p[], int v){
    for(int i=0;i<v;i++){
        muestraUnaPersona(p[i]);
    }
}


