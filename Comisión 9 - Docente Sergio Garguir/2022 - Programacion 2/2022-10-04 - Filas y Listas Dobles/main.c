#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

int main()
{

    printf("Hello world!\n");
    return 0;
}

void fila2archivo(Fila* fila, int edad, char nombreArchivo[]){
    FILE* archi = fopen(nombreArchivo,"ab");
    stPersona p;
    Fila aux;
    inicFila(&aux);

    if(archi){
        while(!filaVacia(fila)){
            p=extraerFila(fila);
            if(p.edad > edad){
                fwrite(&p, sizeof(stPersona), 1, archi);
            }

            agregarFila(&aux, p);
        }
        pasaFila(&aux,fila);
        fclose(archi);
    }
}
