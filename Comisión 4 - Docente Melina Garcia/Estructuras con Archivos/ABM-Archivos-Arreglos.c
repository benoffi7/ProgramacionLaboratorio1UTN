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

} Ubicacion;


typedef struct
{
    char nomyAp[40];
    char dni[10];
    int edad;
    int baja; ///1 dado de baja y 0 no
    Ubicacion ubicacion;
} Persona;

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
    p.baja = 0; ///esto es para la baja logica
    p.ubicacion = cargaUbicacion();

    return p;
}
///siempre que se ejectua el programa, se despersiste hacia el arreglo una sola vez
///alta sincronizada (archivo y arreglo) actualizo ambos a la vez
///modificacion sincronizada (archivo y arreglo) actualizo ambos a la vez
///baja (modificacion de campo de la estructura del registro para denotar baja logica) sincronizada con arreglo
///mantenimiento: se generara un nuevo archivo con los datos no dados de baja (baja en 0) y luego se renombrara
///al nombre original de archivo, tener en cuenta que si ocurre y queremos seguir luego trabajando con el arreglo
///se debe volver a despersistir (para que coincida la informacion).

///baja fisica se dara en X momento que nosotros filtremos aquellos registros que esten dados de baja

void carga(Persona personas[],int* validos)
{
    char seguir='s';
    while (*validos < TAM_MAX && seguir == 's')
    {
        personas[*validos]=cargaPersona();
        printf("Desea continuar\n");
        fflush(stdin);
        persistenciaPersona(personas[*validos]);///hago alta en el archivo.
        (*validos)++;
        scanf("%c",&seguir);
    }

}


void persistenciaPersona(Persona p)
{
    FILE* fp = fopen(nomArch,"ab"); ///se situa al final en el archivo
    if (fp != NULL)
    {
        fwrite(&p,sizeof(Persona),1,fp);
        fclose(fp);
    }

}

void modificaUbicacion(Ubicacion* u)
{
    printf("Seleccione que campo desea modificar\n");

    printf("1. direccion\n");
    printf("2. barrio\n");
    printf("3. ciudad\n");
    printf("4. depto\n");
    scanf("%i",&op);

    switch(op)
    {
    case 1:
        ....

    }
}

void modificaCampos(Persona* p)
{
    int op;
    printf("Seleccione que campo desea modificar\n");

    printf("1. nombre y apellido\n");
    printf("2. dni\n");
    printf("3. edad\n");
    printf("4. ubicacion\n");
    scanf("%i",&op);
    switch(op)
    {
    case 1:
        printf("Ingrese nombre y ap nuevo\n");
        fflush(stdin);
        gets((*p).nomYap);
        break;
    case 2:
        printf("Ingrese nuevo dni\n");
        fflush(stdin);
        gets((*p).dni);
        break;
        ..
        ..
    case 4:
        modificaUbicacion(&((*p).ubicacion));
        break;

    }

}

///modifica un dato en el arreglo y en el archivo, segun coincida con el valor recibido por parametro
void modificacionDato(Persona personas[], int validos, char dni[])
{
    Persona p;
    int i = 0;
    FILE* fp = fopen(nomArch,"r+b");
    if (fp != NULL)
    {
        while (fread(&p,sizeof(Persona),1,fp) > 0 && strcmp(dni,p.dni) != 0)
        {
            i++;
        }
        if (i < validos)
        {
            modificaCampos(&personas[i]);
            fseek(fp,(-1)*sizeof(Persona),SEEK_CUR);
            fwrite(&personas[i],sizeof(Persona),1,fp);
            printf("El dato se modifico con exito en el archivo");
        }
        else
        {
            printf("El dato no se encuentra en el archivo");
        }
        fclose(fp);
    }

}


///baja logica de un dato dado el dni
///baja logica sincronica, tanto en archivo como en arreglo
void baja(Persona personas[], int validos, char dni[])
{
    int i=0;
    FILE * fp = fopen(nomArch,"r+b");
    if (fp != NULL)
    {
        while (fread(&p,sizeof(Persona),1,fp) > 0 && strcmp(dni,p.dni) != 0)
        {
            i++;
        }
        if (i < validos)
        {
            personas[i].baja=1; ///baja logica por que se que NO DEBERIA EXISTIR ya que esta el campo en 1
            fseek(fp,(-1)*sizeof(Persona),SEEK_CUR);
            fwrite(&personas[i],sizeof(Persona),1,fp);
            printf("El dato se dio de baja con exito en el archivo");
        }
        else
        {
            printf("El dato no existe en el archivo");

        }
        fclose(fp);
    }
}

///esto se hace en X momento, cada X semanas.., no cada vez que ejecutemos el programa
///se ejecuta el programa solamente para hacer el mantenimiento
///si no, se puede seguir trabajando en el proceso pero se debe despersistir nuevamente en el arreglo
void mantenimientoArchivo()
{
    Persona p;
    FILE* fp = fopen(nomArch,"rb");
    FILE* fpNuevo = fopen("personas.TMP","wb");
    if (fp != NULL && fpNuevo != NULL)
    {
        while(fread(&p,sizeof(Persona),1,fp) > 0)
        {
            if (p.baja == 0)
            {
                fwrite(&p,sizeof(Persona),1,fpNuevo);
            }
        }
        fclose(fp);
        fclose(fpNuevo);

    }
    remove(nomArch); ///se elimina el archivo del disco
    rename("personas.TMP",nomArch); ///renombramos el archivo temporal al original

}


///pasa a un segundo plano cuando doy de alta persona a persona
///se deja de usar
//void persistencia(Persona personas[],int validos)
//{
//    FILE* fp = fopen(nomArch,"wb"); ///si no existe lo crea, situa el cursor al principio y sobreescribe del archivo
//    if (fp != NULL)
//    {
//        fwrite(personas,sizeof(Persona)*validos,1,fp);
//        fclose(fp);
//    }
//
//}


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
    //printf("%li",sizeof(Persona));
    //despersistencia(personas,&validos);

    return 0;
}
