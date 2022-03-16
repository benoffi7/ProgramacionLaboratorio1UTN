#include <stdio.h>
#include <stdlib.h>

/** Se necesita sumar dos números leídos desde el teclado
(los ingresa el usuario) y mostrar el resultado por pantalla. */

#define PI 3.141592
#define NUMERO_DE_DOCUMENTO "Algo "

const int IVA = 21;

int main()
{
    int num1 = 0;
    int num2, total;
    int i=0;
    int dni;
    int Dni;

    printf("Ingrese el numero 1: ");
    scanf("%d", &num1); /// LEER()

    printf("Ingrese el numero 2: ");
    scanf("%d", &num2); /// LEER()

    total = ((num1 + num2) * PI)/2;

    system("cls");

    printf("El total es: %d", total);

    for(i=0;i<10;i++){
        printf("\n");
    }

    printf("\nvalor de i: %d", i);
    i=0;
    while(i<10){
        printf("-");
        i++;
    }

    printf("\nEl total del \"nro\" %d mas %d es: %d\n", num1, num2, total);

    system("pause");

    return 0;
}
