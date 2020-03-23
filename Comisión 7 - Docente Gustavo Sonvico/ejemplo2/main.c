#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int valor1=0;
    int valor2=0;

    printf("Ingrese dos valores enteros: \n");

    scanf("%d", &valor1);
    scanf("%d", &valor2);

    if(valor1<valor2)
    {
        printf("El valor %d es menor al valor %d",valor1, valor2);
    }
    else
    {
        printf("El valor %d es menor al valor %d",valor2, valor1);
    }



    return 0;
}
