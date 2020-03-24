/**
En un almacén se hace un 20% de descuento a los clientes cuya compra supere los $5000
¿Cuál será la cantidad que pagara una persona por su compra?
*/

#include <stdio.h>
#include <stdlib.h>

const float PORCENTAJEDESCUENTO = 0.2;        /// declaro una constante para el descuento
const int LIMITEDESCUENTO = 5000;   /// declaro una constante para el limite de descuento;

int main()
{
    /// Declaro variables y las inicializo
    float totalCompra = 0, descuento = 0, aPagar = 0;

    /// Interactuo con el usuario
    printf("\n Ingrese el total de su compra ");
    scanf("%f",&totalCompra);                       /// recuerden usar & junto a la variable en la funcion scanf()

    /// Proceso datos
    if(totalCompra >= LIMITEDESCUENTO)
    {
        descuento = totalCompra * PORCENTAJEDESCUENTO;
    }

    aPagar = totalCompra - descuento;       /// como la variable descuento esta inicializada en 0 si la compra no supera el monto limite, va a terminar pagando el total de la compra sin descuento


    /// Muestro los datos

    printf("\n El total de su compra es de ....: $%.2f",totalCompra);
    printf("\n Descuento ......................: $%.2f",descuento);
    printf("\n El total a pagar es de .........: $%.2f",aPagar);

    return 0;
}
