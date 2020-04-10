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
    srand(time(NULL));                          /// Inicializo la semilla para la funcion rand()
	Pila dada, aux, copiaInv, auxCopiaInv;      /// Declaro las pilas
	inicpila(&dada);                            /// Inicializo las pilas
	inicpila(&aux);
	inicpila(&copiaInv);
	inicpila(&auxCopiaInv);
	int i;
	int temperatura;
	int mayor;
	int menor;
	int total = 0;                              /// Declaro e inicializo un acumulador
	int cont = 0;                               /// Declaro e inicializo un contador
	float promedio;
	char opcion;

	/// Cargo la pila con datos aleatorios entre MIN y MAX
	for(i=0;i<LIMITE;i++){
		temperatura=rand()%(MAX-MIN)+(MIN);
		printf("\n Ingresando temperatura de la hora %d: %d", i+1, temperatura);
		apilar(&dada, temperatura);
		Sleep(200);
		system("cls");
	}

	/// Ciclo de carga de una pila sin usar la funcion leer()
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

	/// Muestro la pila sin usar la funcion mostrar()
	printf("\n\n Temperaturas ...\n\n");

	while(!pilavacia(&dada)){
		printf("[%d] ", tope(&dada));
		apilar(&aux, desapilar(&dada));
	}
    /// Regreso los datos a la pila dada
	while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
	}
    /// Hago una copia de la pila dada en la pila copiaInv
	while(!pilavacia(&dada)){
        apilar(&copiaInv, tope(&dada));
		apilar(&aux, desapilar(&dada));
	}
    /// Regreso los datos a la pila dada
	while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
	}
    /// Recorro la pila copiaInv acumulando sus valores, contandolos y buscando menor y mayor
	if(!pilavacia(&copiaInv)){
        total = total + tope(&copiaInv);            /// Acumulando el primer valor de la pila
        cont++;                                     /// Contando el primer valor de la pila
        menor = tope(&copiaInv);                    /// Asigno el tope a la variable menor para tener una perimer referencia
        mayor = desapilar(&copiaInv);               /// desapilo en la variable mayor para tener una perimer referencia

        while(!pilavacia(&copiaInv)){               /// recorro la pila copiaInv
            total = total + tope(&copiaInv);        /// voy acumulando los valores
            cont++;                                 /// voy contando los datos
            if(tope(&copiaInv)<menor){              /// aca busco el menor
                apilar(&auxCopiaInv, menor);
                menor = desapilar(&copiaInv);
            }else if(tope(&copiaInv)>mayor){        /// aca busco el mayor
                apilar(&auxCopiaInv, mayor);
                mayor = desapilar(&copiaInv);
            }else{
                apilar(&aux, desapilar(&copiaInv)); /// si no hay menor y mayor en esta vuelta desapilo para ver el proximo valor
            }
        }
        promedio = (float) total / cont;            /// Realizo el calculo del promedio
        /// Muestro los datos
        printf("\n\n La menor temperatura es................: %d", menor);
        printf("\n La mayor temperatura es................: %d", mayor);
        printf("\n El promedio de las temperaturas es.....: %.2f", promedio);
        printf("\n\n\n\n");
	}
}
