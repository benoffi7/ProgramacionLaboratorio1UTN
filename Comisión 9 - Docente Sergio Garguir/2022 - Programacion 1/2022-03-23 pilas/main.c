#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila temperaturas;
    Pila aux;
    int temperatura;
    int cont=0;

    inicpila(&temperaturas);
    inicpila(&aux);

    for(int i=0;i<40;i++){
        apilar(&temperaturas, rand()%50);
    }

    printf("\n Pila Temperaturas");
    mostrar(&temperaturas);
    printf("\n Pila Aux");
    mostrar(&aux);

    while(!pilavacia(&temperaturas)){
        temperatura = tope(&temperaturas);
        if(temperatura > 0){
            cont++;
            if(cont%20==0){
                printf("\n");
            }
            printf("%d ", temperatura);
        }
        apilar(&aux, desapilar(&temperaturas));
    }

    printf("\n Pila Temperaturas");
    mostrar(&temperaturas);
    printf("\n Pila Aux");
    mostrar(&aux);

    while(!pilavacia(&aux)){
        apilar(&temperaturas, desapilar(&aux));
    }

    printf("\n Pila Temperaturas");
    mostrar(&temperaturas);
    printf("\n Pila Aux");
    mostrar(&aux);

  //  printf("Hello world!\n");
    return 0;
}
