#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void muestraMenu();
int funcion01(int a[], int v, int dim);
void funcion02(int a[], int v);
int funcion03(char a[], int v, int dim);
void funcion04(char a[], int v);
void funcion05(int a[], int v);
int cargaArreglo(int a[], int v, int dim);
void muestraArreglo(int a[], int v);
int buscaInt(int a[], int v, int dato);
int cargaArregloChar(char a[], int v, int dim);
void muestraArregloChar(char a[], int v);
int buscaInt(int a[], int v, int dato);

#define D_PRIMER_ARREGLO 100
#define D_LETRAS 24
const char ESC = 27;

int main(){
    int primerArreglo[D_PRIMER_ARREGLO];
    int paValidos = 0;

    char letras[D_LETRAS];
    int leValidos = 0;

    char opcion;

    do{
        system("cls");
        muestraMenu();
        opcion=getch();
        system("cls");
        switch(opcion){
            case 49: /// 49 es el numero ASCII de la tecla 1
                    paValidos = funcion01(primerArreglo, paValidos, D_PRIMER_ARREGLO);
                    break;
            case 50:
                    funcion02(primerArreglo,paValidos);
                    break;
            case 51:
                    leValidos = funcion03(letras, leValidos, D_LETRAS);
                    break;
            case 52:
                    funcion04(letras, leValidos);
                    break;
            case 53:
                    funcion05(primerArreglo, paValidos);

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
    printf("\n\t 1 - Cargo el Arreglo de enteros");
    printf("\n\t 2 - Muestro el Arreglo de enteros");
    printf("\n\t 3 - Cargo el Arreglo de caracteres");
    printf("\n\t 4 - Muestro el Arreglo de caracteres");
    printf("\n\t 5 - Buscar un dato entero");
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

int funcion03(char a[], int v, int dim){
    printf("\nCarga un arreglo de caracteres\n");
    v = cargaArregloChar(a, v, dim);
    printf("\n\n\n");
    return v;
}

void funcion04(char a[], int v){
    printf("\nMuestro el arreglo de caracteres\n");
    muestraArregloChar(a,v);
}

void funcion05(int a[], int v){
    int dato;
    int encontrado;
    printf("\n Busca datos enteros\n\n");
    printf("\n Ingrese el dato a buscar: ");
    scanf("%d",&dato);
    encontrado = buscaInt(a, v, dato);
    if(encontrado){ /// es igual a poner (encontrado == 1)
        printf("El dato %d se encuentra en el arreglo",dato);
    }else{
        printf("El dato %d NO se encuentra en el arreglo",dato);
    }
/**
    if(buscaInt(a, v, dato)){ /// es igual a poner (encontrado == 1)
        printf("El dato %d se encuentra en el arreglo %d", dato");
    }else{
        printf("El dato %d NO se encuentra en el arreglo",dato);
    }
*/
    printf("\n\n\n");
}

/**************************************************************************
*
* La funcion de carga del arreglo recibe el arreglo, la cantidad de datos
* cargados y la dimension, y retorna la cantidad de datos validos. INT
*
***************************************************************************/
int cargaArreglo(int a[], int v, int dim){
    char opcion = 0;

    while(v<dim && opcion!=27){    /// for(i=0;i<dim && opcion!=27;i++)
        system("cls");
        printf("\n\n Cargando Arreglo de INT......");
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
* La funcion que muestra un arreglo es de tipo int
* y recibe el arreglo y la cantidad de datos cargados.
*
***************************************************************************/
void muestraArreglo(int a[], int v){
    printf("\n Muestro arreglo \n");
    for(int i=0;i<v;i++){
        printf("%d - ", a[i]);
    }
}

/**************************************************************************
*
* La funcion busca un dato en un arreglo de enteros
* Recibo el arreglo, sus validos y el dato a buscar
* Retorno 0 ó 1
*
***************************************************************************/
int buscaInt(int a[], int v, int dato){
    int flag=0; ///0 es false - falso / 1 es true - verdadero
    int i=0;

    while(i<v && flag==0){
        if(a[i] == dato){
            flag = 1;
        }
        i++;
    }

    return flag;
}


/**************************************************************************
*
* La funcion de carga del arreglo recibe el arreglo, la cantidad de datos
* cargados y la dimension, y retorna la cantidad de datos validos. CHAR
*
***************************************************************************/
int cargaArregloChar(char a[], int v, int dim){
    char opcion = 0;

    while(v<dim && opcion!=27){    /// for(i=0;i<dim && opcion!=27;i++)
        system("cls");
        printf("\n\n Cargando Arreglo de CHAR ......");
        printf("\n Ingrese un caracter: ");
        fflush(stdin);
        scanf("%c",&a[v]);

        v++;
        printf("\n\n\t ESC para salir .....");
        opcion=getch();
    }
    return v;
}

/**************************************************************************
*
* La funcion que muestra un arreglo es de tipo char
* y recibe el arreglo y la cantidad de datos cargados.
*
***************************************************************************/
void muestraArregloChar(char a[], int v){
    for(int i=0;i<v;i++){
        printf("%c", a[i]);
    }
}
