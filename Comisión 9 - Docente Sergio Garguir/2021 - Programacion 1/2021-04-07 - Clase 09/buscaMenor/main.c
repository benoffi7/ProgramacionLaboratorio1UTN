#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila origen, menor, aux, ordenada;
    inicpila(&origen);
    inicpila(&menor);
    inicpila(&aux);
    inicpila(&ordenada);

    for(int i=0; i<20; i++){
        apilar(&origen, rand()%20);
    }

    printf("\nPila Origen");
    mostrar(&origen);

    while(!pilavacia(&origen)){  /// cambiando el while por un if solo busca menor y lo saca de la pila origen
        apilar(&menor, desapilar(&origen));

        while(!pilavacia(&origen)){
            if(tope(&origen)<tope(&menor)){
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&origen));
            }else{
                apilar(&aux, desapilar(&origen));
            }
        }

        //apilar(&ordenada, desapilar(&menor));

        while(!pilavacia(&aux)){
            apilar(&origen, desapilar(&aux));
        }
    }



    printf("\nPila Origen");
    mostrar(&origen);
/*
    if(!pilavacia(&menor)){
        printf("\n El menor elemento de la pila origen es: %d", tope(&menor));
    }
*/
    printf("\nPila menor");
    mostrar(&menor);


    return 0;
}
