#include <stdio.h>
#include <stdlib.h>

#define pi 3.14

//PROTOTIPADO, DISENO DE LA FUNCION
//TIPO_DE_SALIDA NOMBRE_FUNCION(TIPOS DE PARAMETROS DE ENTRADA FORMALES); ///hace tal cosa....
int suma_menores_N(int); ///realiza la suma de los enteros positivos menores que el parametro



/*
Diseñe una función que reciba un número entero M y realice la suma de los números enteros positivos menores que N y lo retorne. N es un  dato ingresado por el usuario en el main.
N es un  dato ingresado por el usuario en el main.  */


int main()
{
    int N;
    int suma; ///variable de suma en el main (existe solo en el main)
    printf("Ingrese el valor de N\n");
    scanf("%i",&N);
    suma=suma_menores_N(N); ///llamo a la funcion y le envio como parametro actual mi valor N
    printf("La suma de los numeros positivos menores que N es: %i",suma);


    return 0;
    ///aca no se ejecuta nada
}


// N = 20
// 1..2..3..4..5......19

int suma_menores_N(int M)   /// M = N
{
    int suma; //acumulador local que solo existe en la funcion
    suma = 0; //inicializo en neutro de la suma (0)

    for (int i = 1; i < M; i++) ///i va desde 1 hasta N-1
    {
        suma = suma + i;

    }

    return suma; //genero la salida de suma

    printf("ACA NO SE EJECUTA ESTA LINEA DE CODIGO\n");
}


/////IMPLEMENTACION
//TIPO_DE_SALIDA NOMBRE_FUNCION(PARAMETROS DE ENTRADA FORMALES)
//{
//    CUERPO_DE_LA_FUNCION
//
//}
