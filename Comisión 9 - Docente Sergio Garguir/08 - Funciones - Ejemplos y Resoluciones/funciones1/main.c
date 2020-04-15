#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

/// Prototipado de las funciones
void miPrimerFuncion();
int suma(int a, int b);
void sumaPorReferencia(int a, int b, int *total);
int resta(int a, int b);
float division(int a, int b);
int multiplicacion(int a, int b);
void intercambio(int a, int b);
void intercambioPuntero(int *a, int *b);
void cargarPila(Pila *p);
void pasaPila(Pila *origen, Pila *destino);
void copiaPila(Pila origen, Pila *destino);

const int ALGO = 21;


int main()
{
    Pila dada, pilita;
    inicpila(&dada);
    inicpila(&pilita);

    cargarPila(&dada);
    printf("\nPila dada");
    mostrar(&dada);

    pasaPila(&dada, &pilita);
    printf("\nPila dada");
    mostrar(&dada);
    printf("\nPila pilita");
    mostrar(&pilita);

    copiaPila(pilita, &dada);
    printf("\nPila dada");
    mostrar(&dada);
    printf("\nPila pilita");
    mostrar(&pilita);

    printf("Hello world!\n");
    miPrimerFuncion();

    int n1, n2, resultado;

    printf("\n Ingrese un nro: ");
    scanf("%d",&n1);
    printf("\n Ingrese un nro: ");
    scanf("%d",&n2);

    resultado = suma(n1, n2); /// pasaje de parametros por copia
    printf("\n\n El resultado por copia de %d + %d es %d",n1, n2, resultado);

    sumaPorReferencia(n1, n2, &resultao);
    printf("\n\n El resultado por referencia de %d + %d es %d",n1, n2, resultado);

    intercambio(n1, n2);
    printf("\n Mostrando variables intercambiadas por copia n1 %d y n2 %d", n1, n2);

    intercambioPuntero(&n1, &n2);

    printf("\n Mostrando variables intercambiadas por referencia n1 %d y n2 %d", n1, n2);

    return 0;
}


/// Codigo de las funciones
void miPrimerFuncion(){
	printf("\n Esta es mi primer funcion");
	printf("\n _______________________________________________");
}

/// Suma los elementos recibidos
int suma(int a, int b){
    int total;

    total = a + b;

    return total;
}

void sumaPorReferencia(int a, int b, int *total){
     *total = a + b;
}

void intercambio(int a, int b){
    int tmp;
    printf("\n Mostrando variables antes del intercambio a %d y b %d", a, b);
    tmp = a;
    a = b;
    b = tmp;
    printf("\n Mostrando variables intercambiadas a %d y b %d", a, b);
}

void intercambioPuntero(int *a, int *b){
    int tmp;
    printf("\n Mostrando variables antes del intercambio a %d y b %d", *a, *b);
    tmp = *a; /// direccio de memoria de n1
    *a = *b;
    *b = tmp;
    printf("\n Mostrando variables intercambiadas a %d y b %d", *a, *b);
}

void cargarPila(Pila *p){
    char opcion;
    int temperatura;

	do{
		printf("\n Ingrese temperatura: ");
		scanf("%d", &temperatura);
		apilar(p, temperatura);

		printf("\n\n\t ESC para salir....");
		opcion=getch();
		system("cls");
	}while(opcion!=27);
}

void pasaPila(Pila *origen, Pila *destino){
    while(!pilavacia(origen)){
        apilar(destino, desapilar(origen));
    }
}

void copiaPila(Pila origen, Pila *destino){
    while(!pilavacia(&origen)){
        apilar(destino, desapilar(&origen));
    }
}
