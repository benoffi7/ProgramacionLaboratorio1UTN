#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///1- Hacer una función que agregue un elemento al final de un archivo.
void agregaElementoAlFinalDelArchivo(char nombre_archivo[], int dato)
{
    FILE * archi;

    archi=fopen(nombre_archivo, "ab");

    if(archi!=NULL)
    {
        fwrite(&dato, sizeof(int), 1, archi);
        fclose(archi);
    }
}

//2- Hacer una función que muestre por pantalla el contenido de un archivo.

void mostrarArchivoBinario(char nombre_archivo[])
{
    FILE *archi;
    archi=fopen(nombre_archivo,"rb");
    int aux=0;

    if(archi!=NULL)
    {
        printf("\nContenido del archivo:\n\n");
        while(fread(&aux, sizeof(int),1,archi)>0)
        {
            printf("%d ", aux);
        }
        fclose(archi);
    }
}


int main()
{
    printf("Hello archivos!\n");

    srand(time(NULL));

    int aux=10, bytesLeidos=0, cierreArchivo;

    char nombreDeMiArchivo[]={"enteros.bin"};

    int numerillo;

    numerillo=rand()%1000;


    agregaElementoAlFinalDelArchivo(nombreDeMiArchivo, numerillo);

    mostrarArchivoBinario(nombreDeMiArchivo);


    return 0;
}
