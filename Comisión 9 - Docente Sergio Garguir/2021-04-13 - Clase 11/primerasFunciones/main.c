#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int suma(int x, int y);
int sumaPlus(int x, int y);
float promedio(int total, int cont);

int main()
{
    Pila dada;
    inicpila(&dada);
    apilar(&dada, 2);
    apilar(&dada, 5);

    int n;
    int m;
    int nroPila;
    int aleatorio;
    int resultado;


    printf("\n Ingrese un nro entero: ");
    scanf("%d", &n);

    printf("\n Ingrese un nro entero: ");
    scanf("%d", &m);

    resultado = suma(6, 12);
    nroPila = desapilar(&dada);
    aleatorio = rand()%4;

    suma(5, 10);

    printf("\n Usando suma() - La suma de %d + %d es: %d", 6, 12, resultado);
    printf("\n Usando sumaPlus() - La suma de %d + %d es: %d", nroPila, aleatorio, sumaPlus(nroPila,aleatorio));
    printf("\n Usando promedio() - El promedio de %d + %d es: %.2f", m, n, promedio(m,n));

    for(int i=0;i<10;i++){
        apilar(&dada, sumaPlus(tope(&dada), i));
    }

    mostrar(&dada);

    return 0;
}

int suma(int x, int y){
    int respuesta;

    respuesta = x + y;
    return respuesta;
}

int sumaPlus(int x, int y){
    return x + y;
}

float promedio(int total, int cont){
    float respuesta=0;
    if(cont > 0)
        respuesta = (float)total /cont;

    return respuesta;
}
