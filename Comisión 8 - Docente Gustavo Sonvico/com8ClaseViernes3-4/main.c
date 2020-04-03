#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pila.h"

int main()
{
    printf("Hoy viernes.... y se programa fuerte !!\n");

    Pila dada, menor, aux, ordenada;
    inicpila(&dada);
    inicpila(&menor);
    inicpila(&aux);
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

    mostrar(&dada);
    system("pause");

    while (!pilavacia(&dada))
    {
        /// ejercicio 5 - buscar menor
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
        /// fin ejericio 5 - buscar menor

        ///  printf("\nEl menor elemento de la pila dada es: %d\n", tope(&menor));
        apilar(&ordenada, desapilar(&menor));
    }


    mostrar(&ordenada);
    system("pause");

    /// ejercicio 7

    /// cargar pila dada
    int elemento;

    /// leer el elemento a buscar
    printf("Ingrese el dato a buscar: ");
    scanf("%d", &elemento);

    int flag=0;
    /// 0 - el dato no está
    /// 1 - el dato está


    while(!pilavacia(&dada)&& flag==0)
    {
        if(tope(&dada)!=elemento)
        {
            apilar(&aux, desapilar(&dada));
        }
        else
        {
            flag=1;
        }
    }

    while(!pilavacia(&aux))
    {
        apilar(&dada, desapilar(&aux));
    }

    if (flag==0)
    {
        printf("el dato %d no se encuentra en la pila", elemento);
    }
    else  /// flag ==1
    {
        printf("el dato %d si se encuentra en la pila", elemento);
    }



    return 0;
}
