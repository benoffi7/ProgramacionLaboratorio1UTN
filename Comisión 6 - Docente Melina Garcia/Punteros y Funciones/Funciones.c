#include <stdio.h>
#include <stdlib.h>

//TIPO_DE_SALIDA NOMBRE_FUNCION(PARAMETROS DE ENTRADA)
//{
//    CUERPO DE LA FUNCION
//
//    RETURN DE VALOR ///si es que hay
//}

//funcion de intercambio de valores entre 2 variables y se debe ver afectado en la funcion principal

void intercambiar_valores_variables(int* x, int* y)
{
   int aux;
   aux = *x; ///aux = a
   *x = *y; /// a= b
   *y = aux; /// b= aux
}


int main()
{
    int a; ///0x55
    int b;  ///0x44
    int aux;
    a=15;
    b=10;

    aux = a; 15
    a=b; 10
    b=aux; 15


    intercambiar_valores_variables(&a,&b); //intercambiar_valores_variables(0x55,0x44);

    /// a = 10
    /// b = 15



    return 0;
}












//int sumar_diez(int x) ///0x555
//{
//   x = x + 10;
// return x;
//}
//
//
//
//void cambiar_valor(int *h) ///0x44  x = 0x44
//{
//    *h=18;
//
//}
//
//void muestra_valor(int x)
//{
//    printf("%i",x);
//}
//
////int numero_global = 20;
////variables globales no se usan jamas!!
//
//
//
//int main()
//{
//   int numero; //0x44
//   numero=5;
//
//   cambiar_valor(&numero); //cambiar_valor(0x44);
//   muestra_valor(numero);
//
//    return 0;
//}
