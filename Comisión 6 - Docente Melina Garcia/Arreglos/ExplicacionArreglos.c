#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 25

int main()
{

 int arreglo[TAM_MAX]; ///se genera en tiempo de compilacion

 arreglo[2] = 5;
 arreglo[6] = 8;
 arreglo[15] = 4;

// _ _ 5 _ _ _ 8 _ _ _ _ .... 4 _ _ .... _
// 0 1 2 3 4 5 6 7 8 9 10    15 16 17... 24

// 5 8 4 _ _ _ _ _ ... _
// 0 1 2 3 4 5 6 7     24
///debo darle un cierto orden en el ingreso de datos


 ///declaracion e inicializacion

 int arreglo2[TAM_MAX] = {5,4,7,1,8}; ///esta declaracion e inicializacion
 ///arreglo capaz de almacenar 25 datos, con 5 datos cargados y el resto 0

 int arreglo3[] = {5,4,7,1,8};
 ///arreglo de 5 datos

 arreglo3[2] = 40;

 int arreglo4[]; ///NO



    return 0;
}
