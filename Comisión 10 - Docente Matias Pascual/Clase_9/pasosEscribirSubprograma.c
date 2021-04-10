#include "Librerias/pila.h"

/// DEFINIR EL PROBLEMA
/** encontrar el menor elemento de un pila */

/// NOMBRAR EL SUBPROGRAMA (funcion)
/** nombre: buscarMenorElemento() */

/// TESTEAR FUNCIONAMIENTO

/** ejemplos */
int buscarMenorElemento_v1()
{
    return 1;
}

int buscarMenorElemento_v2(Pila* pila)
{
    return tope(pila);
}

/// ESCRIBIR LA CABECERA (prototipado)
int buscarMenorElemento_v3(Pila*);

/// BUSCAR ALGORITMO ADECUADO
/** algoritmo de busqueda en pila */

/// ESCRIBIR COMENTARIOS DE LOS PASOS PRINCIPALES
int buscarMenorElemento_v4(Pila* pila)
{
    /// recorro la pila usando una pila auxiliar pilaAxu

    /// guardo el tope en una pila auxiliar pilaMenor

    /// mientras la pila no este vacia

    /// comparo pilaMenor con el tope de pila

        /// si es menor

            ///desapilo de pilaMenor a pilaAux

            /// apilo en pilaMenor lo que desapilo de pila


        /// si no

            ///sigo recorriendo la pila


    /// acomoda la pila como estaba

    /// al finalizar el recorrido, devuelvo el tope de pilaMenor
}

int buscarMenorElemento_v5(Pila* pila)
{
    /// recorro la pila usando una pila auxiliar pilaAxu
    Pila pilaAux;
    inicpila(&pilaAux);

    /// desapilo pila en una pila auxiliar pilaMenor
    Pila pilaMenor;
    inicpila(&pilaMenor);

    apilar(&pilaMenor, desapilar(pila));

    /// mientras la pila no este vacia
    while (!pilavacia(pila))
    {
        /// comparo pilaMenor con el tope de pila
        if (tope(pila) < tope(&pilaMenor))
        {
            /// si es menor, desapilo de pilaMenor a pilaAux
            apilar(&pilaAux, desapilar(&pilaMenor));

            /// apilo en pilaMenor lo que desapilo de pila
            apilar(&pilaMenor, desapilar(pila));
        }
        else
        {
            /// si no, sigo recorriendo la pila
            apilar(&pilaAux, desapilar(pila));
        }
    }

    /// al finalizar el recorrido, acomodo la pila
    while(!pilavacia(&pilaAux))
    {
        apilar(pila, desapilar(&pilaAux));
    }

    /// devuelvo el tope de pilaMenor
    return tope(&pilaMenor);
}

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





