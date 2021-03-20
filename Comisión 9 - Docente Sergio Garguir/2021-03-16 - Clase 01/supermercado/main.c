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


Una supermercado ofrece un descuento del 15% sobre el total de la compra
y un cliente desea saber cuánto deberá pagar finalmente por su compra.
*/

/// para comentar una linea

#define IVA 21

const int Iva = 21;

int main()
{
    /// Declaro e inicializo variables
    int porcentajeDescuento = 15;
    int descuento = 0;
    int totalCompra = 0;
    int totalAPagar = 0;
    char c = 'A';
    float pi = 3.14;
    c++;
    printf("\n%c %d %.2f el iva es: %d%%", c, c, pi, Iva);
    printf("\nEl caracter %c en realidad almacena %d", c, c);
    c++;
    printf("\nEl caracter %c en realidad almacena %d", c, c);
    c++;
    printf("\nEl caracter %c en realidad almacena %d", c, c);

    /// Interactuo con el usuario
    printf("\n Ingrese el total de la compra: ");
    scanf("%d",&totalCompra);

    printf("\n Ingrese una letra: ");
    fflush(stdin);
    scanf("%c",&c);
    printf("\n Ingrese un real: ");
    scanf("%f",&pi);

    printf("\nEl entero ingresado es: %d", totalCompra);
    printf("\nLa letra ingresada es.: %c", c);
    printf("\nEl real ingresado es..: %.3f", pi);

    /// Realizo los calculos

    descuento = totalCompra * porcentajeDescuento / 100 * Iva;
    totalAPagar = totalCompra - descuento - Iva;

    /// Muestro el resultado
    printf("\n El importe a pagar es: %d", totalAPagar);

    return 0;
}
