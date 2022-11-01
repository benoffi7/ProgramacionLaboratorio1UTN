#include "arbol.h"

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(stPersona dato){
    nodoArbol* nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

nodoArbol* agregarNodoArbol(nodoArbol* arbol, stPersona dato){
    if(!arbol){
        arbol = crearNodoArbol(dato);
    }else{
        if(dato.id > arbol->dato.id){
            arbol->der = agregarNodoArbol(arbol->der, dato);
        }else{
            arbol->izq = agregarNodoArbol(arbol->izq, dato);
        }
    }

    return arbol;
}

nodoArbol* agregarNodoArbolSinRepetidos(nodoArbol* arbol, stPersona dato){
    if(!arbol){
        arbol = crearNodoArbol(dato);
    }else{
        if(dato.id > arbol->dato.id){
            arbol->der = agregarNodoArbol(arbol->der, dato);
        }else{
            if(dato.id < arbol->dato.id){
                arbol->izq = agregarNodoArbol(arbol->izq, dato);
            }
        }
    }

    return arbol;
}

void preOrden(nodoArbol* arbol){
    if(arbol){
        muestraUnaPersona(arbol->dato);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(nodoArbol* arbol){
    if(arbol){
        inOrden(arbol->izq);
        muestraUnaPersona(arbol->dato);
        inOrden(arbol->der);
    }
}

void postOrden(nodoArbol* arbol){
    if(arbol){
        postOrden(arbol->izq);
        postOrden(arbol->der);
        muestraUnaPersona(arbol->dato);
    }
}

nodoArbol* buscaNodoArbol(nodoArbol* arbol, int id){
    nodoArbol* buscado = NULL;
    if(arbol){
        if(arbol->dato.id == id){
            buscado = arbol;
        }else{
            if(id > arbol->dato.id){
                buscado = buscaNodoArbol(arbol->der, id);
            }else{
                buscado = buscaNodoArbol(arbol->izq, id);
            }
        }
    }
    return buscado;
}

nodoArbol* buscaNodoArbolPorNombre(nodoArbol* arbol, char nombre[]){
    nodoArbol* buscado = NULL;
    if(arbol){
        if(strcmp(arbol->dato.nombre,nombre)==0){
            buscado = arbol;
        }
        else{
            buscado = buscaNodoArbolPorNombre(arbol->izq, nombre);
            if(!buscado){
                buscado = buscaNodoArbolPorNombre(arbol->der, nombre);
            }
        }
    }

    return buscado;
}

int cuentaNodosArbol(nodoArbol* arbol){
    int cont=0;
    if(arbol){
        cont=1+cuentaNodosArbol(arbol->izq)+cuentaNodosArbol(arbol->der);
    }

    return cont;
}

int cuentaNodosArbolTernario(nodoArbol* arbol){
    return (arbol)?1+cuentaNodosArbolTernario(arbol->izq)+cuentaNodosArbolTernario(arbol->der):0;
}

int esHoja(nodoArbol* arbol){
    int rta = 0;
    if(arbol){
        if(!arbol->izq && !arbol->der){
            rta = 1;
        }
    }
    return rta;
}

int cuentaHojas(nodoArbol* arbol){
    int cont=0;
    if(arbol){
        if(esHoja(arbol)){
            cont=1;
        }else{
            cont=cuentaHojas(arbol->izq)+cuentaHojas(arbol->der);
        }
    }

    return cont;
}

nodoArbol* arrayToArbol (stCliente a[], int base, int tope){
    int medio;

    nodoArbol* arbol=NULL;

    if(!(base>tope))
    {

        medio=(base+tope)/2;

        arbol=CrearArbol(a[medio]);

        arbol->izq=arrayToArbol(a,base,medio-1);
        arbol->der=arrayToArbol(a,medio+1,tope);
    }

    return arbol;
}

void arbol2archi(nodoArbol* arbol, FILE* archi){
    if(arbol){
        arbol2archi(arbol->izq, archi);
        fwrite(&arbol->dato, sizeof(stPersona), 1, archi);
        arbol2archi(arbol->der, archi);
    }
}

nodoDoble* arbol2listaDoble(nodoArbol* arbol, nodoDoble* lista){
    if(arbol){
        lista = arbol2listaDoble(arbol->izq, lista);
        lista = agregarAlFinalD(lista, crearNodoD(arbol->dato));
        lista = arbol2listaDoble(arbol->der, lista);
    }
    return lista;
}

int mayor(int izq, int der){
    int rta;
    if(izq > der){
        rta = izq;
    }else{
        rta = der;
    }
    return rta;
}

int mayorTernario(int izq, int der){
    return (izq>der)?izq:der;
}

int cuentaNiveles(nodoArbol* arbol){
    int cont = 0;
    if(arbol){
        if(esHoja(arbol)){
            cont=1;
        }else{
            cont = 1 + mayor(cuentaNiveles(arbol->izq), cuentaNiveles(arbol->der))
        }
    }

    return cont;
}
