#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define IVA21 21
const int IVA10 = 10;

/**
4.	Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables, solo pilas)
*/

int main()
{
    srand(time(NULL));
   Pila dada, auxDada, menor;
   inicpila(&dada);
   inicpila(&auxDada);
   inicpila(&menor);

   int nota;
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

    if(!pilavacia(&dada)){
        apilar(&menor, desapilar(&dada));

        while(!pilavacia(&dada)){
            if(tope(&dada)<tope(&menor)){
                apilar(&auxDada, desapilar(&menor));
                apilar(&menor, desapilar(&dada));
            }else{
                apilar(&auxDada, desapilar(&dada));
            }
        }

        while(!pilavacia(&auxDada)){
            apilar(&dada, desapilar(&auxDada));
        }
    }

    printf("\n Pila dada");
    mostrar(&dada);

    printf("\n Pila menor");
    mostrar(&menor);
    return 0;
}
