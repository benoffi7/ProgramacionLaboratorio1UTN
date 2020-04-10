/**
9.	Verificar si una pila DADA es capicúa.
*/

/**
4.	Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables, solo pilas)
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila dada, aux, copiaInv, auxCopiaInv;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&copiaInv);
    inicpila(&auxCopiaInv);

    char opcion;


    do{
        printf("\n\n Cargando pila dada\n");
        leer(&dada);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);

    printf("\n\n Pila dada");
    mostrar(&dada);

    /// Hago una copia de la pila dada en la pila copiaInv
	while(!pilavacia(&dada)){
        apilar(&copiaInv, tope(&dada));
		apilar(&aux, desapilar(&dada));
	}

    printf("\n\n Pila copiaInv");
    mostrar(&copiaInv);

    /// Regreso los datos a la pila dada
	while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
	}

	/// recorro las pilas dada y copiaInv mientras tengan datos y sus topes sean iguales
	while((!pilavacia(&dada))&&(!pilavacia(&copiaInv))&&(tope(&dada)==tope(&copiaInv))){
        apilar(&aux, desapilar(&dada));
		apilar(&auxCopiaInv, desapilar(&copiaInv));
	}

	/// Si ambas pilas están vacías significa que la pila dada es capicua
	if((pilavacia(&dada))&&(pilavacia(&copiaInv))){
        printf("\n\n La pila dada es capicua\n");
	}
	else{
        printf("\n\n La pila dada NO es capicua\n");
	}

    printf("\n\n Pila dada");
    mostrar(&dada);
    printf("\n\n Pila copiaInv");
    mostrar(&copiaInv);

    printf("\n\n\n\n");
    return 0;
}

