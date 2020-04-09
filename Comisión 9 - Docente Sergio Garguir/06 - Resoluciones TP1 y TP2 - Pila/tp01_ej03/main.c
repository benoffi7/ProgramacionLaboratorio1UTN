/**
3. Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8.
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    srand(time(NULL));
    Pila dada, distintos, ochos;
    inicpila(&dada);
    inicpila(&distintos);
    inicpila(&ochos);
    int limite;
    char opcion;

    limite=rand()%40+1; /// En la variable limite almaceno de manera aleatoria la cantidad de elementos que va a tener la pila
    for(int i=0;i<limite;i++){
        apilar(&dada, rand()%10+1);  /// apilo numeros aleatorios entre 1 y 10 en la pila DADA
    }

    do{
        leer(&dada);

        printf("\n\n ESC para salir ....... ");
        opcion=getch();
    }while(opcion!=ESC);

    printf("\n\n Pila dada .......");
    mostrar(&dada);

    while(!pilavacia(&dada)){     /// recorro la pila dada hasta vaciarla
        if(tope(&dada)==8){
            apilar(&ochos, desapilar(&dada));  /// desapilo los 8 en la pila OCHOS
        }
        else{
            apilar(&distintos, desapilar(&dada));   /// desapilo el resto de los numeros en la pila DISTINTOS
        }
    }

    while(!pilavacia(&ochos)){
        apilar(&dada, desapilar(&ochos));
    }

    printf("\n\n Pila dada .......");
    mostrar(&dada);

    printf("\n\n Pila distintos .......");
    mostrar(&distintos);

    printf("\n\n Pila ochos .......");
    mostrar(&ochos);

    printf("Hello world!\n");
    return 0;
}
