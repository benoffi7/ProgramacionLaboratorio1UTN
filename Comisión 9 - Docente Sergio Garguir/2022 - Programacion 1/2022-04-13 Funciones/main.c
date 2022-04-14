#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

void cargaPilaRandom(Pila *p, int limite);
void muestraPila(Pila p, char titulo[]);
int cuentaPila(Pila p);
int sumaPila(Pila p);

int main()
{
    srand(time(NULL));

    Pila edades;
    inicpila(&edades);

    cargaPilaRandom(&edades, 5);
    muestraPila(edades, "<<<<<<<<<<<<< Pila edades >>>>>>>>>>");

  //  float promedio = (float) sumaPila(edades) / cuentaPila(edades);

    printf("\n \n");
    return 0;
}

/** \brief Carga una pila con numeros aleatorios
 *
 * \param *p - Puntero a Pila
 * \param limite - un entero
 * \return No tiene retorno
 *
 */

void cargaPilaRandom(Pila *p, int limite){
    for(int i=0;i<limite;i++){
        apilar(p, rand()%100);
    }
}

/** \brief Muestra una pila con su titulo
 *
 * \param p - Una copia de pila
 * \param titulo - Un string como titulo
 * \return No tiene retorno
 *
 */
void muestraPila(Pila p, char titulo[]){
    Pila aux;
    inicpila(&aux);

    printf("\n %s \n", titulo);
    while(!pilavacia(&p)){
        printf("%d | ", tope(&p));
        apilar(&aux, desapilar(&p));
    }
}

float promedioPila(Pila p){
    return (float) sumaPila(p) / cuentaPila(p);
}

float promedioPilaConVariables(Pila p){
    int cont = cuentaPila(p);
    int suma = sumaPila(p);
    float promedio = (float) suma / cont;
    return promedio;
}
