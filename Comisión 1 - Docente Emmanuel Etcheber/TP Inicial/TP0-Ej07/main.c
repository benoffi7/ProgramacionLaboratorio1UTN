#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Un obrero necesita calcular su salario semanal, el cual se obtiene
    de la sig. manera: Si trabaja 40 horas o menos se le paga $16
    por hora\nSi trabaja mas de 40 horas se le paga $16 por cada una
    de las primeras 40 horas y $20 por cada hora extra.*/

    const int limiteHoras = 40;
    const float valorHoraNormal = 16;
    const float valorHoraExtra = 20;

    int cantHoras, totalSueldo;


    printf("Ingrese cantidad de horas trabajadas\n");
    fflush(stdin);
    scanf("%d", &cantHoras);

    if(cantHoras >= limiteHoras)
    {
        totalSueldo = limiteHoras * valorHoraNormal   +   (cantHoras-limiteHoras) * valorHoraExtra;

    }
    else
        {
            totalSueldo = cantHoras * valorHoraNormal;
        }

    printf("Su salario es de: $%d\n", totalSueldo);
    return 0;
}
