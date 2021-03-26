#include <stdio.h>
#include <stdlib.h>
///mostrar los primeros N numeros naturales, con N ingresado por el usuario

//N=10
//1
//2
//3
//4
//5
//6
//7
//8
//9
//10  (HASTA N)

///contador
//-es entero
//-debe estar inicializado
//-avanza en un valor fijo

int main()
{
    int N;
   // int i; //contador
    printf("Ingrese un valor para N\n");
    scanf("%i", &N);
    ///mostrar desde 1 hasta N
    for (int i=1; i<=N; i=i+1) //la variable dentro del for es una variable contador
    {
        printf("%i ", i);
    }
    printf("\n");

    /// mostrar desde N hasta 1
    for (int j=N ; j>0 ; j=j-1) //j--
    {
        printf("%i ", j);
    }

    return 0;
}

//definir N como entero
//definir i como entero //contador, es aquel que incrementa en un valor fijo
//escribir "Ingrese el valor de N"
//leer N
//Para i = 1 HASTA N Con Paso 1 hacer
//    escribir i
//Fin-Para
//
//i=1
//  i<=N ?
//    1
//     i++ //2
//       i<=N
//         2
//        i++ //3
//         i<=N
//            3
//            i++ // 4
//              i<=N
//                4
