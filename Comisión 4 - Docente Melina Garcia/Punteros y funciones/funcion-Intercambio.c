#include <stdio.h>
#include <stdlib.h>

///funcion de intercambio de valores entre 2 variables
////PROTOTIPADO
void intercambio_valores(int*,int*); ///intercambio valores es una f uncion que intercambia el valor de dos variables
///defini la cabecera de mi funcion, diseño de mi funcion








int main()
{
    int a; ///0xf7
    int b; /// 0x42
    int aux;
    a = 10;
    b = 20;

//    aux= b; //aux = 20
//    b=a; // b = 10
//    a=aux; /// a = 20



    intercambio_valores(&a,&b); //intercambio_valores(0xf7,0x42);
    print("a %i,b %i", a,b);
//    a = 20
//    b = 10


    return 0;
}






///implementacion de funcion
void intercambio_valores(int* x, int* y) /// int * x = 0xf7, int* y = 0x42
{
    int aux;
    aux = *x; /// a aux le asigno lo que hay adentro de  la dir que almacena x
    *x = *y;  ///al contenido de la dir que almacena x le asigno el contenido de la dir que almacena y
    *y = aux; ///al contenido de la dir de y le almaceno aux

}
