#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 10

///validos LA CANTIDAD DE DATOS CARGADA

///prototipado
int carga(int[],int); ///algoritmo de carga del arreglo desde 0
void muestra(int[],int); ///recorre y muestra las celdas del arreglo cargadas
void cargaPro(int[],int*);

///implementacion
int carga(int arr[], int validos)
{
    char seguir;
    int i=validos; ///subindice, validos
    do
    {
        printf("Ingrese un valor\n");
        scanf("%i", &arr[i]);
        printf("desea seguir s/n \n");
        fflush(stdin);
        scanf("%c",&seguir);
        i++;
    }
    while(seguir == 's' && i < TAM_MAX);

    return i;
}


void muestra(int arr[], int validos)
{
    for (int i = 0; i < validos ; i++)
    {
        printf("[%i]", arr[i]);
    }
}

void cargaPro(int arr[],int* validos)
{
    char seguir;
    do
    {
        printf("Ingrese un valor\n");
        scanf("%i",&arr[*validos]);
        printf("desea seguir s/n \n");
        fflush(stdin);
        scanf("%c",&seguir);
        *validos = *validos + 1;
        //(*validos)++;

    }while(seguir == 's' && *validos < CANT_MAX);

}


int main()
{
    int arreglo[TAM_MAX];
    int validos=0;
    //validos = carga(arreglo,validos);
    cargaPro(arreglo,&validos);
    muestra(arreglo,validos);


    return 0;
}
