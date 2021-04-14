#include "Librerias/pila.h"

void ordenarPila(Pila* pila)
{
    Pila pilaAux;
    inicpila(&pilaAux);

    while(!pilavacia(pila))
    {
        apilar(&pilaAux, buscarMenorElemento(pila));
    }

    /// paso el contenido de la pila ordenada a la pila original
    while(!pilavacia(&pilaAux))
    {
        apilar(pila, desapilar(&pilaAux));
    }
}
