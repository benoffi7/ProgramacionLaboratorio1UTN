#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int cargaAbecedario(char c[], int dim);
void muestraArregloChar(char c[], int v);
int cargaArregloRandom(int t[], int v, int dim);
void muestraArregloInt(int t[], int v);
void arreglo2Pilas(int t[], int v, Pila *pMay, Pila *pMen, int limite);

int main()
{
    Pila tempMay, tempMen;
    inicpila(&tempMay);
    inicpila(&tempMen);

    char letras[100];
    int vLetras=0;

    int temperaturas[100];
    int vTemp=0;

    int otro[50];
    int vOtro=0;

    vLetras=cargaAbecedario(letras, 100);
    printf("\n Muestro arreglo de letras\n");
    muestraArregloChar(letras, vLetras);

    vTemp=cargaArregloRandom(temperaturas, vTemp, 100);
    printf("\n Muestro arreglo de temperaturas\n");
    muestraArregloInt(temperaturas, vTemp);

    arreglo2Pilas(temperaturas, vTemp, &tempMay, &tempMen, 15);
    printf("\n Pila Mayores \n");
    mostrar(&tempMay);
    printf("\n Pila Menores \n");
    mostrar(&tempMen);

    vOtro=pila2arreglo(tempMay, otro, 50, 30);
    printf("\n Muestro arreglo otro\n");
    muestraArregloInt(otro, vOtro);
    printf("\n Pila Mayores \n");
    mostrar(&tempMay);


    printf("\nHello world!\n");
    return 0;
}

int cargaAbecedario(char c[], int dim){
    int i=0;

    while(i<26 && i<dim){
        c[i]=65+i;
        i++;
    }
    return i;
}

void muestraArregloChar(char c[], int v){
    for(int i=0;i<v;i++){
        printf("[%c] ",c[i]);
    }
}

int cargaArregloRandom(int t[], int v, int dim){
    int i=v;
    while(i<dim){
        t[i]=rand()%(40-5)+5;
        i++;
    }
    return i;
}

void muestraArregloInt(int t[], int v){
    for(int i=0;i<v;i++){
        printf("[%d] ",t[i]);
    }
}

void arreglo2Pilas(int t[], int v, Pila *pMay, Pila *pMen, int limite){
    int i=0;
    int contMay=0;
    int contMen=0;
    while(i<v){
        if(t[i] > limite){
            if(contMay<50){
                apilar(pMay, t[i]);
                contMay++;
            }
        }else{
            if(contMen<50){
                apilar(pMen, t[i]);
                contMen++;
            }
        }
        i++;
    }
}

int pila2arreglo(Pila p, int t[], int dim, int limite){
    Pila aux;
    inicpila(&aux);
    int i=0;

    while(!pilavacia(&p) && i<dim){
        if(tope(&p)>limite){
            t[i]=tope(&p);
            i++;
        }
        apilar(&aux, desapilar(&p));
    }
    return i;
}
