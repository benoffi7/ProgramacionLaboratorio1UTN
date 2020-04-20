#include <conio.h>
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
void cargaPilaRandom(Pila *p, int limite, int min, int max){
    for(int i=0;i<limite;i++){
        apilar(p, randomRango(min, max));
    }
}

int randomRango(int min, int max){
    return rand()%(max-min)+min;
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

/**
*
* Funcion que vacía una pila
*
*/
void vaciarPila(Pila *p){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(p)){
        apilar(&aux, desapilar(p));
    }
}

/**
*
* Funcion que divide 2 enteros. Es responsabilidad del programador validar que la función no reciba un 0
*
*/
float dividir(int a, int b){
    float div = 0;

    if(b!=0){
        div = (float) a / b;
    }

    return div;
}

/**
*
* Funcion que suma los elementos de una pila
*
*/
int sumaPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int total=0;

    while(!pilavacia(&p)){
        total = total + tope(&p);
        apilar(&aux, desapilar(&p));
    }

    return total;
}

/**
*
* Funcion que suma los elementos de una pila
*
*/
int cuentaPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int cont=0;

    while(!pilavacia(&p)){
        apilar(&aux, desapilar(&p));
        cont = cont + 1;
    }

    return cont;
}

/**
*
* Funcion que calcula el promedio de una pila
*
*/
float promedioPila(Pila p){
    float promedio = 0;

    if(!pilavacia(&p)){
        promedio = dividir(sumaPila(p), cuentaPila(p));
    }

    return promedio;
}

/**
*
* Funcion que suma y retorna el tope de la pila con el dato siguiente
*
*/
int sumaTopeyAnterior(Pila p){
    int suma = 0;

    if(!pilavacia(&p)){
        suma = desapilar(&p);
        if(!pilavacia(&p))
            suma = suma + tope(&p);
    }
    return suma;
}

/**
*
* Funcion que suma y retorna el tope de la pila con el dato siguiente
* es responsabilidad del programador verificar que la pila tengo como minimo la cantidad
* de datos que dice el parametro limite
*
*/
int sumaTopeHastaLimite(Pila p, int limite){
    int suma = 0;
    int i = 0;

    while(!pilavacia(&p) && i<limite){
        suma = suma + desapilar(&p);
        i++;
    }
    /** NO ME GUSTA
    for(i=0;i<limite && !pilavacia(&p);i++){
        suma = suma + desapilar(&p);
    }
    */

    return suma;
}

/**
*
* Convierte una pila a un entero
*
*/
int pila2decimal(Pila p){
    Pila aux;
    inicpila(&aux);
    int decimal = 0;
    int multiplicador = 1;

    pasaPila(&p, &aux);

    while(!pilavacia(&aux)){
        decimal = decimal + tope(&aux) * multiplicador;
        apilar(&p, desapilar(&aux));
        multiplicador = multiplicador * 10;
    }

    return decimal;
}








