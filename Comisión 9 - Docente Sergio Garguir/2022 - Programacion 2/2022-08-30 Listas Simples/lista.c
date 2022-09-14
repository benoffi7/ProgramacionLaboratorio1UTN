#include <stdio.h>
#include <stdlib.h>
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

nodo * agregarAlPpio(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista=nuevo;
    }else{
        nuevo->siguiente=lista;
        lista = nuevo;
    }
    return lista;
}

nodo * agregarAlPrincipioPro(nodo* lista, nodo* nuevo){
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
    printf("\n Nodo: %p", n);
    muestraUnaPersona(n->dato);
    printf("\n Nodo->sig: %p", n->siguiente);
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
    /// Si la lista esta vacia le asigno el nuevo nodo
    if(!lista){
        lista = nuevo;
    }else{
        /// si el nuevo nodo es menor al primero de la lista, agrego a principio
        if(nuevo->dato.edad <= lista->dato.edad){
            lista = agregarAlPpio(lista, nuevo);
        }else{
            /// buscamos el lugar donde insertar
            nodo* ante = lista;
            nodo* seg = lista;
            while(seg && (nuevo->dato.edad > seg->dato.edad)){
                ante = seg;
                seg = seg->siguiente;
            }
            /// insertar el nuevo nodo en la lista de manera ordenada
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}

nodo* intercalarListas(nodo* listaA, nodo* listaB, nodo* listaFinal){
    nodo* aux = NULL;
    while(listaA && listaB){ /// while(listaA != NULL && listaB != NULL)
        if(listaA->dato.edad < listaB->dato.edad){
            aux = listaA;
            listaA = listaA->siguiente;
        }else{
            aux = listaB;
            listaB = listaB->siguiente;
        }
        aux->siguiente = NULL;
        listaFinal = agregarAlFinal(listaFinal, aux);
    }
    if(listaA){
        listaFinal = agregarAlFinal(listaFinal, listaA);
    }else if(listaB){
        listaFinal = agregarAlFinal(listaFinal, listaB);
    }

    return listaFinal;
}

int cuentaNodosPorEdad(nodo* lista, int edad){
    int cont=0;
    nodo* seg = lista;
    while(seg){
        if(seg->dato.edad>edad){
            cont++;
        }
        seg=seg->siguiente;
    }
    return cont;
}

int cuentaNodosPorEdadRec(nodo* lista, int edad){
    int cont=0;
    if(lista){
        if(lista->dato.edad > edad){
            cont = 1 + cuentaNodosPorEdadRec(lista->siguiente, edad);
        }else{
            cont = cuentaNodosPorEdadRec(lista->siguiente, edad);
        }
    }

    return cont;
}

int cuentaNodosRec(nodo* lista){
    int cont=0;
    if(lista){
        cont = 1 + cuentaNodosRec(lista->siguiente);
    }
    return cont;
}

int cuentaNodosRecTernario(nodo* lista){
    return (lista)?1+cuentaNodosRecTernario(lista->siguiente):0;
}

int sumaNodosPorEdad(nodo* lista, int edad){
    int suma = 0;
    nodo* seg = lista;
    while(seg){
        if(seg->dato.edad>edad){
            suma += seg->dato.edad;
        }
        seg=seg->siguiente;
    }
    return suma;
}

int sumaNodosPorEdadRec(nodo* lista, int edad){
    int suma=0;
    if(lista){
        if(lista->dato.edad>edad){
            suma = lista->dato.edad + sumaNodosPorEdadRec(lista->siguiente, edad);
        }else{
            suma = sumaNodosPorEdadRec(lista->siguiente, edad);
        }
    }

    return suma;
}

int sumaNodosPorEdadRecTern(nodo* lista, int edad){
    return (lista)?(lista->dato.edad>edad)?lista->dato.edad+sumaNodosPorEdadRecTern(lista->siguiente, edad):sumaNodosPorEdadRecTern(lista->siguiente, edad):0;
}

void muestraListaRec(nodo* lista){
    if(lista){
        muestraNodo(lista);
        muestraListaRec(lista->siguiente);
    }
}

stPersona verPrimero(nodo* lista){
    stPersona p;
    if(lista){
        p = lista->dato;
    }
    return p;
}

stPersona verPrimero1(nodo* lista){
    stPersona p;
    return (lista)?lista->dato:p;
}

nodo* borrarPrimero(nodo* lista){
    if(lista){
        nodo* aux=lista;
        lista=lista->siguiente;
        free(aux);
    }
    return lista;
}

nodo* buscaNodoPorNombre(nodo* lista, char nombre[]){
    nodo* seg = lista;
    while(seg && strcmp(nombre, seg->dato.nombre)!=0){
        seg=seg->siguiente;
    }
    return seg;
}

nodo* borrarNodoPorNombre(nodo* lista, char nombre[]){
    nodo* seg;
    nodo* ante;
    if(lista && strcmp(nombre, lista->dato.nombre)==0){
        nodo* aux=lista;
        lista=lista->siguiente;
        free(aux);
    }else{
        seg = lista;
        while(seg && strcmp(nombre, seg->dato.nombre)!=0){
            ante = seg;
            seg = seg->siguiente;
        }
        if(seg){
            ante->siguiente=seg->siguiente;
            free(seg);
        }
    }
    return lista;
}
