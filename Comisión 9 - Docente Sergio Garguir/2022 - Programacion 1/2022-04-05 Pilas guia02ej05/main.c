#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

int main()
{
    Pila ordenada, aux, datos;
    inicpila(&ordenada);
    inicpila(&aux);
    inicpila(&datos);

    int dato;
    char opcion;

    for(int i=0; i<15; i++){
        apilar(&ordenada, i);
    }

    do{
        printf("\n Ingrese el dato a insertar: ");
        scanf("%d", &dato);

        apilar(&datos, dato);

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion = getch();

    }while(opcion != 27);

    printf("\n <<<<<<<<<<<<<< Pila Ordenada >>>>>>>>>>>>> ");
    mostrar(&ordenada);
    printf("\n <<<<<<<<<<<<<< Pila Datos >>>>>>>>>>>>> ");
    mostrar(&datos);

    if(!pilavacia(&datos)){
        while(!pilavacia(&ordenada)
              && tope(&ordenada) > tope(&datos)){
            apilar(&aux, desapilar(&ordenada));
        }

        apilar(&ordenada, desapilar(&datos));

        while(!pilavacia(&aux)){
            apilar(&ordenada, desapilar(&aux));
        }
    }

    printf("\n <<<<<<<<<<<<<< Pila Ordenada >>>>>>>>>>>>> ");
    mostrar(&ordenada);

    return 0;
}
