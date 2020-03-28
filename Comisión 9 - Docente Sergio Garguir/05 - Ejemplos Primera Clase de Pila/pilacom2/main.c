#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/**
Pila
inicpila(&pila);
tope(&pila); retorna el tope pero no lo saca de la pila dato de tipo int
desapilar(&pila); retorna el tope y lo saca de la pila
apilar(&pila,dato_tipo_int); /// int nro; 2; 10; /// tope(&otra_pila) /// const int nro = 100; /// desapilar(&pila)
leer(&pila);
mostrar(&pila);
pilavacia(&pila); /// retorna 0 - si tiene datos / 1 - si está vacia
*/



int main()
{
    int entero = 10;
    char opcion;
    Pila pilita, pilota, destino;
    inicpila(&pilita);
    inicpila(&pilota);
    inicpila(&destino);

    apilar(&pilita, 2);
    apilar(&pilota, entero);
    apilar(&pilita, tope(&pilota));

    printf("\n Despues de la primer carga");
    printf("\n Pila - pilita:");
    mostrar(&pilita);
    printf("\n Pila - pilota:");
    mostrar(&pilota);
    printf("\n Pila - destino:");
    mostrar(&destino);

    do{
        leer(&pilita);

        printf("\n Cualquier tecla para continuar o n para salir");
        fflush(stdin);
        scanf("%c",&opcion);
        system("cls");

    }while(opcion!='n');

    printf("\n Despues de la carga del usuario de pilita");
    printf("\n Pila - pilita:");
    mostrar(&pilita);
    printf("\n Pila - pilota:");
    mostrar(&pilota);
    printf("\n Pila - destino:");
    mostrar(&destino);

    while(!pilavacia(&pilita)){
        apilar(&destino,desapilar(&pilita));
    }
    printf("\n Despues de pasar el contenido de pilita a destino");
    printf("\n Pila - pilita:");
    mostrar(&pilita);
    printf("\n Pila - pilota:");
    mostrar(&pilota);
    printf("\n Pila - destino:");
    mostrar(&destino);

    while(!pilavacia(&destino)){

        apilar(&pilita,desapilar(&destino));
        if(!pilavacia(&destino)){
            apilar(&pilita,desapilar(&destino));
        }
    }



    printf("Hello world!\n");
    return 0;
}
