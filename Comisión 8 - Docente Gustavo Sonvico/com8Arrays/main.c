#include <stdio.h>
#include <stdlib.h>


int cargarArregloInt(int A[], int dim);

const int MAXEMPLE =10;

int main()
{
    printf("Hello arrays!\n");
    int i=0,aux;

    /// declaracion
    int idEmpleados[ ]={1,2,3,4};
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



    cantEmple=4;

    printf("El contenido del arreglo es: \n");
    for(i=0; i<cantEmple; i++)
    {
        printf("%d ", idEmpleados[i]);
    }



    return 0;
}

int cargarArregloInt(int A[], int dim)
{
    int i=0;
    char control='s';

    while(i<dim && control =='s')
    {

    }
}
