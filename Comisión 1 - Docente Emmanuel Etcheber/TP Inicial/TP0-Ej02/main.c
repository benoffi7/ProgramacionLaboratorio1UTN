#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Una tienda ofrece un descuento del 15% sobre el total de la compra
    y un cliente desea saber cuanto debera pagar finalmente por su compra.*/

    #define valorDescuento 0.15
    float compra, descuento=0, total = 0;

    printf("Ingrese monto total de la compra\n");
    fflush(stdin);
    scanf("%f",&compra);

    descuento = compra * valorDescuento;
    total = compra - descuento;

    printf("Usted debera pagar: $ %.2f \n", total);
}
