/**
2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila origen, destino;
    inicpila(&origen);
    inicpila(&destino);

    char opcion;

    /// Ciclo de carga de datos continúa mientras no presione la tecla ESC
    do{
        leer(&origen);

        printf("\n\n ESC para salir ........... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    /// FIN CICLO DE CARGA

    printf("\n\n Pila origen ....... ");
    mostrar(&origen);

    /// Paso todo el contenido de la pila origen a la pila destino
    while(!pilavacia(&origen)){
        apilar(&destino, desapilar(&origen));
    }

    printf("\n\n Pila origen ....... ");
    mostrar(&origen);

    printf("\n\n Pila destino ...... ");
    mostrar(&destino);

    return 0;
}
