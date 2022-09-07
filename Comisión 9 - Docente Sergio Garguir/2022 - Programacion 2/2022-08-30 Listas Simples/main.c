#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

nodo* archivo2lista(char archivo[], nodo* lista);

int main()
{
    nodo* lista;
    lista=iniciLista();
    cargaArchivo("personas.dat");

    lista = archivo2lista("personas.dat", lista);

    /*
    for(int i=0;i<50;i++){
       // lista=agregarAlPrincipioPro(lista, crearNodo(cargaUnaPersona()));
        lista=agregarEnOrdenPorEdad(lista, crearNodo(cargaUnaPersona()));
    }

    lista = agregarAlFinal(lista, crearNodo(cargaUnaPersona()));
*/
    printf("\nLista de Personas!\n");
    muestraLista(lista);

    return 0;
}

void cargaArchivo(char archivo[]){
    FILE* archi = fopen(archivo, "ab");
    stPersona p;
    if(archi){
        for(int i=0;i<30;i++){
            p = cargaUnaPersona();
            fwrite(&p, sizeof(stPersona), 1, archi);
        }
        fclose(archi);
    }
}

nodo* archivo2lista(char archivo[], nodo* lista){
    FILE* archi = fopen(archivo, "rb");
    stPersona p;
    if(archi){
        while(fread(&p, sizeof(stPersona), 1, archi)){
            lista = agregarEnOrdenPorEdad(lista, crearNodo(p));
        }
    }
    return lista;
}
