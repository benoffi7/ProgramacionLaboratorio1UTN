#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 10

typedef struct
{
   char tipoVacuna[20];
   int numDosis;
   char fecha_aplicacion[11];
}VacunaCovid;

typedef struct
{
    char nomYap[40];
    int edad;
    char telefono[20];
    char direccion[20];
    VacunaCovid vacuna;
}Persona;

 _ _ _ _ _ _ _

void cargaPersonas(Persona[],int*);
//void cargaPersonas2(Persona[],int*);
void muestraPersonas(Persona[],int);
void muestraPersona(Persona);
void muestraVacuna(VacunaCovid);
VacunaCovid cargaVacuna();
Persona cargaPersona();
int cuantasTipoVacYNumDosis(Persona[],int,char[],int);


///cantidad de personas que poseen la dosis numero: numDosis de la vacuna tipo: tipoVac
int cuantasTipoVacYNumDosis(Persona personas[],int validos, char tipovac[], int numDosis)
{
    int cont=0;
    for (int i=0; i < validos; i++)
    {
       if (personas[i].vacuna.numDosis == numDosis && strcmpi(personas[i].vacuna.tipoVacuna,tipovac) == 0)
       {
           cont++;
       }
    }
    return cont;
}



VacunaCovid cargaVacuna()
{
    VacunaCovid v;
    printf("Ingrese tipo de vacuna\n");
    fflush(stdin);
    gets(v.tipoVacuna);
    printf("Ingrese numero dosis\n");
    scanf("%i",&v.numDosis);
    printf("Ingrese fecha\n");
    fflush(stdin);
    gets(v.fecha_aplicacion);

    return v;
}


Persona cargarPersona()
{
    Persona p;
    printf("Ingrese nombre y apellido\n");
    fflush(stdin);
    gets(p.nomYap);
    printf("ingrese edad\n");
    scanf("%i",&p.edad);
    printf("ingrese numero telefono\n");
    fflush(stdin);
    gets(p.telefono);
    printf("Ingrese direccion\n");
    fflush(stdin);
    gets(p.direccion);
    p.vacuna=cargaVacuna();

    return p;
}

void muestraPersona(Persona p)
{
    printf("Nombre: %s\n",p.nomYap);
    printf("Edad: %i\n",p.edad);
    printf("Telefono: %s\n",p.telefono);
    printf("Direccion: %s\n",p.direccion);
    muestraVacuna(p.vacuna);
}

void muestraVacuna(VacunaCovid v)
{
    printf("**Vacuna**\n");
    printf("Tipo vacuna: %s \n", v.tipoVacuna);
    printf("Numero dosis: %i\n", v.numDosis);
    printf("Fecha: %s\n",v.fecha_aplicacion);
}


void muestraPersonas(Persona personas[],int validos)
{
    for (int i = 0; i < validos ; i++)
    {
        muestraPersona(personas[i]);

//SI NO:
//    printf("Nombre: %s\n",personas[i].nomYap);
//    printf("Edad: %i\n",personas[i].edad);
//    printf("Telefono: %s\n",personas[i].telefono);
//    printf("Direccion: %s\n",personas[i].direccion);
    }

}

void cargaPersona2(Persona* p)
{
    printf("Ingrese nombre y apellido\n");
    fflush(stdin);
    gets((*p).nomYap);
    printf("ingrese edad\n");
    scanf("%i",&(*p).edad);
    printf("ingrese numero telefono\n");
    fflush(stdin);
    gets((*p).telefono);
    printf("Ingrese direccion\n");
    fflush(stdin);
    gets((*p).direccion);
    (*p).vacuna = cargaVacuna();
}


void cargaPersonas(Persona personas[],int* validos)
{
    char seguir='s';
    while (*validos < CANT_MAX && seguir == 's')
    {
        personas[*validos]=cargarPersona();
        //cargarPersona2(&personas[*validos]);
        (*validos)++;
        printf("desea continuar\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
}


//void cargaPersonas2(Persona personas[],int* validos)
//{
//     char seguir='s';
//    while (*validos < CANT_MAX && seguir == 's')
//    {
//        printf("Ingrese nombre\n");
//        fflush(stdin);
//        gets(personas[*validos].nomYap);
//        ...
//        ...
//    }
//}


int main()
{
    Persona p;
    Persona personas[CANT_MAX];
    int validos=0;
    int cuantas;
    cargaPersonas(personas,&validos);
    muestraPersonas(personas,validos);
    cuantas = cuantasTipoVacYNumDosis(personas,validos,"Sinopharm",1);
    printf("La cantidad de personas que poseen la primer dosis de sinopharm son: %i", cuantas);
    return 0;
}
