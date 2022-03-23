#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    char opcion;
    int edad;
    int mayor;
    Pila edades, aux;
    inicpila(&edades);
    inicpila(&aux);

    do{
        printf("\n Ingrese una edad: ");
        scanf("%d", &edad);

        apilar(&edades, edad);

        printf("ESC para salir o cualquier tecla para continuar");
        opcion = getch();
    }while(opcion != ESC);

    while(!pilavacia(&edades)){
        mayor = tope(&edades);
        if(mayor > 18){
            printf("\n %d", mayor);
        }
        apilar(&aux, desapilar(&edades));

        if(!pilavacia(&edades)){
            apilar(&aux, desapilar(&edades));
        }
    }

    mostrar(&edades);
    mostrar(&aux);

    while(!pilavacia(&aux)){
        apilar(&edades, desapilar(&aux));
    }

    return 0;
}
