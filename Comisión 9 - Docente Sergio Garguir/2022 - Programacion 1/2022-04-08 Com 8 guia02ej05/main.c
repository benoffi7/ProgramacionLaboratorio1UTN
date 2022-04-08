#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

int main()
{
    Pila ordenada, datos, aux;

    inicpila(&ordenada);
    inicpila(&datos);
    inicpila(&aux);

    int num;
    char opcion;

    for(int i=0;i<7;i++){
        apilar(&ordenada, i);
    }

    do{
        printf("\n Ingrese un numero para insertar en la pila: ");
        scanf("%d", &num);

        apilar(&datos, num);

        printf("\n\n ESC para salir o cualquier tecla para continuar");
        opcion = getch();
        system("cls");
    }while(opcion != 27);

    printf("\n <<<<<<<<<<<<<< Pila Ordenada >>>>>>>>>>>>>>>>");
    mostrar(&ordenada);
    printf("\n <<<<<<<<<<<<<< Pila Datos >>>>>>>>>>>>>>>>");
    mostrar(&datos);

    if(!pilavacia(&datos)){
        while(!pilavacia(&ordenada) && tope(&ordenada) > tope(&datos)){
            apilar(&aux, desapilar(&ordenada));
        }

        apilar(&ordenada, desapilar(&datos));

        while(!pilavacia(&aux)){
            apilar(&ordenada, desapilar(&aux));
        }
    }

    printf("\n <<<<<<<<<<<<<< Pila Ordenada >>>>>>>>>>>>>>>>");
    mostrar(&ordenada);
    printf("\n <<<<<<<<<<<<<< Pila Datos >>>>>>>>>>>>>>>>");
    mostrar(&datos);

    return 0;
}
