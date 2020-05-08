#include <stdio.h>
#include <stdlib.h>

int cargaArreglosParalelos(int legajos[], int longitudChar, char nombres[][longitudChar], int anios[], int dimension);
void mostrarArreglosParalelos(int legajos[], int longitudChar, char nombres[][longitudChar], int anios[], int validos);

int main()
{
    printf("Hello world arrays paralelos!\n");

    /// creamos los arreglos para trabajar con arrays paralelos
    int legajos[20];
    char nombres[20][30]; /// 30 son los caracteres maximos por nombre
    int anios[20];

    int cantValidos=0;

    cantValidos=cargaArreglosParalelos(legajos,30,nombres, anios, 20);

    printf("Se cargaron %d alumnos\n\n", cantValidos);

    mostrarArreglosParalelos(legajos, 30, nombres, anios, cantValidos);

    return 0;
}

int cargaArreglosParalelos(int legajos[], int longitudChar, char nombres[][longitudChar], int anios[], int dimension)
{
    int i=0;
    char control='s';

    printf("Cargando el array de alumnos: \n");
    while(i<dimension && control=='s')
    {
        printf("Ingrese el legajo: ");
        scanf("%d", &legajos[i]);

        printf("Ingrese el nombre: ");
        fflush(stdin);
        scanf("%s", nombres[i]);

        printf("Ingrese el a%co: ", 164);
        scanf("%d", &anios[i]);

        printf("Desea continuar la carga? s/n \n");

        fflush(stdin);
        scanf("%c", & control);

        i++;
    }

    return i;
}

void mostrarArreglosParalelos(int legajos[], int longitudChar, char nombres[][longitudChar], int anios[], int validos)
{
    int i=0;

    printf("Contenido del arreglo de alumnos:\n");

    printf("-----------\n");
    for (i=0; i<validos; i++)
    {
        printf("Legajo: %d\n", legajos[i]);
        printf("Nombre: %s\n", nombres[i]);
        printf("A%co:   %d\n", 164, anios[i]);
        printf("-----------\n");
    }
}
