#include "Librerias/pila.h"
#include <windows.h>

void borrador()
{
    Pila pila;
    inicpila(&pila);

    int valor = 0;
    int i = 0;

    while(i < 10)
    {
        scanf("%d", &valor);
        system("cls");

        apilar(&pila, valor);

        mostrar(&pila);

        Sleep(500);
        i++;
    }

    while(!pilavacia(&pila))
    {
        desapilar(&pila);
        system("cls");

        mostrar(&pila);

        Sleep(500);
    }
}
