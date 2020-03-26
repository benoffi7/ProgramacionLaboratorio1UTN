#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num; /// Declaro una variable de tipo int sin inicializar

    printf("\nIngrese un numero: ");
    scanf("%d",&num);

    if(num>0)
    {
        printf("El numero %d es mayor a 0",num);
    }
    else
    {
        printf("El numero %d es menor a 0",num);
    }


    return 0;
}
