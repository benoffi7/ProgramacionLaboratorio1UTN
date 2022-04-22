#include <stdio.h>
#include <stdlib.h>

//Salida: ganancia = capitalInvertido * 2 %

//Entrada: capitalInvertido



//Proceso:
int main()
{

//Definir variables necesarias
    int capitalInvertido=0;
    float ganaciaEnUnMes=0;
    float acumulado=0;

//Definir porcentaje de interes
    int porcent=2;

//Interactuar con el usr
    printf("Bienvenido al banco C, ingrese su capital a invertir: \n$ ");

//Leer el capital a invertir
    scanf("%d", &capitalInvertido);

//Calcular la ganancia
    ganaciaEnUnMes = (float)(capitalInvertido * porcent )/100;
    acumulado=ganaciaEnUnMes+capitalInvertido;

//Imprimir resultados
    printf("La ganacia al final del mes es de $ %.2f\n", ganaciaEnUnMes);
    printf("El total en su cuenta es %.2f", acumulado);

    return 0;
}
