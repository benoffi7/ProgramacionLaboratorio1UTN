/**
10. Comparar las pilas A y B, evaluando si son completamente iguales (en cantidad de elementos,
valores que contienen y posición de los mismos). Mostrar por pantalla el resultado.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila a, b, auxA, auxB;
    inicpila(&a);
    inicpila(&b);
    inicpila(&auxA);
    inicpila(&auxB);

    char opcion;

    /// Cargo la pila A
    do{
        printf("\n Carga de pila A \n");
        leer(&a);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    /// Cargo la pila B
    do{
        printf("\n Carga de pila B \n");
        leer(&b);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    /// Muestro el contenido de las pilas
    printf("\n\n Pila A ....... ");
    mostrar(&a);

    printf("\n\n Pila B ....... ");
    mostrar(&b);

    /// Recorro las dos pilas juntas mientras tengan datos y los topes sean iguales
    while((!pilavacia(&a))&&(!pilavacia(&b))&&(tope(&a)==tope(&b))){
        apilar(&auxA, desapilar(&a));
        apilar(&auxB, desapilar(&b));
    }

    /// si las dos pilas se vaciaron juntas es que son iguales
    if((pilavacia(&a))&&(pilavacia(&b))){
        printf("\n\n Las dos pilas son iguales");
    }
    else{
        printf("\n\n Las dos pilas NO son iguales");
    }

    /// vuelvo a poner los datos en sus pilas originales
    while(!pilavacia(&auxA)){
        apilar(&a, desapilar(&auxA));
    }

    while(!pilavacia(&auxB)){
        apilar(&b, desapilar(&auxB));
    }

    printf("Hello world!\n");
    return 0;
}
