#include "Librerias/pila.h"

float promedio(Pila* pila);
int sumarNumeros(Pila* pila);
int contarCantidad(Pila* pila);
float calcular(int suma, int cantidad);

/// SACAR PROMEDIO
float promedio(Pila* pila)
{
    float promedioCalculado = 0.0F;

    /// SUMABA NUMEROS
    int suma = sumarNumeros(pila);

    /// CONTABA CANTIDAD
    int cantidad = contarCantidad(pila);

    /// CALCULABA SUMA / CANTIDAD
    promedioCalculado = calcular(suma, cantidad);

    return promedioCalculado;
}

int sumarNumeros(Pila* pila)
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

int contarCantidad(Pila* pila)
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

float calcular(int suma, int cantidad)
{
    float calculo = (float) suma / cantidad;

    return calculo;
}






