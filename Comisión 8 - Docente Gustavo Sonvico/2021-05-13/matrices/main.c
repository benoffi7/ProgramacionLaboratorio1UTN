#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void cargaMatrizRandom(int fil, int col, int m[fil][col]);
void muestraMatriz(int fil, int col, int m[fil][col]);
int sumaDiagonalPrincipal(int fil, int col, int m[fil][col]);
int sumaDiagonalSecundaria(int fil, int col, int m[fil][col]);
int cargaNombres(char n[][30], int dim);
void muestraNombres(char n[][30], int v);


#define FILAS 5
#define COLUMNAS 5
#define DIM_NOMBRES 100


int main()
{
    srand(time(NULL));
    int matriz[FILAS][COLUMNAS];

    char nombres[DIM_NOMBRES][30];
    int vNombres=0;

    vNombres = cargaArregloNombresRandom(nombres, 5);
    //vNombres = cargaNombres(nombres, 100);
    printf("\nListado de Nombres\n");
    muestraNombres(nombres, vNombres);

    buscaNombre(nombres, vNombres, "Pepe");
    printf("\nListado de Nombres\n");
    muestraNombres(nombres, vNombres);

    cargaMatrizRandom(FILAS, COLUMNAS, matriz);

    printf("\nMuestro la matriz\n");
    muestraMatriz(FILAS,COLUMNAS,matriz);




    return 0;
}

void cargaMatrizRandom(int fil, int col, int m[fil][col]){
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            m[i][j]=rand()%1000;
        }
    }
}

void muestraMatriz(int fil, int col, int m[fil][col]){
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            printf("[%5d]",m[i][j]);
        }
        printf("\n");
    }
}

int sumaDiagonalPrincipal(int fil, int col, int m[fil][col]){
    int suma=0;
    for(int i=0;i<fil;i++){
        suma+=m[i][i];
    }
    return suma;
}

int sumaDiagonalSecundaria(int fil, int col, int m[fil][col]){
    int suma=0;

    for(int i=0;i<fil;i++){
        for(int j=col-1; j>=0; j--){
            suma+=m[i][j];
        }
    }

    return suma;
}

int cargaNombres(char n[][30], int dim){
    char opcion=0;
    int i=0;

    while(opcion!=27 && i<dim){
        printf("\n Ingrese un nombre: ");
        fflush(stdin);
        //scanf("%s", n[i]);
        gets(n[i]);
        i++;

        printf("\n ESC para salir - cualquier tecla para continuar");
        opcion=getch();
        system("cls");
    }

    return i;
}

void muestraNombres(char n[][30], int v){
    for(int i=0;i<v;i++){
        printf("\n %s", n[i]);
    }
}

int buscaNombre(char n[][30], int v, char dato[]){
    int i=0;
    int flag=0;

    while(i<v && flag==0){
        if(strcmp(n[i],dato)==0){
            strcpy(n[i],"Son Iguales");
            flag=1;
        }
        i++;
    }
    return flag;
}

void cargaNombresRandom(char nombre[]){
    char n[][30]={"Sergio","Juan","Luis","Alfonso","Manuel","Roberto","Alfredo","Santiago","Ernesto"};
    strcpy(nombre,n[rand()%sizeof(n)/30]);
}

int cargaArregloNombresRandom(char n[][30], int dim){
    int i;
    for(i=0; i<dim;i++){
        cargaNombresRandom(n[i]);
    }
    return i;
}
