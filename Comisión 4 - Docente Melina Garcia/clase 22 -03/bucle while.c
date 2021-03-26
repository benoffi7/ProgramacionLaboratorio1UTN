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

int main()
{
    int N;
    int i; //contador
    int j;
    i=1; //inicializo contador
    printf("Ingrese un valor para N\n");
    scanf("%i", &N);
    j=N; //inicializo contador j desde el ultimo valor
    while (i <= N) //condicion opuesta : i > N corta mi bucle
    {
      printf("%i ", i);
      //i=i+1;
      i++; //el operador de incremento hace que la variable incremente en 1
    }
    printf("\n");
    ///mostrar desde N hasta 1
    //con este bucle pierdo el valor original de N
    while (N > 0)
    {
        printf("%i ", N);
        N=N-1; //N--;
    }
    printf("\n");
    //necesito mantener el valor original de N
    while (j>0)
    {
        printf("%i ", j);
        j=j-1; //j--;
    }

    return 0;
}
//
//definir N como entero
//definir i como entero //contador, es aquel que incrementa en un valor fijo
//
//i = 1  /// como todo contador debe estar inicializado en algun valor
//escribir "Ingrese un valor para N"
//leer N
//MIENTRAS i <= N HACER
//   escribir i
//   i=i+1
//FIN-MIENTRAS

