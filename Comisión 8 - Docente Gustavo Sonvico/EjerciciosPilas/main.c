#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

/*2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío
la pila DESTINO. Pasar todos los elementos de la pila ORIGEN a la pila DESTINO. */

int main()
{
    char control;

    Pila origen, destino;

    inicpila(&origen);
    inicpila(&destino);


    printf("Vamos a cargar la pila origen: \n\n");

    do
    {
        leer(&origen);

        printf("\n Desea continuar? s/n ---> ");

        fflush(stdin);

        scanf("%c", &control);
    }
    while(control=='s');

    printf("Contenido de la pila origen luego de su carga:\n");
    mostrar(&origen);

    while(!pilavacia(&origen))
    {
        apilar(&destino, desapilar(&origen) );
    }

    printf("Contenido de la pila origen luego del while:\n");
    mostrar(&origen);
    printf("Contenido de la pila destino luego del while:\n");
    mostrar(&destino);


    return 0;
}
