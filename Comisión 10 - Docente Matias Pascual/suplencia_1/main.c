#include <stdio.h>
#include <stdlib.h>
#include "Librerias/pila.h"

int contarElementos(Pila* pilaLocal)
{/// pilaLocal = &pila que es en el main

    int cantidad = 0;

    /// recorrer la pila
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pilaLocal))
    {
        /// contar elementos
        apilar(&aux, desapilar(pilaLocal));
        cantidad++;
    }

    /// dejar la pila en su estado original
    while(!pilavacia(&aux))
    {
        apilar(pilaLocal, desapilar(&aux));
    }

    /// devolver la cantidad
    return cantidad;
}



int main()
{
    Pila pila;
    inicpila(&pila);

    apilar(&pila,10);
    apilar(&pila,20);
    apilar(&pila,30);
    apilar(&pila,40);

    mostrar(&pila);

    int cantidadElementos = contarElementos(&pila);

    printf("%d", cantidadElementos);

    return 0;
}
