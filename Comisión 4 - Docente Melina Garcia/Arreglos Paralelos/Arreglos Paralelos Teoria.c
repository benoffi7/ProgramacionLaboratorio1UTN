#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 10

int busquedaPosDni(int dnis[],int dni, int validos)
{
    int pos=-1;
    int i =0;
    while (i < validos && dnis[i] != dni)
    {
        i++;
    }
    if (i < validos)
    {
        pos = i;
    }

    return pos;

}



int carga(int dnis[],int edades[],int alturas[], int pesos[])
{
    char seguir;
    int i =0;
    do
    {
        printf("Ingrese un dni\n");
        scanf("%i",&dnis[i]);
        printf("Ingrese la edad\n");
        scanf("%i",&edades[i]);
        printf("Ingrese la altura\n");
        scanf("%i",&alturas[i]);
        printf("Ingrese el peso\n");
        scanf("%i",&pesos[i]);
        printf("Desea ingresar otro dato?\n");
        fflush(stdin);
        scanf("%c",&seguir);
        i++;
    }while (i < CANT_MAX && seguir == 's');

    return i;
}

void mostrarDatosDeUnaPos(int dnis[], int edades[],int alturas[],int pesos[], int pos)
{

        printf("La edad es: %i", edades[pos]);
        printf("La altura es: %i", alturas[pos]);
        printf("El dni es: %i", dnis[pos]);
        printf("El peso es: %i", pesos[pos]);


}


int main()
{
  int dnis[CANT_MAX];
  int edades[CANT_MAX];
  int alturas[CANT_MAX];
  int pesos[CANT_MAX];
  int validos = carga(dnis,edades,alturas,pesos);
///arreglo paralelo: arreglos que se encuentran relacionados bajo un mismo indice
///los arreglos paralelos tienen la misma cantidad de datos
  int dni;
  int pos;
  printf("Ingrese dni a buscar\n");
  scanf("%i",&dni);
  pos=busquedaPosDni(dnis,dni,validos);
    if (pos != -1)
    {
        mostrarDatosDeUnaPos(dnis,edades,alturas,pesos,pos);
    }
    return 0;
}
