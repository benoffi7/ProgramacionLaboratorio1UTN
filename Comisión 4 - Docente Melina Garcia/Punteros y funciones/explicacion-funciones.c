#include <stdio.h>
#include <stdlib.h>

#define IVA 0.21  ///NO SE PUEDE MODIFICAR


///PUNTEROS

TIPO_SALIDA nombre_FUNCION(ENTRADAS)
{

 CUERPO_DE_FUNCION
}

TIPO_SALIDA VOID es cuando no queremos devolver ningun valor ///funcion sin retorno, sin salida

///VARIABLE GLOBAL, existe en cualquier ambito
int numerito; ///0x4597


//int suma(Pila NN)  ///Pila NN es un parametro FORMAL
//{
//    int*puntero; ///variable local a la funcion
//    int descarte; ///variable local a la funcion
//    int sum=0; ///0x457
//    while (!pilavacia(&a))
//    {
//        descarte = desapilar(&a);
//        sum = sum + descarte;
//    }
//  return sum;
//}

///el nombre de la funcion TRATEN de que sea el objetivo que realiza dentro
void cambioValor(int* direccion)  ///0x887632  x = 0x45
{
    ///ambito de cambioValor, finaliza cuando terminan las sentencias de la funcion.

    *direccion = 50;

}


int main()
{
///ambito de main, finaliza cuando el proceso termina.

    int num; ///0x45
    num=10;
    printf("%i\n", num);
    cambioValor(&num);   ///cambioValor(10);
    printf("%i\n", num);




//    Pila dada;
//    int sum; /// 0x3f8
//    inicpila(&dada);
//    apilar(&dada,5);
//    apilar(&dada,8);
//    apilar(&dada,3);
//    sum =suma(dada); ///LLAMADA A LA FUNCION, enviando como PARAMETRO ACTUAL dada

    return 0;

}
