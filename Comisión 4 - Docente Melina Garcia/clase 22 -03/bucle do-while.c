#include <stdio.h>
#include <stdlib.h>
///muestre los numeros naturales desde 1 hasta que el usuario diga basta.
#define MAX 10


int main()
{
  int i; //contador
  char seguir; //variable de corte //'s' o 'n'
  i=1; //inicializo contador

///usando while
//seguir ='s'; ///forzar la variable seguir para que se de verdadera la condicion del while y se ejecute
//  while (seguir == 's')
//  {
//      printf("%i\n", i);
//      i++;
//      printf("Desea seguir viendo numeros naturales? s/n \n");
//      fflush(stdin); //limpia el buffer de entrada
//      scanf("%c", &seguir);
//      system("cls"); ///limpia la consola
//  }


///como sabemos que necesariamente estamos haciendo que el bucle ejecute al menos una vez
///podemos replicar este comportamiento facilmente usando un bucle do..while
   do
   {
      printf("%i\n", i);
      i++;
      printf("Desea seguir viendo numeros naturales s/n ? \n");
      fflush(stdin);
      scanf("%c", &seguir);
      system("cls"); //limpiar la pantalla
   }while (seguir == 's');


    return 0;
}
///HACER
///
///MIENTRAS QUE CONDICION

///tip ejercicio 3
//int main()
//{
//int numero;
//
//for (int i = 1; i <= MAX ; i++)
//{
//    printf("Ingrese un numero\n");
//    scanf("%i", &numero);
//}
//
//}
