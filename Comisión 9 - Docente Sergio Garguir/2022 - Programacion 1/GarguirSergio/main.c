#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define DIM_N 100

void cargaPilaRandom(Pila *p, int cant);
int cargaArregloRandom(int a[], int dim, int cant);
void muestraArreglo(int a[], int v);
int pila2arreglo(Pila *p, int a[], int dim);
int buscaMenorPila(Pila *p);
int cargaArregloUsuario(int a[], int v, int dim, int limite);
void arreglo2pila(int a[], int v, Pila *p);

int main()
{
    Pila notas;
    Pila desaprobados;
    inicpila(&notas);
    inicpila(&desaprobados);
    int n[DIM_N];
    int validosN=0;

    cargaPilaRandom(&notas, 40);

    printf("\n Pila notas \n");
    mostrar(&notas);

    validosN=pila2arreglo(&notas,n, DIM_N);

    printf("\n Arreglo notas - validos notas = %d\n", validosN);
    muestraArreglo(n, validosN);

    validosN = cargaArregloUsuario(n,validosN, DIM_N, 10);
    printf("\n Arreglo notas - validos notas = %d\n", validosN);
    muestraArreglo(n, validosN);

    arreglo2pila(n, validosN, &desaprobados);

    printf("\n Pila desaprobados \n");
    mostrar(&desaprobados);

    return 0;
}

void cargaPilaRandom(Pila *p, int cant){
    for(int i=0;i<cant;i++){
        apilar(p, rand()%101);
    }
}

int cargaArregloRandom(int a[], int dim, int cant){
    int i=0;
    if(cant<dim){
        for(i=0;i<cant;i++){
            a[i]=rand()%50;
        }
    }
    return i;
}

void muestraArreglo(int a[], int v){
    for(int i=0;i<v;i++){
        printf("%d | ", a[i]);
    }
}

int pila2arreglo(Pila *p, int a[], int dim){
    int i=0;
    while(!pilavacia(p) && i<dim){
        a[i]=buscaMenorPila(p);
        i++;
    }
    return i;
}

int buscaMenorPila(Pila *p){
    Pila aux;
    inicpila(&aux);
    int menor;
    if(!pilavacia(p)){
        menor = desapilar(p);
        while(!pilavacia(p)){
            if(tope(p)<menor){
                apilar(&aux, menor);
                menor = desapilar(p);
            }else{
                apilar(&aux, desapilar(p));
            }
        }
        while(!pilavacia(&aux)){
            apilar(p, desapilar(&aux));
        }
    }
    return menor;
}

int cargaArregloUsuario(int a[], int v, int dim, int limite){
    char opcion=0;

    while(v<dim && opcion != 27){
        do{
            system("cls");
            printf("\n Ingrese una nota: ");
            scanf("%d", &a[v]);
            if(a[v]>limite){
                printf("\n Dato invalido. Debe ingresar un nro entre 0 y %d", limite);
                getch();
            }
        }while(a[v]>limite);

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion=getch();
        v++;
    }

    return v;
}

void arreglo2pila(int a[], int v, Pila *p){
    for(int i=0;i<v;i++){
        if(a[i] < 50){
            apilar(p, a[i]);
        }
    }
}
