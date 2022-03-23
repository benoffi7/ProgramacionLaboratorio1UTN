#include <stdio.h>
#include <stdlib.h>

/**
salario semanal
40hs o menos $300
mas de 40 $400 por hora extra
*/

int main()
{
  int cantHorasTrabajadas = 0;
    int cantHorasBase = 0;
    int cantHorasExtra = 0;
    int importeTotalBase = 0;
    int importeTotalExtra = 0;
    int salario = 0;
    int importeHoraBase = 300;
    int importeHoraExtra = 400;

    printf("\nIngrese la cantidad de horas trabajadas: ");
    scanf("%d", &cantHorasTrabajadas);

    if(cantHorasTrabajadas > 40){
        cantHorasBase = 40;
        cantHorasExtra = cantHorasTrabajadas - 40;
    }else{
        cantHorasBase = cantHorasTrabajadas;
    }

    importeTotalBase = cantHorasBase * importeHoraBase;
    importeTotalExtra = cantHorasExtra * importeHoraExtra;
    salario = (cantHorasBase * importeHoraBase) + (cantHorasExtra * importeHoraExtra);

    printf("\n Ud trabajó %d horas base por la cantidad de $%d", cantHorasBase, importeTotalBase);
    printf("\n Ud trabajó %d horas extra por la cantidad de $%d", cantHorasExtra, importeTotalExtra);
    printf("\n Ud cobrara la suma de ........................$%d \n", salario);

    return 0;
}
