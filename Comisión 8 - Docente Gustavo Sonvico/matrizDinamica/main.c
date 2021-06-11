#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int ** crearMatriz (int filas, int columnas)
{
    int i=0;

    int ** M = (int**)calloc(filas,sizeof(int *));  /// igual que malloc, pero setea 0 (cero) a todos los elementos

    for(i=0; i<filas; i++)
    {
        M[i]=(int *)calloc(columnas,sizeof(int));
    }
    return M;
}

void crearMatrizPunteroTriple (int *** M, int filas, int columnas)
{
    int i=0;

    (*M)=(int**)calloc(filas,sizeof(int *));

    for(i=0; i<filas; i++)
    {
        (*M)[i]=(int *)calloc(columnas,sizeof(int));
    }
}

void cargarMatrizInt (int ** M, int filas, int columnas)
{
    int f, c;

    printf("\nCargando la matriz:\n");

    for(f=0;f<filas;f++)
    {
        for(c=0;c<columnas;c++)
        {
            printf("Ingrese un entero: ");
            scanf("%d", &M[f][c]);
        }
        printf("\n");
    }
}

void cargarMatrizIntAutomatico (int ** M, int filas, int columnas)
{
    int f, c;
    srand(time(NULL));

    printf("\nCargando la matriz automaticamente\n");

    for(f=0;f<filas;f++)
    {
        for(c=0;c<columnas;c++)
        {
            M[f][c]=rand()%100;
        }
    }
}

void printMatrizInt (int ** M, int filas, int columnas)
{
    int f, c;

    printf("\nContenido de la matriz:\n");

    for(f=0;f<filas;f++)
    {
        for(c=0;c<columnas;c++)
        {
            printf("[%d]", M[f][c]);
        }
        printf("\n");
    }
}


int main()
{
    printf("Hello world! Probando matrix dinamicas\n");

    int unaMatriz[5][5];

    int ** Matrix = crearMatriz(6,10);
  //  cargarMatrizInt(Matrix, 4,6);
    cargarMatrizIntAutomatico(Matrix, 6,10);
    printMatrizInt(Matrix, 6, 10);

    int ** otraM=NULL;
    crearMatrizPunteroTriple(&otraM, 10,3);
    cargarMatrizIntAutomatico(otraM, 10,3);
    printMatrizInt(otraM, 10,3);
    return 0;
}
