#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/**
Pila
inicpila(&pila);
apilar(&pila, entero);
leet(&pila);
tope(&pila);
desapilar(&pila);
mostrar(&pila);
pilavacia(&pila);

*/

const int DATO=10;
int main()
{
    Pila pilita, pilota, destino, cinco;
    inicpila(&pilita);
    inicpila(&pilota);
    inicpila(&destino);
    inicpila(&cinco);
    int nro = 50;
    char opcion;

    apilar(&pilita, 5);
    apilar(&pilota, DATO);
    apilar(&pilita, nro);
    apilar(&pilita, tope(&pilota));
    apilar(&pilita, desapilar(&pilota));

    do{
        leer(&pilita);

        printf("\n Cualquier tecla para continuar o n para salir ");
        fflush(stdin);
        scanf("%c",&opcion);
        system("cls");
    }while(opcion!='n');

    printf("\n Pila pilita despues de la carga: ");
    mostrar(&pilita);

    while(!pilavacia(&pilita)){
        if(tope(&pilita)==5){
            apilar(&destino, desapilar(&pilita));
        }
        else{
            apilar(&pilota,desapilar(&pilita));
        }
    }

    while(!pilavacia(&pilita)){
        if(tope(&pilita)==5){
            apilar(&cinco,desapilar(&pilita));
        }
        else{
            apilar(&destino, desapilar(&pilita))
        }
    }

    while(!pilavacia(&destino)){
        apilar(&pilota, desapilar(&destino));
        if(!pilavacia(&destino)){
            apilar(&pilita, desapilar(&destino));
        }
    }




    printf("Hello world!\n");
    return 0;
}
