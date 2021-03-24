#include <stdio.h>
#include <stdlib.h>
/**
--------- Algoritmo que ayuda a crear algoritmos -----------
1.	Detectar variables a utilizar
    a.	Datos que me da el problema
    b.	Datos que le pido al usuario
    c.	Datos que necesito para hacer cálculos y guardar resultados
    d.	Iniciar variables.

2.	Interactuar con el usuario
3.	Realizar tareas o cálculos
4.	Le muestro resultados
*/


/**
Un obrero necesita calcular su salario semanal, el cual se obtiene de la sig. manera:
Si trabaja 40 horas o menos se le paga $300 por hora Si trabaja más de 40 horas se le paga
$300 por cada una de las primeras 40 horas y $400 por cada hora extra.
*/

#define HORAS_TOPE 40
const int IMPORTE_POR_HORA_COMUN = 300;
const int IMPORTE_POR_HORA_EXTRA = 400;

int main()
{
    int horasTrabajadas = 0;
    int horasComunes = 0;
    int horasExtra = 0;
    int totalHoraComun = 0;
    int totalHorasExtra = 0;
    int totalACobrar = 0;

    printf("\n Ingrese la cantidad de horas trabajadas: ");
    scanf("%d", &horasTrabajadas);

    if(horasTrabajadas > HORAS_TOPE){
        horasExtra = horasTrabajadas - HORAS_TOPE;
        horasComunes = HORAS_TOPE;
        totalHoraComun = horasComunes * IMPORTE_POR_HORA_COMUN;
        totalHorasExtra = horasExtra * IMPORTE_POR_HORA_EXTRA;
    }else{
        horasComunes = horasTrabajadas;
        totalHoraComun = horasComunes * IMPORTE_POR_HORA_COMUN;
    }

    totalACobrar = totalHoraComun + totalHorasExtra;
    printf("\n Recibo de Sueldo \n");

    printf("\n Total de Horas Comunes Trabajadas.......: %d * %d = %d", horasComunes, IMPORTE_POR_HORA_COMUN, totalHoraComun);
    printf("\n Total de Horas Extra Trabajadas.........: %d * %d = %d", horasExtra, IMPORTE_POR_HORA_EXTRA, totalHorasExtra);
    printf("\n .......................Total a Cobrar...:           %d", totalACobrar);


    return 0;
}
