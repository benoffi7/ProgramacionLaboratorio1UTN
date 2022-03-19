#include <stdio.h>
#include <stdlib.h>

const int INTERES = 2;

/**
Suponga que un individuo desea invertir su capital en un banco y desea saber cuánto dinero
ganará después de un mes si el banco paga a razón de 2% mensual.
*/
int main()
{
    int capital;
    int cantidadDeMeses;
    float ganancia;


    printf("\n Ingrese el capital a invertir: ");
    scanf("%d", &capital);
    printf("\n Ingrese la cantidad de meses: ");
    scanf("%d", &cantidadDeMeses);

    ganancia = (float)((capital * INTERES) / 100) * cantidadDeMeses;

    printf("Luego de %d mes/es, su ganancia es de $%1.2f", cantidadDeMeses, ganancia);

    return 0;
}
