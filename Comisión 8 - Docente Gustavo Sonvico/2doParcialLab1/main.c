#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARCH_MONOTRIBUTISTAS "monotributistas.dat"
#define ARCH_FACTURA_A "facturasA.dat"
#define ARCH_FACTURA_B "facturasB.dat"

//ESTRUCTURAS
typedef struct
{
    int idMonotrib;
    long int cuit;  // valores entre 2.000.000 y 10.000.000
    char nombreYapellido [30];
} stMonotributista;

typedef struct
{
    int nroFactura;
    int idMonotrib;
    char tipoFactura; // A o B en mayúscula
    float montoTotal; // no más de $ 500.000
    // no puede haber montos negativos
} stFactura;


//PROTOTIPADO
int menuPrincipal ();
int cargaArrayMon (stMonotributista array[], int dim);
int devuelveCUIT ();
int cargaArrayFacturas(stFactura array[], int dim2, stMonotributista arraymon[], int * validMon);
char devuelveTipoFactura();
int devuelveMontoTotal();
void ArrayToArchivoMonot(stMonotributista array[], int valid, char nombreArchi[]);
void ArrayToArchivoFact(stFactura array [], int valid);
void cualArchivoMostrar ();
void muestraArchMonot();
void muestraMonot (stMonotributista monot);
void muestraArchFact (char nombreArch[]);
void muestraFact (stFactura factura);
int poseeFactAyB (int id);
int buscaIdMonot(int cuit);

//MAIN
int main()
{
    stMonotributista monotributistas [100];
    stFactura facturas [100];


    int opc=1,validMon=0, validFact=0, rta=0, cuit=0;
    opc = menuPrincipal();
    while (opc!=0)
    {
        switch(opc)
        {
        case 1:
            validMon=cargaArrayMon(monotributistas,100);
            system("pause");
            break;
        case 2:
            validFact=cargaArrayFacturas(facturas,100, monotributistas,&validMon);
            system("pause");
            break;
        case 3:
            ArrayToArchivoMonot(monotributistas,validMon, ARCH_MONOTRIBUTISTAS);
            ArrayToArchivoFact(facturas,validFact);
            printf("Archivos pasados con exiiiitoooo");
            system("pause");
            break;
        case 4:
            cualArchivoMostrar();
            system("pause");
            break;
        case 5:
            printf("\n Ingrese CUIT:");
            scanf("%d",&cuit);
            rta=buscaIdMonot(cuit);
            if(rta==1)
            {
                printf("\nEl monotributista posee facturas en ambos archivos!\n");
            }
            else
            {
                printf("\nEl monotributista NO posee facturas en ambos archivos!\n");
            }

            system("pause");
            break;
        }
        opc = menuPrincipal();
    }
    return 0;
}


//FUNCIONES
int menuPrincipal ()
{
    system("cls");
    int opc=0;
    printf("\n Elija que ejecicio quiere ver o ingrese 0 para salir. \n");
    printf(" NOTA: \n");
    printf(" 1) Carga arreglo de monotributistas.\n");
    printf(" 2) Carga arreglo con las facturas. \n");
    printf(" 3) Pasar los datos a los archivos correspondientes.\n");
    printf(" 4) Muestra archivo seleccionado. \n");
    printf(" 5) Devuelve 1 si posee ambas facutras.\n");
    scanf("%d",&opc);
    return opc;
}


int cargaArrayMon (stMonotributista array[], int dim)
{
    int i=0;
    char opc='1';
    while ((i<dim)&&(opc!='0'))
    {
        i=cargaMonotributista(i,array);

        printf("\n Desea seguir cargando? Ingrese 0 para terminar o cualquier tecla para continuar: ");
        fflush(stdin);
        scanf("%c",&opc);
    }
    return i;
}

int cargaMonotributista (int i, stMonotributista array[])
{
    printf("\n Ingrese ID del monotributista: ");
    scanf("%d", &array[i].idMonotrib);

    array[i].cuit=devuelveCUIT();

    printf("\n Ingrese NOMBRE del monotributista: ");
    fflush(stdin);
    gets(array[i].nombreYapellido);

    i++;

    return i;
}

int devuelveCUIT ()
{
    int num=0;
    printf("\n Ingrese CUIT: ");
    scanf("%d", &num);
    while ((num<2000000)||(num>10000000))
    {
        printf("\n Error, CUIT incorrecto.");
        printf("\n Ingrese CUIT: ");
        scanf("%d", &num);
    }
    return num;
}

int cargaArrayFacturas(stFactura array[], int dim, stMonotributista arraymon[], int * validMon)
{

    int idMon =0;

    int i=0;
    char opc='1';
    while ((i<dim)&&(opc!='0'))
    {

        printf("\n Ingrese ID DEL MONOTRIBUTISTA: ");
        scanf("%d", &idMon);

        if (existeId(idMon,arraymon,*validMon)==0)
        {
            printf("\n El monotributista no existe, debe cargarlo\n ");
            *validMon=cargaMonotributista(*validMon,arraymon);
        }

        array[i].idMonotrib=idMon;

        printf("\n Ingrese NRO DE FACTURA: ");
        scanf("%d", &array[i].nroFactura);

        array[i].tipoFactura = devuelveTipoFactura();

        array[i].montoTotal = devuelveMontoTotal();

        printf("\n Desea seguir cargando? Ingrese 0 para terminar o cualquier tecla para continuar: ");
        fflush(stdin);
        scanf("%c",&opc);
        i++;
    }
    return i;
}

int existeId (int id, stMonotributista array[], int valid)
{
    int flag=0,i=0;

    while (i<valid && flag==0)
    {
        if (id == array[i].idMonotrib)
        {
            flag=1;
        }
        i++;
    }
    return flag;
}

char devuelveTipoFactura()
{
    char tipo='x';
    printf("\n Ingrese TIPO DE FACTURA (A o B): ");
    fflush(stdin);
    scanf("%c", &tipo);
    while ((tipo!='A')&&(tipo!='B'))
    {
        printf("\n Error, TIPO incorrecto.");
        printf("\n Ingrese TIPO DE FACTURA: ");
        fflush(stdin);
        scanf("%c", &tipo);
    }
    return tipo;
}

int devuelveMontoTotal()
{
    int num =0;
    printf("\n Ingrese MONTO TOTAL: ");
    scanf("%d", &num);
    while ((num<0)&&(num>500000))
    {
        printf("\n Error, MONTO incorrecto.");
        printf("\n Ingrese MONTO TOTAL: ");

        scanf("%d", &num);
    }
    return num;
}


void ArrayToArchivoMonot(stMonotributista array[], int valid, char nombreArchi[])
{
    FILE*archi=fopen(nombreArchi, "ab");

    if (archi!=NULL)
    {
        fwrite(array,sizeof(stMonotributista),valid,archi);
        fclose(archi);
    }
}

void ArrayToArchivoFact(stFactura array [], int valid)
{
    FILE*archA=fopen(ARCH_FACTURA_A,"ab");
    FILE*archB=fopen(ARCH_FACTURA_B,"ab");

    stFactura factura;

    int i=0, valor=0;
    int contA=0, contB=0;

    if(archA!=NULL && archB!=NULL)
    {
        for (i=0; i<valid; i++)
        {
            if(array[i].tipoFactura=='A')
            {
                fwrite(&array[i], sizeof(stFactura),1,archA);
            }
            else
            {
                fwrite(&array[i], sizeof(stFactura),1,archB);
            }
        }
        fclose(archA);
        fclose(archB);
    }
}


void cualArchivoMostrar ()
{
    int num=0, num2=0;
    printf("\n Que archivo desea visualizar?");
    printf("\n 1: ARCHIVO DE MONOTRIBUTISTAS");
    printf("\n 2: ARCHIVO DE FACTURAS");
    printf("\n");

    scanf("%d", &num);
    while ((num!=1)&&(num!=2))
    {
        printf("\n Error, opcion invalida.");
        printf("\n Que archivo desea ver?  ");
        scanf("%d", &num);
    }

    if (num==1)
    {
        muestraArchMonot(ARCH_MONOTRIBUTISTAS);
    }
    else
    {
        printf("\n Desea visualizar [1: FACTURAS A] o [2: FACTURAS B]? --> ");
        scanf("%d", &num2);
        while ((num2!=1)&&(num2!=2))
        {
            printf("\n Error, opcion invalida.");
            printf("\n Desea visualizar [1: FACTURAS A] o [2: FACTURAS B]? --> ");
            scanf("%d", &num2);
        }
        if (num2==1)
        {
            muestraArchFact(ARCH_FACTURA_A);
        }
        else
        {
            muestraArchFact(ARCH_FACTURA_B);
        }
    }

}


void muestraArchMonot()
{
    stMonotributista monotributista;
    FILE*archi=fopen(ARCH_MONOTRIBUTISTAS,"rb");
    if (archi!=NULL)
    {
        while (fread(&monotributista,sizeof(stMonotributista),1,archi)>0)
        {
            muestraMonot(monotributista);
        }
        fclose(archi);
    }
}

void muestraMonot (stMonotributista monot)
{
    printf("\n ------------------------------------------");
    printf("\n               ID : %d", monot.idMonotrib);
    printf("\n NOMBRE Y APELLIDO: %s", monot.nombreYapellido);
    printf("\n              CUIT: %d", monot.cuit);
    printf("\n ------------------------------------------");
}

void muestraArchFact (char nombreArch[])
{
    stFactura factura;
    FILE*archi=fopen(nombreArch,"rb");

    if (archi!=NULL)
    {
        while(fread(&factura,sizeof(stFactura),1,archi)>0)
        {
            muestraFact(factura);
        }
    }
    fclose(archi);
}

void muestraFact (stFactura factura)
{
    printf("\n ------------------------------------------");
    printf("\n   NRO DE FACTURA : %d", factura.nroFactura);
    printf("\n               ID : %d", factura.idMonotrib);
    printf("\n   TIPO DE FACTURA: %c", factura.tipoFactura);
    printf("\n       MONTO TOTAL: %f", factura.montoTotal);
    printf("\n ------------------------------------------");
}


int poseeFactAyB (int id)
{
    stFactura factura;
    int flagA=0, flagB=0, flag=0;

    FILE*archA=fopen(ARCH_FACTURA_A,"rb");
    FILE*archB=fopen(ARCH_FACTURA_B,"rb");

    if (archA!=NULL)
    {
        while(fread(&factura,sizeof(stFactura),1,archA)>0 && flagA==0)
        {
            if (factura.idMonotrib==id){
                flagA=1;
            }
        }

        fclose(archA);
    }

    if (archB!=NULL)
    {
        while(fread(&factura,sizeof(stFactura),1,archB)>0 && flagB==0)
        {
            if (factura.idMonotrib==id){
                flagB=1;
            }
        }

        fclose(archB);
    }


    if ((flagA==1)&&(flagB==1))
    {
        flag=1;
    }
    return flag;
}



int buscaIdMonot(int cuit)
{

    int id=0, rta=0;

    id = existeCUIT(cuit);

    if(id==-1)
    {
        rta=0;
    }
    else
    {
        rta = poseeFactAyB(id);
    }

    return rta;
}


int existeCUIT(int num)
{
    int flag=-1;
    stMonotributista monot;
    FILE*archi=fopen(ARCH_MONOTRIBUTISTAS,"rb");

    if (archi!=NULL)
    {
        while ((flag==-1)&&(fread(&monot,sizeof(stMonotributista),1,archi)>0))
        {
            if (monot.cuit==num)
            {
                flag=monot.idMonotrib;
            }
        }
        fclose(archi);
    }
    else
    {
        printf("\n Error, intente nuevamente.");
    }
    return flag;
}






