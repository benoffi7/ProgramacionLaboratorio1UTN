#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10
#define nomArch "personas.bin"

typedef struct
{
    char direccion[40];
    int depto; // 1 si es depto 0 si es casa
    char barrio[20];
    char ciudad[20];

}Ubicacion;


typedef struct {
    char nomyAp[40];
    char dni[10];
    int edad;
    int baja; ///1 dado de baja y 0 no
    Ubicacion ubicacion;
}Persona;

void carga(Persona[],int*);
Persona cargaPersona();
Ubicacion cargaUbicacion();


Ubicacion cargaUbicacion()
{
    Ubicacion u;

    printf("Ingrese direccion\n");
    fflush(stdin);
    gets(u.direccion);
    printf("Ingrese barrio\n");
    fflush(stdin);
    gets(u.barrio);
    printf("Ingrese 1 depto o  0 casa\n");
    scanf("%i",&u.depto);
    printf("Ingrese ciudad\n");
    fflush(stdin);
    gets(u.ciudad);

    return u;
}

Persona cargaPersona()
{
    Persona p;

    printf("Ingrese nombre y apellido\n");
    fflush(stdin);
    gets(p.nomyAp);
    printf("Ingrese dni\n");
    fflush(stdin);
    gets(p.dni);
    printf("ingrese edad\n");
    scanf("%i",&p.edad);
    p.baja = 0;
    p.ubicacion = cargaUbicacion();

    return p;
}


void carga(Persona personas[],int* validos)
{
    char seguir='s';
    while (*validos < TAM_MAX && seguir == 's')
    {
        personas[*validos]=cargaPersona();
        (*validos)++;
        printf("Desea continuar\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }

}

void persistencia(Persona personas[],int validos)
{
    FILE* fp = fopen(nomArch,"ab"); ///si no existe lo crea, situa el cursor al final del archivo
    if (fp != NULL)
    {
        fwrite(personas,sizeof(Persona)*validos,1,fp);
        fclose(fp);
    }

}

void despersistencia(Persona personas2[], int* validos2)
{
    FILE* fp = fopen(nomArch,"rb");
    Persona p;

    if (fp != NULL)
    {
        while (fread(&p,sizeof(Persona),1,fp) > 0)
        {
            personas2[*validos2] = p;
            (*validos2)++;

        }

        fclose(fp);
    }
}

void muestraUbicacion(Ubicacion u)
{
    printf("Direccion: %s\n", u.direccion);
    printf("Barrio: %s\n", u.barrio);
    printf("Ciudad: %s\n", u.ciudad);
    if (u.depto == 1)
        printf("Vive en Depto\n");
    else
        printf("Vive en Casa\n");

}


void muestraPersona(Persona p)
{
   printf("Nombre y apellido: %s\n",p.nomyAp);
   printf("Edad: %i\n",p.edad);
   printf("Dni: %s\n",p.dni);
   muestraUbicacion(p.ubicacion);
}

void muestraPersonas(Persona personas[],int validos)
{
    for (int i = 0 ; i < validos ; i++)
    {
        muestraPersona(personas[i]);
    }

}

///pos comienza desde 0
0..
1
2
3
4
5
6
///cantidad de personas que hay en el archivo
int cantidadPersonasEnArchivo()
{
    int cantidadPersonas=0;
    FILE* fp= fopen(nomArch,"rb");
    if (fp != NULL)
    {
        fseek(fp,0,SEEK_END); ///situo el cursor al final del archivo
        cantidadPersonas = ftell(fp)/sizeof(Persona);
        fclose(fp);
    }

    return cantidadPersonas;
}

-///busca una pos de una persona en el archivo y devuelve dicha persona
Persona buscaPosEnArchivoPersonas(int pos)
{
    Persona p;
    int cant;
    FILE* fp = fopen(nomArch,"rb");
    if (fp != NULL)
    {
        cant=cantidadPersonasEnArchivo();
        if (pos < cant) ///la pos es una posicion valida en mi archivo (esta dentro de mi cantidad)
        {
            fseek(fp,pos*sizeof(Persona),SEEK_SET);
            fread(&p,sizeof(Persona),1,fp);
        }
        fclose(fp);
    }

    return p;
}


int main()
{
    Persona personas[TAM_MAX];
    int validos=0;
    //carga(personas,&validos);
    //persistencia(personas,validos);
    //printf("%li",sizeof(Persona));
    despersistencia(personas,&validos);
    muestraPersonas(personas,validos);

    return 0;
}
