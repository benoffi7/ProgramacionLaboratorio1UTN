#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../pila.h"

/// ejercicios 1 2 y 3 de TP2
/*
Sumar los elementos de una pila (usar variables enteras)
Contar los elementos de una pila (usar variables enteras)
Calcular el promedio de los valores de una pila (usar variables)

*/
void cargarPilaRandom(Pila * p);
int sumarPila(Pila pilita);
int contarPila(Pila pilita);
void pasarPila(Pila * origen, Pila * destino);

float promedioDeEnteros(int, int);

int main()
{
    srand(time(NULL));
    printf("Hello puntos 1, 2 y 3 tp2!\n");

    int sumaTotalMain=0, cantidadMain=0;

    float promedio=0;

    Pila pilita, aux;
    inicpila(&pilita);
    inicpila(&aux);

    cargarPilaRandom(&pilita);

    puts("Pila pilita");

    mostrar(&pilita);

    ///suma
    sumaTotalMain=sumarPila(pilita);

    /// contarPila
    cantidadMain=contarPila(pilita);

    promedio=promedioDeEnteros(sumaTotalMain, cantidadMain);

    printf("La suma total de la pila es %d\n", sumaTotalMain);
    printf("La cantidad de elementos de la pila es %d\n", cantidadMain);
    printf("El promedio de los valores de la pila es %.2f\n", promedio);

    puts("Pila pilita");

    mostrar(&pilita);

    pasarPila(&pilita, &aux);

    puts("Pila pilita");

    mostrar(&pilita);

    puts("Pila aux");

    mostrar(&aux);

    return 0;
}

void cargarPilaRandom(Pila * p)
{
    int i=0;
    for(i=0; i<10; i++)
    {
        apilar(p, (rand()%100) + 1);
    }
}

int sumarPila(Pila copia)
{
    Pila aux;
    inicpila(&aux);

    int sumaTotal=0;

    while(!pilavacia(&copia))
    {
        sumaTotal=sumaTotal + tope(&copia);
        apilar(&aux, desapilar(&copia));
    }

    return sumaTotal;
}

int contarPila(Pila copia)
{
    Pila aux;
    inicpila(&aux);

    int cantidad=0;

    while(!pilavacia(&copia))
    {
        apilar(&aux, desapilar(&copia));
        cantidad++;
    }

    return cantidad;
}

float promedioDeEnteros(int suma, int cantidad)
{
    return (float)suma/cantidad;
}

void pasarPila(Pila * pOrigen, Pila * pDestino)
{
    while(!pilavacia(pOrigen))
    {
        apilar(pDestino, desapilar(pOrigen));
    }
}
