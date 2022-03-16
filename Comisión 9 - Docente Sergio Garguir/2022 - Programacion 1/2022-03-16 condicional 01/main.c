#include <stdio.h>
#include <stdlib.h>

/**
Determinar si un alumno aprueba a reprueba un curso, sabiendo que aprobara
si su promedio de tres calificaciones es mayor o igual a 7; reprueba en caso contrario.
*/
int main()
{
    int nota1, nota2, nota3;
    int promedio;

    printf("\n Ingrese la nota 1: ");
    scanf("%d", &nota1);

    printf("\n Ingrese la nota 2: ");
    scanf("%d", &nota2);

    printf("\n Ingrese la nota 3: ");
    scanf("%d", &nota3);

    promedio = (nota1 + nota2 + nota3) / 3;

    if(promedio >= 7){
        printf("\n El alumno aprobo con %d de promedio", promedio);
    }else{
        printf("\n El alumno desaprobo con %d de promedio", promedio);
    }

    return 0;
}
