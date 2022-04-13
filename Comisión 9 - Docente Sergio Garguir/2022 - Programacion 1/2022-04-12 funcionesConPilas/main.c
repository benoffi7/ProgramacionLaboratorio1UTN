#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include "pila.h"

void cargaPilaRandomPorValor(Pila p, int limite);
void cargaPilaRandom(Pila *p, int limite);
void cargaPila(Pila *p, char titulo[]);
void muestraPila(Pila p, char titulo[]);
int cuentaPila(Pila p);


int main()
{
    srand(time(NULL));
    Pila numeros, edades;
    inicpila(&numeros);
    inicpila(&edades);
    int contador;

    cargaPilaRandom(&numeros, 10);
    cargaPila(&numeros, "Ingrese un numero: ");
    contador = cuentaPila(numeros);
    printf("\n La pila numeros tiene %d elementos", contador);
    cargaPilaRandom(&edades, 40);
    cargaPila(&edades, "Ingrese una edad: ");
    contador = cuentaPila(edades);
    printf("\n La pila edades tiene %d elementos", contador);
    muestraPila(numeros,"<<<<<<<<< Pila numeros >>>>>>>>>>>");
    muestraPila(numeros,"<<<<<<<<< Pila numeros >>>>>>>>>>>");
    muestraPila(edades,"<<<<<<<<< Pila edades >>>>>>>>>>>");

    return 0;
}

/// es una muestra de copia por valor
void cargaPilaRandomPorValor(Pila p, int limite){
    for(int i=0;i<limite;i++){
        apilar(&p, rand()%100);
    }
    printf("\n <<<<<<<<< Pila p >>>>>>>>>>> \n");
    mostrar(&p);
}

void cargaPilaRandom(Pila *p, int limite){
    for(int i=0;i<limite;i++){
        apilar(p, rand()%100);
    }
}

void cargaPila(Pila *p, char titulo[]){
    int nro;
    char opcion;

    do{
        printf("\n %s", titulo);
        scanf("%d", &nro);

        apilar(p, nro);

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion = getch();
        system("cls");

    }while(opcion != 27);
}


/** \brief Función que muestra una pila
 *
 * \param Una Pila p
 * \param string titulo
 * \return sin retorno
 *
 */

void muestraPila(Pila p, char titulo[]){
    Pila aux;
    inicpila(&aux);

    printf("\n\n\t\t %s \n\n", titulo);

    while(!pilavacia(&p)){
        printf("%d - ", tope(&p));
        apilar(&aux, desapilar(&p));
    }
}

int cuentaPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int cont=0;

    while(!pilavacia(&p)){
        apilar(&aux, desapilar(&p));
        cont++;
    }

    return cont;
}

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

















