/**
11. Suponiendo la existencia de una pila MODELO que no esté vacía,
eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO.
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila modelo, dada, auxDada, basura;
    inicpila(&dada);
    inicpila(&modelo);
    inicpila(&auxDada);
    inicpila(&basura);

    char opcion;

    /// Cargo la pila Modelo
    for(int i=0;i<40;i++){
        apilar(&modelo, rand()%10);
    }

    do{
        leer(&modelo);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    /// Cargo la pila Dada
    for(int i=0;i<40;i++){
        apilar(&dada, rand()%10);
    }

    /// Muestro el contenido de las dos pilas
    printf("\n\n Pila Modelo ....... ");
    mostrar(&modelo);

    printf("\n\n Pila Dada ....... ");
    mostrar(&dada);

    if(!pilavacia(&modelo)){                /// Si modelo tiene datos puedo trabajar
        while(!pilavacia(&dada)){           /// Mientras la pila dada no esté vacía
            if(tope(&modelo) == tope(&dada)){ /// Comparto los topes de modelo con el de dada y si son iguales
                apilar(&basura, desapilar(&dada)); /// desapilo dada en la pila basura
            }
            else{                                   /// si no son iguales
                apilar(&auxDada, desapilar(&dada)); /// desapilo dada en auxDada
            }
        }                                           /// termina el ciclo while cuando se vacíe dada

        while(!pilavacia(&auxDada)){                /// vuelvo todos los datos que hay en auxDada a dada
            apilar(&dada, desapilar(&auxDada));
        }
    }

    /// Muestro el contenido de las pilas
    printf("\n\n Pila Modelo ....... ");
    mostrar(&modelo);

    printf("\n\n Pila Dada ....... ");
    mostrar(&dada);


    printf("Hello world!\n");
    return 0;
}
