#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila pilita, pilota;
    inicpila(&pilita);
    inicpila(&pilota);
    char opcion;

    do{
        leer(&pilita);
        printf("\n Cualquier tecla para continuar o n para salir ");
        fflush(stdin);
        scanf("%c",&opcion);
    }while(opcion!='n');

    printf("\n Pila pilita ");
    mostrar(&pilita);

    while(!pilavacia(&pilita)){
        apilar(&pilota, desapilar(&pilita));
    }

    printf("\n Pila pilita ");
    mostrar(&pilita);
    printf("\n Pila pilota");
    mostrar(&pilota);


    return 0;
}
