/**
8.	Eliminar un elemento de una pila. El eliminarlo, finalizar
el recorrido y dejar el resto en el mismo orden.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila dada, aux, basura;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&basura);

    int aBorrar;
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
    printf("\n\n Ingrese un numero a eliminar en la pila: ");
    scanf("%d",&aBorrar);

    /// recorro la pila mientras tenga datos y el elemento no sea igual al tope
    while((!pilavacia(&dada))&&(tope(&dada)!=aBorrar)){
        apilar(&aux, desapilar(&dada));
    }

    /// si la pila no se vació significa que encontré el elemento a eliminar y está en el tope, entonces lo desapilo
    if(!pilavacia(&dada)){
        apilar(&basura, desapilar(&dada));
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }

    printf("\n\n Pila dada");
    mostrar(&dada);

    printf("\n\n\n\n");

    return 0;
}
