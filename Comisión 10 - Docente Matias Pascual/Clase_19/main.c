/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 19:
        * Resolucion de ejercicios de la guia 4.1 : matrices
        * Cargar matriz
        * Mostrar matriz
        * Cargar matriz con numeros aleatorios (resolver en clase)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// DIFERENTES FORMAS DE PASAR UNA MATRIZ POR PARAMETRO

#define CANTIDAD_COLUMNAS 2
#define CANTIDAD_FILAS 2
#define MAX_COL 10

void ejercicio_1(int matriz[][MAX_COL], int cantidadFilas, int cantidadColumnas);

void ejercicio_1_v2 (int matriz[][CANTIDAD_COLUMNAS],int,int); /// usando una constante

void ejercicio_1_v3 (int matriz[CANTIDAD_FILAS][CANTIDAD_COLUMNAS],int,int); /// usando dos constantes

/// ----------------------------------------------------

void mostrarMatriz(int matriz[10][MAX_COL], int filas, int columnas);

/// ----------------------------------------------------

void inicMatriz(int matriz[][MAX_COL], int filas, int columnas);

/// ----------------------------------------------------



typedef struct
{
    int dimensionF;
    int dimensionC;
    int **arreglo;
} stMatriz;

int main()
{
    srand(time(NULL));

    stPersona matriz[3][3];

    matriz[0][0].dni = 100;

    //inicMatriz(matriz, 2, 2);

    //ejercicio_1(matriz, 2, 2);

    inicRandom(matriz, 2, 2);

    mostrarMatriz(matriz, 2, 2);

    return 0;
}

/// ----------------------------------------------------

/// 1 - Hacer una función que reciba como parámetro una matriz de números enteros
/// y permita que el usuario ingrese valores al mismo por teclado.
/// La función debe cargar la matriz por completo.

void ejercicio_1(int matriz[][MAX_COL], int cantidadFilas, int cantidadColumnas)
{
    for(int filaActual = 0; filaActual < cantidadFilas; filaActual++)
    {
        for(int columnaActual = 0; columnaActual < cantidadColumnas; columnaActual++)
        {
            printf("ingrese un numero para la posicion [%d][%d] \n", filaActual, columnaActual);
            fflush(stdin);

            scanf("%d", &matriz[filaActual][columnaActual]);
        }
    }
}

/// ----------------------------------------------------

void ejercicio_1_v2 (int matriz[][CANTIDAD_COLUMNAS],
                     int cantidadFilas, int cantidadColumnas)
{
    for(int filaActual = 0; filaActual < cantidadFilas; filaActual++)
    {
        for(int columnaActual = 0; columnaActual < cantidadColumnas; columnaActual++)
        {
            printf("ingrese un numero para la posicion [%d][%d] \n", filaActual, columnaActual);
            fflush(stdin);

            scanf("%d", &matriz[filaActual][columnaActual]);
        }
    }
}

/// ----------------------------------------------------

void ejercicio_1_v3 (int matriz[CANTIDAD_FILAS][CANTIDAD_COLUMNAS],
                     int cantidadFilas, int cantidadColumnas)
{
    for(int filaActual = 0; filaActual < cantidadFilas; filaActual++)
    {
        for(int columnaActual = 0; columnaActual < cantidadColumnas; columnaActual++)
        {
            printf("ingrese un numero para la posicion [%d][%d] \n", filaActual, columnaActual);
            fflush(stdin);

            scanf("%d", &matriz[filaActual][columnaActual]);
        }
    }
}

/// ----------------------------------------------------

void mostrarMatriz(int matriz[][MAX_COL], int filas, int columnas)
{
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            printf("[%d]", matriz[i][j]);
        }
        printf("\n");
    }
}

void inicMatriz(int matriz[][MAX_COL], int filas, int columnas)
{
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            matriz[i][j] = 0;
        }
    }
}

void inicRandom(int matriz[][MAX_COL], int filas, int columnas)
{
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            matriz[i][j] = 50 + (rand() % (100 - 51));
        }
    }
}



