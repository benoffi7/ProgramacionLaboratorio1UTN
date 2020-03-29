#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///Leer 15 numeros negativos y convertirlos a positivos e imprimir dichos numeros.

    int contador4 = 0;
    int numero4;
    int positivo;

    for(contador4=0; contador4 <15; contador4++)
    {
        printf("Ingrese numero %d\n", contador4+1);
        fflush(stdin);
        scanf("%d", &numero4);
        while(numero4 >= 0)
        {
            printf("Ingrese un numero NEGATIVO!\n");
            fflush(stdin);
            scanf("%d",&numero4);
        }

        positivo = (-1) * numero4;

        printf("El numero en positivo es: %d\n", positivo);
    }

    return 0;
}
