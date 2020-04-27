#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cargarArregloInt(int A[], int dim);

void mostrarArregloInt(int A[], int cantValidos);

void mostrarArregloChar(char A[], int cantVal);

const int MAXEMPLE =100;

int main()
{
    printf("Hello arrays!\n");
    int i=0,aux;

    /// declaracion
    int idEmpleados[MAXEMPLE];

    int cantEmple=0;
    /// lo que ve el compilador

    /// int * idEmpleado = malloc (sizeof(int)*100);


//   idEmpleados[0]=10;
//   idEmpleados[1]=20;
//   idEmpleados[2]=30;
//   idEmpleados[4]=40;

//    printf("Ingrese los ids de empleados\n");
//    for (i=0; i<6; i++)
//    {
//        printf("Ingrese un id: ");
//
//        scanf("%d", &idEmpleados[i]);
//    }



//    cantEmple=4;
//
//    printf("El contenido del arreglo es: \n");
//    for(i=0; i<cantEmple; i++)
//    {
//        printf("%d ", idEmpleados[i]);
//    }
/// invocamos la fn para cargar, enviamos el array de empleados y su dimension
/// la variable cantEmple va a contener la cantidad de datos que cargo el usr
//   cantEmple=cargarArregloInt(idEmpleados,MAXEMPLE);

/// ahora mostramos el contenido del arreglo desde la fn, le enviamos el arreglo y
/// la cantidad que se cargo con la fn de carga
//    mostrarArregloInt(idEmpleados, cantEmple);

//    float unArregloDeFloat[10]={12.3, 11.6,7.8};
//
//    mostrarArregloInt(unArregloDeFloat, 3);

//   char unArregloDeChar[]={'a','b','c','d', 'e'};

//   mostrarArregloChar(unArregloDeChar, 5);

    char palabra[20];
    printf("direccion de memoria del arreglo %p\n", palabra);

    system("pause");
    printf("Ingrese su palabra: ");

    fflush(stdin);
    //  scanf("%s", palabra);


    gets(palabra);
    printf("La palabra escaneada es %s", palabra);

    system("pause");

    printf("La palabra escaneada tiene %d", strlen(palabra));

    return 0;
}

int cargarArregloInt(int A[], int dim)
{
    int i=0;
    char control='s';

    while(i<dim && control =='s')
    {
        printf("Ingrese un valor entero:\n");
        scanf("%d", &A[i]);

        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &control);
        i++;
    }

    return i;
}

void mostrarArregloInt(int A[], int cantValidos)
{
    int i;

    printf("El contenido del arreglo es: \n");

    for(i=0; i<cantValidos; i++)
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

