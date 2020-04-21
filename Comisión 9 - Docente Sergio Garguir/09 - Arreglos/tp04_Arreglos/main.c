#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void muestraMenu();
int funcion01(int a[], int v, int dim);
void funcion02(int a[], int v);
void funcion03(int a[]);
int cargaArreglo(int a[], int v, int dim);
void muestraArreglo(int a[], int v);

const char ESC = 27;

int main(){
    int primerArreglo[100];
    int paDim = 100;
    int paValidos = 0;

    char opcion;

    do{
        system("cls");
        muestraMenu();
        opcion=getch();
        system("cls");
        switch(opcion){
            case 49: /// 49 es el numero ASCII de la tecla 1
                    paValidos = funcion01(primerArreglo, paValidos, paDim);
                    break;
            case 50:
                    funcion02(primerArreglo,paValidos);
                    break;
            case 51:
                    funcion03(primerArreglo);
                    break;
            case 52 ... 55:
                    printf("Ej 3");
                    paValidos = 0;
                    /// aca va el codigo del ej 3
                    printf("\n\n\n");
                    break;
            case 'a':  /// 97
            case 'A':  /// 65
                    printf("Ej a");
                    /// aca va el codigo del ej 3
                    printf("\n\n\n");
                    break;

        }
        printf("\n\n\n");
        system("pause");
    }
    while(opcion!=ESC);

    printf("\n\n Hasta la vista Baby!!!!!\n");
    return 0;
}

void muestraMenu(){
    printf("\t\t\t<<< TP04 - Arreglos >>>");
    printf("\n\n");
    printf("\n\t 1 - Cargo el Arreglo");
    printf("\n\t 2 - Muestro el Arreglo");
    printf("\n\t 3 - Ejercicio 3");
    printf("\n\t 4 a 5 - Ejercicio 4 al 5");
    printf("\n\t a - Ejercicio a");
    printf("\n\n");
    printf("\t ESC para salir");
    printf("\n\n");
}

int funcion01(int a[], int v, int dim){
    printf("\nEj 1\n");
    v = cargaArreglo(a, v, dim);
    return v;
}

void funcion02(int a[], int v){
    printf("\nEj 2\n");
    muestraArreglo(a,v);
}

void funcion03(int a[]){
    printf("\nEj 3\n");
    printf("\n %d - %d", a[10],a[2]);
     /// aca va el codigo del ej 3
    printf("\n\n\n");
}

/**************************************************************************
*
* La funcion de carga del arreglo recibe el arreglo, la cantidad de datos
* cargados y la dimension, y retorna la cantidad de datos validos.
*
***************************************************************************/
int cargaArreglo(int a[], int v, int dim){
    char opcion = 0;

    printf("\n\n Cargando Arreglo ......");

    while(v<dim && opcion!=27){    /// for(i=0;i<dim && opcion!=27;i++)
        system("cls");
        printf("\n Ingrese un numero: ");
        scanf("%d",&a[v]);

        v++;
        printf("\n\n\t ESC para salir .....");
        opcion=getch();
    }
    return v;
}

/**************************************************************************
*
* La funcion que muestra un arreglo es de tipo void
* y recibe el arreglo y la cantidad de datos cargados.
*
***************************************************************************/
void muestraArreglo(int a[], int v){
    printf("\n Muestro arreglo \n");
    for(int i=0;i<v;i++){
        printf("%d - ", a[i]);
    }
}
