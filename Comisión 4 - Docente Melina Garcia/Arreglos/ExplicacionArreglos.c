#include <stdio.h>
#include <stdlib.h>

///defino una constante que determinara la cantidad maxima de datos uqe puedo cargar
#define CANTMAX 10


int main()
{
    int miarreglo[50]; ///coleccion de 50 posiciones, puedo almacenar hasta 50 datos
    ///las posiciones van de 0 a 49
    int miarreglo2[50] = {1,2,8,4,3}; /// 1 2 8 4 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ... 0
                                      /// 0 1 2 3 4 5 6  ...                        49
    int miarreglo3[] = {3,4,7,8}; ///arreglo inicializado de 4 posiciones
    /// si yo no especifico tamano en corchetes, tendra la cantidad de datos que figura a la deerecha

    ///int miarreglo4[]; ESTO NO

//    miarreglo[0] = 4;
//    miarreglo[3] = 8;
//    miarreglo[6] = 25;
//    miarreglo[24] = 40;
//
//    4 _ _ 8 _ _ 25 _ _ _ _ ...... _ 40 _ _ _ ...
//
//    4 25 8 40 _ _ _ _ _ _ _ ....
//    0 1 2  3
//
//    validos = 4 ///cantidad de datos valida


    ///carga de un arreglo

    int arreglo[CANTMAX]; //declaracion de arreglo de CANTMAX elementos (20)
    char seguir;
    int validos; //contador de posiciones validas en el arreglo (cargadas)
    validos = 0; ///inicializacion
    do
    {
        printf("Ingrese un valor\n");
        scanf("%i",&arreglo[validos]);
        printf("Desea seguir cargando?S\N \n");
        fflush(stdin);
        scanf("%c",&seguir);
        validos++; ///incremento posicion

    }while(seguir == 's' && validos < CANTMAX);
    ///mientras el usuario aprete s y la cantidad cargada de datos sea menor a la maxima

    ///muestra del arreglo
    for (int i = 0; i < validos; i++)
    {
        printf("%i ", arreglo[i]);

    }






    return 0;
}
