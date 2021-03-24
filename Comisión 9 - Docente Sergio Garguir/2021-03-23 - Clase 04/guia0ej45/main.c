#include <stdio.h>
#include <stdlib.h>

/**
Suponga que se tiene un conjunto de calificaciones de un grupo de 40 alumnos.
Realizar un algoritmo para calcular la calificación promedio y la calificación más baja de todo el grupo.
*/

#define CANT_MAX 3

int main()
{
    int nota;
    int min;
    int max;
    int suma = 0;
    int i = 0;
    float promedio;
/*
    printf("\n Ingrese la nota nro %d: ", i+1);
    scanf("%d", &nota);
    suma = suma + nota;
    i++;
    min = nota;
    max = nota;
*/
    while(i < CANT_MAX){
        printf("\n Ingrese la nota nro %d: ", i+1);

        scanf("%d", &nota);

        if(i==0){
            min = nota;
            max = nota;
        }
        suma = suma + nota;
        i++;

        if(nota < min){
            min = nota;
        }else if(nota > max){
            max = nota;
        }
    }

    promedio = (float) suma / i;

    printf("\n La nota menor es: %d", min);
    printf("\n La nota mayor es: %d", max);
    printf("\n El promedio es..: %.2f", promedio);
    return 0;
}
