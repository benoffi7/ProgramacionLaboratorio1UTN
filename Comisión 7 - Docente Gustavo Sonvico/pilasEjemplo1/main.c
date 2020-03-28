#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()

{

    printf("Hello world pilas!\n");

    Pila pilita, pilota;
    inicpila(&pilita);
    inicpila(&pilota);


    char control;


/// bucle de carga de la pila
    do
    {
        leer(&pilita);

        printf("Desea continuar? s/n ");
        fflush(stdin);
        scanf("%c", &control);

    }
    while(control=='s');

    printf("pilita");
    mostrar(&pilita);

    while(!pilavacia(&pilita))
    {
        apilar(&pilota, desapilar (&pilita));
    }

    printf("pilita");
    mostrar(&pilita);

    printf("pilota");
    mostrar(&pilota);
    return 0;

}
