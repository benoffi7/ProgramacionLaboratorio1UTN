/**
Calcular e imprimir la tabla de multiplicar de un número cualquiera.
Imprimir el multiplicando, el multiplicador y el producto.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nro, i, producto;

    printf("\Ingrese un numero: ");
    scanf("%d", &nro);

    for(i=0;i<11;i++){
        producto = nro * i;
        printf("\n %d x %d = %d",nro, i,producto);
    }

    return 0;
}
