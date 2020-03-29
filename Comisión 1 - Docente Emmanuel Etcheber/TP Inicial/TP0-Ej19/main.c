#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Calcular e imprimir la tabla de multiplicar de un numero cualquiera.
    Imprimir el multiplicando, el multiplicador y el producto.*/

    int numerito = 0;
    int multiplicador = 0;
    int resultado = 0;

    printf("Ingrese numero para mostrar tabla de multiplicacion\n");
    fflush(stdin);
    scanf("%d", &numerito);

    for(multiplicador = 0; multiplicador<=10; multiplicador++)
    {
        resultado = numerito * multiplicador;
        printf(" %d x %d = %d\n", numerito, multiplicador, resultado);
    }
    return 0;
}
