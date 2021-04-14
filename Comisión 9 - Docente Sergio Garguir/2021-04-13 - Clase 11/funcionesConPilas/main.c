#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

void cargaPilaRandom(Pila *A, int x);
void cargaPilaRandomPorCopia(Pila A);
void cargaPilaUsuario(Pila *P, char titulo[]);

int main()
{
    Pila dada, dada1, dada2;
    inicpila(&dada);
    inicpila(&dada1);
    inicpila(&dada2);

    cargaPilaRandomPorCopia(dada);

    printf("\n Muestro dada despues de usar cargaPilaRandomPorCopia()");
    mostrar(&dada);

    cargaPilaRandom(&dada, 10);

    cargaPilaUsuario(&dada, "Ingrese una temperatura: ");

    cargaPilaRandom(&dada1, 20);

    cargaPilaUsuario(&dada1, "Ingrese una edad: ");

    cargaPilaRandom(&dada2, 30);

    cargaPilaUsuario(&dada2, "Ingrese una dni: ");

    printf("\n Pila Dada");
    mostrar(&dada);

    printf("\n Pila Dada1");
    mostrar(&dada1);

    printf("\n Pila Dada2");
    mostrar(&dada2);


    int cantidad = cuentaPila(dada2);
    int total = sumaPila(dada2);
    printf("\n Pila Dada2 tiene %d elementos - el total de sus elementos es %d", cantidad, total);
    mostrar(&dada2);

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
 * \brief Funcion de carga random de pila por copia
 *  Por eso no sirve
 * \param Pila
 * \param
 * \return
 *
***********************************************/
void cargaPilaRandomPorCopia(Pila A){
    for(int i=0;i<10;i++){
        apilar(&A, rand()%100);
    }
    printf("\n\t Pila A en funcion cargaPilaRandom()");
    mostrar(&A);
}

/**
 * \brief Carga Pila con intervencion del usuario
 *
 * \param Puntero a Pila
 * \param
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

 /**
 * \brief Cuenta los datos de una Pila
 *
 * \param Copia de Pila
 * \param
 * \return la cantidad
 *
 *********************************************/
int cuentaPila(Pila P){
    Pila aux;
    inicpila(&aux);

    int cont=0;

    while(!pilavacia(&P)){
        apilar(&aux, desapilar(&P));
        cont++;
    }

    return cont;
}

 /**
 * \brief Suma los datos de una Pila
 *
 * \param Copia de Pila
 * \param
 * \return el total
 *
 *********************************************/

int sumaPila(Pila P){
    Pila aux;
    inicpila(&aux);

    int total=0;

    while(!pilavacia(&P)){
        total = total + tope(&P);
        apilar(&aux, desapilar(&P));
    }

    return total;
}
