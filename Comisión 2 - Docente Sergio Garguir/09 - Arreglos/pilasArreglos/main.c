#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "miLib.h"

void array2pila(int a[], int v, Pila *p);
int pila2array(Pila p, int a[], int v, int dim);
void array2pilaConFiltro(int a[], int v, Pila *p, int filtro);


#define DIM_ARREGLO 50

int main()
{
    Pila dada, auxDada;
    inicpila(&dada);
    inicpila(&auxDada);

    int arreglo[DIM_ARREGLO];
    int valArreglo = 0;

    int arr[DIM_ARREGLO];
    int valArr = 0;

    valArreglo = cargaArregloInt(arreglo, valArreglo, DIM_ARREGLO);
    valArreglo = cargaArregloOrdenadoInt(arreglo, valArreglo, DIM_ARREGLO);

    muestraArregloInt(arreglo, valArreglo);
    system("pause");

    array2pila(arreglo, valArreglo, &dada);
    ///array2pilaConFiltro(arreglo, valArreglo, &dada, 50);
    printf("\n Pila dada.....\n");
    mostrar(&dada);

    valArr = pila2array(dada, arr, valArr, DIM_ARREGLO);
    //valArr = pila2arrayConFiltro(dada, arr, valArr, DIM_ARREGLO, 30);

    printf("\n Pila dada.....\n");
    mostrar(&dada);

    system("pause");
    printf("\n Arreglo arr .....\n");
    muestraArregloInt(arr, valArr);



    printf("Hello world!\n");
    return 0;
}

/****************************************************//**
*
* \brief Copia un arreglo de tipo Int en una Pila
* \param arreglo int
* \param sus validos
* \param puntero a pila
* \return void
*
******************************************************/
void array2pila(int a[], int v, Pila *p){
    for(int i=0; i<v; i++){
        apilar(p, a[i]);
    }
}

/****************************************************//**
*
* \brief Copia una pila en un arreglo de tipo Int
* \param una pila
* \param arreglo int
* \param sus validos
* \param la dimension del arreglo
* \return la cantidad de validos
*
******************************************************/
int pila2array(Pila p, int a[], int v, int dim){
    while(!pilavacia(&p) && v<dim){
        a[v]=desapilar(&p);
        v++;
    }

    return v;
}


/****************************************************//**
*
* \brief Copia un arreglo de tipo Int con filtro en una Pila
* \param arreglo int
* \param sus validos
* \param puntero a pila
* \param el filtro
* \return void
*
******************************************************/
void array2pilaConFiltro(int a[], int v, Pila *p, int filtro){
    int i=0;
    while(i<v){
        if(a[i]>filtro){
            apilar(p, a[i]);
        }
        i++;
    }
}

/****************************************************//**
*
* \brief Copia una pila con filtro en un arreglo de tipo Int
* \param una pila
* \param arreglo int
* \param sus validos
* \param la dimension del arreglo
* \return la cantidad de validos
*
******************************************************/
int pila2arrayConFiltro(Pila p, int a[], int v, int dim, int filtro){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&p) && v<dim){
        if(tope(&p)>filtro){
            a[v]=desapilar(&p);
            v++;
        }else{
            apilar(&aux, desapilar(&p));
        }
    }

    return v;
}
