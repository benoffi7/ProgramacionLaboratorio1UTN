/**
Un obrero necesita calcular su salario semanal, el cual se obtiene de la sig. manera: Si trabaja 40 horas o menos se le paga
$300 por hora Si trabaja más de 40 horas se le paga $300 por cada una de las primeras 40 horas y $400 por cada hora extra.
*/

#include <stdio.h>
#include <stdlib.h>

const int LIMITE_HORAS = 40;
const int HORA_BASE = 300;
const int HORA_EXTRA = 400;


int main()
{
    /// Declaro e inicializo variables
    int cantHorasTrab = 0, cantHorasBase = 0, cantHorasExtra = 0, montoHorasBase = 0, montoHorasExtra = 0, aCobrar = 0;

    /// Interactuo con el usuario
    printf("\n Ingrese el total de horas trabajadas: ");
    scanf("%d", &cantHorasTrab);

    /// Proceso
    if(cantHorasTrab > LIMITE_HORAS)                    /// si las horas trabajadas superan el limite
    {
        cantHorasBase = LIMITE_HORAS;                   /// horas base va a ser = al limite
        cantHorasExtra = cantHorasTrab - LIMITE_HORAS;  /// horas extra va a ser = a lo que supera el limite
        montoHorasBase = cantHorasBase * HORA_BASE;     /// calculo el montobase que es horas base por 300
        montoHorasExtra = cantHorasExtra * HORA_EXTRA;  /// calculo el montoextra que es horas extra por 400
    }
    else                                                /// si no supera el limite
    {
        cantHorasBase = cantHorasTrab;                  /// horas base = horas trabajadas
        montoHorasBase = cantHorasBase * HORA_BASE;     /// monto base = horas base por 300
    }

    aCobrar = montoHorasBase + montoHorasExtra;         /// lo que el trabajador va a cobrar es la suma de los dos montos

    /// Muestro el recibo de sueldo

    printf("\n Ud. trabajo la cantidad de %d horas", cantHorasTrab);
    printf("\n Cantidad de horas base %d x %d = $ %d", cantHorasBase, HORA_BASE, montoHorasBase);
    printf("\n Cantidad de horas ext. %d x %d = $ %d", cantHorasExtra, HORA_EXTRA, montoHorasExtra);
    printf("\n El total a cobrar es de ............. $%d", aCobrar);

    return 0;
}
