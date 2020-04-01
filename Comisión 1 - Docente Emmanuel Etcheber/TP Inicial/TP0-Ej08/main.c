#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///Que lea dos numeros y los imprima en forma ascendente

    int nro1, nro2 = 0;

    printf("Ingrese Numero 1\n");
    fflush(stdin);
    scanf("%d", &nro1);

    printf("Ingrese Numero 2\n");
    fflush(stdin);
    scanf("%d", &nro2);

    printf("Numeros ordenados: ");
    if(nro1 < nro2)
    {
        printf("- %d - %d -\n", nro1, nro2);
    }
    else{
        printf("- %d - %d -\n", nro2, nro1);
    }

    return 0;
}
