#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void muestraMenu();
int funcion01(int a[], int v, int dim);
void funcion02(int a[],int v);
int funcion03(int v);
int funcion04(char a[], int v, int dim);
void funcion05(char a[],int v);
int cargaArregloInt(int a[], int v, int dim);
void mostrarArregloInt(int a[], int v);
int cargaArregloChar(char a[], int v, int dim);
void mostrarArregloChar(char a[], int v);

#define DDNI 100
#define DLETRAS 24
const char ESC = 27;

int main(){
    char opcion;

    int dni[DDNI];
    int vDni = 0;


    char letras[DLETRAS];
    int vLetras = 0;


    do{
        system("cls");
        muestraMenu();
        opcion=getch();
        system("cls");

        switch(opcion){
            case 49: /// 49 es el codigo ASCII de la tecla 1  - también pueden usar '1'
                    vDni = funcion01(dni, vDni, DDNI);
                    break;
            case 50:
                    funcion02(dni, vDni);
                    break;
            case 51:
                    vDni = funcion03(vDni);
                    ///vDni = 0;
                    break;
            case 52:
                    vLetras = funcion04(letras, vLetras, DLETRAS);
                    break;
            case 53:
                    funcion05(letras, vLetras);
                    break;
            case 'a': /// 97
                    break;
            case 'A':  /// 65
                    break;
        }
        system("pause");
    }
    while(opcion!=ESC);

    printf("Hasta la vista Baby!!!!!\n");
    return 0;
}

void muestraMenu(){
    printf("\t\t\t<<< Mi Primer Menu >>>");
    printf("\n\n");
    printf("\n\t 1 - Carga un arreglo de enteros");
    printf("\n\t 2 - Muestra un arreglo de enteros");
    printf("\n\t 3 - Vacia un arreglo");
    printf("\n\t 4 - Carga un arreglo de letras");
    printf("\n\t 5 - Muestra un arreglo de letras");
    printf("\n\n");
    printf("ESC para salir ");
}

int funcion01(int a[], int v, int dim){
    printf("\nCarga de Arreglo de numeros\n");
    v = cargaArregloInt(a, v, dim);
    printf("\n\n\n");

    return v;
}

void funcion02(int a[], int v){
    printf("\nMuestra el arreglo\n");
    mostrarArregloInt(a, v);
    printf("\n\n\n");
}

int funcion03(int v){
    printf("Vacia un arreglo");
    v = 0;
    printf("\n\n\n");
    return v;
}

int funcion04(char a[], int v, int dim){
    printf("\nCarga de Arreglo de letras\n");
    v = cargaArregloChar(a, v, dim);
    printf("\n\n\n");

    return v;
}

void funcion05(char a[], int v){
    printf("\nMuestra el arreglo de letras\n");
    mostrarArregloChar(a, v);
    printf("\n\n\n");
}

int cargaArregloInt(int a[], int v, int dim){
    char opcion;

    while(v<dim && opcion!=ESC){
        system("cls");
        printf("\n Ingrese un numero: ");
        scanf("%d", &a[v]);

        printf("\n\n\t ESC para salir ...");
        opcion=getch();
        v++;
    }
    return v;
}

void mostrarArregloInt(int a[], int v){
    for(int i=0;i<v;i++){
        printf("%d - ", a[i]);
    }
}


int cargaArregloChar(char a[], int v, int dim){
    char opcion;

    while(v<dim && opcion!=ESC){
        system("cls");
        printf("\n Ingrese una letra: ");
        fflush(stdin);
        scanf("%c", &a[v]);

        printf("\n\n\t ESC para salir ...");
        opcion=getch();
        v++;
    }
    return v;
}

void mostrarArregloChar(char a[], int v){
    for(int i=0;i<v;i++){
        printf("%c - ", a[i]);
    }
}


int dimArray(int a[]){
    int dim = sizeof(a)/sizeof(a[0]);
    return dim;
}
