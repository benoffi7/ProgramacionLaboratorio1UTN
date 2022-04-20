#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define DIM_TEMPERATURAS 100
#define DIM_NOTAS 50

void muestraArreglo(int t[], int v);
int cargaArregloRandom(int t[], int cant);
int cargaArregloUsuario(int t[], int dim, int v);
void arreglo2pila(int t[], int v, Pila *p);

int main()
{
    Pila temp;
    inicpila(&temp);
    int temperaturas[DIM_TEMPERATURAS];
    int validosTemperaturas=0;
    int notas[DIM_NOTAS];

    validosTemperaturas=cargaArregloRandom(temperaturas, 30);
    validosTemperaturas=cargaArregloUsuario(temperaturas, DIM_TEMPERATURAS, validosTemperaturas);

    printf("\n Muestra arreglo! v=%d\n", validosTemperaturas);
    muestraArreglo(temperaturas, validosTemperaturas);

    validosTemperaturas=0;
    validosTemperaturas=cargaArregloUsuario(temperaturas, DIM_TEMPERATURAS, validosTemperaturas);

    printf("\n Muestra arreglo! v=%d\n", validosTemperaturas);
    muestraArreglo(temperaturas, validosTemperaturas);

    arreglo2pila(temperaturas, validosTemperaturas, &temp);
    printf("\n Muestra Pila! v=%d\n", validosTemperaturas);
    mostrar(&temp);

    return 0;
}

void muestraArreglo(int t[], int v){
    for(int i=0;i<v;i++){
        if(i%25==0){
            printf("\n");
        }
        printf("%d - ", t[i]);
    }
}

int cargaArregloRandom(int t[], int cant){
    int i;
    for(i=0;i<cant;i++){
        t[i]=rand()%50;
    }
    return i;
}

int cargaArregloUsuario(int t[], int dim, int v){
    char opcion=0;
    int i = v;
    while(i < dim && opcion !=27){
        printf("\n Ingrese una temperatura: ");
        scanf("%d", &t[i]);

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion = getch();
        system("cls");
        i++;
    }
    return i;
}

void arreglo2pila(int t[], int v, Pila *p){
    for(int i=0;i<v;i++){
        apilar(p, t[i]);
    }
}

int pila2arreglo(Pila a, int t[], int dim){
    int i=0;
    while(!pilavacia(&a) && i < dim){
        t[i]=desapilar(&a);
        i++;
    }
    return i;
}
