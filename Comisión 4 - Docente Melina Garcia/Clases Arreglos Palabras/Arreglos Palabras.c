#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 3

int main()
{
   char arregloPalabras[3][20];
   char arregloPalabras2[3][20] = {"Juan pablo", "Pedro Rodriguez", "Cristian dior"};
//   j u a n  p a b l o \0
//   p e d r o  r o d r i g u e z \0
//   c r i s t i a n  d i o r \0
//
///impresion del arreglo de palabras
    for (int i = 0; i < ROWS ; i++)
    {
        printf("%s\n",arregloPalabras2[i]);
        //puts(arregloPalabras2[i]);
    }

///sin validos
///lectura de cada indice del arreglo de palabras
//
//    for (int i = 0 ; i < ROWS ; i++)
//    {
//        printf("Ingrese una frase o palabra\n");
//        gets(arregloPalabras[i]);
//    }

// ///impresion del arreglo de palabras
//    for (int i = 0; i < ROWS ; i++)
//    {
//        printf("%s\n",arregloPalabras[i]);
//        //puts(arregloPalabras2[i]);
//    }

///con un validos
   int i = 0;
   char seguir;
   int validos;
     do
     {
         printf("Ingrese una frase o palabra\n");
         fflush(stdin);
         gets(arregloPalabras[i]);
         i++;
         printf("Desea continuar\n");
         fflush(stdin);
         scanf("%c",&seguir);
     }while(i < ROWS && seguir == 's');

  validos = i;
///impresion de arreglo palabras con validos
    for (int i = 0 ; i < validos ; i++)
    {
        printf("%s\n",arregloPalabras[i]);
        //puts(arregloPalabras[i]);

    }

    return 0;
}
