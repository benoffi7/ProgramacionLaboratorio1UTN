/**
    Una matriz es un arreglo de dos dimensiones
    4 x 4
              Columnas
              0 1 2 3
    Filas   0 a b c d
            1 e f g h
            2 i j k l
            3 m n o p

    En esta matriz, la posicion 0,0 guarda el valor 'a'.
    Y en la posicion 1,2 se encuentra el valor 'g'.

    Ponemos primero la fila y luego la columna
*/

void ejemplo_matriz()
{
    /// Declaramos una matriz de 3 elementos x 3 elementos
    /// o lo que es lo mismo, decimos que es una matriz de 3x3
    int matriz[3][3];

    /// -----------------------------------------------------------

    /// inicializando matrices

    int unaMatriz[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    int matriz_1[3][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8}
    };

    /// puedo no poner el numero de filas, pero debo poner si o si el
    /// numero de columnas
    int matriz_2[][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int matriz_3[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    /// ambos formas son correctas, pero quizas la primera
    /// sea mas facil para captar la distribucion de sus elementos

    /// -----------------------------------------------------------

    /// mostrando un elemento de la matriz

    printf("el elemento de la posicion 0,0 es: %d \n", matriz_1[0][0]);
    printf("el elemento de la posicion 2,2 es: %d \n", matriz_1[2][2]);
    printf("el elemento de la posicion 1,2 es: %d \n", matriz_1[1][2]);

    /// -----------------------------------------------------------
    printf("\n");

    /// recorriendo una matriz

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("[%d]", matriz_1[i][j]);
        }
        printf("\n"); /// para acomdarlo en pantalla
    }
}

