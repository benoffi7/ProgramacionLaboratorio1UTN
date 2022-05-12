#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cargarUnArreglo(int A[], int dimension);  /// int * A
void mostrarUnArreglo(int A[], int validos);

int main()
{
    srand(time(NULL));

    printf("Hello arrays!\n");

    int i=0, validos=0, otroValidos=0;

    int dimUsr=0, validosUsr;

    int unArreglo[20];

    int otroArreglo[10];

    validos=cargarUnArreglo(unArreglo, 20);

    mostrarUnArreglo(unArreglo, validos);

    otroValidos=cargarUnArreglo(otroArreglo, 10);

    mostrarUnArreglo(otroArreglo, otroValidos);

    return 0;
}

int cargarUnArreglo(int A[], int dimension)
{
    char control='s';
    int i=0;

    while(control=='s'&&i<dimension)
    {
        printf("Ingrese un elemento entero al arreglo: ");
        scanf("%d", &A[i]);

        printf("\nDesea continuar? s/n");
        fflush(stdin);
        scanf("%c", &control);

        i++;
    }

    return i;
}

void mostrarUnArreglo(int A[], int validos)
{
    int i;

    puts("Contenido del arreglo");

    for(i=0; i<validos;i++)
    {
        printf("%d ", A[i]);
    }
}
