#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "gotoxy.h"

#define ESC 27
#define FIL 10
#define COL 15
#define F 100
#define C 30

void muestraMenu();
void cargaMatrizRandomInt(int fil, int col, int m[fil][col]);
void cargaMatrizUserInt(int fil, int col, int m[fil][col]);
void cargaMatrizRandomIntWhile(int fil, int col, int m[fil][col]);
void muestraMatrizInt(int fil, int col, int m[fil][col]);
void colores();
int cargaArregloStrings(int fil, int col, char as[][col], int v);
void muestraArregloStrings(int col, char as[][col], int v);
int cargaArregloParalelo(int fil, int col, char names[][col], int legajos[], int notas[], int v);
void muestraArregloParalelo(int col, char names[][col], int legajos[], int notas[], int v);

int main(){
    char opcion;
    int matrix[FIL][COL];
    char names[F][C];
    int legajos[F];
    int notas[F];
    int v=0;

    char arregloChar[150][30];

    do{
        system("cls");
        muestraMenu();
        opcion=getch();
        system("cls");

        switch(opcion){
            case 49:
                    cargaMatrizRandomInt(FIL, COL, matrix);
                    break;
            case 50:
                    cargaMatrizUserInt(FIL, COL, matrix);
                    break;
            case 51:
                    muestraMatrizInt(FIL, COL, matrix);
                    break;
            case 52:
                    v=cargaArregloStrings(F, C, names, v);
                    break;
            case 53:
                    muestraArregloStrings(C, names, v);
                    break;
            case 54:
                    v=cargaArregloParalelo(F, C, names, legajos, notas, v);
                    break;
            case 55:
                    muestraArregloParalelo(C, names, legajos, notas, v);
                    break;
        }
        system("pause");
    }
    while(opcion!=ESC);

    printf("Hasta la vista Baby!!!!!\n");

    return 0;
}

void muestraMenu(){
    //int x=10;
    //int y=2;
    //color(48);
    //gotoxy(x,y);
    printf("\t\t\t<<< Mi Menu >>>");
    //y=y+4;
    printf("\n\n");
    //gotoxy(x,y);
    //color(30);
    printf("\n\t 1 - Carga una matriz random de tipo Int");
    printf("\n\t 2 - Carga una matriz el usuario");
    printf("\n\t 3 - Muestra una matriz de tipo int");
    printf("\n\t 4 - Carga arreglo de string");
    printf("\n\t 5 - Muestra arreglo de string");
    printf("\n\t 6 - Carga arreglos paralelos");
    printf("\n\t 7 - Muestra arreglos paralelos");
    printf("\n\n\n");
    printf("ESC para salir ");
}

/*********************************************************//**
*
* \brief Funcion de carga aleatoria de una matriz de tipo INT
* \param filas
* \param columnas
* \param la matriz
* \return void
*
*************************************************************/
void cargaMatrizRandomInt(int fil, int col, int m[fil][col]){
    for(int i=0;i<fil; i++){
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
* \param la matriz
* \return void
*
******************************************************************/
void cargaMatrizUserInt(int fil, int col, int m[fil][col]){
    for(int i=0;i<fil; i++){
        for(int j=0;j<col;j++){
            scanf("%d",&m[i][j]);
        }
    }
}

/*********************************************************//**
*
* \brief Funcion de carga aleatoria de una matriz de tipo INT
* \brief usando ciclos while anidados
* \param filas
* \param columnas
* \param la matriz
* \return void
*
*************************************************************/
void cargaMatrizRandomIntWhile(int fil, int col, int m[fil][col]){
    int i=0;
    int j=0;

    while(i<fil){
        while(j<col){
            m[i][j]=rand()%100;
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
* \param la matriz
* \return void
*
******************************************************************/
void muestraMatrizInt(int fil, int col, int m[fil][col]){
    for(int i=0;i<fil; i++){
        for(int j=0;j<col;j++){
            printf("%d - ",m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**************************************************************//**
*
* \brief Funcion que muestra los colores 16 de fondo x 16 de frente
* \param sin parametros
* \return void
*
******************************************************************/
void colores(){
    for(int i=0;i<256;i++){
        color(i);
        printf("\n Color Nro: %d", i);
    }
}

/**************************************************************//**
*
* \brief Funcion de carga por el usuario de un Arreglo de Strings
* \param filas
* \param columnas
* \param el arreglo
* \param validos
* \return retorna validos
*
******************************************************************/
int cargaArregloStrings(int fil, int col, char as[][col], int v){
    char opcion;
    while(v<fil && opcion != ESC){
        printf("\n Ingrese un nombre: ");
        fflush(stdin);
        //scanf("%s", as[v]);
        gets(as[v]);
        v++;

        printf("\n\n ESC para salir");
        opcion=getch();
    }
    return v;
}

/**************************************************************//**
*
* \brief Funcion que muestra un arreglo de Strings
* \param columnas
* \param el arreglo
* \param sus validos
* \return void
*
******************************************************************/
void muestraArregloStrings(int col, char as[][col], int v){
    for(int i=0;i<v; i++){
        printf("\n%s",as[i]);
    }
    printf("\n");
}

/**************************************************************//**
*
* \brief Funcion de carga por el usuario de Arreglos Paralelos
* \param filas
* \param columnas
* \param el arreglo nombres
* \param el arreglo legajos
* \param el arreglo notas
* \param validos
* \return retorna validos
*
******************************************************************/
int cargaArregloParalelo(int fil, int col, char names[][col], int legajos[], int notas[], int v){
    char opcion;
    while(v<fil && opcion != ESC){
        printf("\n Ingrese un nombre: ");
        fflush(stdin);
        //scanf("%s", names[v]);
        gets(names[v]);

        printf("Ingrese el legajo: ");
        scanf("%d", &legajos[v]);

        printf("Ingrese la nota: ");
        scanf("%d", &notas[v]);

        v++;

        printf("\n\n ESC para salir");
        opcion=getch();
    }
    return v;
}

/**************************************************************//**
*
* \brief Funcion que muestra arreglos paralelos
* \param columnas
* \param el arreglo de nombres
* \param el arreglo de legajos
* \param el arreglo de notas
* \param sus validos
* \return void
*
******************************************************************/
void muestraArregloParalelo(int col, char names[][col], int legajos[], int notas[], int v){
    printf("\n-----------------------------------------");
    for(int i=0;i<v; i++){
        printf("\n Nombre: %s",names[i]);
        printf("\n Legajo: %d",legajos[i]);
        printf("\n Nota..: %d",notas[i]);
        printf("\n-----------------------------------------");
    }
    printf("\n");
}

/**************************************************************//**
*
* \brief Muestra los codigos ASCII y sus caracteres
* \return void
*
******************************************************************/
void muestraTablaASCII(){
    for(int i=0;i<256;i++){
        printf("| %d - %c ", i, i);
    }
}
