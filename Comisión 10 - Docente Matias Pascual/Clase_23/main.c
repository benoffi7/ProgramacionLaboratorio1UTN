/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 23:
        * Ejemplos de uso de archivos con arreglos y pilas
        * Ejemplos de uso de funciones y archivos
        * Resolucion de ejercicios

*/

#include <stdio.h>
#include <stdlib.h>
#include "../Librerias/pila.h"

/// Pasar de un archivo a un arreglo
void pasarDatosArchivoArreglo(FILE* archivo, int arreglo[], int dimension)
{
    fseek(archivo, 0, SEEK_END);
    int cantidadRegistros = ftell(archivo) / sizeof(int);
    rewind(archivo);

    int variable;

    /// desde el arreglo
    for(int i = 0; i < dimension && i < cantidadRegistros; i++)
    {
        fread(&variable, sizeof(int), 1, archivo);

        arreglo[i] = variable;
    }

    /// --------------------------------------------------------

    /// desde el archivo
    int j = 0;
    while(fread(arreglo[j], sizeof(int), 1, archivo) > 0 && j < dimension)
    {
        j++;
    }

    /// --------------------------------------------------------

    if (cantidadRegistros < dimension)
    {
        fread(arreglo, sizeof(int), cantidadRegistros, archivo);
    }
}


void pasarDatosPilaArchivo(Pila* pila, FILE* archivo)
{
    /// desapilar de la pila
    Pila aux;
    inicpila(&aux);

    int variable;

    while(!pilavacia(pila))
    {
        variable = tope(pila);

        apilar(&aux, desapilar(pila));

        /// guardo en archivo

        fwrite(&variable, sizeof(int), 1, archivo);
    }

    /// ordenar la pila
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }
}

void MostrarDatosArchivo(FILE* archivo)
{
    int variable;

    while(fread(&variable, sizeof(int), 1, archivo) > 0)
    {
        printf("%i \n", variable);
    }
}

int main()
{
    Pila pila;
    inicpila(&pila);

    apilar(&pila, 10);
    apilar(&pila, 20);
    apilar(&pila, 30);
    apilar(&pila, 40);
    apilar(&pila, 50);

    FILE* archivo = fopen("pila.bin", "wb");

    if(archivo != NULL)
    {
        pasarDatosPilaArchivo(&pila, archivo);

        fclose(archivo);
    }

    archivo = fopen("pila.bin", "rb");

    if(archivo != NULL)
    {
        MostrarDatosArchivo(archivo);

        fclose(archivo);
    }


    int arreglo[100];

    pasarDatosArchivoArreglo(archivo, arreglo, 100);

    return 0;
}

