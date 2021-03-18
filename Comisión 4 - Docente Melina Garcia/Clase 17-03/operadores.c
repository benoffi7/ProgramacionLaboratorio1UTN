#include <stdio.h>
#include <stdlib.h>
#define AFIP 0.21 ///estoy creando la constante
#define NUMERO5 5

///Real --->  float
///Entero ---> int
///Caracter ---> char (UN SOLO CHAR)

int main()
{
    int numero1; ///  definir numero como entero
    int numero2;
    float resultado;
    int resultadoRel;
    int tamano;
    printf("Ingrese un numero entero\n");
    scanf("%i", &numero1);///leer numero
    printf("Ingrese otro numero entero\n");
    scanf("%i", &numero2);

///suma
    resultado = numero1 + numero2;
    printf("La suma es %i\n", (int)resultado);
///resta
    resultado = numero1 - numero2;
    printf("La resta es %i\n", (int)resultado);
///multiplicacion
    resultado = numero1 * numero2;
    printf("La multiplicacion es %i\n", (int)resultado);
///division
    resultado = (float)numero1 / numero2;
    printf("La division es: %f\n",resultado);

///operadores relacionales necesitan de dos operandos
/// > >= < <= == !=

///> <
    resultadoRel = (numero1+numero2) > (numero1*numero2);
    printf("El resultado de %i > %i es: %i",numero1+numero2,numero1*numero2,resultadoRel);

///operadores logicos
/// && || !
    resultadoRel = (numero1 != 0) && (numero2/numero1 > 10);
    printf("\nEl resultado de %i && %i es: %i",numero1,numero2,resultadoRel);
    resultadoRel = numero1 || numero2;
    printf("\nEl resultado de %i || %i es: %i",numero1,numero2,resultadoRel);
    resultadoRel = !(numero1 > numero2);
    printf("\nEl resultado de !%i>%i es: %i",numero1,numero2,resultadoRel);

///sizeof() ///nos devuelve el tamano en bytes de la variable que pongamos dentro del parentesis
    tamano = sizeof(numero1);
    printf("\nEl tamano de numero1 es %i", tamano);


    return 0;
}

//p  q  pANDq
//1  1   1
//0  1   0
//1  0   0
//0  0   0

//p  q  OR
//1  1  1
//0  1  1
//1  0  1
//0  0  0

///casting: hacer que una variable se comporte como otro tipo
/// definir var1 como Logico --> VERDADERO o FALSO /// NO EXISTE EN C!!!
/// todo numero distinto de 0 es VERDADERO en una operacion logica
