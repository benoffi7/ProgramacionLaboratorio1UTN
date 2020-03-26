/**
Calcular el promedio de un alumno que tiene 7 calificaciones en la materia de Programación 1

*/


#include <stdio.h>
#include <stdlib.h>

const int CANT_NOTAS = 7;

int main()
{
    /// Declaro variables y las inicializo
    int nota = 0, cont = 0, totalNotas = 0;
    float promedio = 0;

    /// Interactuo con el usuario;
    while(cont < CANT_NOTAS){
        cont = cont + 1; /// cont++;  /// cont +=1;
        printf("\n Ingrese la nota nro %d: ",cont);
        scanf("%d", &nota);
        totalNotas = totalNotas + nota; /// totalNotas += nota;
    }

    promedio = (float) totalNotas / cont;


    /// Muestro los resultados
    printf("\n\n El promedio de las notas ingresadas es: %.2f", promedio);

    return 0;
}
