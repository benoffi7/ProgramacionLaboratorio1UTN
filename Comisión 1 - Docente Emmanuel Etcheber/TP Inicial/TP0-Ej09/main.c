#include <stdio.h>
#include <stdlib.h>

int main()

{
    /*Hacer un algoritmo que calcule el total a pagar por la compra de
     camisas. Si se compran tres camisas o mas se aplica un descuento
     del 20%% sobre el total de la compra y si son menos de
     tres camisas un descuento del 10%*/

    int cantCamisas = 0;
    float precioCamisas, totalCamisas = 0;

    printf("Ingrese cantidad de camisas\n");
    fflush(stdin);
    scanf("%d", &cantCamisas);

    printf("Ingrese precio por camisa\n");
    fflush(stdin);
    scanf("%f", &precioCamisas);

    totalCamisas = precioCamisas * cantCamisas;

    if(cantCamisas >= 3)
    {
        totalCamisas -= totalCamisas*0.2;
        printf("El cliente tiene un descuento del 20%% por lo tanto ");
    }
    else{
        totalCamisas -= totalCamisas*0.1;
        printf("El cuente tiene un descuento del 10%% por lo tanto");
    }

    printf("tiene que pagar: $%.2f\n", totalCamisas);

    return 0;
}
