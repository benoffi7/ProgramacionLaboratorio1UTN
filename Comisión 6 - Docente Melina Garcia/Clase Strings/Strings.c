#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///String es una cadena de caracteres, un arreglo de caracter (vector,array).
/// '\0' terminator, es un caracter
int main()
{
    char palabra[] = {'t','o','m','a','s','\0'}; //6
    char palabra2[] = "tomas es un genio"; //el terminator en esta inicializacion se agrega automaticamente
    char palabra3[20];
//    for (int i = 0; i < 5 ; i++)
//    {
//        printf("%c",palabra[i]);
//    }

//     printf("%s\n", palabra2);
//     printf("%s",palabra);
//     printf("Ingrese una palabra:");
//     fflush(stdin);
//     scanf("%s",palabra3); ///scanf lee hasta que encuentra un terminator o un espacio
//     printf("\n%s", palabra3);

///string.h me permite tratar a los arreglos de caracteres exclusivamente como strings
//    printf("Ingrese una cadena de caracteres\n");
//    ///gets es una funcion que nos permite ingresar una cadena de caracteres por teclado
//    ///incluye espacios y caracteres especiales, y al finalizar agrega el terminator.
//    gets(palabra3);
//    ///puts es una funcion que imprime una cadena de caracteres hasta el terminator.
//    puts(palabra3);
    ///strcmp(op1,op2) devuelve un entero.  Es sensible a mayusculas y minusculas
    /// Pepe != pepe
    ///op1 > op2 devuelve > 0
    ///op1 < op2 devuelve < 0
    /// op1 = op2 devuelve = 0
//    if (strcmp(palabra2,palabra3) == 0)
//    {
//        printf("son iguales");
//    }
//    else if(strcmp(palabra2,palabra3) > 0)
//    {
//        printf("palabra2 es mas grande que palabra2");
//    }
//    else
//        printf("palabra3 es mas grande que palabra2");

    ///strcmpi(palabra2,palabra3) no diferencia mayusculas de minusculas.
    ///op1 > op2 devuelve > 0
    ///op1 < op2 devuelve < 0
    /// op1 = op2 devuelve = 0

    ///strcpy(palabra3,palabra2) copia un string en otro junto con el terminator.
    //palabra3 = palabra2;
//    char palabra3[] = "hola me llamo juan soy de palermo"
//    char palabra2[] = "tomas es un genio";
//    strcpy(palabra3,palabra2);
//    palabra3:  tomas es un genio\0n soy de palermo\0


    ///strlen(palabra3) nos devuelve cuantos caracteres contiene mi string, sin contar el terminator
    ///longitud de mi cadena de caracteres


///ARREGLOS DE PALABRAS
  char arreglo_palabras[3][20]; ///3 cadenas de caracteres de 20 caracteres de longitud
  char arreglo_palabras2[3][20]= {"juan","pepe","julieta"};
  char arreglo_palabras3[4][20];
//    0 1 2 3 4 5 6 7
//  0 j u a n \0
//  1 p e p e \0
//  2 j u l i e t a  e s  m i  a m i g a \0

  for (int i = 0 ; i < 3 ; i++)
  {
      printf("%s\n",arreglo_palabras2[i]);
  }
  ///ingreso de palabras en mi arreglo de palabras

  for (int i=0; i<4 ; i++)
  {
      printf("Ingrese una frase o palabra\n");
      gets(arreglo_palabras3[i]);
  }

    for (int i = 0 ; i < 4 ; i++)
  {
      printf("%s\n",arreglo_palabras3[i]);
  }


    return 0;
}
