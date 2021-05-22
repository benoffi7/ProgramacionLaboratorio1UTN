#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char calle[25];
    int numero;
    int piso;
    char dpto[4];
} stDireccion;

typedef struct
{
    int matricula;
    char nombreApellido[40];
    char genero;
    stDireccion direccion;
} stAlumno;

/// fns manejo struct direccion
stDireccion cargarDireccion();
void mostrarDireccion(stDireccion dir);



///
int cargarArregloInt(int A[], int dim);

/// pensarla
stAlumno cargarUnAlumno();

int cargarArregloAlumnos(stAlumno listadoDeAlumnos[], int dim);

/// pensarla
void mostrarUnAlumno(stAlumno a);

void mostraArregloAlumno(stAlumno listadoDeAlumnos[], int validos);

int main()
{

    printf("Hello structs!\n");
    int unVariable=0;

   /* stDireccion miDir=cargarDireccion();
    mostrarDireccion(miDir);*/

    /// como creamos una variable de tipo stAlumno

    /// stAlumno unAlumno= {12345,"Pepe Grillo", 'm'};
    stAlumno unAlumno;

    /*  unAlumno.matricula=12345;
      unAlumno.genero='m';
      strcpy(unAlumno.nombreApellido, "Pepe Grillo");*/


    /* printf("Ingrese la matricula: ");
     scanf("%d", &unAlumno.matricula);

     printf("Ingrese el genero: ");
     fflush(stdin);
     scanf("%c", &unAlumno.genero);

     printf("Ingrese el nombre: ");
     fflush(stdin);
     gets(unAlumno.nombreApellido);


     printf("\n         Matricula: %d", unAlumno.matricula);
     printf("\n Nombre y Apellido: %s", unAlumno.nombreApellido);
     printf("\n            Genero: %c", unAlumno.genero);*/


    /// como creamos un arreglo de tipo stAlumno

    stAlumno listadoDeAlumnos[60];
    int validos=0;

    /// copiar informacion sobre el arreglo o pasar la misma desde el arreglo a una variable
    /// listadoDeAlumnos[0] = unAlumno;
    /// stAlumno otroAlumno = listadoDeAlumnos[0];

    validos=cargarArregloAlumnos(listadoDeAlumnos, 60);


    mostraArregloAlumno(listadoDeAlumnos, validos);

    return 0;
}

int cargarArregloInt(int a[], int dim)
{
    int i=0,aux;
    char control='s';

    printf("Cargando el arreglo de int \n");

    while(i<dim && control=='s')
    {
        printf("Ingrese un valor entero: ");
        scanf("%d", &a[i]);

        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &control);

        i++;
    }
    return i;
}

int cargarArregloAlumnos(stAlumno listadoDeAlumnos[], int dim)
{
    int i=0;
    char control='s';

    stAlumno unAlumno;

    printf("Cargando el listado de alumnos: \n");

    while(i<dim && control=='s')
    {
        /*    printf("Ingrese la matricula: ");
            scanf("%d", &listadoDeAlumnos[i].matricula);

            printf("Ingrese el genero: ");
            fflush(stdin);
            scanf("%c", &listadoDeAlumnos[i].genero);

            printf("Ingrese el nombre: ");
            fflush(stdin);
            gets(&listadoDeAlumnos[i].nombreApellido);*/

        printf("Ingrese la matricula: ");
        scanf("%d", &unAlumno.matricula);

        printf("Ingrese el genero: ");
        fflush(stdin);
        scanf("%c", &unAlumno.genero);

        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(unAlumno.nombreApellido);

        unAlumno.direccion=cargarDireccion();

        /// valido los datos
        listadoDeAlumnos[i]=unAlumno;

        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &control);

        i++;
    }
    return i;
}

void mostraArregloAlumno(stAlumno listadoDeAlumnos[], int validos)
{
    int i;

    printf("Listado de alumnos cargados: \n");

    for(i=0; i<validos; i++)
    {
        printf("\n----------------------------------");
        printf("\n         Matricula: %d", listadoDeAlumnos[i].matricula);
        printf("\n Nombre y Apellido: %s", listadoDeAlumnos[i].nombreApellido);
        printf("\n            Genero: %c", listadoDeAlumnos[i].genero);
        printf("\n         Direccion:");
        mostrarDireccion(listadoDeAlumnos[i].direccion);
        printf("\n----------------------------------");
    }
}

stDireccion cargarDireccion()
{
    stDireccion aux;
    printf("Ingrese los datos de la direccion: \n");

    printf("Ingrese su calle: ");
    fflush(stdin);
    gets(aux.calle);

    printf("Ingrese la altura: ");
    scanf("%d", &aux.numero);

    printf("Ingrese el piso: ");
    scanf("%d", &aux.piso);

    printf("Ingrese el depto: ");
    fflush(stdin);
    gets(aux.dpto);

    return aux;
}

void mostrarDireccion(stDireccion dir)
{
    printf("\n-------------------");
    printf("\n Calle: %s", dir.calle);
    printf("\nAltura: %d", dir.numero);
    printf("\n  Piso: %d", dir.piso);
    printf("\n Depto: %s", dir.dpto);
    printf("\n-------------------");
}
