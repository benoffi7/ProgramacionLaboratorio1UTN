#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargaMatrizIntRandom(int filas, int columnas, int M[filas][columnas]);
void mostraMatrizInt(int filas, int columnas, int M[filas][columnas]);

int cargarPalabras(int f, int c, char P[f][c]);
void mostrarPalabras(int f, int c, char P[f][c]);

int main()
{
    printf("Hello the matrix!\n");

    srand(time(NULL));

    int miMatrix[4][8];

    cargaMatrizIntRandom(4,8,miMatrix);

    mostraMatrizInt(4,8,miMatrix);


    char misPalabras[10][30];
    int validosPalabras;

    validosPalabras=cargarPalabras(10, 30, misPalabras);
    mostrarPalabras(validosPalabras, 30, misPalabras);


    return 0;
}

void cargaMatrizIntRandom(int filas, int columnas, int M[filas][columnas])
{
    int i, j;
    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            M[i][j]=rand()%1000;
        }
    }
}

void mostraMatrizInt(int filas, int columnas, int M[filas][columnas])
{
    int i, j;

    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            printf("[%d]", M[i][j]);
        }
        printf("\n");
    }
}

int cargarPalabras(int f, int c, char P[f][c])
{
    int i=0;
    char control='s';

    printf("Carguemos tus palabras: \n");
    while(i<f && control=='s')
    {
        printf("Ingrese una palabra (max. 30 char): ");
        fflush(stdin);

        scanf("%s", &P[i]);

        printf("Desea continuar esta tortura? s/n \n\n\t");
        fflush(stdin);
        scanf("%c", &control);

        i++;
    }
    return i;
}

void mostrarPalabras(int f, int c, char P[f][c])
{
    int i=0;
    printf("Estas son tus palabras: \n");
    for(i=0;i<f;i++)
    {
        printf("\t%s\n", P[i]);
    }
}
