#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{

/// ///////////////////////////////////////////////////////////////////////////
/// ejercicio 5 - Insertar en orden

    Pila nuevo, dodo, aux;
    inicpila(&nuevo);
    inicpila(&dodo);
    inicpila(&aux);

    apilar(&dodo, 8);
    apilar(&dodo, 7);
    apilar(&dodo, 5);
    apilar(&dodo, 3);
    apilar(&dodo, 1);

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

/// ///////////////////////////////////////////////////////////////////////////
 /// ejercicio 6, orden por seleccion

    Pila dada, menor, ordenada;
    inicpila(&dada);
    inicpila(&menor);
    inicpila(&ordenada);
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

    printf("\nPila dada\n");
    mostrar(&dada);




    while (!pilavacia(&dada))
    {

    /// buscar menor(ejercicio 4), nucleo de la ordenacion

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
    /// fin buscar menor

        apilar(&ordenada, desapilar(&menor));
        ///     printf("\nEl menor elemento de la pila dada es: %d\n", tope(&menor));
    }
    printf("\nPila ordenada\n");
    mostrar(&ordenada);


/// ///////////////////////////////////////////////////////////////////////////
/// 7) Determinar si un elemento buscado está dentro de una pila

    apilar(&dada, 11);
    apilar(&dada, 14);
    apilar(&dada, 3);
    apilar(&dada, 7);
    apilar(&dada, 5);
    apilar(&dada, 3);
    apilar(&dada, 4);
    apilar(&dada, 6);

    int flag=0;

    int elemento =0;

    printf("Ingrese un elemento a buscar en la pila dada: ");
    scanf("%d", &elemento);

    while (!pilavacia(&dada) && flag==0)
    {
        if(tope(&dada)!=elemento)
        {
            apilar(&aux, desapilar(&dada));
        }
        else
        {
            flag = 1;
        }
    }

    while (!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    if(flag==1)
        printf("\nEl elemento %d se encuentra en la pila dada", elemento);
    else
        printf("\nEl elemento %d no se encuentra en la pila dada", elemento);

    printf("\nPila dada");
    mostrar(&dada);
    return 0;
}
