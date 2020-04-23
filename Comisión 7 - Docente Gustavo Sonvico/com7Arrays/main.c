#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarArregloInt(int A[], int dim);

void mostrarArregloInt(int A[], int cantVal);

void mostrarArregloChar(char A[], int cantVal);

const int MAXEMPLE=100;

int main()
{

    printf("Hello arrays!\n");

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

    return 0;
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

    printf("Contenido del arreglo de int:\n");

    for(i=0; i<cantVal; i++)
    {
        printf("%d ", A[i]);
    }
}

void mostrarArregloChar(char A[], int cantVal)
{
    int i;

    printf("Contenido del arreglo de char:\n");

    for(i=0; i<cantVal; i++)
    {
        printf("%d ", A[i]);
    }
}
