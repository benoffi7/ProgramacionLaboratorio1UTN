#include <stdio.h>
#include <stdlib.h>

#define CANT_MAX 10

int main()
{
    int arreglo[CANT_MAX];
    char seguir;
    int validos=0; //contador de los validos

    do
    {
        printf("Ingrese un valor\n");
        scanf("%i", &arreglo[validos]);
        printf("Desea continuar S/n \n");
        fflush(stdin);
        scanf("%c",&seguir);
        validos++;
    }
    while(seguir == 's');

    ///validos es la CANTIDAD cargada de datos
    ///NO es la ultima posicion cargada
    for (int i = 0; i < validos; i++)
    {
        printf("%i", arreglo[i]);
    }

    ///sumar los elementos del arreglo
    int suma=0; //acumulador

    for (int i = 0; i < validos; i++)
    {
        suma = suma + arreglo[i];
    }

    ///buscar un dato en el arreglo
    int num;
    int i=0; ///contador, subindice
    printf("Ingrese un valor a buscar\n");
    scanf("%i", &num);
    while (i < validos && arreglo[i] != num)
    {
        i++;
    }

    if (i < validos)
    {
        printf("El dato esta en la posicion %i", i);

    }
    else
    {
        printf("El dato no se encontro");
    }


    return 0;
}
