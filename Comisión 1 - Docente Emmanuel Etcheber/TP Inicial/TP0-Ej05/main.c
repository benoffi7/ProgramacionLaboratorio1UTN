#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Determinar si un alumno aprueba a reprueba un curso,
    sabiendo que aprobara si su promedio de tres calificaciones
    es mayor o igual a 7; reprueba en caso contrario.*/

    int contador=0, nota=0, suma = 0;
    float promedioCalificacion = 0;

    while(contador < 3)
    {
        contador++; /// lo pongo primero porque lo uso para mostrar por pantalla

        printf("Ingrese nota nro %d\n", contador);
        scanf("%d",&nota);

        suma += nota; //suma = suma + nota;
    }
    promedioCalificacion = (float)suma/(float)contador;

    printf("El promedio del alumno es %.2f, por lo tanto el alumno ", promedioCalificacion);
    if(promedioCalificacion >= 7)
    {
        printf("APROBO la materia\n");
    }
    else{
        printf("DESAPROBO la materia\n");
    }

    return 0;
}
