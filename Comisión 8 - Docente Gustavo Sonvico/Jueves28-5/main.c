#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void cargaMatrizRandom (int dimF, int dimC, int M[dimF][dimC]);
void mostrarMatriz (int valF, int valC, int M[valF][valC]);
void mostrarMatrizTabulada (int valF, int valC, int M[valF][valC]);
int sumaMatriz(int valF, int valC, int M[valF][valC]);

int sumaArreglo(int A[], int validos);
int sumaMatrizBis (int valF, int valC, int M[valF][valC]);

int main()
{
    printf("Hello world!\n");
    srand(time(NULL));

    int miMatriz[5][10];
    int miOtraMatriz[2][5];

    cargaMatrizRandom(5, 10, miMatriz);

    mostrarMatrizTabulada(5, 10, miMatriz);

    cargaMatrizRandom(2, 5, miOtraMatriz);

    mostrarMatrizTabulada(2, 5, miOtraMatriz);

    int suma= sumaMatriz(2,5,miOtraMatriz);

    printf("La suma es %d", suma);


    return 0;
}

void cargaMatrizRandom (int dimF, int dimC, int M[dimF][dimC])
{
    int f=0; /// filas
    int c=0; /// columnas

    for(f=0; f<dimF; f++)
    {
        for(c=0; c<dimC; c++)
        {
            M[f][c]=(rand()%1000) +1;
        }
    }
}

void mostrarMatriz (int valF, int valC, int M[valF][valC])
{
    int f=0;
    int c=0;

    printf("\nContenido de la matriz: \n");
    for(f=0; f<valF; f++)
    {
        for(c=0; c<valC; c++)
        {
            printf("%d ", M[f][c]);
        }
        printf("\n");
    }
}

void mostrarMatrizTabulada (int valF, int valC, int M[valF][valC])
{
    int f=0;
    int c=0;
    int dato;

    printf("\nContenido de la matriz: \n");
    for(f=0; f<valF; f++)
    {
        for(c=0; c<valC; c++)
        {
            dato=M[f][c];
            switch(dato)
            {
            case 0 ... 9:
                printf("   ");
                break;
            case 10 ... 99:
                printf("  ");
                break;
            case 100 ... 999:
                printf(" ");
            }
            printf("%d", M[f][c]);
        }
        printf("\n");
    }
}

int sumaMatriz(int valF, int valC, int M[valF][valC])
{
    int f=0;
    int c=0;
    int suma=0;

    for(f=0; f<valF; f++)
    {
        for(c=0; c<valC; c++)
        {
            suma+=M[f][c];
        }
    }

    return suma;
}

int sumaArreglo(int A[], int validos)
{
    int i=0;
    int suma=0;

    for(i=0; i<validos; i++)
    {
        suma+=A[i];
    }
    return suma;
}

int sumaMatrizBis (int valF, int valC, int M[valF][valC])
{
    int f=0;

    int suma=0;

    for(f=0; f<valF; f++)
    {
        /// utiliza la funcion sumaArreglo
        /// y trabaja cada fila de la matriz
        /// como si fuera un arreglo de dimension valC

        /// esta bueniiiiisimo!!!

        suma +=sumaArreglo(M[f], valC);
    }
    return suma;
}

