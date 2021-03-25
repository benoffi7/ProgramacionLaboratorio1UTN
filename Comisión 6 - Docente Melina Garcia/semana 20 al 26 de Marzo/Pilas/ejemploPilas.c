#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///pedirle a un usuario que ingrese 10 valores en la pila, y luego eliminar solamente los pares.

int main()
{
    Pila p;
    Pila aux;
    int basura;
    inicpila(&p);
    inicpila(&aux);
    for(int i = 1; i <= 10 ; i++)
    {
        leer(&p);
        mostrar(&p);
    }

    while (!pilavacia(&p)) /// pilavacia(&p) == 0
    {
        if (tope(&p) % 2 == 0)
        {
            basura = desapilar(&p);
        }
        else
        {
            apilar(&aux,desapilar(&p));
            mostrar(&aux);
        }
        mostrar(&p);
    }
    printf("P despues de pasarlo a aux\n");
    mostrar(&p);
    while (!pilavacia(&aux))
    {
        apilar(&p,desapilar(&aux));
        mostrar(&aux);
        mostrar(&p);
    }
    printf("P luego de devolver todos los valores desde aux a P\n");
    mostrar(&p);
    return 0;
}
