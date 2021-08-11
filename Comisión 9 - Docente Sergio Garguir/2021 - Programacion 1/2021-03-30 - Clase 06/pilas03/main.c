#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
3. Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8.
*/

int main()
{
    Pila dada, distintos, ochos;
    inicpila(&dada);
    inicpila(&distintos);
    inicpila(&ochos);

    int nro;
    char opcion;

    /// Ciclo de ingreso de datos
    do{
        printf("\n Ingrese un nro: ");
        scanf("%d", &nro);
        apilar(&dada, nro);
        printf("\n Cualquier tecla para continuar - ESC para salir ");
        opcion=getch();
        system("cls");
    }
    while(opcion!=27);

    while(!pilavacia(&dada)){
        if(tope(&dada)!=8){
            apilar(&distintos, desapilar(&dada));
        }else{
            apilar(&ochos, desapilar(&dada));
        }
    }

    while(!pilavacia(&ochos)){
        apilar(&dada, desapilar(&ochos));
    }

    printf("\n Muestro Pila Dada");
    mostrar(&dada);

    printf("\n Muestro Pila Distintos");
    mostrar(&distintos);

    printf("\n Muestro Pila Ochos");
    mostrar(&ochos);

    printf("Hello world!\n");
    return 0;
}
