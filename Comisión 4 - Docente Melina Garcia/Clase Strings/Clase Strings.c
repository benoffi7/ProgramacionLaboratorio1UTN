#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///Un string es un array (arreglo o vector) de caracteres
///un arreglo de caracteres se puede recorrer caracter a caracter
///existen funciones que forman parte de una libreria de C en donde se puede manipular
///estos arreglos como si fueran un bloque de caracteres (palabras o frases)

int main()
{
 char palabra[6] = "tomas";  /// 0---4   /// '\0' para avisar que el string termina ahi
 char palabra2[] = {'t','o','m','a','s','\0'};
 char palabra3[20];
// for (int i = 0 ; i < 5 ; i++)
// {
//     printf("%c",palabra2[i]);
// }
//  for (int i = 0 ; i < 5 ; i++)
// {
//     printf("%c",palabra[i]);
// }

// printf("\n %s",palabra);
// printf("\n %s",palabra2);
//  printf("Ingrese una palabra\n");
  fflush(stdin);
  //scanf("%s", palabra3); //me lee hasta el espacio ( lo considera especial)
 //printf("\n %s", palabra3);
 int tam;

///funciones de la libreria string.h
 //  gets(palabra3); ///me lee caracteres especiales, me agrega el '\0'
   ///'h' 'o' 'l' 'a' '\0' ' ' ' ' ' ' ' ' ' '
//   printf("\n %s", palabra3);
//   puts(palabra3); /// su funcion es imprimir una cadena de caracteres (igual que printf %s)
///contar la cantidad de caracteres del string
   tam=strlen(palabra3); /// nos devuelve la longitud del string sin el terminator
/// comparar dos strings
  strcmp(palabra3,palabra2); ///retorna un valor
  /** negativo < 0 si palabra2 es mas grande a palabra3
      positivo > 0 si palabra3 es mas grande a palabra2
      0 si son iguales
      TOMAS != tomas
      ToMaS != tomas

  **/
  strcmpi(palabra3,palabra2);
    /** negativo < 0 si palabra2 es mayor a palabra3
      positivo > 0 si palabra3 es mayor a palabra2
      0 si son iguales
      IGNORA MAYUSCULAS Y MINUSCULAS
      TOMAS = tomas
      ToMaS = tomas

  **/
//  if (strcmp(palabra3,palabra2) == 0)
//  {
//      printf("Son iguales\n");
//  }
//  else
//  {
//     if (strcmp(palabra3,palabra2) > 0)
//     {
//         printf("palabra3 es mayor a palabra2");
//     }
//     else
//        printf("palabra2 es mayor a palabra3");
//  }
///copiar un string en otro
//palabra3 = palabra2/// !!! ESTO NO
strcpy(palabra3,palabra2); ///copio a palabra3 lo que hay en palabra2
///palabra3= 'j' 'u' 'a' 'n' 'd' 'n' '\0'
///strcpy(palabra3,"teo");
///palabra3 = 't' 'e' 'o' '\0' 'd' 'n' '\0'
puts(palabra3);

///strconcat
///ARREGLO DE PALABRAS
//
//char palabras[3][10] = {"juan","pepe","pablo"};
//'j' 'u' 'a' 'n' '\0'
//'p' 'e' 'p' 'e' '\0'
//'p' 'a' 'b' 'l' 'o' '\0'

    return 0;
}
