#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int main()
{
    Pila MODELO, DADA, AUX, DESCARTE;
    char control='s';

    inicpila(&MODELO);
    inicpila(&DADA);
    inicpila(&AUX);
    inicpila(&DESCARTE);

    apilar(&MODELO,2);
    apilar(&MODELO,4);
    apilar(&MODELO,8);
    apilar(&MODELO,6);

    while (control=='s' || control=='S')
    {
        leer(&DADA);

        printf("\Para continuar presione s ");
        fflush(stdin);
        scanf("%c",&control);
    }

    printf("\nPila sin cambios: ");
    mostrar(&DADA);

    while(!pilavacia(&MODELO))
    {

        while(!pilavacia(&DADA))
        {
            if(tope(&MODELO)==tope(&DADA))
                apilar(&DESCARTE,desapilar(&DADA));
            else
                apilar(&AUX,desapilar(&DADA));
        }

        while(!pilavacia(&AUX))
            apilar(&DADA,desapilar(&AUX));

        apilar(&DESCARTE,desapilar(&MODELO));

    }

    printf("\nPila modificada: ");
    mostrar(&DADA);


    return 0;
}
