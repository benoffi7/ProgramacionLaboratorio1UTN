#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int cargaArregloRandom(int n[], int dim);
void muestraArreglo(int n[], int v);
int buscaPosMenorParaOrdenar(int n[], int c, int v);
void ordenaPorSel(int n[], int v);
void intercambio(int *a, int *b);
int insertaEnArreglo(int a[], int v, int dim, int dato);
void insertaParaOrdenar(int a[], int v, int dato);
void ordenaPorIns(int a[], int v);


#define DIM_NOTAS 100

int main()
{
    int notas[DIM_NOTAS];
    int vNotas=0;

    vNotas = cargaArregloRandom(notas, 20);
    printf("\n Arreglo recien cargado\n");
    muestraArreglo(notas, vNotas);

    ordenaPorIns(notas, vNotas);

    printf("\n Arreglo ordenado\n");
    muestraArreglo(notas, vNotas);

    printf("\nHello world!\n");
    return 0;
}

int cargaArregloRandom(int n[], int dim){
    int i;
    for(i=0;i<dim;i++){
        n[i]=rand()%110;
    }

    return i;
}

void muestraArreglo(int n[], int v){
    for(int i=0;i<v;i++){
        printf("[%d]", n[i]);
    }
}

int buscaPosMenorParaOrdenar(int n[], int c, int v){
    int i=c;
    int posMenor=i;
    i++;

    while(i<v){
        if(n[i]<n[posMenor]){
            posMenor = i;
        }
        i++;
    }

    return posMenor;
}

void ordenaPorSel(int n[], int v){
    int posMenor;
    int i=0;
    while(i<v-1){
        posMenor = buscaPosMenorParaOrdenar(n, i, v);
        intercambio(&n[i], &n[posMenor]);
        i++;
    }
}

void intercambio(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int insertaEnArreglo(int a[], int v, int dim, int dato){
    int i=v-1;
    if(v<dim){
        while(v>=0 && a[i]>dato){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=dato;
        v+1;
    }
    return v;
}

void insertaParaOrdenar(int a[], int v, int dato){
    int i = v;
    while(i>=0 && a[i]>dato){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=dato;
}

void ordenaPorIns(int a[], int v){
    int i = 0;
    while(i<v-1){
        insertaParaOrdenar(a, i, a[i+1]);
        i++;
    }
}

int buscaPalabra(char p[][20], int v, char dato[]){
    int i=0;
    int flag=0;

    while(i<v && flag==0){
        if(strcmp(p[i],dato[i])==0){
            flag=1;
        }
        i++;
    }

    return flag;
}
