#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nya [30]; //nombreYapellido
    int edad;
    int anio; //año que cursa, recordar que no podemos utilizar la ñ para definir variables
} alumno;



void cerrarArchivo(FILE * archi)
{
    int estado;

    estado = fclose(archi);

    if(estado!=0)
    {
        printf("Ocurrio un error al cerrar el archivo");
    }
}

///1- Hacer una función que agregue un elemento al final de un archivo.
void agregaElementoAlFinalDelArchivo(char nombre_archivo[], int dato)
{
    FILE * archi;

    archi=fopen(nombre_archivo, "ab");

    if(archi!=NULL)
    {
        fwrite(&dato, sizeof(int), 1, archi);

       cerrarArchivo(archi);
    }
}

///2- Hacer una función que muestre por pantalla el contenido de un archivo.

void mostrarArchivoBinario(char nombre_archivo[])
{
    FILE *archi;
    archi=fopen(nombre_archivo,"rb");
    int aux=0;

    if(archi!=NULL)
    {
        printf("\nContenido del archivo:\n\n");

        while(!feof(archi))
        {
            if(fread(&aux, sizeof(int),1,archi)>0)
                printf("%d ", aux);
        }
       cerrarArchivo(archi);
    }
}

///3- Hacer una función que retorne la cantidad de registros que contiene
///  un archivo.
int cuentaElementosArchivo(char nombre_archivo[])
{
    int rta=0;
    int aux=0;
    FILE * archi;
    archi=fopen(nombre_archivo, "rb");
    if(archi!=NULL)
    {
        // contamos los registros leyendolos uno por uno
        while(fread(&aux, sizeof(int), 1, archi)>0)
        {
            rta++;
        }

        cerrarArchivo(archi);
    }
    return rta;
}


int cuentaCantRegistrosGenerica(char nombreArchivo[], int bytes)
{
    FILE * archi = fopen(nombreArchivo, "rb" );

    int cantidad=0;

    if(archi!=NULL)
    {

        fseek(archi, 0 ,SEEK_END);

        cantidad=ftell(archi)/bytes;

        cerrarArchivo(archi);
    }

    return cantidad;
}

void pruebaFseek(char nombre_archivo[], int pos)
{

    FILE *archi;
    archi=fopen(nombre_archivo,"rb");
    int aux=0, aux2;

    if(archi!=NULL)
    {

    /// saltamos dos bloques desde el inicio

        fseek(archi, sizeof(int)*pos, SEEK_SET);

        fread(&aux, sizeof(int),1,archi);

        printf("\n%d ", aux);

        fclose(archi);
    }

}

// funcion auxiliar

void mostrarAlumno(alumno a)
{
    puts("\n---------------------------------------");
    printf("\n           Legajo: %d", a.legajo);
    printf("\nNombre y Apellido: %s", a.nya);
    printf("\n             Edad: %d", a.edad);
    printf("\n              Año: %d", a.anio);
    puts("\n---------------------------------------");
}

///Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.
/// el archivo debe contar con por lo menos un registro
void buscaAlumnoMayorEdad(char nombreArchivo[])
{
    FILE * archi=NULL;
    alumno mayor, aux;

    if(cuentaCantRegistrosGenerica(nombreArchivo, sizeof(alumno))>0)
    {
        archi=fopen(nombreArchivo, "rb");
        if(archi!=NULL)
        {
            fread(&mayor, sizeof(alumno), 1, archi);


            while(!feof(archi))
            {
                fread(&aux, sizeof(alumno), 1, archi);
                if(!feof(archi))
                {
                    if(aux.edad>mayor.edad)
                    {
                        mayor=aux;
                    }
                }
            }

            printf("El alumno de mayor edad en el archivo es: \n");
            mostrarAlumno(mayor);

            cerrarArchivo(archi);
        }

    }
    else
    {
        printf("No hay registros suficientes en el archivo...");
    }

}

void invierteArchivo(char nombreArchivo[])
{
    int i=0;

    int u=cuentaRegistrosGenericos(nombreArchivo, sizeof(alumno))-1;

    alumno inicio, fin;

    FILE * archi=fopen(nombreArchivo, "r+b");

    if(archi!=NULL)
    {
        while(i<u)
        {
            /// 1 2 3 4 5
            /// i      u
            /// 1       5

            fseek(archi, i*sizeof(alumno),SEEK_SET);
            fread(&inicio, sizeof(alumno), 1, archi);

            fseek(archi, u*sizeof(alumno),SEEK_SET);
            fread(&fin, sizeof(alumno), 1, archi);

            fseek(archi, i*sizeof(alumno),SEEK_SET);
            fwrite(&fin, sizeof(alumno), 1, archi);

            fseek(archi, u*sizeof(alumno),SEEK_SET);
            fwrite(&inicio, sizeof(alumno), 1, archi);

            i++;
            u--;
        }

        fclose(archi);

    }

}

int pasarDeArchivoToArreglo(char nombreArchivo[], alumno listado[], int dim)
{
    FILE * archi=fopen(nombreArchivo, "rb");
    alumno aux;

    int i=0;

    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(alumno), 1, archi)>0 && i<dim )
        {
            listado[i]=aux;
            i++;
        }

        fclose(archi);
    }

    return i;
}

int pasarArregloToArchivoConFiltro(char nombreArchivo[], alumno listado[], int validos)
{
    FILE * archi=fopen(nombreArchivo, "wb");
    alumno aux;

    int i=0;

    if(archi!=NULL)
    {
        for(i=0; i<validos; i++)
        {
            aux=listado[i];
            if(aux.anio==1)
            {
                fwrite(&aux, sizeof(alumno), 1, archi);
            }
        }

        fclose(archi);
    }

    return i;
}

/// esta fn debe ser modularizada

void modificarUnRegistro(char nombreArchivo[], int legajo)
{
    FILE * archi=fopen(nombreArchivo, "r+b");

    alumno aux;

    int flag=0;

    if(archi!=NULL)
    {
        /// busco el alumno
                           /// !flag
        while(!feof(archi)&& flag==0)
        {
            if(fread(&aux,sizeof(alumno),1, archi)>0)
            {
                if(aux.legajo==legajo){
                    flag=1;
                }
            }
        }

        /// lo encontre
        if(flag==1)
        {
            /// modificar el registro o darlo de baja
/// esto podria llamar a una fn que modifique un dato en particular de la estructura
            strcpy(aux.nya, "gustavo");

            /// me muevo un registro para atras
            fseek(archi, -1*sizeof(alumno),SEEK_CUR);

            /// sobre escribo el registro
            fwrite(&aux, sizeof(alumno), 1, archi);


        }
        fclose(archi);

    }

}


int main()
{
    printf("Hello archivossss!\n");

    printf("Hoy es VIERNES y se da teoria fuerte!!! ");

    char nombreArchivo[]= {"enteros.bin"};

    int valor, bytes, cant;


    FILE * bufferArchi=NULL;

    bufferArchi=fopen(nombreArchivo, "ab");

    if(bufferArchi!=NULL)
    {
        printf("\nIngrese un dato: ");
        scanf("%d", &valor);

        cant=fwrite(&valor, sizeof(int), 1, bufferArchi);

        printf("Se escribio %d elemento en el archivo\n", cant);

        cant=fclose(bufferArchi);

        printf("Cierre del archivo %d\n", cant);
    }
    else
    {
        printf("El archivo no se pudo abrir...");
    }



    bufferArchi=fopen(nombreArchivo, "rb");

    printf("Elementos del archivo: \n");

    if(bufferArchi!=NULL)
    {
        while(fread(&valor, sizeof(int), 1,bufferArchi)>0)
        {

            printf("%d ", valor);
        }

        cant=fclose(bufferArchi);

        printf("Cierre del archivo %d\n", cant);
    }
    else
    {
        printf("El archivo no se pudo CERRAR...");
    }

    int cantidad=cuentaCantRegistrosGenerica(nombreArchivo, sizeof(int));


    return 0;
}
