#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "arbolPersona.h"
#include "lista.h"

nodoArbol* arreglo2arbol(int a[], int v, nodoArbol* arbol);
nodoArbol* arreglo2arbolSinRepetidos(int a[], int v, nodoArbol* arbol);
nodoLista* arbol2lista(nodoArbol* arbol, nodoLista* lista, int limite);

int main()
{
    int a[]={5,6,4,7,3,8,8,9,0,2};
    int v = 10;
    nodoArbol* arbol = inicArbol();
    nodoArbolPersona* arbolPersona = inicArbol();
    nodoLista* lista = inicLista();
    stPersona p;
    p.edad = 25;
    strcpy(p.nombre, "Juana");
    p.legajo = 105;

    arbol = arreglo2arbol(a, v, arbol);
    arbolPersona = agregarArbolPersona(arbolPersona, crearNodoArbolPersona(p));

    printf("\nArbol PreOrden\n");
    preOrden(arbol);

    printf("\nArbol EnOrden\n");
    enOrden(arbol);

    printf("\nArbol PostOrden\n");
    postOrden(arbol);

    lista = arbol2lista(arbol, lista,5);
    printf("\nLista enlazada\n");
    muestraLista(lista);

    return 0;
}

nodoArbol* arreglo2arbol(int a[], int v, nodoArbol* arbol){
    for(int i=0;i<v;i++){
        arbol = agregarArbol(arbol, crearNodoArbol(a[i]));
    }
    return arbol;
}

nodoArbol* arreglo2arbolSinRepetidos(int a[], int v, nodoArbol* arbol){
    for(int i=0;i<v;i++){
        arbol = agregarArbolSinRepetidos(arbol, crearNodoArbol(a[i]));
    }
    return arbol;
}

nodoLista* arbol2lista(nodoArbol* arbol, nodoLista* lista, int limite){
    if(arbol){
        lista = arbol2lista(arbol->izq, lista, limite);
        if(arbol->dato > limite){
            lista = agregarAlPrincipio(lista, crearNodoLista(arbol->dato));
        }
        lista = arbol2lista(arbol->der, lista, limite);
    }
    return lista;
}
