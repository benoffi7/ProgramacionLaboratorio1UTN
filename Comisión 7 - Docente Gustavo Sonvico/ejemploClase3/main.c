#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello ejemplos de clase!\n");
    int num, num2;

    /// ejemplo if en cascada o anidados

    /// escanear los valores

    if(num==num2)
    {
        total=num*num2;
        printf("Los numeros son iguales\n");
        printf("Total: %d",total);
    }
    else
    {
        if(num>num2)
        {
            /// aca evaluaria la segunda posibilidad
        }
        else
        {
            /// por descarte, la tercer posibilidad
        }
    }


    /// ejercicios guia inicial
    printf("PROBLEMAS SELECTIVOS SIMPLES\n----------------------------\n");
    printf(".:EJERCICIO 3:.\n\n");

    printf("Un obrero necesita calcular su salario semanal, el cual se obtiene de la sig. manera:\nSi trabaja 40 horas o menos se le paga $300 por hora\nSi trabaja mas de 40 horas se le paga $300 por cada una de las primeras 40 horas y $400 por cada hora extra.\n\n");

    int cantHoras, totalSueldo, extrasHoras, extraSueldo = 0;


    printf("Ingrese cantidad de horas trabajadas\n");
    fflush(stdin);
    scanf("%d", &cantHoras);

    if(cantHoras >= 40)
    {
        extrasHoras = cantHoras - 40;
        extraSueldo = extrasHoras * 400;
        totalSueldo = 40 * 300 + extraSueldo;
        printf("El empleado hizo mas de 40 horas, su salario total es: $%d de los cuales $%d pertenecen a horas extras\n",totalSueldo, extraSueldo);
    }
    else
    {
        totalSueldo = cantHoras * 300;
        printf("El empleado no registra horas extras, su salario es de: $%d\n", totalSueldo);
    }


    system("Pause");
    system("cls");


    printf("EJEMPLOS PARA - HACER\n---------------------\n");
    printf(".:EJERCICIO 1:.\n\n");

    printf("Calcular el promedio de un alumno que tiene 7 calificaciones en la\nmateria de Disenio Estructurado de Algoritmos\n\n");

    int contPromedio, notas, sumaCalificaciones = 0;
    float promedioNotas = 0;

    for(contPromedio = 0; contPromedio < 7; contPromedio++)
    {
        printf("Ingrese nota %d\n", contPromedio+1);

        scanf("%d", &notas);


        sumaCalificaciones= sumaCalificaciones+ notas;
    }

    promedioNotas = (float)sumaCalificaciones/(float)contPromedio;

    printf("El promedio de la materia Disenio Estructurado de Algoritmos es: %.2f\n", promedioNotas);

    system("Pause");
    system("cls");


    printf("EJEMPLOS PARA - HACER\n---------------------\n");
    printf(".:EJERCICIO 2:.\n\n");

    printf("Leer 10 numeros y obtener su cubo y su cuarta.\n\n");

    int valor = 0;
    int contadorCubo = 0;
    int valorCubo, valorCuarta;


    for(contadorCubo = 0 ; contadorCubo < 10; contadorCubo++)
    {
        printf("\nIngrese valor %d\n", contadorCubo+1);
        fflush(stdin);
        scanf("%d", &valor);

        valorCubo = valor * valor * valor;
        printf("El cubo de %d es: %d\n", valor, valorCubo);
        valorCuarta = valorCubo * valor;
        printf("La cuarta de %d es: %d\n", valor, valorCuarta);
    }

    system("Pause");
    system("cls");
    /////////

    return 0;
}
