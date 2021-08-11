#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
12. Suponiendo la existencia de una pila MODELO (vacía o no),
eliminar de la pila DADA todos los elementos que existan en MODELO.
*/

int main()
{
    Pila modelo, dada, auxModelo, auxDada, basura;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&auxModelo);
    inicpila(&auxDada);
    inicpila(&basura);

    for(int i=0;i<10;i++){
        apilar(&modelo, rand()%10);
        apilar(&dada, rand()%20);
    }

    printf("\n Pila Modelo");
    mostrar(&modelo);

    printf("\n Pila Dada");
    mostrar(&dada);

    while(!pilavacia(&modelo)){

        while(!pilavacia(&dada)){
            if(tope(&dada)==tope(&modelo)){
                apilar(&basura, desapilar(&dada));
            }else{
                apilar(&auxDada, desapilar(&dada));
            }
        }

        while(!pilavacia(&auxDada)){
            apilar(&dada, desapilar(&auxDada));
        }

        apilar(&auxModelo, desapilar(&modelo));
    }

    while(!pilavacia(&auxModelo)){
        apilar(&modelo, desapilar(&auxModelo));
    }

    printf("\n Pila Modelo");
    mostrar(&modelo);

    printf("\n Pila Dada");
    mostrar(&dada);

    printf("\n Pila Basura");
    mostrar(&basura);


    return 0;
}
