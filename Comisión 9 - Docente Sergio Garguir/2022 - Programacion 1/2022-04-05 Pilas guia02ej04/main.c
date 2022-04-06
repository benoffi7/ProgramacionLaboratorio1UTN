#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"


int main()
{
    Pila datos, aux, menor;
    inicpila(&datos);
    inicpila(&aux);
    inicpila(&menor);

    for(int i=0; i<15; i++){
        apilar(&datos, rand()%100);
    }

    printf("\n <<<<<<<<<<<<< Datos >>>>>>>>>>>> ");
    mostrar(&datos);

    if(!pilavacia(&datos)){
        apilar(&menor, desapilar(&datos));

        while(!pilavacia(&datos)){
            if(tope(&datos) < tope(&menor)){
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&datos));
            }else{
                apilar(&aux, desapilar(&datos));
            }
        }

        while(!pilavacia(&aux)){
            apilar(&datos, desapilar(&aux));
        }
    }

    printf("\n <<<<<<<<<<<<< Datos >>>>>>>>>>>> ");
    mostrar(&datos);

    printf("\n <<<<<<<<<<<<< Menor >>>>>>>>>>>> ");
    mostrar(&menor);

    return 0;
}
