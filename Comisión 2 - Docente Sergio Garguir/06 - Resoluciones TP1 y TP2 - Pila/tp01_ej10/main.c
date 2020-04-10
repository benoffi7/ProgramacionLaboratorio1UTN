/**
10. Comparar las pilas A y B, evaluando si son completamente iguales
(en cantidad de elementos, valores que contienen y posición de los mismos).
Mostrar por pantalla el resultado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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

    do{
        printf("\n\n Cargando pila A ....... \n");
        leer(&a);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    do{
        printf("\n\n Cargando pila B ....... \n");
        leer(&b);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);


    printf("\n\n Pila A ....... ");
    mostrar(&a);

    printf("\n\n Pila B ....... ");
    mostrar(&b);
/**
    recorro las dos pilas a la vez, comparando sus topes como otra condición del ciclo para que el ciclo corte si los
    topes no son iguales (ya no me interesa seguir recorriendo porque sé que son distintas)
*/
    while((!pilavacia(&a))&&(!pilavacia(&b))&&(tope(&a)==tope(&b))){
        apilar(&auxA, desapilar(&a));
        apilar(&auxB, desapilar(&b));
    }
/// si se vaciaron es poque son iguales
    if((pilavacia(&a))&&(pilavacia(&b))){
        printf("\n\n Las Pilas son IGUALES");
    }
    else{
        printf("\n\n Las Pilas son DISTINTAS");
    }
/// vuelvo las pilas a sus estado original
    while(!pilavacia(&auxA)){
        apilar(&a, desapilar(&auxA));
    }

    while(!pilavacia(&auxB)){
        apilar(&b, desapilar(&auxB));
    }

    printf("\n\n Pila A ....... ");
    mostrar(&a);

    printf("\n\n Pila B ....... ");
    mostrar(&b);


    return 0;
}
