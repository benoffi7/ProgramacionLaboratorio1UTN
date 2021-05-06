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

1 7 4
2 3 4
1 1 0


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

//matriz 3x3
//0 4 3
//4 6 8   validosF = 2
//
//matriz 3x3
//cuantas columnas desea cargar? 2 validosC=2
//6  5  ""
//9  2  ""  validosF = 2
//"" "" ""

//tenemos que elegir solo uno de los dos validos, validos para filas O para columnas, pero
//no para ambos

//6  5  3
//9  2  5  validosF = 2
//5  4  2

//validosF esta inicializado en el main en 0
void cargaMatrizValidosF(int mat[][COLS], int* validosF)
{
    int i= *validosF;
    char continuar = 's';
    while( i < ROWS && continuar == 's')
    {
        for (int j = 0 ; j < COLS ; j++)
        {
            printf("Ingrese un valor para la celda %i,%i", i,j);
            scanf("%i", &mat[i][j]);
        }
        i++;
        printf("desea continuar?\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    *validosF = i;
}

///busqueda de un dato en una matriz cargada completamente
///informar que se encontro
void busquedaIndice(int mat[][COLS],int dato)
{
    int i = 0;
    int j;
    int flag=0; ///indicador
    while (i < ROWS && flag == 0)
    {
        j=0;
        while (j < COLS && mat[i][j] != dato)
        {
            j++;
        }

        if (j < COLS)
        {
            flag = 1;
        }

        i++; /// i = i + 1
    }

    if (flag == 1)
    {
        printf("se encontro el dato\n");
    }

}
///indI e indJ llegan con valores -1.
void indicesBusquedaDato(int mat[][COLS], int dato, int* indI, int* indJ)
{
    int i,j;
    i=0;
    int flag=0;
    while (i < ROWS && flag == 0)
    {
        j=0;
        while (j<COLS && mat[i][j] != dato)
        {
            j++;
        }
        if (j<COLS)
        {
            flag=1;
        }
        else
        {
            i++;
        }
    }
    if (i< ROWS)
    {
        *indI = i;
        *indJ = j;
    }
    else ///deberian estar inicializadas en el main
    {
        *indI=-1;
        *indJ=-1;
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

void mostrarMatriz(int mat[][COLS])
{
    for (int i = 0; i < ROWS ; i++)
    {
        for (int j = 0 ; j < COLS ; j++)
        {
            printf("[%i]\t",mat[i][j]);
        }
        printf("\n");
    }


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
    int validos=0;
    int indI=-1;
    int indJ=-1;
    int dato;
    printf("Ingrese un valor a buscar\n");
    scanf("%i", &dato);
    cargaMatrizValidosF(matriz,&validos);
    indicesBusquedaDato(matriz,dato,&indI,&indJ);
    ///carga completa de la matriz

    return 0;
}
