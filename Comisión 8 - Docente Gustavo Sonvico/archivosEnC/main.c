#include <stdio.h>
#include <stdlib.h>
#include "miLibreria.h"

void cargarArchivoIntConUsr(char nombreArchivo[]);

void mostrarArchivoInt(char nombreArchivo[]);
void mostrarUnInt(int v);

void pruebaFseek(char nombre_archivo[], int pos);


int main()
{

    stAlumno alumnos[100];

    printf("Hello Files!\n");

    char nombreDeMiArchivo[]= {"miArchivoDeInts.dat"};

    //  cargarArchivoIntConUsr(nombreDeMiArchivo);

    // system("pause");

    mostrarArchivoInt(nombreDeMiArchivo);

    system("pause");

    pruebaFseek(nombreDeMiArchivo, 3);

    system("pause");
    mostrarArchivoInt(nombreDeMiArchivo);

    return 0;
}

void cargarArchivoIntConUsr(char nombreArchivo[])
{
    char control = 's';

    int valor;

    FILE * pFile;

    /// abrimos en modo escritura (sobreescribe)
    pFile = fopen(nombreArchivo, "ab");

    if(pFile!=NULL)
    {
        while(control=='s')
        {
            printf("\nIngrese un valor entero: ");
            scanf("%d", &valor);

            fwrite(&valor, sizeof(int), 1, pFile);

            printf("\nDesea continuar? s/n");
            fflush(stdin);
            scanf("%c", &control);
        }
        fclose(pFile);
    }
    else
    {
        printf("No pudimos abrir el archivo, paso algo malo....");
    }

}

void mostrarUnInt(int v)
{
    printf("%d ", v);
}

void mostrarArchivoInt(char nombreArchivo[])
{
    int valor;

    FILE * pFile;

    /// abrimos en modo lectura
    pFile = fopen(nombreArchivo, "rb");

    if(pFile!=NULL)
    {

        while( ! feof(pFile) )
        {
            fread(&valor, sizeof(int), 1, pFile);
            if(!feof(pFile))
                mostrarUnInt(valor);

        }

        fclose(pFile);
    }
    else
    {
        printf("No pudimos abrir el archivo, paso algo malo....");
    }
}

void pruebaFseek(char nombre_archivo[], int pos)
{

    FILE *archi;
    archi=fopen(nombre_archivo,"r+b");
    int aux;

    if(archi!=NULL)
    {

        /// saltamos dos bloques desde el inicio

        fseek(archi, sizeof(int)*pos,SEEK_SET);

        /// leemos la posicion
        if(fread(&aux, sizeof(int),1,archi)>0)
        {
            printf("\nValor en la posicion %d del archivo: %d ", pos, aux);

            /// modificamos el dato a nivel local
            aux=123;

            /// nos movemos un espacio para atras
            fseek(archi, sizeof(int)*-1, SEEK_CUR);

            /// sobre escribimos el dato
            fwrite(&aux, sizeof(int),1,archi);
        }

        fclose(archi);
    }

}
