#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargaPilaUsuario(Pila *P, char titulo[]);
void cargaPilaRandom(Pila *A, int x);
int buscaMayorPila(Pila A);

int main()
{
    Pila origen, dada;
    inicpila(&origen);
    inicpila(&dada);

    int mayor;

    cargaPilaRandom(&origen,5);
    cargaPilaRandom(&dada,10);

    mostrar(&origen);
    mostrar(&dada);

    mayor = buscaMayorPila(origen);
    printf("\n el mayor elemento de origen es: %d", mayor);

    mayor = buscaMayorPila(dada);
    printf("\n el mayor elemento de dada es: %d", mayor);


    return 0;
}


/** \brief Carga Pila Random
 *
 * \param Puntero a pila
 * \param cantidad de datos a cargar
 * \return void
 *void cargaPilaRandomPorCopia(Pila A){
 */

void cargaPilaRandom(Pila *A, int x){
    for(int i=0;i<x;i++){
        apilar(A, rand()%100);
    }
}

/**
 * \brief Carga Pila con intervencion del usuario
 *
 * \param Puntero a Pila
 * \param Dato String - El titulo
 * \return nada
 *
 *********************************************/

void cargaPilaUsuario(Pila *P, char titulo[]){
    int nro;
    char opcion;

    do{
        printf("\n %s", titulo);
        scanf("%d", &nro);

        apilar(P, nro);

        printf("\n ESC para salir - cualquier tecla para continuar ");
        opcion = getch();
        system("cls");
    }
    while(opcion!=27);
}

int buscaMayorPila(Pila A){
    Pila aux;
    inicpila(&aux);
    int mayor = 0;
    if(!pilavacia(&A)){
        mayor = desapilar(&A);
        while(!pilavacia(&A)){
            if(tope(&A)>mayor){
                mayor = tope(&A);
            }
            apilar(&aux, desapilar(&A));
        }
    }
    return mayor;
}
