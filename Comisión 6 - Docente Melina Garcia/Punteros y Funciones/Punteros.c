#include <stdio.h>
#include <stdlib.h>

///puntero es un tipo de variable que almacena direcciones de memoria

//    10101010101010110100101011001010101
//   0xff4
//   direccion de memoria esta almacenando un dato de tipo entero
//    10100101
//   0x44
//   direccion de memoria esta almacenando un dato de tipo char

//int 4 bytes
//char 1 byte
//float 4 bytes


int main()
{
 int* puntero; ///es un puntero a un entero
 ///almacena direccion de memoria de una variable de tipo entero
 int numero; // numero 0x44
 numero = 5;
 puntero = &numero; // puntero = 0x44 //puntero esta almacenando la direccion de memoria de numero

 printf("numero: %i\n", numero);


 ///al contenido de la direccion de memoria que almacena puntero cambialo por un 10
  *puntero = 10;
  *puntero = *puntero + 1;
  printf("puntero: %i\n",puntero);

  printf("numero despues de modificarse: %i", *puntero);

   return 0;

}



  ///a traves del operador indireccion me meto adentro de la direccion de memoria
  /// que almacena puntero y le asigno un 10
