/**
Determinar si un alumno aprueba a reprueba un curso, sabiendo que aprobara si su promedio
de tres calificaciones es mayor o igual a 7; reprueba en caso contrario.

*/

#include <stdio.h>
#include <stdlib.h>

const int limiteAprobado = 7;   /// Declaro una constante para usar como limite de aprobacion


int main()
{
    /// Declaro variables y las inicializo

    int nota1 = 0, nota2 = 0, nota3 = 0;        /// Declaro las 3 variables de tipo int para ingresar notas
    int promedio = 0;                           /// Declaro la variable para calcular el promedio de tipo int porque necesito la parte entera

    /// Interactuo con el usuario

    printf("\n Ingrese la nota 1: ");
    scanf("%i",&nota1);

    printf("\n Ingrese la nota 2: ");
    scanf("%i",&nota2);

    printf("\n Ingrese la nota 3: ");
    scanf("%i",&nota3);

    /// Proceso - Realizo los calculos
    promedio = (nota1 + nota2 + nota3) / 3;     /// Ojo con los parentesis


    /// Muestro los datos de acuerdo al contenido de la variable promedio
    if (promedio >=7)
    {
          printf("El almuno aprobo la materia con un promedio de %i",promedio);
    }
    else{
          printf("El almuno no aprobo la materia y su promedio final es de %i",promedio);
    }

    return 0;
}


