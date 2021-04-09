#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

int main()
{
    Pila dada, modelo, aux, basura, auxModelo;
    inicpila(&dada);
    inicpila(&modelo);
    inicpila(&auxModelo);
    inicpila(&aux);
    inicpila(&basura);

    int nro;
    char opcion='s';

    for(int i=0;i<5;i++){
        apilar(&modelo, rand()%10);
    }

    for(int i=0;i<10;i++){
        apilar(&dada, rand()%10);
    }

    while(opcion=='s'){
        printf("\n Ingrese una temperatura: ");
        scanf("%d",&nro);

        apilar(&dada, nro);

        printf("\n Ingrese 's' para continuar ");
        fflush(stdin);
        scanf("%c",&opcion);
        system("cls");
    }

    printf("\n Pila Dada");
    mostrar(&dada);

    printf("\n Pila Modelo");
    mostrar(&modelo);


    while(!pilavacia(&modelo)){
        while(!pilavacia(&dada)){
            if(tope(&dada)==tope(&modelo)){
                apilar(&basura, desapilar(&dada));
            }else{
                apilar(&aux, desapilar(&dada));
            }
        }
        while(!pilavacia(&aux)){
            apilar(&dada, desapilar(&aux));
        }
        apilar(&auxModelo, desapilar(&modelo));
    }

    while(!pilavacia(&auxModelo)){
        apilar(&modelo, desapilar(&auxModelo));
    }

    printf("\n Pila Dada");
    mostrar(&dada);

    printf("\n Pila Modelo");
    mostrar(&modelo);


    return 0;
}
