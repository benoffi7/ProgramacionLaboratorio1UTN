#include "Librerias/pila.h"

void ejemploLeerVaribleDesdePuntero (int* puntero)
{
    printf("&: %X \n", &puntero);
    printf("=: %X \n",  puntero);
    printf("*: %d \n", *puntero);
}

/// BUSCAR EL MENOR ELEMENTO DE UNA PILA, SACARLO Y DEVOLVERLO

int buscarMenorElemento(Pila* pila)
{
    Pila pilaAux;
    Pila pilaMenor;

    inicpila(&pilaAux);
    inicpila(&pilaMenor);

    apilar(&pilaMenor, desapilar(pila));

    while (!pilavacia(pila))
    {
        if (tope(pila) < tope(&pilaMenor))
        {
            apilar(&pilaAux, desapilar(&pilaMenor));

            apilar(&pilaMenor, desapilar(pila));
        }

        else
        {
            apilar(&pilaAux, desapilar(pila));
        }
    }

    /// acomodo la pila
    while(!pilavacia(&pilaAux))
    {
        apilar(pila, desapilar(&pilaAux));
    }

    return tope(&pilaMenor);
}
