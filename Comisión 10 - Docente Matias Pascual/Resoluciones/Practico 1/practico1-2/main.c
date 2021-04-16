#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

/* 2.	Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.*/

int main()
{
    Pila origen, destino;
    inicpila(&origen);
    inicpila(&destino);

    leer(&origen);
    leer(&origen);
    leer(&origen);
    leer(&origen);
    leer(&origen);

    printf("Pila origen\n");
    mostrar(&origen);

    while(!pilavacia(&origen))
    {
        apilar(&destino, desapilar(&origen));
    }

    printf("Pila origen\n");
    mostrar(&origen);
    printf("Pila destino\n");
    mostrar(&destino);

    return 0;
}
