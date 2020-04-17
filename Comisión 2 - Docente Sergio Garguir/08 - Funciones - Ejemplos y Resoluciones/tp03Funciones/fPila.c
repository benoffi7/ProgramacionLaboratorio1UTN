#include "pila.h"
#include "fPila.h"

/**
*********************************************************//**
*
* Ciclo de carga de una pila por el usuario
*
***********************************************************
*/
void cargaPila(Pila *p, char texto[]){
    char opcion;
    int e;

    do{
        printf("\n %s: ",texto);
        scanf("%d",&e);
        apilar(p,e);

        printf("\n\n ESC para salir ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);
}

/**
***********************************************************
*
* Carga una pila con datos aleatorios
*
***********************************************************
*/
void cargaPilaRandom(Pila *p, int limite){
    for(int i=0;i<limite;i++){
        apilar(p, rand()%100);
    }
}

/**
***********************************************************
*
* Pasa una pila a otra
*
***********************************************************
*/
void pasaPila(Pila *origen, Pila *destino){
    while(!pilavacia(origen)){
        apilar(destino, desapilar(origen));
    }
}

/**
***********************************************************
*
* Pasa una pila en el mismo orden a otra
*
***********************************************************
*/
void pasaPilaOrden(Pila *origen, Pila *destino){
    Pila aux;
    inicpila(&aux);

    pasaPila(origen, &aux);
    pasaPila(&aux, destino);
}

/**
***********************************************************
*
* Copia un apila en otra
*
***********************************************************
*/
void copiaPila(Pila origen, Pila *destino){
    Pila aux;
    inicpila(&aux);
    pasaPila(&origen, &aux);                /// paso la pila usando la funcion

    /*while(!pilavacia(&origen)){           /// paso la pila usando un while
        apilar(&aux, desapilar(&origen));
    }*/

    pasaPila(&aux, destino);
    /*while(!pilavacia(&aux)){
        apilar(destino, desapilar(&aux));
    }*/
}

/**
***********************************************************
*
* Busca y retorna sin elimar el menor elemento de una pila
*
***********************************************************
*/
int buscaMenor(Pila origen){
    Pila aux;
    inicpila(&aux);
    int menor;

    if(!pilavacia(&origen)){
        menor=desapilar(&origen);
        while(!pilavacia(&origen)){
            if(tope(&origen)<menor){
                menor=desapilar(&origen);
            }
            else{
                apilar(&aux, desapilar(&origen));
            }
        }
    }

    return menor;
}

/**
***********************************************************
*
* Busca y retorna eliminando el menor elemento de una pila
*
***********************************************************
*/
int buscaMenorE(Pila *origen){
    Pila aux;
    inicpila(&aux);
    int menor;

    if(!pilavacia(origen)){
        menor=desapilar(origen);
        while(!pilavacia(origen)){
            if(tope(origen)<menor){
                apilar(&aux, menor);
                menor=desapilar(origen);
            }
            else{
                apilar(&aux, desapilar(origen));
            }
        }
        pasaPila(&aux, origen);
    }

    return menor;
}

/**
**********************************************
*
* Ordena una pila por Seleccion
*
**********************************************
*/
void ordenaPorSeleccion(Pila *p){
    Pila aux;
    inicpila(&aux);
    int menor;
    /**
    while(!pilavacia(p)){
        apilar(&aux, buscaMenorE(p));
    }
    */
    while(!pilavacia(p)){
        menor = buscaMenorE(p);
        apilar(&aux, menor);
    }
    pasaPila(&aux, p);
}

/**
**********************************************
*
* Inserta un elemento en una pila ordenada
*
**********************************************
*/
void insertaElemento(Pila *p, int e){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p) && tope(p)>e){
        apilar(&aux, desapilar(p));
    }
    apilar(p, e);
    pasaPila(&aux, p);
}

/**
***********************************************************************
*
* Ordena una pila por Insercion, usando la funcion de insertar elemtno
*
***********************************************************************
*/

void ordenaPorInsercion(Pila *p){
    Pila aux;
    inicpila(&aux);
    int e;
    /**
    while(!pilavacia(p)){
        insertaElemento(&aux, desapilar(p));
    }
    */
    while(!pilavacia(p)){
        e = desapilar(p);
        insertaElemento(&aux, e);
    }
    pasaPila(&aux, p);
}












