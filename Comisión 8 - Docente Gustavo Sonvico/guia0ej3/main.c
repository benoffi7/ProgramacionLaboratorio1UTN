#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hombres, mujeres, suma;
    float porcentajeM, porcentajeH;

    printf("Ingrese la cantidad de hombres; \n");
    scanf("%d", &hombres);

    printf("Ingrese la cantidad de mujeres; \n");
    scanf("%d", &mujeres);

    suma=hombres+mujeres;

    porcentajeH=(float)hombres*100/suma;
    porcentajeM=(float)mujeres*100/suma;

    printf("La cantidad de alumnos es: %d \n", suma);

    printf("El porcentaje de hombres corresponde al %.2f %% \n",porcentajeH);
    printf("El porcentaje de mujeres corresponde al %.2f %% \n",porcentajeM);

    return 0;
}
