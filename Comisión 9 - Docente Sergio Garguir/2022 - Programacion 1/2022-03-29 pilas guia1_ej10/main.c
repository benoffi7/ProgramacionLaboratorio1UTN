#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESCAPE 27

int main()
{
    Pila a;
    Pila b;
    Pila auxA;
    Pila auxB;

    inicpila(&a);
    inicpila(&b);
    inicpila(&auxA);
    inicpila(&auxB);

    int num;
    char opcion;

    do{
        printf("\n Ingrese un numero para la pila a: ");
        scanf("%d", &num);

        apilar(&a, num);
        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion = getch();
    }while(opcion!=ESCAPE);  /// }while(opcion!=ESC);

    do{
        printf("\n Ingrese un numero para la pila b: ");
        scanf("%d", &num);

        apilar(&b, num);
        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion = getch();
    }while(opcion!=ESCAPE);  /// }while(opcion!=ESC);

    printf("\n Pila a");
    mostrar(&a);
    printf("\n Pila b");
    mostrar(&b);

    while(!pilavacia(&a) && !pilavacia(&b) && (tope(&a) == tope(&b))){
        apilar(&auxA, desapilar(&a));
        apilar(&auxB, desapilar(&b));
    }

    if(pilavacia(&a) && pilavacia(&b)){
        printf("\n Las dos son exactamente iguales");
    }else{
        printf("\n las dos pilas son distintas");
    }

    return 0;
}
