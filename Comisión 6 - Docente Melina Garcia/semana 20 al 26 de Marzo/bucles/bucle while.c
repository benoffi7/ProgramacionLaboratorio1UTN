#include <stdio.h>
#include <stdlib.h>

///mostrar los primeros N numeros naturales, con N ingresado por el usuario

//definir N como Entero
//definir i como Entero ///mi contador
//i=1 ///inicializo mi contador
//escribir "Ingrese el valor de N"
//leer N
//MIENTRAS i <= N HACER
// escribir i
// i=i+1
//FIN-MIENTRAS




///todo contador : debe estar inicializado en algun valor, es entero, incrementan/decrementan en algun valor fijo.

int main()
{
    int i;  //contador
    int N;
    i=1;
    printf("ingrese el valor de N\n");
    scanf("%i", &N);
    while (i <= N)
    {
        printf("%i ", i);
        i++;  //i=i+1 operador ++ o -- se usa para incremento o decremento en 1
    }
    return 0;
}
