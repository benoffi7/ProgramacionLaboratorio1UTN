#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

void cargaPilaUsuario(Pila *P, char titulo[]);
void cargaPilaRandom(Pila *A, int x);
int buscaMayorPila(Pila A);
char menu();
void copiaPila(Pila origen, Pila *destino);
void pasaPila(Pila *o, Pila *d);
void pasaPilaEnOrden(Pila *origen, Pila *destino);

int main()
{
    Pila origen, dada;
    inicpila(&origen);
    inicpila(&dada);
    int mayor;

    char opcion;

    do{
        opcion = menu();

        switch(opcion){
            case '1':
                cargaPilaRandom(&origen, 25);
                printf("\n Pila cargada correctamente ");
                break;
            case '2':
                cargaPilaUsuario(&origen, "Igrese una nota: ");
                break;
            case '3':
                muestraPila(origen);
                break;
            case '4':
                mayor = buscaMayorPila(origen);
                printf("\n El mayor elemento es: %d", mayor);
                break;
            case '5':
                copiaPila(origen,&dada);
                printf("\n Pila origen \n");
                muestraPila(origen);
                printf("\n Pila dada \n");
                muestraPila(dada);
                break;
            case '6':
                pasaPilaEnOrden(&origen, &dada);
                printf("\n Pila origen \n");
                muestraPila(origen);
                printf("\n Pila dada \n");
                muestraPila(dada);
        }
        printf("\n");
        system("pause");
    }
    while(opcion!=27);


    return 0;
}

char menu(){
    char opcion;

    system("cls");
    system("color 1F");
    printf("\n\t\t\t Menu de funciones de Pila\n\n");
    printf("\n 1 - Carga una pila de manera aleatoria");
    printf("\n 2 - Carga una pila con intervencion del usuario");
    printf("\n 3 - Muestra una pila");
    printf("\n 4 - Busca el mayor elemento en una pila");
    printf("\n 5 - Copia una pila en otra");
    printf("\n 6 - Pasa Pila en orden");
    printf("\n\t ESC para salir");

    printf("\n\n\t Elija una opcion: ");
    opcion=getch();

    return opcion;
}



/** \brief Carga Pila Random
 *
 * \param Puntero a pila
 * \param cantidad de datos a cargar
 * \return void
 * void cargaPilaRandomPorCopia(Pila A){
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

/**
 * \brief Busca el mayor elemento en una pila
 *
 * \param Pila
 * \return int - El mayor elemento
 *
 *********************************************/
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

/** \brief Muestra el contenido de una pila
 *
 * \param Pila
 * \return nada
 *
 */
void muestraPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int i=0;
    printf("\n");
    while(!pilavacia(&p)){
        i++;
        if(i%15==0){
            printf("\n");
        }
        printf("%d - ", tope(&p));
        apilar(&aux, desapilar(&p));
    }
}

/** \brief Copia una pila en otra
 *
 * \param Pila origen
 * \param Pila* destino
 * \return nada
 *
 */
void copiaPila(Pila origen, Pila *destino){
    pasaPila(&origen, destino);
}

void pasaPila(Pila *o, Pila *d){
    while(!pilavacia(o)){
        apilar(d, desapilar(o));
    }
}

void pasaPilaEnOrden(Pila *origen, Pila *destino){
    Pila aux;
    inicpila(&aux);

    pasaPila(origen, &aux);
    pasaPila(&aux, destino);
}

