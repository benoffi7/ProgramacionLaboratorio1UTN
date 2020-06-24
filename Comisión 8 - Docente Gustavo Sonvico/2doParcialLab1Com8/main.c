#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idEquipo;
    char nombre[30];
    int zona; /// las zonas pueden ser 1, 2 o 3
} stEquipo;

typedef struct
{
    int idJugador;
    char nombre[30];
    int edad;
    int idEquipo;
} stJugador;

/// 1
int decimeSiExisteEquipo(char nombreArchivo[], int idEquipo);
int cargaArregloJugadores(stJugador listado[], int dim, char nombreArchivo[]);
void mostrarArregloJugadores(stJugador listado[], int validos);
void mostrarJugador(stJugador j);

/// 2
void pasarJugadoresToArchivo(char nombreArch1[], char nombreArchi2[], stJugador listado[], int validos);
void mostrarArchivoJugadores(char nombreArchivo[]);


/// 3
int cantidadRegistro(char nombreArchivo[]);
float porcentajeArchivo(char nombreArchivo[], int edad, int total);
void subProgramaInciso3(char nombreArchivo1[], char nombreArchivo2[]);

/// 4
int pasarNombresEquipos(char nombreArchivo[], int f, int c, char arregloPalabras[f][c], int zona);
void mostrarArrayPalabras(int f, int c, char arregloPalabras[f][c], int zona);
void subProgramaInciso4(char nombreArchivo[],int f, int c, char arregloPalabras[f][c]);


/// 5
int main()
{
    printf("Hello world!\n");

    stJugador misJugadores[100];
    int validos =0;

    char nombreArchEquipos[]= {"equipos.dat"};
    char nombreArchJug1[]= {"jugadoresJunior.dat"};
    char nombreArchJug2[]= {"jugadoresSenior.dat"};

    validos=cargaArregloJugadores(misJugadores, 100, nombreArchEquipos);
    mostrarArregloJugadores(misJugadores, validos);

    system("pause");
    pasarJugadoresToArchivo(nombreArchJug1, nombreArchJug2, misJugadores, validos);

    printf("\nArchivo Junior");
    mostrarArchivoJugadores(nombreArchJug1);

    printf("\nArchivo Senior");
    mostrarArchivoJugadores(nombreArchJug2);

    subProgramaInciso3(nombreArchJug1, nombreArchJug2);

    char equipos[20][30];

    subProgramaInciso4(nombreArchEquipos, 20, 30, equipos);

    return 0;
}

int decimeSiExisteEquipo(char nombreArchivo[], int idEquipo)
{
    int rta=0;
    stEquipo aux;

    FILE * archi = fopen(nombreArchivo, "rb");
    if(archi!=NULL)
    {
        while(fread(&aux, sizeof(stEquipo), 1, archi)>0 && rta==0)
        {
            if(aux.idEquipo==idEquipo)
            {
                rta=1;
            }
        }
        fclose(archi);
    }
    return rta;
}
int cargaArregloJugadores(stJugador listado[], int dim, char nombreArchivo[])
{
    int i=0;
    char control='s';
    stJugador nuevo;

    printf("Cargando jugadores: ");
    while(i<dim && control=='s')
    {

        printf("\nIngrese id jugador: ");
        scanf("%d", &nuevo.idJugador);

        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(nuevo.nombre);

        printf("\nIngrese edad: ");
        scanf("%d", &nuevo.edad);

        printf("\nIngrese id equipo: ");
        scanf("%d", &nuevo.idEquipo);

        while(decimeSiExisteEquipo(nombreArchivo, nuevo.idEquipo)==0)
        {
            printf("\n Id equipo erroneo, ingrese nuevamente id equipo: ");
            scanf("%d", &nuevo.idEquipo);
        }

        listado[i]=nuevo;

        printf("\nDesea continuar cargando? s/n \n ");
        fflush(stdin);
        scanf("%c", &control);

        i++;
    }

    return i;
}

void mostrarArregloJugadores(stJugador listado[], int validos)
{
    int i;
    printf("Listado de jugadores: \n ----------------\n");

    for(i=0; i<validos; i++)
    {
        mostrarJugador(listado[i]);
        printf("----------------\n");
    }

}

void mostrarJugador(stJugador j)
{
    printf("Id jugador: %d\n", j.idJugador);
    printf("    Nombre: %s\n", j.nombre);
    printf("      Edad: %d\n", j.edad);
    printf(" Id equipo: %d\n", j.idEquipo);
}

void pasarJugadoresToArchivo(char nombreArchi1[], char nombreArchi2[], stJugador listado[], int validos)
{
    FILE * archivoJunior = fopen(nombreArchi1,"ab");
    FILE * archivoSenior = fopen(nombreArchi2,"ab");

    stJugador aux;
    int i=0;

    if(archivoJunior!=NULL && archivoSenior!=NULL)
    {
        for(i=0; i<validos; i++)
        {
            aux=listado[i];

            if (aux.edad<30)
            {
                fwrite(&aux, sizeof(stJugador), 1, archivoJunior);
            }
            else
            {
                fwrite(&aux, sizeof(stJugador), 1, archivoSenior);
            }
        }
        fclose(archivoJunior);
        fclose(archivoSenior);
    }
}

void mostrarArchivoJugadores(char nombreArchivo[])
{
    FILE * archivo = fopen(nombreArchivo, "rb");
    stJugador j;

    if(archivo!=NULL)
    {
        printf("Archivo de jugadores: \n ----------------\n");
        while(fread(&j, sizeof(stJugador), 1, archivo)>0)
        {
            mostrarJugador(j);
            printf("----------------\n");
        }
        fclose(archivo);
    }
}

int cantidadRegistro(char nombreArchivo[])
{
    int cantidad=0;
    FILE * archi=fopen(nombreArchivo, "rb");

    if(archi!=NULL)
    {
        fseek(archi, 0, SEEK_END);
        cantidad=ftell(archi)/sizeof(stJugador);
        fclose(archi);
    }
    return cantidad;
}


float porcentajeArchivo(char nombreArchivo[], int edad, int total)
{
    int cantidadEdad=0;
    float porcentaje=0;
    stJugador aux;

    FILE * archi=fopen(nombreArchivo, "rb");

    if(archi!=NULL)
    {
        while(fread(&aux, sizeof(stJugador), 1, archi)>0)
        {
            if(aux.edad>edad)
            {
                cantidadEdad++;
            }
        }
        fclose(archi);
        /// total         100
        /// cantiEdad      x
        porcentaje=((float)cantidadEdad*100)/(float)total;
    }
    return porcentaje;
}

void subProgramaInciso3(char nombreArchivo1[], char nombreArchivo2[])
{
    int edad;
    int total=0;
    float porcentaje=0;

    printf("\n Ingrese la edad para realizar el filtrado: ");
    scanf("%d", &edad);

    if(edad<30)
    {
        total=cantidadRegistro(nombreArchivo1);
        porcentaje=porcentajeArchivo(nombreArchivo1, edad, total);
    }
    else
    {
        total=cantidadRegistro(nombreArchivo2);
        porcentaje=porcentajeArchivo(nombreArchivo2, edad, total);
    }

    printf("\nHay % d registros en el archivo\n", total);
    printf("El porcentaje de jugadores mayores a %d años de edad es de %.2f", edad, porcentaje);
}

int pasarNombresEquipos(char nombreArchivo[], int f, int c, char arregloPalabras[f][c], int zona)
{
    int i=0;
    stEquipo aux;

    FILE * archi = fopen(nombreArchivo, "rb");
    if(archi!=NULL)
    {
        while(fread(&aux, sizeof(stEquipo), 1, archi)>0 && i<f)
        {
            if(aux.zona==zona)
            {
                strcpy(arregloPalabras[i], aux.nombre);
                i++;
            }
        }
        fclose(archi);
    }
    return i;

}
void mostrarArrayPalabras(int f, int c, char arregloPalabras[f][c], int zona)
{
    int i;
    printf("\nListado de equipos de la zona %d \n ----------------\n", zona);

    for(i=0; i<f; i++)
    {
        printf("%s\n", arregloPalabras[i]);
        printf("----------------\n");
    }
}

void subProgramaInciso4(char nombreArchivo[],int f, int c, char arregloPalabras[f][c])
{
    int zona=0;
    int validos=0;

    printf("\nIngrese la zona a listar: ");
    scanf("%d", &zona);

    validos=pasarNombresEquipos(nombreArchivo, f,c,arregloPalabras, zona);

    mostrarArrayPalabras(validos, c, arregloPalabras, zona);

}
