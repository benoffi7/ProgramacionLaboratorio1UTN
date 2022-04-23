#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num1=0;
    int num2=0;
    int num3=0;

    int sumaDeLosValores=0;

    printf("Hola mundo!\n");
    printf("Estimado usr, introduzca tres valores numericos: ");

    /// lectura de datos por consola con intervencion del usr
    scanf("%i", &num1);
    scanf("%i", &num2);
    scanf("%i", &num3);

    if(num1>num2 & num1>num3 & condiciones & condiciones)
    {
        printf("El valor mayor es %d", num1);
    }
    else
    {
        if(num2 > num1 && num2> num3)
        {
            printf("El valor mayor es %d", num2);
        }
        else
        {
            printf("El valor mayor es %d", num3);
        }
    }
    return 0;
}
