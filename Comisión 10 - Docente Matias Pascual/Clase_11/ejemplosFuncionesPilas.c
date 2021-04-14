/**
    Ejemplos de funciones y pilas
*/

#include "Librerias/pila.h"

/// prototipado de funciones

/// carga una pila con 3 datos que le pide al usuario
void cargarPila(Pila* pila);

/// cuenta los elementos de un apila
int contarElementosPila(Pila* pila);

/// intercambia los valores de dos pilas
void intercambiarPilas(Pila* pilaA, Pila* pilaB);

/// pasa los valores de una pila a otra pila
void pasarPila(Pila* origen, Pila* destino);

/// invierte el orden de una pila
void invertirPila(Pila* pila);

/// devuelve el mayor elemento de una pila (sin sacarlo)
int dameMayorPila(Pila* pila);

/// devuelve el menor elemento de una pila (sin sacarlo)
int dameMenorPila(Pila* pila);

/// ----------------------------------------------

/// definicion de funciones

void cargarPila(Pila* pila)
{
    int contador = 0;
    int numero = 0;

    while(contador < 3)
    {
        printf("ingrese un numero");

        fflush(stdin);
        scanf("%d", &numero);

        apilar(pila, numero);

        contador++;
    }
}

/// ----------------------------------------------

int contarElementosPila(Pila* pila)
{
    Pila aux;
    inicpila(&aux);

    int cantidadElementos = 0;
    while(!pilavacia(pila))
    {
        apilar(&aux, desapilar(pila));
        cantidadElementos++;
    }

    /// acomodo la pila a su estado original
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return cantidadElementos;
}

/// ----------------------------------------------

void intercambiarPilas(Pila* pilaA, Pila* pilaB)
{
    Pila auxA;
    Pila auxB;

    inicpila(&auxA);
    inicpila(&auxB);

    while(!pilavacia(pilaA))
    {
        apilar(&auxA, desapilar(pilaA));
    }

    while(!pilavacia(pilaB))
    {
        apilar(&auxB, desapilar(pilaB));
    }

    while(!pilavacia(&auxA))
    {
        apilar(pilaB, desapilar(&auxA));
    }

    while(!pilavacia(&auxB))
    {
        apilar(pilaA, desapilar(&auxB));
    }
}

/// ----------------------------------------------

void pasarPila(Pila* origen, Pila* destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}

/// ----------------------------------------------

void invertirPila(Pila* pila)
{
    Pila aux;
    Pila aux2;

    inicpila(&aux);
    inicpila(&aux2);

    pasarPila(pila, &aux);
    pasarPila(&aux, &aux2);
    pasarPila(&aux2, pila);
}

/// ----------------------------------------------

int dameMenorPila(Pila* pila)
{
    int menor = tope(pila);

    Pila aux;
    inicpila(&aux);

    apilar(&aux, desapilar(pila));

    while(!pilavacia(pila))
    {
        if (tope(pila) < menor)
        {
            menor = tope(pila);
        }
        apilar(&aux, desapilar(pila));
    }

    pasarPila(&aux, pila);

    return menor;
}

/// ----------------------------------------------

int dameMayorPila(Pila* pila)
{
    int mayor = tope(pila);

    Pila aux;
    inicpila(&aux);

    apilar(&aux, desapilar(pila));

    while(!pilavacia(pila))
    {
        if (tope(pila) > mayor)
        {
            mayor = tope(pila);
        }
        apilar(&aux, desapilar(pila));
    }

    pasarPila(&aux, pila);

    return mayor;
}
