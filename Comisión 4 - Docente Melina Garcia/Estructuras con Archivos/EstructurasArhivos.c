#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 10
#define NOMARCH "personas.bin"

typedef struct
{
    char direccion[30];
    char ciudad[30];
    char barrio[30];
} Ubicacion;

typedef struct
{
    char nomYap[40];
    char dni[11];
    char telefono[15];
    Ubicacion ubicacion;
} Persona;

Ubicacion cargaUbicacion()
{
    Ubicacion u;

    printf("Ingrese direccion\n");
    fflush(stdin);
    gets(u.direccion);
    printf("Ingrese ciudad\n");
    fflush(stdin);
    gets(u.ciudad);
    printf("Ingrese barrio\n");
    fflush(stdin);
    gets(u.barrio);

    return u;
}


Persona cargaPersona()
{
    Persona p;
    printf("Ingrese nombre y apellido\n");
    fflush(stdin);
    gets(p.nomYap);
    printf("Ingrese dni\n");
    fflush(stdin);
    gets(p.dni);
    printf("Ingrese telefono\n");
    fflush(stdin);
    gets(p.telefono);
    p.ubicacion = cargaUbicacion();

    return p;
}


void carga(Persona personas[], int* validos)
{
    char seguir='s';
    while (*validos < CANT_MAX && seguir == 's')
    {
        personas[*validos] = cargaPersona();
        (*validos)++;
        printf("desea continuar\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }

}

void mostrarUbicacion(Ubicacion u)
{
    printf("direccion: %s\n", u.direccion);
    printf("ciudad: %s\n", u.ciudad);
    printf("barrio: %s\n", u.barrio);
}


void mostrarPersona(Persona p)
{
    printf("nombre y apellido: %s\n", p.nomYap);
    printf("dni: %s\n", p.dni);
    printf("telefono: %s\n", p.telefono);
    mostrarUbicacion(p.ubicacion);


}


void muestraPersonas(Persona personas[],int validos)
{
    for (int i = 0 ;  i < validos ; i++)
    {
        mostrarPersona(personas[i]);

    }

}

///persistencia y despersistencia de datos

void persistencia(Persona personas[],int validos)
{
    FILE* fp = fopen(NOMARCH,"ab"); ///modo ab agrega cada dato al final el archivo, crea el archivo si este no exsiste
    if (fp != NULL)
    {
        fwrite(personas,sizeof(Persona),validos,fp);
        fclose(fp);
    }
}

void despersistencia(Persona personas2[], int* validos2)
{
    FILE* fp = fopen(NOMARCH, "rb"); ///se abre en modo lectura
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

///mostrar la Persona que se encuentra en la posicion pos del archivo.
///si pos comienza desde 0: avanzare sizeof(PErsona)*pos
///si pos comienza desde 1: avanzare sizeof(Persona)*(pos-1) ///esta no se tiene en cuenta

int posExiste(int pos)
{
    FILE* fp = fopen(NOMARCH,"rb");
    int cant;
    if (fp != NULL)
    {
        fseek(fp,0,SEEK_END); ///me situo al final del archivo
        cant = ftell(fp)/sizeof(Persona); ///devuelvo donde en cantidad de bytes se situa el cursor
        ///y lo divido por el tamano de una persona
        fclose(fp);
        if ( pos < cant)
        {
            return 1;

        }
        else
        {
            return 0;
        }
    }

}

void traerPersona(int pos)
{
    Persona p;
    FILE* fp = fopen(NOMARCH,"rb");
    if ( fp != NULL)
    {
        if (posExiste(pos) == 1)
        {
            fseek(fp,sizeof(Persona)*(pos),SEEK_SET); ///me situo al principio y me voy a la derecha (positivo en bytes)
            fread(&p,sizeof(Persona),1,fp); ///leo la persona en esa posicion
            fclose(fp);
            mostrarPersona(p);
        }
        else
        {
            printf("La posicion es inexistente\n");
        }
    }
}


void modificarPersona(int pos)
{
    FILE* fp = fopen(NOMARCH,"r+b"); /// puedo leer y escribir en el archivo
    if (fp != NULL)
    {
        //busco posicion
        //leo dato
        //modifico dato
       //y luego debo moverme una posicion HACIA ATRAS (negativamente en bytes) fseek(fp,sizeof(Persona)*(-1), SEEK_CUR);
       //y reescribo ese dato que modifique.
    }

}


int main()
{
    Persona personas[CANT_MAX];
    int validos=0;
    //carga(personas,&validos);
    //persistencia(personas,validos);
    //despersistencia(personas,&validos);
    //muestraPersonas(personas,validos);

    return 0;
}
