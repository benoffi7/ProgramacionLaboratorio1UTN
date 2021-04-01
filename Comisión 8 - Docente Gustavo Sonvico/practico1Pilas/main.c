#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*
 Cargar desde el teclado una pila DADA con 5 elementos.
 Pasar los tres primeros elementos que se encuentren en el
 tope a la pila AUX1 y los restantes a la pila AUX2,
 ambas pilas inicializadas.

 */
int main()
{
//    printf("Hello world!\n");
//
//    Pila dada;
//    Pila aux1;
//    Pila aux2;
//
//    inicpila(&dada);
//    inicpila(&aux1);
//    inicpila(&aux2);
//
//    leer(&dada);
//    leer(&dada);
//    leer(&dada);
//    leer(&dada);
//    leer(&dada);
//
//    printf("Contenido de la pila dada luego de cargarla");
//    mostrar(&dada);
//
//    apilar(&aux1, desapilar(&dada));
//    apilar(&aux1, desapilar(&dada));
//    apilar(&aux1, desapilar(&dada));
//
//    apilar(&aux2, desapilar(&dada));
//    apilar(&aux2, desapilar(&dada));
//
//
//    printf("Contenido de la pila dada ");
//    mostrar(&dada);
//
//    printf("Contenido de la pila aux1 ");
//    mostrar(&aux1);
//
//    printf("Contenido de la pila aux2 ");
//    mostrar(&aux2);
//
//
//    /// ejercicio 3
//
//    /// crear las pilas
//    /// inicialiar
//    ///cargar
//
//    while(!pilavacia(&dada))
//    {
//        if(tope(&dada)!=8)
//        {
//            apilar(&distintos, desapilar(&dada));
//        }
//        else
//        {
//            apilar(&auxOchos, desapilar(&dada));
//        }
//    }
//
//
//    while(!pilavacia(&auxOchos)
//          {
//        apilar(&dada, desapilar(&auxOchos));
//    }
///// mostrar las pilas


    Pila origen, destino, aux;
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux);

    char control='s';
    /// cargar en origen

    printf("Vamos a cargar la pila origen\n");
    while(control=='s')
    {
        leer(&origen);

        printf("Desea continuar cargando valores? s/n ");

        fflush(stdin);
        scanf("%c", &control);
    }

    printf("Contenido de la pila origen\n");
    mostrar(&origen);


    system("pause");

    /// paso los elementos de origen a aux

    while(!pilavacia(&origen))
    {
        apilar(&aux, desapilar(&origen));
    }

    /// paso los elementos de aux a destino
    while(!pilavacia(&aux))
    {
        apilar(&destino, desapilar(&aux));
    }

    printf("Contenido de la pila destino\n");
    mostrar(&destino);


    return 0;
}
