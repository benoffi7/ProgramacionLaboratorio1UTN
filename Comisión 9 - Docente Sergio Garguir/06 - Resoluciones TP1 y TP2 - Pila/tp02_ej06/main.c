/**
6.	Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que la segunda
pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de ordenación por selección.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila dada, aux, menor, ordenada;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&menor);
    inicpila(&ordenada);

    char opcion;

    /// Cargo la pila de manera aleatoria
    for(int i=0;i<20;i++){
        apilar(&dada, rand()%100);
    }

    /// Ciclo de carga
    do{
        printf("\n\n Cargando pila dada\n");
        leer(&dada);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    printf("\n\n Pila dada");
    mostrar(&dada);

    /// este es el proceso de buscar menor cambiando el if por while
    while(!pilavacia(&dada)){
        apilar(&menor, desapilar(&dada));

        while(!pilavacia(&dada)){
            if(tope(&dada)<tope(&menor)){
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&dada));
            }
            else{
                apilar(&aux, desapilar(&dada));
            }
        }

        while(!pilavacia(&aux)){
            apilar(&dada, desapilar(&aux));
        }
    /// una vez encontrado el menor lo apilo en ordenada
        apilar(&ordenada, desapilar(&menor));
    }

    printf("\n\n Pila dada");
    mostrar(&dada);

    printf("\n\n Pila Ordenada");
    mostrar(&ordenada);

    return 0;
}
