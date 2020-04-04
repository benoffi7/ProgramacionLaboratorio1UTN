/**
4.	Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables, solo pilas)
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila a, auxA;
    inicpila(&a);
    inicpila(&auxA);
    inicpila(&menor);
    int menor;

    char opcion;

    for(int i=0;i<15;i++){
        apilar(&a, rand()%100);
    }

    do{
        printf("\n\n Cargando pila A ....... \n");
        leer(&a);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);


    printf("\n\n Pila A ....... ");
    mostrar(&a);

    if(!pilavacia(&a)){
        apilar(&menor, desapilar(&a));
        while(!pilavacia(&a)){
            if(tope(&a)<tope(&menor)){
                apilar(&auxA, desapilar(&menor));
                apilar(&menor, desapilar(&a));
            }
            else{
                apilar(&auxA, desapilar(&a));
            }
        }
        while(!pilavacia(&auxA)){
            apilar(&a, desapilar(&auxA));
        }
    }


    printf("\n\n Pila A ....... ");
    mostrar(&a);

    printf("\n\n El menor elemento de la Pila es: %d", tope(&menor));
    return 0;
}
