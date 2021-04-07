#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    srand(time(NULL));
    Pila origen, aux;
    inicpila(&origen);
    inicpila(&aux);

    int flag=0;
    int aBuscar;
    int nro;
    char opcion='s';

    /// Ciclo automatico de carga random
    for(int i=0;i<10;i++){
        apilar(&origen, rand()%99);
    }

    /// Ciclo de carga por el usuario
    while(opcion=='s'){
        printf("\n Ingrese un nro: ");
        scanf("%d", &nro);

        apilar(&origen, nro);

        printf("\n Desea seguir ingresando datos? s/n ");
        fflush(stdin);
        scanf("%c", &opcion);
        system("cls");
    }

    printf("\n Pila Origen");
    mostrar(&origen);

    printf("\n Ingrese un dato a buscar en la pila ");
    scanf("%d", &aBuscar);

    while(!pilavacia(&origen) && flag==0){
        printf("\n El nro tope %d", tope(&origen));
        if(aBuscar == tope(&origen)){
            flag=1;
        }
        apilar(&aux, desapilar(&origen));
    }

    while(!pilavacia(&aux)){
        apilar(&origen, desapilar(&aux));
    }

    printf("\n Pila Origen");
    mostrar(&origen);

    if(flag==1){
        printf("\n El nro %d existe en la pila ", aBuscar);
    }else{
        printf("\n El nro %d NO existe en la pila ", aBuscar);
    }

    printf("Hello world!\n");
    return 0;
}
