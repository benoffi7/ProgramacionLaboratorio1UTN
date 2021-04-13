#include <stdio.h>
#include <stdlib.h>
/////PROTOTIPADO O DISENO DE LA FUNCION
//TIPO_DE_SALIDA NOMBRE_FUNCION(TIPOS DE PARAMETROS); /// realiza tal cosa...
//
//
/////IMPLEMENTACION DE LA FUNCION
//TIPO_DE_SALIDA NOMBRE_FUNCION(PARAMETROS FORMALES)
//{
//    CUERPO_DE_FUNCION
//
//}

///1.... N-1
///Diseñe una función que reciba un número entero N y
///realice la suma de los números enteros positivos menores que N
///y lo retorne.
///N es un  dato ingresado por el usuario en el main.


///prototipado
int suma_menores_N(int); ///suma los numeros enteros positivos menores que el numero pasado por parametro



///ambito de suma_menores_N
int suma_menores_N(int M)
{
    int resultado; ///defino acumulador
    resultado = 0; //neutro de la suma es mi inicial del acumulador
    int i=1;
//    for (int i = 1; i < M; i++)
//    {
//        resultado = resultado + i;
//    }
    while (i < M)
    {
        resultado = resultado + i;
        i++;
    }

    return resultado;
}



///ambito main
int main()
{
    int N;
    int resultado;
    printf("Ingrese el valor para N\n");
    scanf("%i",&N);
    resultado = suma_menores_N(N); ///llamada a la funcion enviandole como parametro POR VALOR N
    printf("La suma es: %i",resultado);
    return 0;
}

