#include <stdio.h>
#include <stdlib.h>


void cargarArchivoIntConUsr(char nombreArchivo[]);

void mostrarArchivoInt(char nombreArchivo[]);
void mostrarUnInt(int v);

void pruebaFseek(char nombre_archivo[], int pos);

int cuentaRegistroArchivo(char nombre_archivo[], long tamanioBloqueEnBytes);

void invierteArchivoInt(char nombre_archivo[]);


int main()
{



    printf("Hello Files!\n");

    char nombreDeMiArchivo[]= {"miArchivoDeInts.dat"};

    cargarArchivoIntConUsr(nombreDeMiArchivo);

    system("pause");

    mostrarArchivoInt(nombreDeMiArchivo);

    system("pause");

//   pruebaFseek(nombreDeMiArchivo, 3);

/// invertir el archivo

    invierteArchivoInt(nombreDeMiArchivo);

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
    pFile = fopen(nombreArchivo, "wb");

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

int cuentaRegistroArchivo(char nombre_archivo[], long tamanioBloqueEnBytes)
{
    int cantidad =0;
    FILE * archi;

    archi = fopen(nombre_archivo,"rb");
    if(archi!=NULL)
    {
        /// me posiciono al final del archivo
        fseek(archi,0,SEEK_END);

        /// divido la cantidad de bytes del archivo por la cantidad de
        /// bytes de un registro de alumnos
        cantidad = ftell(archi)/tamanioBloqueEnBytes;
        fclose(archi);
    }

    return cantidad;
}

void invierteArchivoInt(char nombre_archivo[])
{

    int datoInicio;
    int datoFin;

    int inicio=0;
    int fin=cuentaRegistroArchivo(nombre_archivo, sizeof(int) )-1;

    FILE * archi=fopen(nombre_archivo, "r+b");

    if(archi!=NULL)
    {
        while(inicio<fin)
        {
            /// me paro al inicio
            fseek(archi, inicio*sizeof(int), SEEK_SET);
            /// leo el inicio
            fread(&datoInicio, sizeof(int), 1, archi);

            /// me paro al final
            fseek(archi, fin*sizeof(int), SEEK_SET);
            /// leo el final
            fread(&datoFin, sizeof(int), 1, archi);

            /// me paro al inicio
            fseek(archi, inicio*sizeof(int), SEEK_SET);
            /// sobreescribo en el inicio el valor del final
            fwrite(&datoFin, sizeof(int), 1, archi);

            /// me paro al final
            fseek(archi, fin*sizeof(int), SEEK_SET);
            /// sobreescribo en el final el valor del inicio
            fwrite(&datoInicio, sizeof(int), 1, archi);

            inicio++;
            fin--;
        }

        fclose(archi);
    }

}
