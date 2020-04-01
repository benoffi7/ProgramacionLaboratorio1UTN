#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Suponga que se tiene un conjunto de calificaciones de un grupo de 40 alumnos.
    Realizar un algoritmo para calcular la calificacion media y la calificacion
    mas baja de todo el grupo.*/

    int calificacion = 0;
    float media = 0;
    int sumaMedia = 0;
    int cantidad = 0;
    int notaMenor = 500;

    for(cantidad = 0; cantidad<3; cantidad++)
    {
        printf("Ingrese nota del alumno %d\n", cantidad+1);
        fflush(stdin);
        scanf("%d", &calificacion);

        if(notaMenor>calificacion)
        {
            notaMenor = calificacion;
        }
        sumaMedia += calificacion;
    }

    media = (float)sumaMedia/cantidad;
    printf("La nota mas baja es : %d\n", notaMenor);
    printf("La media de las notas es: %.2f\n", media);

    return 0;
}
