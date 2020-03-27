/**
Leer 10 números e imprimir solamente los números positivos

*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nro, cont=0;

    while(cont<10){

        printf("\n Ingrese un nro: ");
        scanf("%d", &nro);
        if(nro>0){
            printf("\n\n Numero positivo: %d\n\n",nro);
        }
        cont = cont + 1; /// cont++; /// cont+=1;
        system("pause");
        system("cls");
    }

    printf("Bye Bye world!\n");
    return 0;
}
