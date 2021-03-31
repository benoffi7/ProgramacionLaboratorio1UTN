#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
   Pila         -- para crear una pila
   inicpila()   -- para inicializar una pila
   apilar()     -- para agregar un dato a una pila
   tope()       -- para conocer el dato que esta en el tope de la pila (sin quitarlo)
   desapilar()  -- nos devuelve el tope de la pila (lo quita de la pila)
*/

int main()
{
    Pila pila, auxiliar;
    inicpila(&pila);
    inicpila(&auxiliar);

    float f = 3.14;
    char c = 'A';
    int nro = 50;
    int aux;

    apilar(&pila,5);
    apilar(&pila,nro);
    apilar(&pila,c);
    apilar(&pila,f);

    printf("\n Pila pila \n");
    mostrar(&pila);

    do{
        printf("\n Ingrese un nro: ");
        scanf("%d", &nro);
        apilar(&pila, nro);
        system("cls");
    }
    while(nro != 99);

    if(!pilavacia(&pila)){
        aux = tope(&pila);
    }
    printf("\n tope pila: %d",aux);

    printf("\n Pila pila \n");
    mostrar(&pila);

    if(!pilavacia(&pila)){
        aux = desapilar(&pila);
    }
    printf("\n desapilar pila: %d",aux);

    printf("\n Pila sin la funcion mostrar \n");
    while(!pilavacia(&pila)){
        printf("\n tope pila: %d",tope(&pila));
        apilar(&auxiliar, desapilar(&pila));
    }

    printf("\n Muestro pila");
    mostrar(&pila);

    printf("\n Muestro auxiliar");
    mostrar(&auxiliar);

    printf("Hello world!\n");
    return 0;
}
