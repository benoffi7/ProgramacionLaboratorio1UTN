#include <string.h>

void ejemplo_arreglosString()
{
    /**
        Podriamos imaginar un arreglo de string de la siguiente manera

        [0] -> "hola"
        [1] -> "buenos dias"
        [2] -> "mucho gusto"

        Cada posicion del arreglo, contiene un arreglo a su vez, y
        cada caracter esta en una posicion

                0  1  2  3  4  5  6  7  8  9  10
        [0] -> [h][o][l][a]
        [1] -> [b][u][e][n][o][s][ ][d][i][a][s]
        [2] -> [m][u][c][h][o][ ][g][u][s][t][o]
    */

    /// cada string tendra como maximo 100 caracteres
    char matrizString[][100] = {
        {"hola"},
        {"buenos dias"},
        {"mucho gusto"}
    };

    /// mostramos cada palabra
    printf("%s \n", matrizString[0]);
    printf("%s \n", matrizString[1]);
    printf("%s \n", matrizString[2]);

    /// ------------------------------------------------------
    printf("\n");

    /// tambien puedo poner caracteres especiales entre los caracteres
    char otraMatriz[][100] = {
        {"hola \n"},
        {"buenos\tdias \n"},
        {"mucho\0 gusto \n"},
    };

    printf("%s", otraMatriz[0]);
    printf("%s", otraMatriz[1]);
    printf("%s", otraMatriz[2]);

    /// ------------------------------------------------------
    printf("\n\n");

    /// mostrando toda la matriz de string
    for(int i = 0; i < 3; i++)
    {
        printf("%s \n", matrizString[i]);
    }
}

