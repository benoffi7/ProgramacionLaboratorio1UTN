#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila dada;
    Pila otra;
    Pila otraMas;
    inicpila(&dada);
    inicpila(&otra);
    inicpila(&otraMas);

    cargaPilaRandom(&dada);

    printf("\nMuestra temperaturas...... \n");
    muestraPila(dada);
    muestraPila(otra);
    muestraPila(otraMas);

    printf("Hello world!\n");
    return 0;
}

void cargaPilaRandom(Pila *p){
    for(int i=0;i<30;i++){
        apilar(p, rand()%100);
    }
}

void muestraPila(Pila a){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&a)){
        printf("[%d]", tope(&a));
        apilar(&aux, desapilar(&a));
    }
}

int cuentaPilaConLimite(Pila a, int limite){
    Pila aux;
    inicpila(&aux);
    int cont=0;

    while(!pilavacia(&a)){
        if(tope(&a)>limite){
            cont++;
        }
        apilar(&aux, desapilar(&a));
    }
    return cont;
}

int cuentaPila(Pila a){
    Pila aux;
    inicpila(&aux);
    int cont=0;

    while(!pilavacia(&a)){
        cont++;
        apilar(&aux, desapilar(&a));
    }
    return cont;
}

/**
total      100
mayores     x

mayores * 100 / total
*/
/**
8.	Hacer una función que me retorne que porcentaje del total de
temperaturas de una pila representan las temperaturas mayores a
un valor dado (recibido por parámetro).
*/
float porcentajeMayores(Pila a, int limite){
    Pila aux;
    inicpila(&aux);
    int total = cuentaPila(a);
    int mayores = cuentaPilaConLimite(a, limite);
    float porcentaje;

    if(total > 0){
        porcentaje = (float)mayores * 100 / total;
    }

    return porcentaje;
}

