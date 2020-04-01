#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///Leer 10 numeros e imprimir solamente los numeros positivos.

    int numeros;
    int cont = 0;

    for(cont = 0; cont<10; cont++)
    {
        printf("Ingrese valor\n");
        fflush(stdin);
        scanf("%d",&numeros);

        if(numeros>=0)
        {
            printf("El numero es positivo: %d\n",numeros);
        }
        else
        {
            printf("El numero es negativo, no se muestra\n");
        }
    }

    return 0;
}
