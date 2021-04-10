#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

/**
1.	Sumar los elementos de una pila (usar variables)
2.	Contar los elementos de una pila (usar variables)
3.	Calcular el promedio de los valores de una pila (usar variables)

*/

int main()
{
    Pila dada, aux;
    inicpila(&dada);
    inicpila(&aux);

    int cont=0;
    int total=0;
    float promedio;

    int nro;
    char opcion;

    for(int i=15;i>0;i--){
        apilar(&dada, rand()%50);
    }

    do{
        printf("\n Ingrese un dato: ");
        scanf("%d", &nro);

        apilar(&dada, nro);

        printf("\n ESC para salir o cualquier tecla para continuar ");
        opcion=getch();
        system("cls");
    }
    while(opcion!=27);

    printf("\n Pila dada");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        cont++;
        total=total+tope(&dada);
        apilar(&aux, desapilar(&dada));
    }

    while(!pilavacia(&aux)){
        apilar(&dada, desapilar(&aux));
    }

    if(cont > 0){
        promedio = (float) total / cont;
    }

    printf("\n Pila dada");
    mostrar(&dada);

    printf("\n La pila dada tiene %d elementos que suman %d y su promedio es %.2f", cont, total, promedio);
    return 0;
}

