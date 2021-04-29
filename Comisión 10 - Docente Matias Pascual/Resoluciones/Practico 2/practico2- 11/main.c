#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila a,b;
    inicpila(&a);
    inicpila(&b);

    apilar(&a, 1);
    apilar(&a, 3);
    apilar(&a, 5);
    apilar(&a, 7);
    apilar(&a, 9);
    apilar(&a, 11);

    apilar(&b, 2);
    apilar(&b, 4);
    apilar(&b, 6);
    apilar(&b, 12);
    apilar(&b, 14);

    mostrar(&a);
    mostrar(&b);

    Pila destino;
    inicpila(&destino);

    while(!pilavacia(&a)&&!pilavacia(&b))
    {
        if (tope(&a)>tope(&b))
        {
            apilar(&destino, desapilar(&a));
        }
        else
        {
            apilar(&destino, desapilar(&b));
        }
    }

    // ahora evaluo si quedo algo en alguna de las dos pilas

    if(!pilavacia(&a))
    {
        while(!pilavacia(&a))
            apilar(&destino, desapilar(&a));
    }
    else
    {
        while(!pilavacia(&b))
            apilar(&destino, desapilar(&b));
    }

    mostrar(&a);
    mostrar(&b);
    mostrar(&destino);

    return 0;
}
