/**
13. Suponiendo la existencia de una pila LÍMITE, pasar los elementos de la pila
DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES,
y los elementos que sean menores a la pila MENORES.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    srand(time(NULL));
    Pila dada, limite, mayores, menores;
    inicpila(&dada);
    inicpila(&limite);
    inicpila(&mayores);
    inicpila(&menores);

    char opcion;

    /// Cargamos la pila dada

    for(int i=0;i<15;i++){
        apilar(&dada, rand()%10);
    }

    do{
        printf("\n\n Cargando pila dada ....... \n");
        leer(&dada);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    /// Cargamos la pila limite

    for(int i=0;i<15;i++){
        apilar(&limite, rand()%10);
    }

    do{
        printf("\n\n Cargando pila limite  ....... \n");
        leer(&limite);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    printf("\n\n Pila dada ....... ");
    mostrar(&dada);

    printf("\n\n Pila limite ....... ");
    mostrar(&limite);

    while(!pilavacia(&dada)){
        if(tope(&dada)<tope(&limite)){
            apilar(&menores, desapilar(&dada));  /// si el tope de dada es menor al tope de limite lo paso a menores
        }
        else{
            apilar(&mayores, desapilar(&dada));  /// sino se enciende que el tope de dada es mayor o igual al tope de limite
        }                                        /// entonces lo paso a la pila mayores
    }

    printf("\n\n Pila dada ....... ");
    mostrar(&dada);

    printf("\n\n Pila limite ....... ");
    mostrar(&limite);

    printf("\n\n Pila menores ....... ");
    mostrar(&menores);

    printf("\n\n Pila mayores ....... ");
    mostrar(&mayores);

    printf("Hello world!\n");
    return 0;
}
