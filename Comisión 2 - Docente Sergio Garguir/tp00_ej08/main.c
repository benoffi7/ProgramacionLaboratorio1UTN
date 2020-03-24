/**
Hacer un algoritmo que calcule el total a pagar por la compra de camisas. Si se compran tres camisas
 o más se aplica un descuento del 20% sobre el total de la compra y si son menos de tres camisas un descuento del 10%
Yo voy a suponer que la oferta es por 3 camisas del mismo precio
*/


#include <stdio.h>
#include <stdlib.h>

const int LIMITE_CAMISAS = 3;
const float DESCUENTO_MENOR = 0.1;
const float DESCUENTO_MAYOR = 0.2;

int main()
{
    /// declaro e inicializo variables
    int cantCamisas = 0, importeCamisa = 0, importeTotal;
    float descuento = 0, aPagar = 0;

    /// Interactuo con el usuario
    printf("\n Ingrese cantidad de camisas compradas...: ");
    scanf("%d",&cantCamisas);
    printf("\n Ingrese el importe de la camisa.........: ");
    scanf("%d",&importeCamisa);

    /// proceso datos
    importeTotal = importeCamisa * cantCamisas;

    if(cantCamisas >= LIMITE_CAMISAS)
    {
        descuento = importeTotal * DESCUENTO_MAYOR;
    }
    else
    {
        descuento = importeTotal * DESCUENTO_MENOR;
    }

    aPagar = importeTotal - descuento;

    /// Muestro los datos
    printf("\n Su compra de %d es de un total de..: $%d",cantCamisas, importeTotal);
    printf("\n Obtuvo un descuento de.............: $%.2f", descuento);
    printf("\n Debe abonar la suma de ............: $%.2f", aPagar);

    return 0;
}
