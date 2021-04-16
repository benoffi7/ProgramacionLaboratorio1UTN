/// Este archivo contiene funciones utilizadas durante las clases

#include "Librerias/pila.h" 
#include <windows.h>

void sumarElementosDePila()
{
    Pila pila;
    inicpila(&pila);

    Pila aux;
    inicpila(&aux);

    int sumatoria = 0;

    /// agrego datos a la pila
    leer(&pila);
    leer(&pila);
    leer(&pila);
    leer(&pila);

    /// muestro la pila
    mostrar(&pila);

    /// recorro la pila sumando sus elementos
    /**
        Usamos tope para sumar el numero en sumatoria
        y luego usamos una pila auxiliar para desapilar la pila,
        asi podemos pasar al siguiente numero.

        si hicieramos sumatoria += desapilar(&pila);
        estariamos realizando la sumatoria correctamente, pero
        perderiamos los valores de la pila en el proceso.
    */

    while(!pilavacia(&pila))
    {
        sumatoria += tope(&pila);
        apilar(&aux, desapilar(&pila));
    }

    /// uso aux para dejar la pila como estaba antes del proceso anterior
    while(!pilavacia(&aux))
    {
        apilar(&pila, desapilar(&aux));
    }

    printf("la sumatoria es: %d \n\n", sumatoria);

    /// muestro la pila nuevamente para comprobar que no perdi ningun dato
    mostrar(&pila);
}

/// ------------------------------------------------------------------------

void buscarElementoYFinalizar()
{
    /// version simple. Todo hardcodeado.
    /** una siguiente version seria que el usuario ingrese el numero a buscar */

    Pila pila;
    inicpila(&pila);

    Pila aux;
    inicpila(&aux);

    apilar(&pila, 10);
    apilar(&pila, 20);
    apilar(&pila, 30);
    apilar(&pila, 40);
    apilar(&pila, 50);

    int elementoBuscado = 2;
    int flag = 0;   /// otros nombres correctos podrian ser:
                    ///     elementoEncontrado
                    ///     flagElementoEncontrado
                    ///     elementoEncontradoFlag

    while(!pilavacia(&pila) && flag == 0)
    {
        mostrar(&pila);
        mostrar(&aux);
        Sleep(500);

        if (tope(&pila) == elementoBuscado)
        {
            flag = 1;   /// recordemos que el while analiza tambien que flag sea 0 para continuar
        }
        else
        {
            apilar(&aux, desapilar(&pila));
        }
    }

    /// informo al usuario si el elemento se encontro o no
    if (flag == 1)
    {
        /**
            si al finalizar el while, el flag es 1, entonces el elemento
            fue encontrado
        */

        printf("elemento %d encontrado!", elementoBuscado);
    }
    else
    {
        /**
            si al finalizar el while, el flag es 0, entonces el elemento
            no fue encontrado
        */

        printf("no se encontro el elemento %d", elementoBuscado);
    }

    /// dejamos la pila como estaba antes de recorrerla
    while(!pilavacia(&aux))
    {
        apilar(&pila, desapilar(&aux));
    }

    mostrar(&pila);
    mostrar(&aux);
}
