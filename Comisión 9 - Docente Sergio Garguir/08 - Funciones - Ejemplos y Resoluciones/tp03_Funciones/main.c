#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"
#include "fPila.h"


int main()
{
    srand(time(NULL));
    Pila temperaturas, horas, aux, tempOrd;
    inicpila(&temperaturas);
    inicpila(&horas);
    inicpila(&aux);
    inicpila(&tempOrd);

    cargaPila(&temperaturas,"Ingrese una temperatura: ");
    cargaPilaRandom(&temperaturas,40,-10,50);
    printf("\n Pila temperaturas\n");
    mostrar(&temperaturas);
    system("pause");

    //ordenaPorSeleccion(temperaturas, &tempOrd);
    ordenaPorSeleccion(temperaturas, &tempOrd);

    printf("\n Pila temperaturas Ordenada\n");
    mostrar(&tempOrd);
    system("pause");
    cargaPila(&horas, "Ingrese una hora: ");
    printf("\n Pila horas\n");
    mostrar(&horas);

    copiaPila(temperaturas, &aux);
    printf("\n Pila temperaturas\n");
    mostrar(&temperaturas);
    printf("\n Pila aux\n");
    mostrar(&aux);

    return 0;
}
