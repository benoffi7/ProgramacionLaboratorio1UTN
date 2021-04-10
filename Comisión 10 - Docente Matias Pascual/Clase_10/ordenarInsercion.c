#include "Librerias/pila.h"

/// el objetivo de la funcion es insertar un elemento en una pila ordenada
/// en el lugar que le corresponde

void ingresarEnOrden(Pila* pila, int elemento)
{
    /// utilizo una pila auxiliar para recorrer la pila
    Pila aux;
    inicpila(&aux);

    /// utilizo un flag para saber si pude ingresar el elemento
    int flag = 0;

    /// busco cual es el lugar donde debo insertar el elemento
    while(!pilavacia(pila) && flag == 0)
    {
        if (elemento < tope(pila))
        {
            apilar(pila, elemento);
            flag = 1;
        }
        else
        {
            apilar(&aux, desapilar(pila));
        }
    }

    /// si vacio la pila, pero aun no ingreso el elemento, entonces
    /// ingreso el elemento en la pila auxiliar
    if (flag == 0)
    {
        apilar(&aux, elemento);
    }

    /// acomodo la pila
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }
}
