#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

int main()
{
    Pila  datos, aux;

    inicpila(&datos);
    inicpila(&aux);

    int num;
    int flag = 0;

    for(int i=0;i<7;i++){
        apilar(&datos, rand()%100);
    }

    printf("\n <<<<<<<<<<<<<< Pila Datos >>>>>>>>>>>>>>>>");
    mostrar(&datos);

    printf("\n Ingrese un numero para buscar en la pila: ");
    scanf("%d", &num);

    while(!pilavacia(&datos) && flag==0){
        if(tope(&datos)==num){
            flag=1;
        }else{
            apilar(&aux, desapilar(&datos));
        }
    }

    while(!pilavacia(&aux)){
        apilar(&datos, desapilar(&aux));
    }

    if(flag==1){
        printf("\n El dato %d se encuentra en la pila", num);
    }else{
        printf("\n El dato %d NO se encuentra en la pila", num);
    }

    while(!pilavacia(&aux)){
        apilar(&datos, desapilar(&aux));
    }

    printf("\n <<<<<<<<<<<<<< Pila Datos >>>>>>>>>>>>>>>>");
    mostrar(&datos);

    return 0;
}
