#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Realizar un algoritmo que permita realizar 3 veces lo siguiente:
    Ingresar 2 numeros calcular su suma e informar el resultado.*/

    int i = 0, valorIngresado, sumaTotal = 0;

    while(i<3)
    {
        int j = 0;
        for(j=0; j<2; j++)
        {
            printf("Ingrese nro %d\n", j+1);
            fflush(stdin);
            scanf("%d", &valorIngresado);
            sumaTotal += valorIngresado;
        }
        printf("El resultado de la suma de los dos nros es: %d\n\n", sumaTotal);
        sumaTotal = 0;
        i++;
    }

    return 0;
}
