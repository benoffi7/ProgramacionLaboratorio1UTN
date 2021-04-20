#include <stdio.h>
#include <stdlib.h>

#define CANTMAX 20

int main()
{
    int arreglo[CANTMAX];
    int validos; //cantidad valida de datos

///algoritmo de carga
    do
    {
        printf("Ingrese un valor\n");
        scanf("%i",&arreglo[validos]);
        printf("Desea seguir cargando?S\N \n");
        fflush(stdin);
        scanf("%c",&seguir);
        validos++; ///incremento posicion

    }
    while(seguir == 's' && validos < CANTMAX);
    ///mientras el usuario aprete s y la cantidad cargada de datos sea menor a la maxima



/// algoritmo de muestra del arreglo
    for (int i = 0; i < validos; i++)
    {
        printf("%i ", arreglo[i]);

    }

///algoritmo de busqueda de un dato

    int num;
    int i = 0; //contador, subindice
    printf("Ingrese el valor a buscar\n");
    scanf("%i",&num);
    while ( i < validos && arreglo[i] != num)
    {
        i++; //avanzo el subindice
    }
    if (i < validos)
    {
        printf("El dato se encuentra en la posicion %i", i);
    }
    else
    {
        printf("El dato no se encuentra en el arreglo\n");
    }

///sumar los elementos del arreglo
    int suma = 0; ///acumulador

    for (int i = 0; i < validos; i++)
    {
        suma = suma + arreglo[i];
    }


    return 0;
}
