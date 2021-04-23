#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pila.h"

int randomRango(int min, int max);
void cargaPilaRandom(Pila *p, int limite, int min, int max);
void cargaPilaUsuario(Pila *p, char titulo[]);
void muestraPila(Pila o);

int main()
{
    Pila dada;
    inicpila(&dada);

    cargaPilaRandom(&dada, 50, -10, 12);
    cargaPilaUsuario(&dada, "Ingrese una temperatura: ");
    muestraPila(dada);

    printf("\nHello world!\n");
    return 0;
}

/** \brief Retorna un entero entre un rango de numeros
 *
 * \param int - Numero minimo
 * \param int - Numero maximo
 * \return int - Numero aleatorio
 *
 */
int randomRango(int min, int max){
    return rand()%(max-min)+min+1;
}

void cargaPilaRandom(Pila *p, int limite, int min, int max){
    for(int i=0;i<limite;i++){
        apilar(p, randomRango(min,max));
    }
}

/**************************************************************//**
 * \brief    Carga una pila con intervencion del usuario
 * \param    Pila * - Puntero a pila
 * \param    char [] - El titulo como cadena de caracteres
 * \return   Nada
 ****************************************************************/
void cargaPilaUsuario(Pila *p, char titulo[]){
    int nro;
    char opcion;

    do{
        printf("\n %s", titulo);
        scanf("%d", &nro);

        apilar(p, nro);

        printf("\n ESC para salir - cualquier tecla para continuar ");
        opcion = getch();
        system("cls");
    }
    while(opcion!=27);
}

void muestraPila(Pila o){
    Pila aux;
    inicpila(&aux);
    int cont=0;

    while(!pilavacia(&o)){
        cont++;
        if(cont%15 == 0){
            printf("\n");
        }
        printf("%d | ",tope(&o));
        apilar(&aux, desapilar(&o));
    }
}

int buscaEnPila(Pila o, int b){
    Pila aux;
    inicpila(&aux);
    int flag=0;

    while(!pilavacia(&o) && flag==0){
        if(tope(&o)==b){
            flag=1;
        }
        apilar(&aux, desapilar(&o));
    }

    return flag;
}
