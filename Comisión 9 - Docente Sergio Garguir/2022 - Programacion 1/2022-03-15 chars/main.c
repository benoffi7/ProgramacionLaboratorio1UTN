#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    char letra;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    printf("Ingrese un caracter: ");
    fflush(stdin);
    scanf("%c", &letra);

    printf("\nEl numero es %d y la letra es %c\n", num, letra);

    return 0;
}
