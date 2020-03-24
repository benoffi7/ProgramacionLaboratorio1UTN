/**
1)Suponga que un individuo desea invertir su capital en un banco y desea saber
cuánto dineroganara después de un mes si el banco paga a razón de 2% mensual.

*/

#include <stdio.h>
#include <stdlib.h>

 /**
 esto es para comentarios en bloque,
 o sea de varial líneas
*/

#define INT 2     /// esta es una definicion de constante literal
const float INTERES = 0.02; /// esta es definicion de constante, estoy definiendo 2/100 asi me ahorro un calculo

int main()
{
    /// Definición e inicializacion de variables
    int capital=0; /// defino la variable de tipo entero capital para que el usuario ingrese la cantidad de dinero a invertir
    float ganancia=0; /// defino la variable de tipo float (porque del cálculo de interes seguramente la ganancia no va a ser entera)

    /// Interaccion con el usuario
    printf("\n Ingrese el capital a invertir: ");
    scanf("%d",&capital);

    /// Proceso de datos (realizo el o los calculos necesarios)
    ganancia = capital * INTERES; ///este caso no requiere casteo porque en el calculo interviene un dato tipo float (el interes)
    /// ganancia = (float) capital * INT /100; /// este caso requiere el casteo (float) porque los datos que intervienen en el calculo son todos enteros

    /// Muestro los datos
    printf("\n Ud invirtio la suma de $%d y al cabo de un mes gano la suma de $%.2f",capital, ganancia);

    ///    el %f se usa para una variable de tipo float y .2 para limitar los decimales a 2

    return 0;
}
