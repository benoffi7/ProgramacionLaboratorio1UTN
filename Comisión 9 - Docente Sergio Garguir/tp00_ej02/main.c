/**
2)Una tienda ofrece un descuento del 15% sobre el total de la compra
y un cliente desea sabercuánto deberá pagar finalmente por su compra.
*/

#include <stdio.h>
#include <stdlib.h>

const float DESCUENTO = 0.15;

int main()
{
    /// Defino e inicializo las variables necesarias
    float totalCompra=0, aPagar=0, descuento=0;

    /// Interactuo con el usuario
    printf("\n Ingrese el total de su compra: ");
    scanf("%f",&totalCompra);

    /// Proceso. Realizo los calculos necesarios
    descuento = totalCompra * DESCUENTO;
    aPagar = totalCompra - descuento;

    /// Muestro los datos lo mas prolijo posible
    printf("\n Total de la compra.........: %.2f",totalCompra);
    printf("\n Menos el %.0f%% de descuento..:  %.2f",DESCUENTO*100, descuento);
    printf("\n                              ___________");
    printf("\n Total a Pagar..............:  %.2f", aPagar);

    return 0;
}
