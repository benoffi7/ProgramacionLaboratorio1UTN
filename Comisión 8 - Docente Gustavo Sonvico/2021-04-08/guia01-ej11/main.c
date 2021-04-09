#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
11. Suponiendo la existencia de una pila MODELO
que no esté vacía, eliminar de la pila DADA todos
los elementos que sean iguales al tope de la pila MODELO.
*/

int main()
{
    Pila dada, modelo, aux, basura;
    inicpila(&dada);
    inicpila(&modelo);
    inicpila(&aux);
    inicpila(&basura);

    int nro;
    char opcion;

    for(int i=0;i<5;i++){
        apilar(&modelo, rand()%10);
    }

    for(int i=0;i<10;i++){
        apilar(&dada, rand()%15);
    }

    do{
        printf("\n Ingrese una edad: ");
        scanf("%d", &nro);

        apilar(&dada, nro);

        printf("\n ESC para salir - cualquier tecla para continuar");
        opcion=getch();
        system("cls");
    }
    while(opcion != 27);

    printf("\n Pila Dada");
    mostrar(&dada);

    printf("\n Pila Modelo");
    mostrar(&modelo);


    if(!pilavacia(&modelo)){
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
    }


    printf("\n Pila Dada");
    mostrar(&dada);

    printf("\n Pila Modelo");
    mostrar(&modelo);

    return 0;
}
