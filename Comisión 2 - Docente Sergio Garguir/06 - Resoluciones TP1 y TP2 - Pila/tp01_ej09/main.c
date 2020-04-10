/**
9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.
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
    Pila a, b, auxA, auxB;
    inicpila(&a);
    inicpila(&b);
    inicpila(&auxA);
    inicpila(&auxB);

    char opcion;

    for(int i=0;i<40;i++){
        apilar(&a, rand()%10);
    }

    do{
        printf("\n\n Cargando pila A ....... \n");
        leer(&a);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
    }while(opcion!=ESC);

    for(int i=0;i<40;i++){
        apilar(&b, rand()%10);
    }

    do{
        printf("\n\n Cargando pila B ....... \n");
        leer(&b);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
    }while(opcion!=ESC);

    while((!pilavacia(&a))&&(!pilavacia(&b))){  /// le saco un elemento a cada pila en el mismo ciclo
        apilar(&auxA, desapilar(&a));
        apilar(&auxB, desapilar(&b));
    }

    if((pilavacia(&a))&&(pilavacia(&b))){    /// si las pilas se vaciaron es que tenían la misma cantidad de elementos
        printf("\n\n Las Pilas tienen la misma cantidad de elementos");
    }
    else if(!pilavacia(&a)){  /// sino, si la pila A no se vació es que tiene más elemntos que la pila B
        printf("\n\n La Pila A tiene mas elementos que la pila B");
    }
    else{  /// y sino la pila B es la que tiene más elementos
        printf("\n\n La Pila B tiene mas elementos que la pila A");
    }
    /// Vuelvo las pilas al estado original
    while(!pilavacia(&auxA)){
        apilar(&a, desapilar(&auxA));
    }

    while(!pilavacia(&auxB)){
        apilar(&b, desapilar(&auxB));
    }

    return 0;
}
