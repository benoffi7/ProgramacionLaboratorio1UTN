#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 20

void cargaPalabrasValidos(char nomyAp[][COLS], int edades[], int* validos)
{
  char seguir = 's';
  int i = *validos;
  while (i < ROWS && seguir == 's')
  {
      printf("Ingrese nombre y apellido\n");
      fflush(stdin);
      gets(nomyAp[i]);
      printf("Ingrese la edad\n");
      scanf("%i", &edades[i]);
      printf("desea continuar\n");
      fflush(stdin);
      scanf("%c",&seguir);
      i++;
  }

  *validos = i;

}

void muestraArregloPalabras(char arreglo[][COLS], int validos)
{
    for (int i = 0 ; i < validos ; i++)
    {
        //printf("%s\n",arreglo[i]);
        puts(arreglo[i]);
    }
}




int main()
{
   char nombreYApellidos[3][20];
   int edades[ROWS];
   int validos=0;

    return 0;
}
