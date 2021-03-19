#include <stdio.h>
#include <stdlib.h>
#define MAX 100


int main()
{
    int numero1;
    int numero2;
    printf("Ingrese numero1\n");
    scanf("%i",&numero1);
    printf("Ingrese numero 2\n");
    scanf("%i",&numero2);
    if (numero1 >0 && numero2 >0)
    {
        printf("Los numeros  son positivos\n");
        if (numero1 <=MAX && numero2 <=MAX)
        {
            printf("Los numeros estan entre 1 y 100 incluido\n");
            if (numero1 > numero2)
            {
                printf("El numero1 es mayor al numero2\n");
            }
            else
            {
                if (numero1 < numero2)
                {
                    printf("El numero 2 es mayor al numero1\n");
                }
                else
                {
                    printf("Los numeros son iguales\n");
                }
            }
        }
    }
    return 0;
}



//SI numero1 >0 Y numero2 > 0 entonces...
