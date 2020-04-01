#include <stdio.h>
#include <stdlib.h>

int main()

{
    const float interes = 0.02;
    /*Suponga que un individuo desea invertir su capital en un banco y desea nsaber cuanto dinero ganara despues de un mes
    si el banco paga a razon de 2% mensual.*/

    float capital, ganancia = 0;

    printf("Ingrese capital a invertir\n");
    scanf("%f",&capital);

    ganancia = capital * interes;

    printf("Va a tener una ganancia de: %.2f  \n", ganancia);
}
