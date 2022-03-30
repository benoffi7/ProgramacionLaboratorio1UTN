#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


int main()
{
    Pila dada;
    Pila modelo;
    Pila aux;
    Pila basura;

    inicpila(&dada);
    inicpila(&modelo);
    inicpila(&aux);
    inicpila(&basura);

    for(int i=0;i<10;i++){
        apilar(&dada, rand()%10);
    }
    for(int i=0;i<15;i++){
        apilar(&modelo, rand()%10);
    }

    printf("<<<<<<<<<<<<<<< pila dada >>>>>>>>>>>>>>>>>>>");
    mostrar(&dada);

    printf("<<<<<<<<<<<<<<< pila modelo >>>>>>>>>>>>>>>>>>>");
    mostrar(&modelo);

    if(!pilavacia(&modelo)){
        while(!pilavacia(&dada)){
            if(tope(&modelo)==tope(&dada)){
                apilar(&basura, desapilar(&dada));
            }else{
                apilar(&aux, desapilar(&dada));
            }
        }

        while(!pilavacia(&aux)){
            apilar(&dada, desapilar(&aux));
        }
    }

    printf("<<<<<<<<<<<<<<< pila dada >>>>>>>>>>>>>>>>>>>");
    mostrar(&dada);

    printf("<<<<<<<<<<<<<<< pila modelo >>>>>>>>>>>>>>>>>>>");
    mostrar(&modelo);

    return 0;
}
