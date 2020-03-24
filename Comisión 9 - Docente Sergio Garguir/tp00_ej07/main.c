/**
Desarrolle un algoritmo que lea dos números y los imprima en forma ascendente
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    /// declaro e inicializo variables
    int nro1 = 0, nro2 = 0;

    /// Interactuo con el usuario
    printf("\n Ingrese un nro: ");
    scanf("%d", &nro1);
    printf("\n Ingrese otro nro: ");
    scanf("%d", &nro2);

    /// Proceso y muestro los datos

    if(nro1 <= nro2)
    {
        printf("\n %d", nro1);
        printf("\n %d", nro2);
    }
    else
    {
        printf("\n %d", nro2);
        printf("\n %d", nro1);
    }

    return 0;
}
