/**
Suponga que se tiene un conjunto de calificaciones de un grupo de 40 alumnos.
Realizar un algoritmo para calcular la calificación promedio y la calificación más baja de todo el grupo.
*/

#include <stdio.h>
#include <stdlib.h>

/// para probar el codigo cambien el 40 por un numero menor
const int TOTAL_ALUMNOS = 40;

int main()
{
    int nota, notaMenor, notaMayor, totalNotas=0, i=0;
    float promedio;

    /// es primer input es para tener como mi nota mayor y mi nota menor la primer nota, de esta forma tengo una referencia
    printf("\n Ingrese la nota del alumno Nro %d: ",i+1);
    scanf("%d",&nota);
    notaMenor = nota;
    notaMayor = nota;
    totalNotas = totalNotas + nota;
    i++;
    system("pause");
    system("cls");

    for(i=1;i<TOTAL_ALUMNOS;i++){
        printf("\n Ingrese la nota del alumno Nro %d: ",i+1);
        scanf("%d",&nota);
        totalNotas = totalNotas + nota;

        /// Este if es para buscar la nota mayor y menor
        if(nota < notaMenor){
            notaMenor = nota;
        }
        else{
            if(nota > notaMayor){
                notaMayor = nota;
            }
        }


        system("pause");
        system("cls");
    }

    promedio = totalNotas / TOTAL_ALUMNOS;

    printf("\n\n El promedio de las notas es.....: %.2f", promedio);
    printf("\n\n La nota menor es................: %d", notaMenor);
    printf("\n\n La nota mayor es................: %d", notaMayor);

    return 0;
}
