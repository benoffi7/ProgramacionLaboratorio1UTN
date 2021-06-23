#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idTipoDonacion;
    char nombre[30];
    int categoria; /// pueden ser 1, 2, 3 o 4
} stTipoDonacion;

typedef struct
{
    int idDonante;
    char nombre[30];
    float montoDonado;
    int idTipoDonacion;
} stDonante;

/// 1
int decimeSiExisteDonacion(char nombreArchivo[], int idTipoDonacion);
int cargaArregloDonantes(stDonante listado[], int dim, char nombreArchivo[]);
void mostrarArregloDonantes(stDonante listado[], int validos);
void mostrarDonante(stDonante d);

/// 2
void pasarDonantesToArchivo(char nombreArch1[], char nombreArchi2[], stDonante listado[], int validos);
void mostrarArchivoDonantes(char nombreArchivo[]);


/// 3
int cantidadRegistro(char nombreArchivo[]);
float promedioArchivo(char nombreArchivo[], int total);
void subProgramaInciso3(char nombreArchivo1[], char nombreArchivo2[]);

/// 4
int pasarNombresDonaciones(char nombreArchivo[], int f, int c, char arregloPalabras[f][c], int categoria);
void mostrarArrayPalabras(int f, int c, char arregloPalabras[f][c], int categoria);
void subProgramaInciso4(char nombreArchivo[],int f, int c, char arregloPalabras[f][c]);


/// 5
int main()
{
    printf("Hello world!\n");

    stDonante misDonantes[100];
    int validos =0;

    char nombreArchTiposDonacion[]= {"tipoDonacion.dat"};
    char nombreArchDonantesA[]= {"donantesA.dat"};
    char nombreArchDonantesB[]= {"donantesB.dat"};

    validos=cargaArregloDonantes(misDonantes, 100, nombreArchTiposDonacion);
    mostrarArregloDonantes(misDonantes, validos);

    system("pause");
    pasarDonantesToArchivo(nombreArchDonantesA, nombreArchDonantesB, misDonantes, validos);

    printf("\n Donantes A\n");
    mostrarArchivoDonantes(nombreArchDonantesA);

    printf("\n Donantes B\n");
    mostrarArchivoDonantes(nombreArchDonantesB);

    subProgramaInciso3(nombreArchDonantesA, nombreArchDonantesB);

    char donaciones[20][30];

    subProgramaInciso4(nombreArchTiposDonacion, 20, 30, donaciones);

    return 0;
}

/// 1 si existe, 0 si no lo encuentra
int decimeSiExisteDonacion(char nombreArchivo[], int idTipoDonacion)
{
    int rta=0;
    stTipoDonacion aux;

    FILE * archi = fopen(nombreArchivo, "rb");
    if(archi!=NULL)
    {
        while(fread(&aux, sizeof(stTipoDonacion), 1, archi)>0 && rta==0)
        {
            if(aux.idTipoDonacion==idTipoDonacion)
            {
                rta=1;
            }
        }
        fclose(archi);
    }
    return rta;
}

int cargaArregloDonantes(stDonante listado[], int dim, char nombreArchivo[])
{
    int i=0;
    char control='s';
    stDonante nuevo;

    printf("Cargando donantes: ");
    while(i<dim && control=='s')
    {

        printf("\nIngrese id donante: ");
        scanf("%d", &nuevo.idDonante);

        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(nuevo.nombre);

        printf("\nIngrese monto donado: $ ");
        scanf("%f", &nuevo.montoDonado);

        printf("\nIngrese id tipo de donacion: ");
        scanf("%d", &nuevo.idTipoDonacion);

        while(decimeSiExisteDonacion(nombreArchivo, nuevo.idTipoDonacion)==0)
        {
            printf("\n Id tipo de donacion erroneo, ingrese nuevamente: ");
            scanf("%d", &nuevo.idTipoDonacion);
        }

        listado[i]=nuevo;

        printf("\nDesea continuar cargando? s/n \n ");
        fflush(stdin);
        scanf("%c", &control);

        i++;
    }

    return i;
}

void mostrarArregloDonantes(stDonante listado[], int validos)
{
    int i;
    printf("Listado de donantes: \n ----------------\n");

    for(i=0; i<validos; i++)
    {
        mostrarDonante(listado[i]);
        printf("----------------\n");
    }

}

void mostrarDonante(stDonante d)
{
    printf("  Id donante: %d\n", d.idDonante);
    printf("      Nombre: %s\n", d.nombre);
    printf("Monto donado: %.2f\n", d.montoDonado);
    printf(" Id donacion: %d\n", d.idTipoDonacion);
}

void pasarDonantesToArchivo(char nombreArchi1[], char nombreArchi2[], stDonante listado[], int validos)
{
    FILE * archivoA = fopen(nombreArchi1,"ab");
    FILE * archivoB = fopen(nombreArchi2,"ab");

    stDonante aux;
    int i=0;

    if(archivoA!=NULL && archivoB!=NULL)
    {
        for(i=0; i<validos; i++)
        {
            aux=listado[i];

            if (aux.montoDonado>25000)
            {
                fwrite(&aux, sizeof(stDonante), 1, archivoA);
            }
            else
            {
                fwrite(&aux, sizeof(stDonante), 1, archivoB);
            }
        }
        fclose(archivoA);
        fclose(archivoB);
    }
}

void mostrarArchivoDonantes(char nombreArchivo[])
{
    FILE * archivo = fopen(nombreArchivo, "rb");
    stDonante d;

    if(archivo!=NULL)
    {
        printf("Archivo de donantes: \n ----------------\n");
        while(fread(&d, sizeof(stDonante), 1, archivo)>0)
        {
            mostrarDonante(d);
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

        cantidad=ftell(archi)/sizeof(stDonante);

        fclose(archi);
    }
    return cantidad;
}

float promedioArchivo(char nombreArchivo[], int total)
{
    float totalDonaciones=0;
    float promedio=0;
    stDonante aux;

    FILE * archi=fopen(nombreArchivo, "rb");

    if(archi!=NULL)
    {
        while(fread(&aux, sizeof(stDonante), 1, archi)>0)
        {
            totalDonaciones+=aux.montoDonado;
        }

        fclose(archi);

        promedio=totalDonaciones/total;
    }
    return promedio;
}

void subProgramaInciso3(char nombreArchivo1[], char nombreArchivo2[])
{
    int tipo;
    int total=0;
    float promedio=0;

    printf("\n Ingrese que archivo desea verificar: \n 1- Donantes A\n 2- Donantes B\n");
    scanf("%d", &tipo);

    while(tipo!=1 && tipo!=2)
    {
        printf("\nIngreso erroneo... \n Ingrese que archivo desea verificar: \n 1- Donantes A\n 2- Donantes B\n");
        scanf("%d", &tipo);
    }

    if(tipo==1)
    {
        total=cantidadRegistro(nombreArchivo1);
        promedio=promedioArchivo(nombreArchivo1, total);
    }
    else /// tipo==2
    {
        total=cantidadRegistro(nombreArchivo2);
        promedio=promedioArchivo(nombreArchivo2, total);
    }


    printf("\nHay % d donantes en el archivo\n", total);
    printf("El promedio de donaciones en el archivo seleccionado es $ %.2f", promedio);
}

int pasarNombresDonaciones(char nombreArchivo[], int f, int c, char arregloPalabras[f][c], int categoria)
{
    int i=0;
    stTipoDonacion aux;

    FILE * archi = fopen(nombreArchivo, "rb");
    if(archi!=NULL)
    {
        while(fread(&aux, sizeof(stTipoDonacion), 1, archi)>0 && i<f)
        {
            if(aux.categoria==categoria)
            {
                strcpy(arregloPalabras[i], aux.nombre);
                i++;
            }
        }
        fclose(archi);
    }
    return i;

}
void mostrarArrayPalabras(int f, int c, char arregloPalabras[f][c], int categoria)
{
    int i;
    printf("\nListado de donaciones de categoria %d \n ----------------\n", categoria);

    for(i=0; i<f; i++)
    {
        printf("%s\n", arregloPalabras[i]);
        printf("----------------\n");
    }
}

void subProgramaInciso4(char nombreArchivo[],int f, int c, char arregloPalabras[f][c])
{
    int categoria=0;
    int validos=0;

    printf("\nIngrese la categoria a listar: ");
    scanf("%d", &categoria);

    validos=pasarNombresDonaciones(nombreArchivo, f,c,arregloPalabras, categoria);

    mostrarArrayPalabras(validos, c, arregloPalabras, categoria);

}
