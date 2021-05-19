#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 20

typedef struct
{
    char tipoVacuna[20];
    char fechaAplicacion[20];
    int dosis;
} VacunaCovid;


typedef struct
{
    char nombreYapellido[20];
    int edad;
    char direccion[40];
    char telefono[15];
    VacunaCovid v;
} Persona;


Persona cargaPersona();
void muestraPersona(Persona);
void cargaPersonas(Persona[],int*);
void cargaPersonas2(Persona[],int*);
void muestraPersonas(Persona[],int);
void cargaVacuna(VacunaCovid*);






Persona cargaPersona()
{
    Persona p;
    printf("Ingrese nombre y Apellido\n");
    fflush(stdin);
    gets(p.nombreYapellido);
    printf("Ingrese edad\n");
    scanf("%i", &p.edad);
    printf("Ingrese telefono\n");
    fflush(stdin);
    gets(p.telefono);
    printf("Ingrese direccion\n");
    fflush(stdin);
    gets(p.direccion);
    printf("Ingrese datos de la vacuna:\n");
    printf("Ingrese tipo de vacuna\n");
    fflush(stdin);
    gets(p.v.tipoVacuna);
    printf("Ingrese fecha aplicacion\n");
    fflush(stdin);
    gets(p.v.fechaAplicacion);
    printf("Ingrese numero de dosis\n");
    scanf("%i", &p.v.dosis);

    return p;
}


void muestraPersona(Persona p)
{
    printf("nombre y apellido: %s \n", p.nombreYapellido);
    printf("Edad: %i\n", p.edad);
    printf("Telefono: %s\n", p.telefono);
    printf("Direccion: %s\n", p.direccion);
    printf("datos de la vacuna: \n");
    printf("Tipo vacuna: %s\n", p.v.tipoVacuna);
    printf("fecha aplicacion: %s\n", p.v.fechaAplicacion);
    printf("numero dosis: %i\n", p.v.dosis);
}

void cargaPersonas(Persona personas[], int* validos)
{
    char seguir='s';

    while (*validos < TAM_MAX && seguir == 's')
    {
        personas[*validos] = cargaPersona();
        (*validos)++;
        printf("desea agregar otra persona\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }

}

void cargaPersonas2(Persona personas[], int* validos)
{
    char seguir='s';

    while (*validos < TAM_MAX && seguir == 's')
    {
        printf("Ingrese nombre y Apellido\n");
        fflush(stdin);
        gets(personas[*validos].nombreYapellido);
        printf("Ingrese edad\n");
        scanf("%i", &personas[*validos].edad);
        printf("Ingrese telefono\n");
        fflush(stdin);
        gets(personas[*validos].telefono);
        printf("Ingrese direccion\n");
        fflush(stdin);
        gets(personas[*validos].direccion);
        printf("Ingrese datos de la vacuna:\n");
        cargaVacuna(&personas[*validos].v);
        (*validos)++;
        printf("desea agregar otra persona\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }

}

void cargaVacuna(VacunaCovid* v)
{
    printf("Ingrese tipo de vacuna\n");
    fflush(stdin);
    gets((*v).tipoVacuna);
    printf("Ingrese fecha aplicacion\n");
    fflush(stdin);
    gets((*v).fechaAplicacion);
    printf("Ingrese numero de dosis\n");
    scanf("%i", &((*v).dosis));
}

void muestraPersonas(Persona personas[], int validos)
{
    for(int i = 0 ; i < validos ; i++)
    {
        muestraPersona(personas[i]);
    }

}

int main()
{
    Persona p; /// variable de tipo Persona.
    Persona personas[TAM_MAX];
    int validos=0;
//    p=cargaPersona();
//    muestraPersona(p);
    cargaPersonas2(personas,&validos);
    muestraPersonas(personas,validos);

    return 0;
}
