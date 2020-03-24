/**
3)Un maestro desea saber que porcentaje de hombres y que porcentaje de mujeres hay en ungrupo de estudiantes.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /// Defino e inicializo las variables necesarias
    int totalAlumnos = 0, cantHombres = 0, cantMujeres = 0;
    float porcentajeHombres = 0, porcentajeMujeres = 0;

    /// Interactuo con el usuario
    printf("\n Ingrese la cantidad de hombres....: ");
    scanf("%d",&cantHombres);
    printf("\n Ingrese la cantidad de mujeres....: ");
    scanf("%d",&cantMujeres);

    /// Proceso. Realizo los calculos necesarios
    totalAlumnos = cantHombres + cantMujeres;
    porcentajeHombres = (float) cantHombres * 100 / totalAlumnos;
    porcentajeMujeres = 100 - porcentajeHombres; /// es mas simple el calculo

    /// Muestro los datos
    printf("\n Total de Hombres.........: %d - Porcentaje: %.2f", cantHombres, porcentajeHombres);
    printf("\n Total de Mujeres.........: %d - Porcentaje: %.2f", cantMujeres, porcentajeMujeres);
    printf("\n Total de Alumnos.........: %d", totalAlumnos);


    return 0;
}
