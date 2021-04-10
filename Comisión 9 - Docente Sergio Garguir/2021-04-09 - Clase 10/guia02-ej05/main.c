#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

/**
5.	Insertar un elemento en una pila ordenada de menor (tope)
a mayor (base) de forma tal que se conserve el orden.
(sin variables, solo pilas)
*/

int main()
{
    Pila ordenada, elemento, aux;
    inicpila(&ordenada);
    inicpila(&elemento);
    inicpila(&aux);

    int nro;
    char opcion;

    for(int i=15;i>0;i--){
        apilar(&ordenada, i);
    }

    printf("\n Pila Ordenada");
    mostrar(&ordenada);

    do{
        printf("\n Ingrese un dato ordenado: ");
        scanf("%d", &nro);

        apilar(&ordenada, nro);

        printf("\n ESC para salir o cualquier tecla para continuar ");
        opcion=getch();
        system("cls");
    }
    while(opcion!=27);

    printf("\n Ingrese un dato a insertar: ");
    scanf("%d", &nro);

    apilar(&elemento, nro);

    if(!pilavacia(&elemento)){
        while(!pilavacia(&ordenada) && tope(&ordenada)<tope(&elemento)){
            apilar(&aux, desapilar(&ordenada));
        }
        apilar(&ordenada, desapilar(&elemento));
        while(!pilavacia(&aux)){
            apilar(&ordenada, desapilar(&aux));
        }
    }

    printf("\n Pila Ordenada");
    mostrar(&ordenada);

    return 0;
}
