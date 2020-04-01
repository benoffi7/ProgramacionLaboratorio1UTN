#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

int main()
{
    Pila ejemplo;
    char control = 's';
    int numero;
    inicpila(&ejemplo);

    while (control == 's')
    {
        leer(&ejemplo);

        printf("Presione s para seguir ingresando \n");
        fflush(stdin);
        scanf("%c", &control);
    }

    numero = tope(&ejemplo);

    printf("\n\n El valor es: %d",numero);

    mostrar(&ejemplo);
    return 0;
}
