#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Realizar un algoritmo que permita ingresar un numero e informe
    Numero mayor a cero o Numero menor o igual a cero segun corresponda.*/

    int numero = 0;

    printf("Ingrese un numero entero\n");
    scanf("%d",&numero);

    if(numero>0)
        {
            printf("El numero %d es mayor a cero\n", numero);
        }
    else
        {
            if (numero<0)
                printf("El numero %d es menor a cero\n", numero);
            else
                printf("El numero es igual a cero\n");
        }

}
