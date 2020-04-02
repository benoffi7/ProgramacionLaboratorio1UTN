/**
5. Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA
contenga los elementos cargados originalmente en ella, pero en orden inverso.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila dada, aux1, aux2;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    char opcion;

    /// Ciclo de carga de datos continúa mientras no presione la tecla ESC
    do{
        leer(&dada);

        printf("\n\n ESC para salir ........... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    /// FIN CICLO DE CARGA

    printf("\n\n Pila dada ....... ");
    mostrar(&dada);


    /// Paso todo el contenido de la pila dada a la pila aux1
    while(!pilavacia(&dada)){
        apilar(&aux1, desapilar(&dada));
    }

    /// Paso todo el contenido de la pila aux1 a la pila aux2
    while(!pilavacia(&aux1)){
        apilar(&aux2, desapilar(&aux1));
    }

    /// Paso todo el contenido de la pila aux2 a la pila dada
    while(!pilavacia(&aux2)){
        apilar(&dada, desapilar(&aux2));
    }

    printf("\n\n Pila dada ....... ");
    mostrar(&dada);

    return 0;
}
