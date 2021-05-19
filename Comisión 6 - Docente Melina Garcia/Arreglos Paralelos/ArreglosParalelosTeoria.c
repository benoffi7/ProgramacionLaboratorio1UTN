#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 5
///relacionar categorias con valores enteros
///categoria 'a' 25 puntos  'b' 38 puntos
int main()
{
   char categorias[TAM_MAX];
   int puntos[TAM_MAX];

a  b  c  d  e  f  g ...
0  1  2  3  4  5  6..

22 23 24 8  7  9  5...
0  1  2  3  4  5  6..

   ///digame los puntos que tiene la categoria 'h'
   ///recorro el arreglo de categorias buscando el 'h' retorno el indice
   ///puntos de esa categroia van a ser encontrados en el arreglo de puntos en ese mismo indice

  int dnis[CANT_MAX];
  int edades[CANT_MAX];
  float alturas[CANT_MAX];
  float pesos[CANT_MAX];

///indice 0, dni de la persona en el arreglo de dnis
///su edad en el arreglo de edades
/// su altura en el arreglo de alturas
///su peso en el arreglo de pesos
///todo bajo el mismo indice!


///los arreglos paralelos son arreglos que estan relacionados por un indice
///deben tener misma cantidad de datos


///cuando me pidan ordenar arreglos paralelos, por ejemplo por dni
///ordenare con el criterio del arreglo de dnis pero al mismo tiempo cambiando el resto
///de los datos tambien en los otros arreglos (usanddo el mismo indice)


    return 0;
}
