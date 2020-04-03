#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    /// ejercicio 14
    Pila dada, impar, par, aux;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&impar);
    inicpila(&par);

    char control;
    /// se carga dada

    do
    {
        leer(&dada);
        printf("Desea continuar? s/n ");
        printf("%c", control = getch());
        printf("\n");
    }
    while(control == 's');

    while(!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada)); /// saco 1er elemento

        if(!pilavacia(&dada))
        {
            apilar(&aux, desapilar(&dada)); /// saco 2do elemento

            if(pilavacia(&dada))  /// averigua que es par
            {
                apilar(&par, desapilar(&aux));
            }
        }
        else   /// es impar
        {
            apilar(&impar, desapilar(&aux));
        }
    }

    if(!pilavacia(&impar))
    {
        printf("Dada tenia cantidad de elementos impares\n");
    }
    else
    {
        if (!pilavacia(&par))
        {
            printf("Dada tenia cantidad de elementos pares\n");
        }
        else
        {
            printf("La pila dada estaba vacia\n");
        }
    }


    system("pause");

///  //////////////////////////////////////////////////////////////////////////////
/// Ejercicios guia 2
///* 1) Sumar los elementos de una pila (usar variables)*/


    inicpila(&dada);
    inicpila(&aux);


    do
    {
        leer(&dada);
        printf("Desea continuar? s/n ");
        printf("%c", control = getch());
        printf("\n");
    }
    while(control == 's');


    int suma=0;

    while (!pilavacia(&dada))
    {
        suma= suma + tope(&dada);

        apilar(&aux, desapilar(&dada));
    }

/// paso los elementos de aux a dada
    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    mostrar(&dada);
    printf("La suma de los elementos de dada es %d\n", suma);

//////////////////////////////////////////////////////////////////////////////
/// 2) Contar los elementos de una pila (usar variables)

    int cuenta=0;

    while(!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));
        cuenta++;
    }

/// paso los elementos de aux a dada
    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    printf("La cantidad de elementos que contiene dada es %d\n", cuenta);

//////////////////////////////////////////////////////////////////////////////
///3) Calcular el promedio de los valores de una pila (usar variables)
    float promedio = 0;
    promedio = (float) suma/ (float) cuenta;

    printf("Y el promedio de dada es %.2f \n", promedio);



/// ///////////////////////////////////////////////////////////////////////////
/// ejercicio 4 - buscar el menor

/// dada esta declarada mas arriba
    Pila menor;
    inicpila(&menor);

    if (!pilavacia(&dada))
    {

        /// tomo el primer elemento y lo supongo como el menor
        apilar(&menor, desapilar(&dada));


        while(!pilavacia(&dada))
        {
            if(tope(&dada)<tope(&menor))
            {
                apilar(&aux, desapilar(&menor));

                apilar(&menor, desapilar(&dada));
            }
            else
            {
                apilar(&aux, desapilar(&dada));
            }
        }

        while(!pilavacia(&aux))
        {
            apilar(&dada, desapilar(&aux));
        }


        printf("\nEl menor elemento de la pila dada es: %d\n", tope(&menor));
    }

/// ///////////////////////////////////////////////////////////////////////////
/// ejercicio 5 - Insertar en orden

    Pila nuevo, dodo;
    inicpila(&nuevo);
    inicpila(&dodo);



    printf("\nPila dodo\n");
    mostrar(&dodo);

    printf("\nIngrese un valor a insertar en la pila ordenada:\n ");
    leer(&nuevo);

/// buscamos el lugar en la pila que esta ordenada para realizar la insercion
    while(!pilavacia(&dodo)  &&  tope(&dodo)<tope(&nuevo))
    {
        apilar(&aux, desapilar(&dodo));
    }

/// insertamos el nuevo elemento
    apilar(&dodo, desapilar(&nuevo));

/// pasamos nuevamente los datos a la pila original
    while(!pilavacia(&aux))
    {
        apilar(&dodo, desapilar(&aux));
    }

    printf("\nPila dodo\n");
    mostrar(&dodo);
    return 0;
}
