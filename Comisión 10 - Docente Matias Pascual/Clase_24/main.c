/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 24:
        * Borrando registros de un archivo
        * Funciones de ejemplo para trabajar con estructuras
            - inicPersona
            - mostrarPersona
            - mostrarValidos

        * Uso de -> para acceder a los datos de un puntero a persona
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "personas.h"


int main()
{
    /// INIC PERSONA

    Persona hugo = inicPersona(13213, "Hugo");
    Persona leo = inicPersona(3321312, "Leonardo");

    /// MOSTRAR PERSONA

    mostrarPersona(&hugo);
    mostrarPersona(&leo);

    /// CARGAR UN ARREGLO DE PERSONAS

    Persona personas[10];

    const int DIMENSION = 10;

    int validos = 3; //= cargarPersonas(personas, DIMENSION);

    mostrarPersonas(personas, validos);

    /// GUARDAR ARREGLO DE PERSONAS EN UN ARCHIVO

    const char* RUTA_ARCHIVO = "personas.bin";

    FILE* archivo = fopen(RUTA_ARCHIVO, "ab");

    if(archivo != NULL)
    {
        guardarPersonas(personas, validos, archivo);

        fclose(archivo);
    }

    /// CARGAR ARREGLO DESDE UN ARCHIVO

    archivo = fopen(RUTA_ARCHIVO, "rb");

    if(archivo != NULL)
    {
        leerPersonas(personas, DIMENSION, archivo);

        fclose(archivo);
    }

    /// MOSTRAMOS EL ARREGLO CARGADO DESDE EL ARCHIVO

    mostrarPersonas(personas, validos);

    /// BORRAMOS UN REGISTRO

    archivo = fopen(RUTA_ARCHIVO, "r+b");

    if(archivo != NULL)
    {
        borrarRegistro(1, archivo);

        fclose(archivo);
    }

    archivo = fopen(RUTA_ARCHIVO, "rb");

    if(archivo != NULL)
    {
        leerPersonas(personas, DIMENSION, archivo);

        fclose(archivo);
    }

    printf("TODAS LAS PERSONAS: \n");

    mostrarPersonas(personas, validos);

    system("pause");

    /// MOSTRAMOS SOLO LAS PERSONAS QUE NO FUERON ELIMINADAS DE FORMA LOGICA

    archivo = fopen(RUTA_ARCHIVO, "rb");

    if(archivo != NULL)
    {
        leerPersonas(personas, DIMENSION, archivo);

        fclose(archivo);
    }

    printf("SOLO LOS VALIDOS: \n");

    mostrarValidos(personas, validos);

    return 0;
}
