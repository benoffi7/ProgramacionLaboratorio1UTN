#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hombres = 0;
    int mujeres = 0;
    int totalAlumnos = 0;
    float porcentajeHombres = 0;
    float porcentajeMujeres = 0;

    printf("Ingrese el total de alumnos \n");
    scanf("%d",&totalAlumnos);

    printf("Ingrese el total de mujeres \n");
    scanf("%d",&mujeres);

    printf("Ingrese el total de hombres \n");
    scanf("%d",&hombres);

    totalAlumnos=hombres+mujeres;
    porcentajeHombres=(float)hombres*100/totalAlumnos;
    porcentajeMujeres=(float)mujeres*100/totalAlumnos;

    printf("En el grupo hay %.2f%% mujeres y %.2f%% hombres \n", porcentajeMujeres, porcentajeHombres);

        return 0;

}

