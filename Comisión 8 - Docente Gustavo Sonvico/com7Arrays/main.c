#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarArregloInt(int A[], int dim);

void mostrarArregloInt(int A[], int cantVal);

void mostrarArregloChar(char A[], int cantVal);

char buscarCharMax(char A[], int cantVal);

void cargaRandomMatrizInt(int filas, int columnas, int M[filas][columnas]);

void mostrarMatrizInt(int filas, int columnas, int M[filas][columnas]);

int cargarArregloPalabras(int dim, int dimCaracteres, char p[][dimCaracteres]);

void mostrarArregloPalabras(int cantVal, int dimCaracteres, char p[][dimCaracteres]);

int agregaCharEnOrden (char A[], int validos, char dato);

void generaNuevoArray(int viejo[], int valV, int nuevo[], int dimN);

void mostrarMatrizTabulada (int valF, int valC, int M[valF][valC]);

int sumaArreglo(int A[], int validos);

int sumaMatrizBis (int valF, int valC. int M[valF][valC]);

const int MAXEMPLE=100;

int main()
{

    srand(time(NULL));
    /*
        printf("Hello arrays!\n");

        int arregloOrig[]= {1,5,6,7,8};

        printf("%p", arregloOrig);

        system("pause");

        int arregloNuevo[5];

        mostrarArregloInt(arregloOrig, 5);

        generaNuevoArray(&arregloOrig, 5, arregloNuevo, 5);

        mostrarArregloInt(arregloNuevo, 5);

        system("pause");

        int matriz[10][4];


    /// declaro el arreglo

        int idEmpleados[MAXEMPLE];

    /// el compilador ve esto.
    /// int * idEmpleados=malloc(sizeof(int)*100);

    /// variable para saber cuantos elementos se cargaron en el arreglo
        int cantEmpleados=0;


        int aux;
        int a[10];
        int cantVal=0;
        int i;

        printf("Vamos a cargar el arreglo desde el main: \n");
        for(i=0; i<10; i++)
        {
            printf("Ingrese un valor: ");
            scanf("%d", &a[i]);
        }

        cantVal=i;

        printf("Contenido del arreglo (mostrado desde el main):\n");
        for(i=0; i<cantVal; i++)
        {
            printf("%d ", a[i]);
        }

        system("pause");
        system("cls");

    /// invocamos la fn para cargar, enviamos el array de empleados y su dimension
    /// la variable cantEmpleados va a contener la cantidad de datos que cargo el usr
        cantEmpleados=cargarArregloInt(idEmpleados, MAXEMPLE);

    /// ahora mostramos el contenido del arreglo desde la fn, le enviamos el arreglo y
    /// la cantidad que se cargo con la fn de carga
        mostrarArregloInt(idEmpleados, cantEmpleados);



        char unaPalabra[5];

        printf("direccion de memoria del arreglo %p\n", unaPalabra);

        system("pause");

        printf("Ingrese una palabra: ");
        fflush(stdin);

    ///   scanf("%s", unaPalabra);
        gets(unaPalabra);

        printf("La palabra escaneada es %s\n", unaPalabra);

    /// mostrarArregloChar(unArregloDeChar, 10);

        system("pause");

        char miArreglo[7]= {"pomlfai"};

        int validos=7;

        mostrarArregloChar(miArreglo, validos);

        char caracterMaximo = buscarCharMax(miArreglo,validos);

        printf("El maximo caracter es %c \n", caracterMaximo);*/

    int matrix [5][6];
    int otramatrix [2][3];

    cargaRandomMatrizInt(5,6,matrix);
    cargaRandomMatrizInt(2,3,otramatrix);

    mostrarMatrizTabulada(5,6,matrix);
    mostrarMatrizTabulada(2,3,otramatrix);

//    char palabras[10][30];
//
//    int val=cargarArregloPalabras(10, 30, palabras);

//    mostrarArregloPalabras(val, 30, palabras);

    return 0;
}

void generaNuevoArray(int viejo[], int valV, int nuevo[], int dimN)
{
    /// Dado un el arreglo de enteros {1,5,6,7,8} escribir un programa que
    /// genere otro arreglo con la suma del contenido de todo los elementos
    /// anteriores al índice actual. El resultado final del segundo arreglo
    /// es el siguiente: {1,6,12,19,27}.

    int i=0, j=0;

    if(i<valV)
    {
        nuevo[i]=viejo[i];
        for(i=1; i<valV; i++)
        {
            nuevo[i]=0;
            for(j=i; j>=0; j--)
            {
                nuevo[i]+=viejo[j];
            }
        }
    }
}


int cargarArregloInt(int A[], int dim)
{
    int i=0;
    char control='s';

    while(i<dim && control=='s')
    {
        printf("Ingrese un valor entero: ");
        scanf("%d",&A[i]);

        printf("Desea continuar? s/n\n");
        fflush(stdin);
        scanf("%c", &control);
        i++;
    }
    /// retornamos el valor de i, que es la cantidad de valores que se cargaron en el array

    return i;
}

void mostrarArregloInt(int A[], int cantVal)
{
    int i;

    printf("\nContenido del arreglo de int:\n");

    for(i=0; i<cantVal; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void mostrarArregloChar(char A[], int cantVal)
{
    int i;

    printf("Contenido del arreglo de char:\n");

    for(i=0; i<cantVal; i++)
    {
        printf("%c ", A[i]);
    }
}

char buscarCharMax(char A[], int cantVal)
{
    int i=0;

    char charMax=A[i];


    for(i=1; i<cantVal; i++)
    {
        if(A[i]>charMax)
        {
            charMax=A[i];
        }
    }

    return charMax;
}

int buscaPosMenor(int A[], int cantVal, int pos)
{
    int menor = A[pos];

    int posMenor=pos;

    int i = pos+1;

    while(i<cantVal)
    {
        if(A[i]<menor)
        {
            menor=A[i];
            posMenor=i;
        }
        i++;
    }

    return posMenor;
}

void cargaRandomMatrizInt(int filas, int columnas, int M[filas][columnas])
{
    int i, j;

    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            M[i][j]=rand()%1000;
        }
    }
}

void mostrarMatrizInt(int filas, int columnas, int M[filas][columnas])
{
    int i, j;

    printf("Contenido de la matriz: \n");
    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}


int cargarArregloPalabras(int dim, int dimCaracteres, char p[][dimCaracteres])
{
    int i=0;
    char control='s';

    while(i<dim && control=='s')
    {
        printf("Ingrese una palabra: (maximo 30 chars)\n");

        fflush(stdin);
        scanf("%s", p[i]);

        printf("Desea continuar? s/n\n");
        fflush(stdin);
        scanf("%c", &control);
        i++;
    }
    /// retornamos el valor de i, que es la cantidad de valores que se cargaron en el array

    return i;

}

void mostrarArregloPalabras(int cantVal, int dimCaracteres, char p[][dimCaracteres])
{

    int i;

    printf("Contenido del arreglo de palabras:\n");

    for(i=0; i<cantVal; i++)
    {
        printf("%s\n", p[i]);
    }
}

/*Hacer una función (o varias) que ordene un arreglo de palabras por
orden alfabético. (Por selección o inserción, el que más te guste)  */

int buscaPalabraMenor(int cantVal, int dimCaracteres, char p[][dimCaracteres], int limite)
{
    int posMenor=limite;

    char menor[dimCaracteres];

    strcpy(menor, p[limite]);

    int i=limite+1;

    while(i<cantVal)
    {
        if(strcmpi(p[i], menor)<0)
        {
            posMenor=i;
            strcpy(menor, p[limite]);
        }
        i++;
    }

    return posMenor;
}

void ordenXseleccionPalabras(int cantVal, int dimCaracteres, char p[][dimCaracteres])
{
    int i, posMenor;

    char aux[dimCaracteres];

    for(i=0; i<cantVal-1; i++)
    {
        posMenor=buscaPalabraMenor(cantVal, dimCaracteres, p,i);

        strcpy(aux, p[posMenor]);
        strcpy(p[posMenor], p[i]);
        strcpy( p[i], aux);
    }
}



int agregaCharEnOrden (char A[], int validos, char dato)
{
    int i = validos-1;
    while (i>=0 && dato<A[i])
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]= dato;
    return validos+1;
}

void mostrarMatrizTabulada (int valF, int valC, int M[valF][valC])
{
    int f=0;
    int c=0;
    int dato;

    printf("\nContenido de la matriz: \n");
    for(f=0; f<valF; f++)
    {
        for(c=0; c<valC; c++)
        {
            dato=M[f][c];
            switch(dato)
            {
            case 0 ... 9:
                printf("   ");
                break;
            case 10 ... 99:
                printf("  ");
                break;
            case 100 ... 999:
                printf(" ");
            }
            printf("%d", M[f][c]);
            ///   printf("%4d", M[f][c]);
        }
        printf("\n");
    }
}

int sumaArreglo(int A[], int validos)
{
    int i=0;
    int suma=0;

    for(i=0; i<validos; i++)
    {
        suma+=A[i];
    }
    return suma;
}

int sumaMatrizBis (int valF, int valC. int M[valF][valC])
{
    int f=0;

    int suma=0;

    for(f=0; f<valF; f++)
    {
        /// utiliza la funcion sumaArreglo
        /// y trabaja cada fila de la matriz
        /// como si fuera un arreglo de dimension valC

        /// esta bueniiiiisimo!!!

        suma +=sumaArreglo(M[f], valC);
    }
    return suma;
}
