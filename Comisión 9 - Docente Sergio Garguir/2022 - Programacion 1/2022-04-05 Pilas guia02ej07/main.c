#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

int main()
{
    Pila datos, aux;
    inicpila(&datos);
    inicpila(&aux);

    int aBuscar = 15;
    int flag = 0;

    for(int i=0; i<45; i++){
        apilar(&datos, rand()%100);
    }

    printf("\n <<<<<<<<<<<<< Datos >>>>>>>>>>>> ");
    mostrar(&datos);

    while(!pilavacia(&datos) && flag == 0){
        if(tope(&datos) == aBuscar){
            flag = 1;
        }else{
            apilar(&aux, desapilar(&datos));
        }
    }

    while(!pilavacia(&aux)){
        apilar(&datos, desapilar(&aux));
    }
    /// if(!pilavacia(&pila)) if(pilavacia(&pila) == 1)
    if(flag){ /// if(flag == 1)
        printf("\n El dato %d existe en la coleccion", aBuscar);
    }else{
        printf("\n El dato no existe");
    }

    while(!pilavacia(&aux)){
        apilar(&datos, desapilar(&aux));
    }





    printf("Hello world!\n");
    return 0;
}
