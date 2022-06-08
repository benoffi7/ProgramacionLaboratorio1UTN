#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int unDato;

    printf("Hello archivos!\n");

    char rutaDelArchivo[]= {"archivoDeEnteros.dat"};

    FILE * archivoDeEnteros = fopen(rutaDelArchivo, "ab");

    if(archivoDeEnteros==NULL)
    {
        printf("El archivo no existe!");
    }
    else
    {
        printf("El archivo se abrio con exiiiito!");

        for(int i =0; i<5; i++)
        {
            unDato=rand()%100;

            ///TODO capturar el valor de retorno de la fn
            fwrite(&unDato, sizeof(int), 1, archivoDeEnteros);
        }
        fclose(archivoDeEnteros);
    }

    int unArreglo[100];
    int i=0;

    archivoDeEnteros = fopen(rutaDelArchivo, "rb");


    if(archivoDeEnteros!=NULL)
    {

        while(fread(&unDato, sizeof(int), 1, archivoDeEnteros)>0  && i<100)
        {
            unArreglo[i]=unDato;
            i++;
        }

        fclose(archivoDeEnteros);
    }

    printf("\n\nContenido del arreglo: \n");
    for(int j=0; j<i; j++)
    {
        printf(" %d ", unArreglo[j]);
    }

    return 0;
}
