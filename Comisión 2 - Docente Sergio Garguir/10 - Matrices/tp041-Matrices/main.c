#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ESC 27
#define FIL 10
#define COL 10
#define CANT_CHAR 30
#define DIM_NAMES 100

void muestraMenu();
void cargoMatrizRandInt(int fil, int col, int m[fil][col]);
void cargoUserMatrizInt(int fil, int col, int m[fil][col]);
void muestroMatrizInt(int fil, int col, int m[fil][col]);
void muestraArregloChar(char a[], int v);
int cargaArregloNombres(int cantChar, char nombres[][cantChar], int v, int dim);
void muestraArregloNombres(int cantChar, char names[][cantChar], int v);


int main(){
    char opcion;
    int matriz[FIL][COL];
    char names[DIM_NAMES][CANT_CHAR];
    int vNames=0;


    do{
        system("cls");
        muestraMenu();
        opcion=getch();
        system("cls");

        switch(opcion){
            case 49:
                    cargoMatrizRandInt(FIL, COL, matriz);
                    break;
            case 50:
                    cargoUserMatrizInt(FIL, COL, matriz);
                    break;
            case 51:
                    muestroMatrizInt(FIL, COL, matriz);
                    break;
            case 52:
                    vNames=cargaArregloNombres(CANT_CHAR, names, vNames, DIM_NAMES);
                    break;
            case 53:
                    muestraArregloNombres(CANT_CHAR, names, vNames);
                    break;
        }
        system("pause");
    }
    while(opcion!=ESC);

    printf("Hasta la vista Baby!!!!!\n");

    return 0;
}

void muestraMenu(){
    printf("\t\t\t<<< TP 4.1 Matrices >>>");
    printf("\n\n");
    printf("\n\t 1 - Carga una matriz de forma aleatoria");
    printf("\n\t 2 - Carga una matriz por el usuario");
    printf("\n\t 3 - Muestra una matriz");
    printf("\n\t 4 - Carga un arreglo de Strings");
    printf("\n\t 5 - Muestra un arreglo de Strings");
    printf("\n\n\n");
    printf("ESC para salir ");
}

/*********************************************************//**
*
* \brief Funcion de carga aleatoria de una matriz de tipo INT
* \param filas
* \param columnas
* \param la matriz[fil][col]
* \return void
*
*************************************************************/
void cargoMatrizRandInt(int fil, int col, int m[fil][col]){
    for(int i=0; i<fil;i++){
        for(int j=0;j<col;j++){
            m[i][j]=rand()%100;
        }
    }
}

/**************************************************************//**
*
* \brief Funcion de carga por el usuario de una matriz de tipo INT
* \param filas
* \param columnas
* \param la matriz[fil][col]
* \return void
*
******************************************************************/
void cargoUserMatrizInt(int fil, int col, int m[fil][col]){
    int i=0;
    int j=0;
    printf("\nIngrese un nro: ");
    while(i<fil){
        while(j<col){
            scanf("%d",&m[i][j]);
            j++;
        }
        j=0;
        i++;
    }
}

/**************************************************************//**
*
* \brief Funcion que muestra una matriz de tipo INT
* \param filas
* \param columnas
* \param la matriz[fil][col]
* \return void
*
******************************************************************/
void muestroMatrizInt(int fil, int col, int m[fil][col]){
    for(int i=0; i<fil;i++){
        for(int j=0;j<col;j++){
            printf("%d - ", m[i][j]);
        }
        printf("\n");
    }
}

/**************************************************************//**
*
* \brief Funcion que muestra un arreglo de tipo CHAR
* \param arreglo
* \param validos
* \return void
*
******************************************************************/
void muestraArregloChar(char a[], int v){
    for(int i=0;i<v;i++){
        printf("%c", a[i]);
    }
    printf("\n");
}

/**************************************************************//**
*
* \brief Funcion que carga un arreglo de Strings
* \param cantidad de caracteres por nombre
* \param arreglo
* \param validos
* \param dimension
* \return validos
*
******************************************************************/
int cargaArregloNombres(int cantChar, char nombres[][cantChar], int v, int dim){
    char opcion;
    while(v<dim && opcion!=ESC){
        printf("\nIngrese un nombre: ");
        gets(nombres[v]);
        v++;

        printf("\n ESC para salir..... ");
        opcion=getch();
        system("cls");
    }
    printf("\n");
    return v;
}

/**************************************************************//**
*
* \brief Funcion muestra un arreglo de Strings
* \param cantidad de caracteres por nombre
* \param arreglo
* \param validos
* \return void
*
******************************************************************/
void muestraArregloNombres(int cantChar, char names[][cantChar], int v){
    for(int i=0;i<v;i++){
        printf("\n %s", names[i]);
    }
    printf("\n");
}
