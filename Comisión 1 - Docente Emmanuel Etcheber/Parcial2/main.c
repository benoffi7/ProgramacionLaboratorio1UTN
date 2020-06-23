#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int dimF = 3;
const int dimDias = 31;

typedef struct
{
    char tipoTrabajo[40];
    char contratador[40];
    int cantHorasTrabajo;
    int cantHorasInvestigacion;
    int cantLitrosCafe;
} trabajoFreelance;


void inicArreglos (char tipoTrab[31][40],char contratador[31][40],int cantTrab[],int cantInves[],int cantCafe[], int dim);
int cargarArreglos (char tipoTrab[31][40],char contratador[31][40],int cantTrab[],int cantInves[],int cantCafe[], int dim);
void pasarAStruct (char tipoTrab[31][40],char contratador[31][40],int cantTrab[],int cantInves[],int cantCafe[], trabajoFreelance tf[]);
void mostrarTrabajoFreelance (trabajoFreelance mostrado);
void guardarArchivo (char nombreAr[], trabajoFreelance tf[]);
void mostrarArchivo (char nombreAr[]);


int main()
{
    char tipoTrabajo[31][40];
    char contratador[31][40];
    int cantHorasTrabajo [31];
    int cantHorasInvestigacion [31];
    int cantLitrosCafe[31];

    char nombreArchivo[] = "Enero.bin";


    trabajoFreelance arregloTrabajos[dimDias];

    int calendario[dimF][dimDias];

    inicArreglos(tipoTrabajo,contratador,cantHorasTrabajo,cantHorasInvestigacion,cantLitrosCafe,dimDias);

    int DiasCargados = cargarArreglos(tipoTrabajo,contratador,cantHorasTrabajo,cantHorasInvestigacion,cantLitrosCafe,dimDias);

    pasarAStruct(tipoTrabajo,contratador,cantHorasTrabajo,cantHorasInvestigacion,cantLitrosCafe,arregloTrabajos);

    armarCalendario(arregloTrabajos,calendario);

    mostrarCalendario(calendario);

    guardarArchivo(nombreArchivo, arregloTrabajos);

    mostrarArchivo(nombreArchivo);
}
void inicArreglos (char tipoTrab[31][40],char contratador[31][40],int cantTrab[],int cantInves[],int cantCafe[], int dim)
{
    for (int i=0; i<dim; i++)
    {
        strcpy(tipoTrab[i],"SinDatos");
        strcpy(contratador[i],"SinDatos");
        cantTrab[i]=-1;
        cantInves[i]=-1;
        cantCafe[i]=-1;
    }
}

int cargarArreglos (char tipoTrab[31][40],char contratador[31][40],int cantTrab[],int cantInves[],int cantCafe[], int dim)
{
    int diasCargados=0;
    char cargar;
    for (int i=0; i<dim; i++)
    {
        printf("Desea cargar el dia %i? \n",i+1);
        fflush(stdin);
        scanf("%c",&cargar);
        if (cargar=='s' || cargar=='S')
        {
            printf("\n\nIngrese tipo trabajo: ");

            scanf("%s",&tipoTrab[i]);
            fflush(stdin);
            printf("\n\nIngrese contratador: ");
            fflush(stdin);
            scanf("%s",&contratador[i]);
            printf("\n\nIngrese horas trabajadas: ");
            scanf("%i",&cantTrab[i]);
            printf("\n\nIngrese horas investigadas: ");
            scanf("%i",&cantInves[i]);
            printf("\n\nIngrese litros de cafe bebido: ");
            scanf("%i",&cantCafe[i]);
            diasCargados++;
        }
    }
    system("cls");
    return diasCargados;
}


void pasarAStruct (char tipoTrab[31][40],char contratador[31][40],int cantTrab[],int cantInves[],int cantCafe[], trabajoFreelance tf[])
{

    for (int i=0; i<dimDias; i++)
    {
        strcpy(tf[i].tipoTrabajo,tipoTrab[i]);
        strcpy(tf[i].contratador,contratador[i]);
        tf[i].cantHorasTrabajo=cantTrab[i];
        tf[i].cantHorasInvestigacion=cantInves[i];
        tf[i].cantLitrosCafe=cantCafe[i];
    }
}

void armarCalendario (trabajoFreelance tf[], int calendario[dimF][dimDias])
{
    for (int i=0; i<dimDias; i++)
    {
        calendario[0][i] = tf[i].cantHorasInvestigacion;
        calendario[1][i] = tf[i].cantHorasTrabajo;
        calendario[2][i] = tf[i].cantLitrosCafe;
    }
}

void mostrarCalendario (int calendario[dimF][dimDias])
{
    for (int j=0; j<dimF; j++)
    {
        printf("\n");
        for (int i=0; i<15; i++) ///Muestro 15 porque con 31 la consola lo muestra corrido, pero anda igual
        {
            printf("%i\t",calendario[j][i]);
        }
    }
}
void guardarArchivo (char nombreAr[], trabajoFreelance tf[])
{
    FILE * archi = fopen(nombreAr,"wb");
    if (archi!=NULL)
    {
        for (int i=0; i<dimDias; i++)
        {
            fwrite(&tf[i],sizeof(trabajoFreelance),1,archi);
        }
        fclose(archi);
    }
}

void mostrarTrabajoFreelance (trabajoFreelance mostrado)
{
    printf("\n\nTipo trabajo: %s",mostrado.tipoTrabajo);
    printf("\n\nContratador: %s",mostrado.contratador);
    printf("\n\nHoras trabajadas: %i",mostrado.cantHorasTrabajo);
    printf("\n\nHoras investigadas: %i",mostrado.cantHorasInvestigacion);
    printf("\n\nLitros de cafe bebido: %i",mostrado.cantLitrosCafe);
}

void mostrarArchivo (char nombreAr[])
{
    trabajoFreelance aux;
    FILE * archi = fopen(nombreAr,"rb");
    if (archi!=NULL)
    {
        while (fread(&aux,sizeof(trabajoFreelance),1,archi)>0)
        {
            if (aux.cantHorasInvestigacion < aux.cantHorasTrabajo)
            {
                mostrarTrabajoFreelance (aux);
            }
        }
        fclose(archi);
    }
}

