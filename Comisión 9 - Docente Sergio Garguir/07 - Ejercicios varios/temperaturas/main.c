#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "pila.h"

#define ESC 27
const int LIMITE=24;
const int MAX=15;
const int MIN=-10;

int main(){
	Pila dada, aux;
	inicpila(&dada);
	inicpila(&aux);
	int i;
	int temperatura;
	int mayor;
	int menor;
	float promedio;
	char opcion;

	for(i=0;i<LIMITE;i++){
		temperatura=rand()%(MAX-MIN)+(MIN);
		printf("\n Ingresando temperatura de la hora %d: %d", i+1, temperatura);
		apilar(&dada, temperatura);
		Sleep(500);
		system("cls");
	}
	/**
	do{
		printf("\n Ingrese temperatura: ");
		scanf("%d", &temperatura);
		apilar(&dada, temperatura);

		printf("\n\n\t ESC para salir....");
		opcion=getch();
		system("cls");
	}while(opcion!=27);
	*/

	printf("\n Pila dada...");
	mostrar(&dada);

	while(!pilavacia(&dada)){
		printf("[%d] - ", tope(&dada));
		apilar(&aux, desapilar(&dada));
	}

	while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
	}
}
