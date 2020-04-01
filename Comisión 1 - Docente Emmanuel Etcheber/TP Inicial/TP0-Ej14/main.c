#include <stdio.h>
#include <stdlib.h>

int main()

{
    /*Calcular el promedio de un alumno que tiene 7 calificaciones
    en la materia de Disenio Estructurado de Algoritmos*/

    int contPromedio, notas, sumaCalificaciones = 0;
    float promedioNotas = 0;

    for(contPromedio = 0; contPromedio < 7; contPromedio++)
    {
        printf("Ingrese nota %d\n", contPromedio+1);
        fflush(stdin);
        scanf("%d", &notas);

        sumaCalificaciones+= notas;
    }

    promedioNotas = (float)sumaCalificaciones/(float)contPromedio;

    printf("El promedio de la materia Disenio Estructurado de Algoritmos es: %.2f\n", promedioNotas);

    return 0;
}
