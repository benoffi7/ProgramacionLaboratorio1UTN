/**
Leer 15 números negativos y convertirlos a positivos e imprimir dichos números.
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nro = 0, i;

    for(i=0;i<15;i++){
        printf("\n Ingrese un nro: ");
        scanf("%d", &nro);
        if(nro<0){
            nro = nro * (-1); /// o tambien se puede hacer asi nro *= -1;
            printf("\n\n Numero positivo: %d\n\n",nro);
        }
        system("pause");
        system("cls");

    }

    printf("Hello world!\n");
    return 0;
}
