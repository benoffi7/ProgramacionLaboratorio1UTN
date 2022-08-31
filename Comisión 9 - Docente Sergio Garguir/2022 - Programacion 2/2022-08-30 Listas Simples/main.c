#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main()
{
    nodo* lista;
    lista=iniciLista();

    for(int i=0;i<10;i++){
        lista=agregarAlPrincipioPro(lista, crearNodo(cargaUnaPersona()));
    }

    printf("\nLista de Personas!\n");
    muestraLista(lista);

    return 0;
}
