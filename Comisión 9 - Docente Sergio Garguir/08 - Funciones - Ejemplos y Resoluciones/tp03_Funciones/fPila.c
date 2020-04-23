#include <conio.h>
#include "pila.h"
#include "fPila.h"

/**
*@ Author Sergio Garguir <br>
*@ Funcion para carga de pila <br>
*1. Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el usuario.
*/

void cargaPila(Pila *p, char texto[]){
    char opcion;
    int e;

    do{
        printf("\n %s", texto);
        scanf("%d",&e);
        apilar(p,e);

        printf("\n\n ESC para salir .......");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);
}

int randomRango(int min, int max){
    return rand()%(max-min)+min;
}

void cargaPilaRandom(Pila *p, int cantidad, int minimo, int maximo){
    int i;
    for(i=0;i<cantidad;i++){
        apilar(p, randomRango(minimo, maximo));
    }
}

/// 2. Hacer una función que pase todos los elementos de una pila a otra.
void pasaPila(Pila *origen, Pila *destino){
    while(!pilavacia(origen)){
        apilar(destino, desapilar(origen));
    }
}

void pasaPilaEnOrden(Pila *origen, Pila *destino){
    Pila aux;
    inicpila(&aux);

    pasaPila(origen, &aux);
    pasaPila(&aux, destino);
}

/// Copiar los elementos de una pila en otra
void copiaPila(Pila origen, Pila *destino){
    Pila aux;
    inicpila(&aux);

    pasaPila(&origen, &aux);
    /**while(!pilavacia(&origen)){
        apilar(&aux, desapilar(&origen));
    }*/
    pasaPila(&aux, destino);
    /**while(!pilavacia(&aux)){
        apilar(destino, desapilar(&aux));
    }*/
}

/// Buscar el menor elemento en una pila sin quitarlo y retornarlo
/// Corre por cuenta del programador verificar que la pila tenga datos antes de usar esta funcion
int buscaMenor(Pila p){
    Pila aux;
    inicpila(&aux);
    int menor;

    if(!pilavacia(&p)){
        menor = desapilar(&p);
        while(!pilavacia(&p)){
            if(tope(&p)<menor){
                menor = desapilar(&p);
            }
            else{
                apilar(&aux, desapilar(&p));
            }
        }
    }
    return menor;
}

/// Buscar el menor elemento en una pila eliminandolo y retornandolo
/// Corre por cuenta del programador verificar que la pila tenga datos antes de usar esta funcion
int buscaMenorEliminandolo(Pila *p){
    Pila aux;
    inicpila(&aux);
    int menor;

    if(!pilavacia(p)){
        menor = desapilar(p);
        while(!pilavacia(p)){
            if(tope(p)<menor){
                apilar(&aux, menor);
                menor = desapilar(p);
            }
            else{
                apilar(&aux, desapilar(p));
            }
        }
        pasaPila(&aux, p);
    }
    return menor;
}

/// Ordena una pila por seleccion
/*
void ordenaPorSeleccion(Pila origen, Pila *ordenada){
    while(!pilavacia(&origen)){
        apilar(ordenada, buscaMenorEliminandolo(&origen));
    }
}
*/
void ordenaPorSeleccion(Pila origen, Pila *ordenada){
    int menor;
    while(!pilavacia(&origen)){
        menor = buscaMenorEliminandolo(&origen);
        apilar(ordenada, menor);
    }
}

/// Inserta un elemento un una pila ordeana
void insertaElemento(Pila *p, int e){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p) && tope(p)>e){
        apilar(&aux, desapilar(p));
    }
    apilar(p, e);
    pasaPila(&aux, p);
}

/// Ordena por Insercion
void ordenaPorInsercion(Pila origen, Pila *ordenada){
    int e;
    while(!pilavacia(&origen)){
        e = desapilar(&origen);
        insertaElemento(ordenada, e);
        /// insertaElemento(ordenada, desapilar(&origen));
    }
}

/**
*
* Ordena por Insercion
*
*/
void ordenaPorInsercion2(Pila *origen){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(origen)){
        insertaElemento(&aux, desapilar(origen));
        /// insertaElemento(ordenada, desapilar(&origen));
    }
    pasaPila(&aux, origen);
}

/**
*
* Suma los 2 primeros datos de la pila y lo retorna
*
*/

int sumaTopeYSiguiente(Pila p){
    int total=0;
    if(!pilavacia(&p)){
        total = desapilar(&p);
        if(!pilavacia(&p)){
            total = total + tope(&p);
        }
    }

    return total;
}

int sumaPilaLimite(Pila p, int limite)
{
    Pila aux;
    inicpila(&aux);
    int total =0;
    int i =0;

    while(!pilavacia(&p)&& i<limite)
    {
        total=total+tope(&p);
        apilar(&aux,desapilar(&p));
        i++;
    }

    return total;
}

/**
*
*  Funcion que suma los elementos de una pila
*  y retorna el resultado
*
*/
int sumaPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int total = 0;

    while(!pilavacia(&p)){
        total = total + tope(&p);
        apilar(&aux, desapilar(&p));
    }

    return total;
}

/**
*
*  Funcion que cuenta los elementos de una pila
*  y retorna el resultado
*
*/
int cuentaPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int cont = 0;

    while(!pilavacia(&p)){
        apilar(&aux, desapilar(&p));
        cont++;
    }

    return cont;
}

float divide(int n1, int n2){
    float div = 0;

    if(n2 > 0){
        div = (float) n1/n2;
    }

    return div;
}

float promedioPila(Pila p){
    float promedio = 0;
    if(!pilavacia(&p)){
        promedio = divide(sumaPila(p), cuentaPila(p));
    }
    return promedio;
}

float promedioPila2(Pila p){
    float promedio = 0;
    int suma;
    int cont;

    if(!pilavacia(&p)){
        suma = sumaPila(p);
        cont = cuentaPila(p);
        promedio = divide(suma, cont);
    }
    return promedio;
}

int pila2decimal(Pila p){
    Pila aux;
    inicpila(&aux);
    int nro = 0;
    int multiplicador = 1;

    pasaPila(&p, &aux);

    while(!pilavacia(&aux)){
        nro = nro + desapilar(&aux)*multiplicador;
        multiplicador = multiplicador * 10;
    }
    return nro;
}
