#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargaMatrizIntRandom(int filas, int columnas, int M[filas][columnas]);
void mostraMatrizInt(int filas, int columnas, int M[filas][columnas]);

void mostrarArreglo (int A[], int cantidad);
void mostrarMatrizOtro(int filas, int columnas, int M[filas][columnas]);

int cargarPalabras(int f, int c, char P[f][c]);
void mostrarPalabras(int f, int c, char P[f][c]);

int cargaArreglosParalelos (int matricula[],  char nombre[][30], int dim);
void muestraArreglosParelelos (int matricula[], char nombre[][30], int cant);

int main()
{
    printf("Hello the matrix!\n");

    srand(time(NULL));

    int unArreglo[10];

    int * otroArreglo = malloc( sizeof(int) * 10);

   /// cargo el arreglo

   /// muestro el arreglo

    otroArreglo = realloc(otroArreglo, sizeof(int)*20);

    int miMatrix[4][8];

    cargaMatrizIntRandom(4,8,miMatrix);

    mostraMatrizInt(4,8,miMatrix);


    char misPalabras[10][30];
    int validosPalabras=0;

    validosPalabras=cargarPalabras(10, 30, misPalabras);
    mostrarPalabras(validosPalabras, 30, misPalabras);


    return 0;
}

void cargaMatrizIntRandom(int filas, int columnas, int M[filas][columnas])
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

void mostraMatrizInt(int filas, int columnas, int M[filas][columnas])
{
    int i, j;

    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            printf("[%d]", M[i][j]);
        }
        printf("\n");
    }
}

void mostrarArreglo (int A[], int cantidad)
{
    int i = 0;

    while (i<cantidad)
    {
        printf("%d ", A[i]);
        i++;
    }
}

void mostrarMatrizOtro(int filas, int columnas, int M[filas][columnas])
{
    int f, c;

    for(f=0; f<filas; f++)
    {
        mostrarArreglo(M[f],columnas);
        printf("\n");
    }
}


int cargarPalabras(int filas, int columnas, char P[filas][columnas])
{
    int i=0;
    char control='s';

    printf("Carguemos tus palabras: \n");
    while(i<filas && control=='s')
    {
        printf("Ingrese una palabra (max. %d char): ", columnas-1);
        fflush(stdin);

        scanf("%s", &P[i]);

        printf("Desea continuar esta tortura? s/n \n\n\t");
        fflush(stdin);
        scanf("%c", &control);

        i++;
    }
    return i;
}

void mostrarPalabras(int f, int c, char P[f][c])
{
    int i=0;
    printf("Estas son tus palabras: \n");
    for(i=0;i<f;i++)
    {
        printf("\t%s\n", P[i]);
    }
}


/// arreglos paralelos


///Sean los arreglos paralelos: int matricula[20], char nombre[20][30]

///1. Crear una función que los cargue, hasta que el usuario lo decida */

int cargaArreglosParalelos (int matricula[],  char nombre[][30], int dim)
{
    int i = 0;
    char rta='s';

    while(i<dim && rta=='s')
    {
        printf("\nIngrese matricula del alumno: ");
        scanf("%d",&matricula[i]);
        fflush(stdin);
        printf("\nIngrese nombre del alumno (hasta 30 caracteres): ");
        scanf("%s",&nombre[i]);
        i++;

        printf("\n\nDesea ingresar los datos de otro alumno? (s/n): ");
        fflush(stdin);
        scanf("%c",&rta);
    }
    return i;
}

void muestraArreglosParelelos (int matricula[], char nombre[][30], int cant)
{
    int i=0;

    while(i<cant)
    {
        printf("\tMatricula: %d\n", matricula[i]);
        printf("\tNombre:    %s\n", nombre[i]);
        i++;
    }
}
