#include <stdio.h>
#include <stdlib.h>
#define pi 3.14

///void significa vacio (ningun tipo de valor a retornar o asignar)
void main()
{
    int numero1; //4 bytes
    int numero2;  // ocupan 4 bytes///
    int resultado2; // definir resultado2 como Logico
    float resultado;


printf("Esta almacenada en la dir: %i", &resultado2);



///suma
    printf("Ingrese primer valor\n");
    scanf("%i", &numero1);
    printf("Ingrese el 2do valor\n");
    scanf("%i", &numero2);
    resultado = numero1 + numero2;
    printf("El resultado de la suma es: %i\n", (int)resultado);
///resta
   resultado = numero1 - numero2;
   printf("el resultado de la resta es: %f\n", resultado);
///multiplicacion
   resultado = numero1 * numero2;
   printf("el resultado de la multiplicacion es: %f\n", resultado);
///division
   resultado = (float)numero1 / numero2;
   printf("el resultado de la division es %f\n", resultado);

///operadores de comparacion == > < != >= <=

resultado2 = numero1 == numero2;  /// si numero1 > numero2 me devuelve verdadero ( 1) , si no me devolvera falso ( 0 )
printf("El resultado de %i == %i es: %i\n",numero1,numero2,resultado2);

/// operadores logicos &&  ||  !
resultado2 = (numero1!=0) && (numero2/numero1 > 6);
printf("El resultado de %i && %i es %i\n",numero1,numero2,resultado2);
resultado2 = !numero1;
printf("El resultado de !%i es %i\n",numero1,resultado2);
resultado2 = (numero1>5) || (numero2>10);
printf("El resultado de %i || %i es %i\n",numero1,numero2,resultado2);
}

//p  q  AND
//1  1   1
//0  1   0
//1  0   0
//0  0   0

//p  q   OR
//1  1   1
//0  1   1
//1  0   1
//0  0   0

///cualquier numero distinto de 0 sujeto a una operacion logica es VERDADERO (1)
///casting es una operacion que permite cambiar el comportamiento de una variable, para que se comporte como otro tipo
