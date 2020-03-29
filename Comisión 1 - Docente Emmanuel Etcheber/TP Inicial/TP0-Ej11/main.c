#include <stdio.h>
#include <stdlib.h>

int main()

{
    ///Leer tres números diferentes e imprimir el numero mayor de los tres.

    int nro111, nro222, nro333, mayor = 0;

    printf("Ingrese nro 1\n");
    fflush(stdin);
    scanf("%d",&nro111);

    printf("Ingrese nro 2\n");
    fflush(stdin);
    scanf("%d",&nro222);

    printf("Ingrese nro 3\n");
    fflush(stdin);
    scanf("%d",&nro333);

    if(nro111< nro222 && nro222 < nro333)
    {
        mayor = nro333;
    }
    else{
        if(nro111 < nro222 && nro222 > nro333)
        {
            mayor = nro222;
        }
        else{
            mayor = nro111;
        }
    }

    printf("El mayor de los tres es: %d\n", mayor);

    return 0;
}
