#include "listaDoble.h"

nodoDoble* inicListaD(){
    return NULL;
}

nodoDoble* crearNodoD(stPersona dato){
    nodoDoble* nuevo=(nodoDoble*)malloc(sizeof(nodoDoble));
    nuevo->dato=dato;
    nuevo->anterior=NULL;
    nuevo->siguiente=NULL;
    return nuevo;
}

nodoDoble* agregarAlPrincipioD(nodoDoble* listaDoble, nodoDoble* nuevo){
    nuevo->siguiente=listaDoble;
    if(listaDoble){
        listaDoble->anterior=nuevo;
    }
    return nuevo;
}

void muestraListaD(nodoDoble* listaDoble){
    while(listaDoble){
        muestraUnNodoD(listaDoble);
        listaDoble=listaDoble->siguiente;
    }
}

void muestraUnNodoD(nodoDoble* nodo){
    muestraUnaPersona(nodo->dato);
}

stPersona verPrimeroD(nodoDoble* listaDoble){
    stPersona p;
    if(listaDoble){
        p=listaDoble->dato;
    }
    return p;
}

nodoDoble* borrarPrimeroD(nodoDoble* listaDoble){
    if(listaDoble){
        nodoDoble* aBorrar=listaDoble;
        listaDoble=listaDoble->siguiente;
        if(listaDoble){
            listaDoble->anterior=NULL;
        }
        free(aBorrar);
    }

    return listaDoble;
}

nodoDoble* buscarUltimoD(nodoDoble* listaDoble){
    if(listaDoble){
        while(listaDoble->siguiente != NULL){
            listaDoble=listaDoble->siguiente;
        }
    }
    return listaDoble;
}

nodoDoble* agregarAlFinalD(nodoDoble* listaDoble, nodoDoble* nuevo){
    if(!listaDoble){
        listaDoble = nuevo;
    }else{
        nodoDoble* ultimo = buscarUltimoD(listaDoble);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }

    return listaDoble;
}

int cuentaMayoresDeEdadDoble(nodoDoble* lista, int edad){
    int cont=0;
    if(lista){
        if(lista->dato.edad > edad){
            cont=1+cuentaMayoresDeEdadDoble(lista->siguiente, edad);
        }else{
            cont=cuentaMayoresDeEdadDoble(lista->siguiente, edad);
        }
    }

    return cont;
}
