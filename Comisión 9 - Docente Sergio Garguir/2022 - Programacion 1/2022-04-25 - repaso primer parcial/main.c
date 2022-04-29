#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

void cargaPilaRandom(Pila *p, int limite);
int buscaMenorPila(Pila *p);
int pila2arregloOrdenado(Pila *c, int a[], int dim);
void muestraArreglo(int a[], int v);
void insertaOrdenado(Pila *p, int valor);

int main()
{
    Pila notas;
    inicpila(&notas);
    int menor;

    int n[100];
    int validosN = 0;

    cargaPilaRandom(&notas,20);

    printf("\nPila Notas\n");
    mostrar(&notas);

    validosN = pila2arregloOrdenado(&notas, n, 100);

    printf("\nArreglo\n");
    muestraArreglo(n, validosN);

    printf("\nPila Notas\n");
    mostrar(&notas);

    return 0;
}

void cargaPilaRandom(Pila *p, int limite){
    for(int i=0;i<limite;i++){
        apilar(p, rand()%10+1);
    }
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

int pila2arregloOrdenado(Pila *c, int a[], int dim){
    Pila algo;
    inicpila(&algo);
    int i = 0;
    while(!pilavacia(c) && i < dim){
        a[i] = buscaMenorPila(c);
        i++;
    }
    return i;
}

void muestraArreglo(int a[], int v){
    for(int i=0; i<v;i++){
        printf("%d | ", a[i]);
    }
}

void intercambio(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

/// para verificar
void intercambioSinVarAux(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void ordenaPorInsercion(Pila *p){
    Pila ordenada;
    inicpila(&ordenada);

    while(!pilavacia(p)){
        insertaOrdenado(&ordenada, desapilar(p));
    }

    while(!pilavacia(&ordenada)){
        apilar(p, desapilar(&ordenada));
    }
}
