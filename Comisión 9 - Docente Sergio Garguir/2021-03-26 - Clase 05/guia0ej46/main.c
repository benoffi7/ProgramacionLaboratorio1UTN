#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    int nro;

    printf("\Ingrese un numero: ");
    scanf("%d",&nro);


    printf("\n\tTabla del nro %d con WHILE", nro);
    while(i<11){
        printf("\n %d x %d = %d", nro, i, nro*i);
        i++;
    }

    printf("\n\n\tTabla del nro %d con FOR", nro);
    for(i=0;i<11;i++){
        printf("\n %d x %d = %d", nro, i, nro*i);
    }

    printf("\n Hello world! %d \n", i);
    return 0;
}
