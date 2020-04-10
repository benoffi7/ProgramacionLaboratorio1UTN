/**
5.	Insertar un elemento en una pila ordenada de menor
(tope) a mayor (base) de forma tal que se conserve el orden. (sin variables, solo pilas)
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila ordenada, aux, elemento;
    inicpila(&ordenada);
    inicpila(&aux);
    inicpila(&elemento);

    char opcion;
    /// Cargo la pila para que quede ordenada
    apilar(&ordenada,10);
    apilar(&ordenada,9);
    apilar(&ordenada,8);
    apilar(&ordenada,7);
    apilar(&ordenada,5);
    apilar(&ordenada,4);
    apilar(&ordenada,3);

    /// Apilo un elemento para insertar en ordenada
    apilar(&elemento, 6);
/**
    do{
        printf("\n\n Cargando pila ordenada\n");
        leer(&ordenada);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);
*/
    printf("\n\n Pila ordenada");
    mostrar(&ordenada);

    /// Recorro la pila ordenada buscando el lugar para insertar el elemento
    while((!pilavacia(&ordenada))&&(tope(&ordenada)<tope(&elemento))){
        apilar(&aux, desapilar(&ordenada));
    }

    /// Inserto el elemento
    apilar(&ordenada, desapilar(&elemento));

    /// regreso los datos de aux a ordenada
    while(!pilavacia(&aux)){
        apilar(&ordenada, desapilar(&aux));
    }

    printf("\n\n Pila ordenada");
    mostrar(&ordenada);
    return 0;
}
