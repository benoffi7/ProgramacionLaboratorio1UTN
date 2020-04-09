/**
3. Cargar desde teclado una pila DADA y pasar a la pila
DISTINTOS todos aquellos elementos distintos al valor 8.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    srand(time(NULL)); /// Inicializo la semilla para generar numeros aleatorios

    Pila DADA, DISTINTOS, OCHOS;
    inicpila(&DADA);
    inicpila(&DISTINTOS);
    inicpila(&OCHOS);

    int limite;
    char opcion;

    limite=rand()%49+1; /// En la variable limite almaceno de manera aleatoria la cantidad de elementos que va a tener la pila

    for(int i=0; i<limite;i++){
        apilar(&DADA,rand()%15); /// apilo numeros aleatorios entre 0 y 14 en la pila DADA
    }

    do{     /// este es el típico bucle de carga de datos, hasta que el usuario quiera, se sale con la tecla ESC
        leer(&DADA);

        printf("\n\n ESC para salir .... ");
        opcion=getch();

    }while(opcion!=ESC);

    printf("\n\n Pila DADA.....");
    mostrar(&DADA);

    while(!pilavacia(&DADA)){    /// recorro la pila dada hasta vaciarla
        if(tope(&DADA)==8){
            apilar(&OCHOS, desapilar(&DADA));   /// desapilo los 8 en la pila OCHOS
        }
        else{
            apilar(&DISTINTOS, desapilar(&DADA));  /// desapilo el resto de los numeros en la pila DISTINTOS
        }
    }

    while(!pilavacia(&OCHOS)){
        apilar(&DADA, desapilar(&OCHOS)); /// Vuelvo a poner los ochos en la pila DADA
    }

    printf("\n\n Pila DADA.....");
    mostrar(&DADA);

    printf("\n\n Pila DISTINTOS.....");
    mostrar(&DISTINTOS);

    printf("\n\n Pila OCHOS.....");
    mostrar(&OCHOS);

    return 0;
}
