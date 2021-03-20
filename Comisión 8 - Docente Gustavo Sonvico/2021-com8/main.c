#include <stdio.h>
#include <stdlib.h>

int main()
{
    int acum=0;
    int cont=0;
    float sueldo=0;
    char c;


    printf("\nIngrese un nro: ");
    scanf("%d",&cont);

    printf("\nEl numero ingresado es: %d", cont);

    printf("\nIngrese un nro real: ");
    scanf("%f",&sueldo);

    printf("\nEl numero real ingresado es: %.2f - %.3f", sueldo, sueldo);

    printf("\nIngrese una letra: ");
    fflush(stdin);
    scanf("%c",&c);

    printf("\nLa letra ingresada es: %c y su codigo ASCII es: %d", c, c);
    c++;
    system("pausa");
    printf("\nLa letra ingresada es: %c y su codigo ASCII es: %d", c, c);
    c = c + 1;
    system("pausa");
    printf("\nLa letra ingresada es: %c y su codigo ASCII es: %d", c, c);
    c = c + 1;
    system("pausa");
    printf("\nLa letra ingresada es: %c y su codigo ASCII es: %d", c, c);


    printf("\nHello world!\n");
    return 0;
}
