#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27
#define DIM 10

int existePila(Pila p, int dato);
void cargaDNIs(Pila *p);
void muestraDNIs(Pila p);
int ultimoDigito(int nro);
void cuentoDNIs(Pila p, int a[], int v);
int totalDNIs(int a[], int v);
void muestraArreglo(int a[], int v);

int main()
{
    Pila dni;
    inicpila(&dni);
    int contador[DIM]={0};

    cargaDNIs(&dni);
    muestraDNIs(dni);
    printf("\n");

    cuentoDNIs(dni,contador,DIM);
    muestraArreglo(contador,DIM);

    printf("\n\nHello UTN!\n");
    return 0;
}

/****************************************************************************//*****
*
* \brief Función que busca un elemento en una pila y retorna si existe o no
* \param Pila
* \param int el dato a buscar
* \return int 0 si no existe ó 1 si existe
*
**********************************************************************************/
int existePila(Pila p, int dato){
    Pila aux;
    inicpila(&aux);
    int flag=0;
    while(!pilavacia(&p) && flag==0){
        if(tope(&p)==dato){
            flag=1;
        }
        apilar(&aux, desapilar(&p));
    }

    return flag;
}

/*********************************************************************************
*
* \brief Función que carga una pila con datos al azar
* \param Pila *
* \return void
*
**********************************************************************************/
void cargaDNIs(Pila *p){
    int dni;
    for(int i=0;i<50;i++){
        dni=((rand()%51684)*(rand()%1680))+5000000;
        if(!existePila(*p,dni)){
            apilar(p, dni);
        }
    }
}

/*********************************************************************************
*
* \brief Función que muestra una pila
* \param Pila
* \return void
*
**********************************************************************************/
void muestraDNIs(Pila p){
    Pila aux;
    inicpila(&aux);
    int i=0;
    while(!pilavacia(&p)){
        if(i%10==0){
            printf("\n");
        }
        printf("%d - ",tope(&p));
        apilar(&aux, desapilar(&p));
        i++;
    }
}

/*********************************************************************************
*
* \brief Función que retorna el primer dígito de un entero
* \param int
* \return int
*
**********************************************************************************/
int ultimoDigito(int nro){
    return nro%10;
}

/*********************************************************************************
*
* \brief Función que cuenta en un arreglo los DNIs de cada terminacion
* \param Pila
* \param int arreglo
* \param int validos
* \return void
*
**********************************************************************************/
void cuentoDNIs(Pila p, int a[], int v){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&p)){
        a[ultimoDigito(tope(&p))]++;
        apilar(&aux, desapilar(&p));
    }
}

/*********************************************************************************
*
* \brief Función que calcula el valor total de los elementos de un arreglo
* \param int arreglo
* \param int validos
* \return int total
*
**********************************************************************************/
int totalDNIs(int a[], int v){
    int total=0;
    for(int i=0;i<v;i++){
        total+=a[i];
    }
    return total;
}

/*********************************************************************************
*
* \brief Función que muestra el arreglo de beneficiarios con sus porcentajes
* \param int arreglo
* \param int validos
* \return void
*
**********************************************************************************/
void muestraArreglo(int a[], int v){
    int total = totalDNIs(a,10);
    float porcentaje=0;
    for(int i=0;i<v;i++){
        if(i%10==0){
            printf("\n");
        }
        porcentaje=(float)a[i]*100/total;
        printf("\n Terminacion en %d = %d - %.2f%%",i,a[i],porcentaje);
    }

    printf("\n ----TOTAL DE BENEFICIARIOS %d",total);
}

