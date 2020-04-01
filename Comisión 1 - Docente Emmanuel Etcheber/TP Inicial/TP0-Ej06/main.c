#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*En un almacen se hace un 20% de descuento a los clientes cuya
    compra supere los $1000 ¿Cual sera la cantidad que pagara
    una persona por su compra?*/

    float compraAlmacen, totalCompraDescuento = 0;

    printf("Ingrese total de compra\n");
    fflush(stdin);
    scanf("%f", &compraAlmacen);

    if(compraAlmacen >= 1000)
    {
        totalCompraDescuento = compraAlmacen - (compraAlmacen * 0.2);
        printf("El cliente supero los $1000, el monto con descuento es: $");
    }
    else
    {
        totalCompraDescuento = compraAlmacen;
        printf("El cliente NO supero los $1000, el monto a pagar es el mismo: $");
    }
    printf("%.2f\n", totalCompraDescuento);

    return 0;
}
