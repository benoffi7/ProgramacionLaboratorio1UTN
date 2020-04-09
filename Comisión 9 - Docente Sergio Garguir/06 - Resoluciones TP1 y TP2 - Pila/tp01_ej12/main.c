/**
12. Suponiendo la existencia de una pila MODELO (vacía o no),
eliminar de la pila DADA todos los elementos que existan en MODELO.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila modelo, dada, auxDada, basura, auxModelo;
    inicpila(&dada);
    inicpila(&modelo);
    inicpila(&auxDada);
    inicpila(&basura);
    inicpila(&auxModelo);

    char opcion;

    /// Cargo la pila Modelo
    for(int i=0;i<20;i++){
        apilar(&modelo, rand()%100);
    }

    do{
        leer(&modelo);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    /// Cargo la pila Dada
    for(int i=0;i<20;i++){
        apilar(&dada, rand()%100);
    }

    /// Muestro las pilas
    printf("\n\n Pila Modelo ....... ");
    mostrar(&modelo);

    printf("\n\n Pila Dada ....... ");
    mostrar(&dada);

    while(!pilavacia(&modelo)){                     /// mientras modelo no esté vacía
        while(!pilavacia(&dada)){                   /// mientras dada no esté vacía
            if(tope(&modelo) == tope(&dada)){       /// comparo si son iguales los topes de modelo y dada
                apilar(&basura, desapilar(&dada));  /// en caso verdadero desapilo dada en basura
            }
            else{                                   /// sino, en caso de ser distintos
                apilar(&auxDada, desapilar(&dada)); /// desapilo dada en auxDada
            }
        }                                           /// termina este ciclo while cuando dada se vacíe

        while(!pilavacia(&auxDada)){                /// paso todos los datos de auxDada a dada
            apilar(&dada, desapilar(&auxDada));
        }
        apilar(&auxModelo, desapilar(&modelo));     /// desapilo modelo en auxModelo
    }                                               /// este while termina cuando modelo no tenga datos

    while(!pilavacia(&auxModelo)){
        apilar(&modelo, desapilar(&auxModelo));     /// vuelvo los datos de auxModelo a modelo
    }

    /// muestro el contenido de las pilas
    printf("\n\n Pila Modelo ....... ");
    mostrar(&modelo);

    printf("\n\n Pila Dada ....... ");
    mostrar(&dada);


    printf("Hello world!\n");
    return 0;
}
