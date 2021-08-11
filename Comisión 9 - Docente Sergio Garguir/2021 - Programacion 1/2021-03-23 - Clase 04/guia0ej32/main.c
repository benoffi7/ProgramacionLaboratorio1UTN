#include <stdio.h>
#include <stdlib.h>

/**
Leer tres números diferentes e imprimir el número mayor de los tres.
*/

int main()
{
    int n1, n2, n3, mayor;

    printf("\n Ingrese 3 numeros diferentes: ");
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);

    if(n1 > n2 && n1 > n3){
        mayor = n1;
    }else if(n2 > n1 && n2 > n3){
        mayor = n2;
    }else{
        mayor = n3;
    }

    printf("\n El numero mayor es: %d", mayor);
    return 0;
}
