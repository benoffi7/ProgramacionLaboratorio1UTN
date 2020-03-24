#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;

    printf("Bienvenidos al mundo de C\n");

    printf("El valor de la variable x es %d\n", x);

    printf("Introduzca un valor entero: ");

    scanf("%d", &x);

    printf("\nEl valor que introdujo fue %d", x);

    return 0;
}
