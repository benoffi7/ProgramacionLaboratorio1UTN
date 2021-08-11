#include <stdio.h>
#include <stdlib.h>

/**
Suponga que se tiene un conjunto de calificaciones de un grupo de 40 alumnos.
Realizar un algoritmo para calcular la calificación promedio y la calificación más baja de todo el grupo.
*/

#define CANT_MAX 3

int main()
{
    int nota=0;
    int min=0;
    int max=0;
    int suma = 0;
    int i = 0;
    float promedio;

    printf("\n Ingrese la nota nro %d: ", i+1);
    scanf("%d", &nota);

    i = i + 1;
    suma = suma + nota;
    min = nota;
    max = nota;

    while(i < CANT_MAX){

        do{
            printf("\n Ingrese la nota nro %d: ", i+1);
            scanf("%d", &nota);
            if(nota < 1 || nota > 10){
                printf("\n\t <<< ERROR >>> \n");
                printf("La nota ingresada no es correcta\n");
                system("pause");
                system("cls");
            }
        }
        while(nota < 1 || nota > 10);

        i = i + 1;
        suma = suma + nota;

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
