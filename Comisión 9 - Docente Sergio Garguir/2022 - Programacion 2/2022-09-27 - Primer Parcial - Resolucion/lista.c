#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

nodo * iniciLista(){
    return NULL;
}

nodo * crearNodo(stPersona dato){
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo * agregarAlPrincipio(nodo* lista, nodo* nuevo){
    nuevo->siguiente = lista;
    return nuevo;
}

void muestraLista(nodo* lista){
    nodo* seg = lista;
    while(seg!=NULL){
        muestraNodo(seg);
        seg=seg->siguiente;
    }
}

void muestraNodo(nodo* n){
    printf("\n Nodo: %p - Nodo siguiente: %p", n, n->siguiente);
    muestraUnaPersona(n->dato);
}

nodo* buscarUltimo(nodo* lista){
    nodo* seg = lista;
    while(seg->siguiente != NULL){
        seg = seg->siguiente;
    }
    return seg;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        nodo* ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}

nodo* agregarEnOrdenPorEdad(nodo* lista, nodo* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        if(nuevo->dato.edad <= lista->dato.edad){
            lista = agregarAlPrincipio(lista, nuevo);
        }else{
            nodo* ante = lista;
            nodo* seg = lista->siguiente;
            while(seg && (nuevo->dato.edad > seg->dato.edad)){
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}

void agregarEnOrdenPorApellido(nodo** lista, nodo* nuevo){
    if(!(*lista)){
        (*lista) = nuevo;
    }else{
        if(strcmp(nuevo->dato.apellido, (*lista)->dato.apellido)==0){
            (*lista) = agregarAlPrincipio((*lista), nuevo);
        }else{
            nodo* ante = (*lista);
            nodo* seg = (*lista)->siguiente;
            while(seg && (strcmp(nuevo->dato.apellido, seg->dato.apellido)!=0)){
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
}

int sumaEdades(nodo* lista){
    int suma=0;
    while(lista){
        suma+=lista->dato.edad;
        lista=lista->siguiente;
    }
    return suma;
}

int sumaEdadesRecursiva(nodo* lista){
    int suma=0;
    if(lista){
        if(atoi(lista->dato.dni)%2==0 && lista->dato.edad >=18){
            suma=lista->dato.edad + sumaEdadesRecursiva(lista->siguiente);
        }else{
            suma=sumaEdadesRecursiva(lista->siguiente);
        }
    }
    return suma;
}

int sumaEdadesRecursivaTernario(nodo* lista){
    return (lista)?(atoi(lista->dato.dni)%2==0 && lista->dato.edad>=18)?lista->dato.edad+sumaEdadesRecursivaTernario(lista->siguiente):sumaEdadesRecursivaTernario(lista->siguiente):0;
}

nodo* buscaMenorEdad(nodo* lista){
    nodo* menor=lista;
    if(lista && lista->siguiente){
        menor = buscaMenorEdad(lista->siguiente);
        if(lista->dato.edad<menor->dato.edad){
            menor=lista;
        }
    }
    return menor;
}

int cuentaNodosRecursivo(nodo* lista, int edad){
    int cont=0;
    if(lista){
        if(lista->dato.edad > edad){
            cont=1+cuentaNodosRecursivo(lista->siguiente, edad);
        }else{
            cont=cuentaNodosRecursivo(lista->siguiente, edad);
        }
    }
    return cont;
}
