/**
8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    srand(time(NULL));  /// Inicializo la semilla para generar numeros aleatorios
    Pila mazo, j1, j2;
    inicpila(&mazo);
    inicpila(&j1);
    inicpila(&j2);

    int limite;
    char opcion;

    limite = rand()%50+1;  /// En la variable limite almaceno de manera aleatoria la cantidad de elementos que va a tener la pila
    for(int i=0;i<limite;i++){
        apilar(&mazo, rand()%31);  /// apilo numeros aleatorios entre 0 y 30 en la pila DADA
    }

    do{
        leer(&mazo);

        printf("\n\n ESC para salir ... ");
        opcion = getch();
    }while(opcion!=ESC);

    printf("\n Pila Mazo .....");
    mostrar(&mazo);

    while(!pilavacia(&mazo)){    /// reparto los elementos de MAZO a J1 y J2 en el mismo ciclo
        apilar(&j1, desapilar(&mazo));
        if(!pilavacia(&mazo)){     /// compruebo que MAZO tenga elementos antes de desapilar por segunda vez
            apilar(&j2, desapilar(&mazo));
        }
    }

    printf("\n Pila Mazo .....");
    mostrar(&mazo);

    printf("\n Pila j1 .....");
    mostrar(&j1);

    printf("\n Pila j2 .....");
    mostrar(&j2);

    printf("Hello world!\n");
    return 0;
}
