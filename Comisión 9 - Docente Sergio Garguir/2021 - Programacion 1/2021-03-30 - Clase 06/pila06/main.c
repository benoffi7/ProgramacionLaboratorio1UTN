#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
6. Pasar el primer elemento (tope) de la pila DADA a su última posición (base), dejando los restantes elementos en el mismo orden.
*/

int main()
{
    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);

    int top;
    int nro;
    char opcion;

    /// Ciclo de ingreso de datos
    do{
        printf("\n Ingrese un nro: ");
        scanf("%d", &nro);
        apilar(&dada, nro);
        printf("\n Cualquier tecla para continuar - ESC para salir ");
        opcion=getch();
        system("cls");
    }
    while(opcion!=27);

    printf("\n Pila dada ");
    mostrar(&dada);
    /// Guardo el tope de dada en una variable auxiliar de tipo int
    if(!pilavacia(&dada)){
        top = desapilar(&dada);
    }
    /// paso los datos de la pila dada a la pila aux
    while(!pilavacia(&dada)){
        apilar(&aux, desapilar(&dada));
    }
    /// apilo en dada el contenido de la varialbe top
    apilar(&dada, top);
    /// paso el contenido de la pila aux a dada
    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }

    printf("\n Pila dada ");
    mostrar(&dada);

    printf("Hello world!\n");
    return 0;
}
