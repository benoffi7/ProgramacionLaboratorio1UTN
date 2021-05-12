#include <stdio.h>
#include <stdlib.h>
#define ROWS 8
#define COLS 8

void carga_completa_Matriz_filas(int mat[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("ingrese un dato\n");
            scanf("%i", &mat[i][j]);///ingreso un dato en la fila i columna j, mat[i,j]
        }
    }

}


void carga_completa_Matriz_columnas(int mat[][COLS])
{
    for (int j=0; j < COLS; j++)
    {
        for (int i = 0; i < ROWS ; i++)
        {
            printf("ingrese un dato\n");
            scanf("%i", &mat[i][j]);
        }
    }

}
//ROWS = 3
//COLS = 3
//  0 1 2
//0
//1 3 6 7
//2 8 4 5

void carga_completa_Matriz_inversa_filas(int mat[][COLS])
{
    for (int i=ROWS-1; i >=0 ; i--)
    {
        for (int j=COLS-1; j>=0 ; j--)
        {
            printf("ingrese un dato\n");
            scanf("%i", &mat[i][j]);
        }
    }

}

void carga_completa_Matriz_inversa_columnas(int mat[][COLS])
{
    for (int j=COLS-1; j>=0; j--)
    {
        for (int i=ROWS-1; i>=0 ; i--)
        {
            printf("ingrese un dato\n");
            scanf("%i",&mat[i][j]);
        }
    }
}

//1 0 0
//0 1 0
//0 0 1
///mat[0][0] mat[1][1] mat[2][2]
void carga_diagonal_principal(int mat[][COLS]) ///MATRIZ CUADRADA ROWS = COLS
{
    for( int i = 0; i < ROWS ; i++)
    {
        mat[i][i] = 1;
    }

}


int suma_total(int mat[][COLS])
{
    int suma=0; ///acumulador
    for (int i = 0 ; i < ROWS ; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            suma = suma + mat[i][j];
        }
    }
    return suma;
}

///cargar un arreglo con la suma de los elementos de cada fila de la matriz
///el arreglo es de tamano ROWS
void suma_fila(int mat[][COLS], int arr[])
{
    int sumaFila=0;
    for (int i = 0 ; i < ROWS ; i++)
    {
        for (int j = 0 ; j < COLS ; j++)
        {
            sumaFila = sumaFila + mat[i][j];
        }
        arr[i] = sumaFila;
        sumaFila=0;
    }
}
//validosfila = 2; //
//validosColumna = 2 //
//me conviene elegir un criterio, o validoscolumna, o validosfila, para no generar baches

///carga de una matriz donde en FILAS puede no estar completa, en columnas si
int carga_Matriz_filas_validos(int mat[][COLS])
{
    int i = 0;
    char continuar= 's';
    while (i<ROWS && continuar == 's')
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("ingrese un valor\n");
            scanf("%i", &mat[i][j]);
        }
        printf("desea ingresar otra fila?\n");
        fflush(stdin);
        scanf("%c",&continuar);
        i++;
    }

    return i; ///i son los validosFila
}


  0 1 2
0 5 2 3
1
2

///carga matriz por filas validos usando ultima fila cargada como referencia
void carga_Matriz_filas_validosF(int mat[][COLS], int* validosF)
{
    int i= *validosF;
    char continuar = 's';
    while (i<ROWS && continuar == 's')
    {
        for (int j=0; j < COLS ; j++)
        {
            printf("ingrese un valor\n");
            scanf("%i",&mat[i][j]);
        }
        printf("desea ingresar otra fila?\n");
        fflush(stdin);
        scanf("%c",&continuar);
        i++;
    }
    *validosF = i; ///actualizo validosF
}


int main()
{
    // int matriz[8][8]; //matriz[filas][columnas]
    int matriz[ROWS][COLS] = {0};

    ///carga completa de la matriz

    return 0;
}
