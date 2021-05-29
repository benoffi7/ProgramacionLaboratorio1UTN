/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 22:
        * Archivos. Segunda parte
            _ guardando datos desde un arreglo
            _ mostrando datos con modularizacion
            _ fseek()
            _ ftell()

            _ Para resolver en clase: buscar una persona en un archivo
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "misFunciones.h"

/*
int dameNuevoId()
{
    int idMayor;

    fseek(fArchivo, sizeof(stUsuario) * -1, SEEK_END);

    fread(&usuario, sizeof(usuario), 1, fArchivo);

    idMayor = usuario.id + 1;

    return idMayor;
}*/

//usuario.id = dameNuevoId();

int main()
{
    /*FILE* farchivo = fopen("nombreArchivo.bin", "rb");

    if(farchivo != NULL)
    {
        stPersona persona;

        strcpy(persona.nombre, "tomas");

        fwrite(&persona, sizeof(stPersona), 1, farchivo);

        fclose(farchivo);
    }*/

    //sndPlaySound("C:\\Windows\\Media\\Alarm04.wav",0);
    //sndPlaySound("\Musica\\Alarm04.wav",0);

    mostrarDatos();

    printf("-----\n\n");

    //ejemplo_archivos_1();

    //ejemplo_archivos_2();

    //guardarDatos();

    int dniBuscado = 4758147;

    int encontrado = buscarPersonaDNI(dniBuscado);

    if(encontrado == 0)
    {
        printf("la persona no existe \n");
    }
    else
    {
        printf("la persona existe \n");
        //mostrarPersona(persona);
    }

    //printf("encontrado = %i \n", encontrado);

    //printf("encontrado = %i \n" , buscarPersona(32141543));

    return 0;
}
