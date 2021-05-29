#include <time.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    int dni;
    char nombre[30];

} stPersona;

void ejemplo_archivos_1()
{
    /// fseek: desplazo el puntero una cierta cantidad de bytes en el archivo
    FILE* fArchivo = fopen("personas.bin", "rb");

    int cantidad = 2;

    if(fArchivo != NULL)
    {
        stPersona persona;

        fseek(fArchivo, sizeof(persona) * -1, SEEK_END);

        fread(&persona, sizeof(persona), 1, fArchivo);

        mostrarPersona(&persona);

        /// mostramos la persona anterior

        fseek(fArchivo, sizeof(persona) * -2, SEEK_CUR);

        fread(&persona, sizeof(persona), 1, fArchivo);

        mostrarPersona(&persona);

        fclose(fArchivo);
    }
}

void ejemplo_archivos_2()
{
    /// ftell : me dice la cantidad de bytes desde el inicio hasta la posicion del puntero
    FILE* fArchivo = fopen("personas.bin", "rb");

    if(fArchivo != NULL)
    {
        stPersona persona;

        fseek(fArchivo, 0, SEEK_END);

        printf("cantidad de registros: %i \n", ftell(fArchivo) / sizeof(persona));

        fclose(fArchivo);
    }
}

/// PARA RESOLVER EN CLASE: buscar una persona dentro de un archivo
int buscarPersonaDNI(int dni)
{
    FILE* archivo = fopen("personas.bin", "rb");

    int flag = 0;

    if(archivo != NULL)
    {
        stPersona persona;

        while(fread(&persona, sizeof(persona), 1, archivo) > 0 && flag == 0)
        {
            if(dni == persona.dni)
            {
                flag = 1;
            }
        }

        fclose(archivo);
    }

    return flag;
}










/*int buscarPersona(int dni)
{
    int encontrado = 0; /// de momento nos paramos en que no esta

    FILE* fArchivo = fopen("personas.bin", "rb");

    if(fArchivo != NULL)
    {
        stPersona persona;

        while(fread(&persona, sizeof(persona), 1, fArchivo) > 0 && encontrado == 0)
        {
            if(persona.dni == dni)
            {
                encontrado = 1;

                mostrarPersona(persona);
            }
        }

        fclose(fArchivo);
    }

    return encontrado;
}*/

/// ---------------------------------------------------------------

void guardarDatos()
{
    char nombres[][30] = {{"Diego"}, {"Fernanda"}, {"Maria"}, {"Esteban"}, {"Julieta"}};
    int datosDni[] = {37548457,457896541,24578745,26797854, 47589647};

    FILE* fArchivo = fopen("personas.bin", "wb");

    if(fArchivo != NULL)
    {
        for(int i = 0; i < 5; i++)
        {
            stPersona persona;

            persona.dni = datosDni[i];

            strcpy(persona.nombre, nombres[i]);

            fwrite(&persona, sizeof(persona), 1, fArchivo);
        }

        fclose(fArchivo);
    }
}

void mostrarDatos()
{
    FILE* fArchivo = fopen("personas.bin", "rb");

    if(fArchivo != NULL)
    {
        stPersona persona;

        while(fread(&persona, sizeof(stPersona), 1, fArchivo) > 0)
        {
            mostrarPersona(persona);
        }

        fclose(fArchivo);
    }
}

void mostrarPersona(stPersona persona)
{
    printf("Dni: %i \nNombre: %s\n\n", persona.dni, persona.nombre);
}
