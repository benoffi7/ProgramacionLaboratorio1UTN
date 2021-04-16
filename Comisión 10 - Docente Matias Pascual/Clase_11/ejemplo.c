#include "Librerias/pila.h"

/// prototipado de funciones

float promedio(Pila* pila, float* resultado);
int sumarElementos(Pila* pila);
int cantidadElementos(Pila* pila);
float division(int suma, int cantidad);

/// ----------------------------------------------

/// definicion de funciones

float promedio(Pila* pila, float* resultado)
{
    /// suma de los elementos
    int suma = sumarElementos(pila);

    /// cantidad elementos
    int cantidad = cantidadElementos(pila);

    /// division
    float r = division(suma, cantidad);

    *resultado = r;

    return r;
}

/// ----------------------------------------------

int sumarElementos(Pila* pila)
{
    int suma = 0;

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pila))
    {
        suma += tope(pila);
        apilar(&aux, desapilar(pila));
    }

    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return suma;
}

/// ----------------------------------------------

int cantidadElementos(Pila* pila)
{
    int cantidad = 0;

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pila))
    {
        apilar(&aux, desapilar(pila));
        cantidad++;
    }

    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return cantidad;
}

/// ----------------------------------------------

float division(int suma, int cantidad)
{
    float resultado = (float) suma / cantidad;

    return resultado;
}
