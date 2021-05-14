/**
    Los archivos permiten la persistencia de datos

    Para trabajar con archivos necesitamos una puntero de tipo FILE

    Lo declaramos con FILE* nombre;
*/

#include <stdio.h>
#include <string.h>

/// write (escribir) es guardar datos en el archivo
void write_archivos()
{
    /** primero usamos fopen para abrir el archivo
        el archivio es abierto en modo escritura */

    FILE* archivo = fopen("miArchivo.txt", "w");

    /// siempre comprobamos que el archivo haya sido abierto con exito
    if (archivo != NULL)
    {
        char palabra[] = "hola mundo!";

        /// escribimos en el archivo
        fwrite(&palabra, sizeof(palabra), 1, archivo);

        /// siempre cerramos el archivo al terminar de trabajar con el.
        /// si no cerramos el archivo, los datos no se guardan en el disco.
        fclose(archivo);
    }
}

void write_archivos_2()
{
    const char* rutaArchivo = "miArchivo.txt";
    FILE* fArchivo = fopen(rutaArchivo, "a");

    char frase[] = ", buenas\n noches!";

    if(fArchivo != NULL)
    {
        fwrite(&frase, sizeof(frase), 1, fArchivo);

        fclose(fArchivo);
    }
}

#define RUTA_ARCHIVO "miArchivo.dat"

void write_archivos_3()
{
    FILE* fArchivo = fopen(RUTA_ARCHIVO, "wb");

    char frase[] = "Good Night";

    if(fArchivo != NULL)
    {
        fwrite(frase, sizeof(frase), 1, fArchivo);

        fclose(fArchivo);
    }
}

typedef struct
{
    int dni;
    char nombre[30];

} stPersona;

void write_archivos_4()
{
    FILE* fArchivo = fopen(RUTA_ARCHIVO, "wb");

    if(fArchivo != NULL)
    {
        stPersona persona;

        persona.dni = 20123321;

        strcpy(persona.nombre, "Ricardita");

        fwrite(&persona, sizeof(persona), 1, fArchivo);

        fclose(fArchivo);
    }
}

#define RUTA_ARCHIVO_LECTURA "miArchivo.txt"

void read_archivos()
{
    FILE* fArchivo = fopen(RUTA_ARCHIVO_LECTURA, "r");

    char palabras[200];

    if(fArchivo != NULL)
    {
        char caracter = ' ';

        int contadorCaracteres = 0;

        while(fread(&caracter, sizeof(caracter), 1, fArchivo) > 0)
        {
            //printf("%c", caracter);

            palabras[contadorCaracteres++] = caracter;

        }

        for(int i = 0; i < contadorCaracteres; i++)
        {
            printf("%c", palabras[i]);
        }

        fclose(fArchivo);
    }
}

#define RUTA_ARCHIVO_LECTURA_DAT "miArchivo.dat"

void read_archivos_2()
{
    FILE* fArchivo = fopen(RUTA_ARCHIVO_LECTURA_DAT, "rb");

    if(fArchivo != NULL)
    {
        stPersona persona;

        while(fread(&persona, sizeof(persona), 1, fArchivo) > 0)
        {

        }

        printf("- nombre: %s \n- dni: %i", persona.nombre, persona.dni);

        fclose(fArchivo);
    }
}
