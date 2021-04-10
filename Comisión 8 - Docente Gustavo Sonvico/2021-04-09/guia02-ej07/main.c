#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

/**
7.	Determinar si un elemento buscado está dentro de una pila.
Al encontrarlo, finalizar la búsqueda.
*/

int main()
{
    srand(time(NULL));
   Pila dada, auxDada;
   inicpila(&dada);
   inicpila(&auxDada);

   int flag=0;
   int nota;
   int aBuscar;
   char opcion;

   for(int i=0; i<20; i++){
        apilar(&dada, rand()%100);
   }

    do{
        printf("\n Ingrese una nota: ");
        scanf("%d", &nota);

        apilar(&dada, nota);

        printf("\n ESC para salir o cualquier tecla para continuar ");
        opcion=getch();
        system("cls");
    }
    while(opcion!=27);

    printf("\n Pila dada");
    mostrar(&dada);

    printf("\n Ingrese una nota a buscar en la coleccion: ");
    scanf("%d", &aBuscar);

    while(!pilavacia(&dada) && flag==0){
        if(tope(&dada)==aBuscar){
            flag=1;
        }else{
            apilar(&auxDada, desapilar(&dada));
        }
    }

    if(flag==1){
        printf("\n El nro %d se encuentra en la pila", aBuscar);
    }else{
        printf("\n El nro %d NO se encuentra en la pila", aBuscar);
    }


    return 0;
}
