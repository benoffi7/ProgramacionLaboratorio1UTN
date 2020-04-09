/**
7.	Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la búsqueda.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);

    int aBuscar;
    char opcion;

    for(int i=0;i<20;i++){
        apilar(&dada, rand()%100);
    }

    do{
        printf("\n\n Cargando pila dada\n");
        leer(&dada);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    printf("\n\n Pila dada");
    mostrar(&dada);

    /// Ingrese el elemento a buscar en la pila
    printf("\n\n Ingrese un numero a buscar en la pila: ");
    scanf("%d",&aBuscar);

    /// recorro la pila mientras tenga datos y el elemento no sea igual al tope
    while((!pilavacia(&dada))&&(tope(&dada)!=aBuscar)){
        apilar(&aux, desapilar(&dada));
    }

    /// si la pila no se vació significa que el elemento se encuentra en la pila
    if(!pilavacia(&dada)){
        printf("\n\n El elemento %d se encuentra en la pila", aBuscar);
    }
    else{
        printf("\n\n El elemento %d NO se encuentra en la pila", aBuscar);
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }


    printf("\n\n\n\n");

    return 0;
}
