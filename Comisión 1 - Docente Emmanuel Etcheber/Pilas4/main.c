#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

int main()
{
    Pila ORIGEN,DESTINO, AUX;
    inicpila(&ORIGEN);
    inicpila(&DESTINO);
    inicpila(&AUX);
    char control = 's';

    while (control=='s')
    {
        printf("\n");
        leer(&ORIGEN);

        printf("Para continuar presione s ");
        fflush(stdin);
        scanf("%c",&control);
    }

    while(!pilavacia(&ORIGEN))
    {
        apilar(&AUX,desapilar(&ORIGEN));
    }
    while(!pilavacia(&AUX))
    {
        apilar(&DESTINO,desapilar(&AUX));
    }
    while(!pilavacia(&DESTINO))
    {
        apilar(&ORIGEN,desapilar(&DESTINO));
    }

    printf("\nPila ORIGEN: ");
    mostrar(&ORIGEN);
    printf("\nPila DESTINO: ");
    mostrar(&DESTINO);
    return 0;
}
