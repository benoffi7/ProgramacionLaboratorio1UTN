#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

/**
6.	Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a
otra de forma tal que la segunda pila quede ordenada de mayor (tope) a menor (base).
Esto se llama método de ordenación por selección.
*/

int main()
{
    srand(time(NULL));
   Pila dada, auxDada, menor, ordenada;
   inicpila(&dada);
   inicpila(&auxDada);
   inicpila(&menor);
   inicpila(&ordenada);

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

    while(!pilavacia(&dada)){
        apilar(&menor, desapilar(&dada));

        while(!pilavacia(&dada)){
            if(tope(&dada)<tope(&menor)){
                apilar(&auxDada, desapilar(&menor));
                apilar(&menor, desapilar(&dada));
            }else{
                apilar(&auxDada, desapilar(&dada));
            }
        }
        apilar(&ordenada, desapilar(&menor));

        while(!pilavacia(&auxDada)){
            apilar(&dada, desapilar(&auxDada));
        }
    }

    printf("\n Pila dada");
    mostrar(&dada);

    printf("\n Pila menor");
    mostrar(&menor);

    printf("\n Pila ordenada");
    mostrar(&ordenada);

    return 0;
}
