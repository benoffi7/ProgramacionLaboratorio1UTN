#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila pila1, aux, aux1;
    inicpila(&pila1);
    inicpila(&aux);
    inicpila(&aux1);

    int temperatura;
    char opcion;

    /// Carga la pila con 10 valores aleatorios menores a 10
    for(int i=0;i<10;i++){
        apilar(&pila1, rand()%10);
    }

    /// Ciclo de carga con intervención del usuario
    do{
        printf("\n Ingrese la temperatura: ");
        scanf("%d", &temperatura);

        apilar(&pila1, temperatura);

        printf("\n Cualquier tecla para continuar - ESC para salir ");
        opcion=getch();
        system("cls");
    }
    while(opcion!=27);

    printf("\n Pila pila1");
    mostrar(&pila1);

    while(!pilavacia(&pila1)){
        apilar(&aux, desapilar(&pila1));
        if(!pilavacia(&pila1)){
            apilar(&aux1, desapilar(&pila1));
        }
    }

    printf("\n Pila pila1");
    mostrar(&pila1);

    printf("\n Pila aux");
    mostrar(&aux);

    printf("\n Pila aux1");
    mostrar(&aux1);

    printf("Hello world!\n");
    return 0;
}
