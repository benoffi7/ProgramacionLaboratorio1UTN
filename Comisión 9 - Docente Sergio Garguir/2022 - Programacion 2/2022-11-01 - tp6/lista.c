#include "lista.h"

nodoDoble* inicListaD(){
    return NULL;
}

nodoDoble* crearNodoD(stNotaAlumno dato){
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
    muestraUnaNota(nodo->dato);
}

stNotaAlumno verPrimeroD(nodoDoble* listaDoble){
    stNotaAlumno n;
    if(listaDoble){
        n=listaDoble->dato;
    }
    return n;
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
/*
int cuentaNotasMayoresDoble(nodoDoble* lista, int nota){int cuentaNotasMayoresDoble(nodoDoble* lista, int nota){
    int cont=0;
    if(lista){
        if(lista->dato.nota > nota){
            cont=1+cuentaNotasMayoresDoble(lista->siguiente, nota);
        }else{
            cont=cuentaNotasMayoresDoble(lista->siguiente, nota);
        }
    }

    return cont;
}
*/
