#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

int main()
{
    /* 4.	Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
    Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden.*/

    Pila origen, destino, aux;

    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux);

    leer(&origen);
    leer(&origen);
    leer(&origen);
    leer(&origen);
    leer(&origen);

    printf("Origen\n");
    mostrar(&origen);

    while (!pilavacia(&origen))
    {
        apilar(&aux, desapilar(&origen));
    }

    printf("auxi\n");
    mostrar(&aux);
    while (!pilavacia(&aux))
    {
        apilar(&destino, desapilar(&aux));
    }

    printf("Destino\n");
    mostrar(&destino);

    printf("Origen\n");
    mostrar(&origen);

    return 0;
}
