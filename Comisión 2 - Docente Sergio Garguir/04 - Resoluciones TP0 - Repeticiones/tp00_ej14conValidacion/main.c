/**
Leer 15 números negativos y convertirlos a positivos e imprimir dichos números.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nro = 0, i;

    for(i=0;i<15;i++){

        do{
            printf("\n Ingrese un nro negativo: ");
            scanf("%d", &nro);
            /// si el numero ingresado NO es negativo muestro un mensaje de error
            if(nro>=0){
                printf("\n\n ERROR El numero ingresado no es negativo - Intente nuevamente\n\n");
                system("pause");
                system("cls");
            }
        }while(nro >=0); /// mientras el numero NO sea negativo le sigo pidiendo que ingrese un nro negativo

        nro = nro * (-1); /// o tambien se puede hacer asi nro *= -1;
        printf("\n\n Numero positivo: %d\n\n",nro);

        system("pause");
        system("cls");

    }

    printf("Hello world!\n");
    return 0;
}
