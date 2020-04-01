#include <stdio.h>
#include <stdlib.h>

int main()

{
    /*Realizar un algoritmo que permita ingresar 5 numeros e informe cuantos
    numeros ingresados son mayores a cero y cuantos menores a cero.*/

    int datos, contadorfor = 0;
    int mayores = 0, menores = 0;

    for(contadorfor = 0; contadorfor < 5; contadorfor++)
    {
        printf("Ingrese valor %d\n", contadorfor+1);
        fflush(stdin);
        scanf("%d", &datos);
        if(datos >= 0)
        {
            mayores++;
        }
        else
        {
            menores++;
        }
    }

    printf("En total se ingresaron %d numeros mayores a 0 y %d numeros menores a 0\n", mayores, menores);

    return 0;
}
