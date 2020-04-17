#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

void cargarPila(Pila * punteroPila);

void cargarPilaRandom(Pila * punteroPila, int limite);

void pasarPila(Pila * pOrigen, Pila * pDestino);

void pasarPilaMismoOrden(Pila * pOrigen, Pila * pDestino);

int buscarMenor (Pila * pPila);

void ordenPorSeleccion(Pila * pOrigen, Pila *pDestino);

void insertaEnOrden(Pila * pPila, int aInsertar);

void ordenPorInsercion(Pila * pOrigen, Pila *pDestino);

int sumaTopeYAnterior(Pila copiaDePila);

int main()
{
    srand(time(NULL));

    printf("Hello funciones con pilas!\n");

    Pila pilita, pilota;

    inicpila(&pilita);
    inicpila(&pilota);

    ///cargarPila(&pilita);
    cargarPilaRandom(&pilita,10);

    printf("Pila pilita cargada: \n");
    mostrar(&pilita);

    printf("La suma del tope y anterior es %d\n", sumaTopeYAnterior(pilita));

    system("pause");

    printf("Pila pilita cargada: \n");
    mostrar(&pilita);

    system("pause");
/// vayan pensando un main con menu, para ir ejecutando
/// cada una de las funciones que hicimos hasta ahora

    /* pasarPila(&pilita, &pilota);

     printf("Pila pilita vacia: \n");
     mostrar(&pilita);

     printf("Pila pilota con los datos pasados: \n");
     mostrar(&pilota);

     int menor=buscarMenor(&pilita);

     printf("El menor en la pila es %d\n\n", menor );

     printf("Pila pilita cargada: \n");
     mostrar(&pilita);

     */

    /// ordenPorSeleccion(&pilita, &pilota);

    ordenPorInsercion(&pilita, &pilota);

    printf("Pila pilota con los datos ordenados: \n");
    mostrar(&pilota);

    printf("Pila pilita: \n");
    mostrar(&pilita);
    insertaEnOrden(&pilota, 32);

    printf("Pila pilota el dato insertado: \n");
    mostrar(&pilota);

    return 0;
}

///1- hacer una funcion que cargue la pila con intervencion del usr
void cargarPila(Pila * punteroPila)
{
    char control;

    printf("Cargando la pila desde la funcion:\n");
    do
    {
        leer(punteroPila);
        printf("Desea continuar? s/n ");
        printf("%c", control = getch());
        printf("\n");
    }
    while(control == 's');
}

/// fn de testing para cargar pilas
void cargarPilaRandom(Pila * punteroPila, int limite)
{
    int i=0;

    /// limite me da la cantidad a apilar
    for (i=0; i< limite; i++)
    {
        /// apilo valores random entre 1 y 100
        apilar(punteroPila, (rand()%100)+1);
    }

}

/// 2 -Hacer una función que pase todos los elementos de una pila a otra.
void pasarPila(Pila * pOrigen, Pila * pDestino)
{
    while(!pilavacia(pOrigen))
    {
        apilar(pDestino, desapilar(pOrigen));
    }
}


/// 3 - Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden

void pasarPilaMismoOrden(Pila * pOrigen, Pila * pDestino)
{
    Pila aux;
    inicpila(&aux);

    pasarPila(pOrigen, &aux);

    pasarPila(&aux, pDestino);
}

/// 4 - Hacer una función que encuentre el menor elemento de una pila y
/// lo retorne. La misma debe eliminar ese dato de la pila.

/// validar previamente que la pila tenga datos
int buscarMenor (Pila * pPila)
{
    Pila aux;
    inicpila(&aux);

    int minimo;

    if(!pilavacia(pPila))
    {
        minimo=desapilar(pPila);

        while(!pilavacia(pPila))
        {
            if(tope(pPila)<minimo)
            {
                apilar(&aux, minimo);
                minimo=desapilar(pPila);
            }
            else
            {
                apilar(&aux, desapilar(pPila));
            }
        }

        pasarPila(&aux, pPila);
    }

    return minimo;
}

/// 5- Hacer una función que pase los elementos de una pila a otra,
/// de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4.
/// (Ordenamiento por selección)

void ordenPorSeleccion(Pila * pOrigen, Pila *pDestino)
{
    int menor;

    while(!pilavacia(pOrigen))
    {
        menor=buscarMenor(pOrigen);

        apilar(pDestino, menor);
    }
}


/// 6- Hacer una función que inserte en una pila ordenada un nuevo elemento,
/// conservando el orden de ésta.

void insertaEnOrden(Pila * pPila, int aInsertar)
{
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(pPila) && tope(pPila) < aInsertar)
    {
        apilar(&aux, desapilar(pPila));
    }

    apilar(pPila, aInsertar);

    pasarPila(&aux,pPila);
}

/// 7 - Hacer una función que pase los elementos de una pila a otra, de manera
/// que se genere una nueva pila ordenada. Usar la función del ejercicio 6.
/// (Ordenamiento por inserción)
/// pOrigen tiene datos desordenados, pdestino debe estar vacia

void ordenPorInsercion(Pila * pOrigen, Pila * pDestino)
{
    int dato;



    while(!pilavacia(pOrigen))
    {
        dato=desapilar(pOrigen);

        insertaEnOrden(pDestino, dato);
    }


}

/// 8 - Hacer una función que sume y retorne los dos primeros elementos
/// de una pila (tope y anterior), sin alterar su contenido.

int sumaTopeYAnterior(Pila copiaDePila)
{
    int rta=0;
    int i=0;

    while(!pilavacia(&copiaDePila)&& i< 2)
    {

        rta = rta+desapilar(&copiaDePila);

        i++;
    }

    return rta;
}
