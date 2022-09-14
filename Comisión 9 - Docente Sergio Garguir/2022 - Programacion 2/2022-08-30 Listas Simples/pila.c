#include "pila.h"

void inicPila(Pila* pila){
    (*pila)=iniciLista();
}

int pilavacia(Pila* pila){
    int rta=0;
    if((*pila)==NULL){
        rta=1;
    }
    return rta;
}

int pilavacia2(Pila* pila){
    return ((*pila)==NULL);
}

int pilavaciaTernario(Pila* pila){
    return (*pila)?1:0;
}

stPersona tope(Pila* pila){
    return verPrimero(*pila);
}

stPersona desapilar(Pila* pila){
    stPersona p = verPrimero(*pila);
    (*pila)=borrarPrimero(*pila);
    return p;
}

void apilar(Pila* pila, stPersona dato){
    (*pila)=agregarAlPpio(*pila, crearNodo(dato));
}

void mostrar(Pila* pila){
    muestraLista(*pila);
}
