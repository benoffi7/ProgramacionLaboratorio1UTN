#include <stdio.h>
#include <stdlib.h>

/**Realizar una función que reciba dos números enteros por parámetro
 por referencia y cargue sus valores el usuario dentro de la función.
**/


/**
prototipado
1- orden del codigo
2- por que el compilador lee secuencial

**/

///prototipado
void carga_valores(int*,int*); ///El usuario carga 2 valores enteros recibidos por referencia
void muestra_valores(int,int); ///muestra los valores de 2 variables recibidas por parametro



int main()
{
    int num1;
    int num2;
    carga_valores(&num1,&num2); ///por referencia, envio direcciones de memoria
    muestra_valores(num1,num2); /// por valor, envio valores enteros char float..
    return 0;
}



//implementacion
void carga_valores(int* n1,int* n2) ///parametros por referencia (reciben direcciones de memoria)
{
    printf("Ingrese el valor del numero 1\n");
    scanf("%i",n1);
    printf("Ingrese el valor del numero 2\n");
    scanf("%i",n2);
}

//implementacion
void muestra_valores(int n1, int n2) ///parametros por valor (reciben valores int,char..float)
{
    printf("num1: %i", n1);
    printf("num2: %i", n2);
}
