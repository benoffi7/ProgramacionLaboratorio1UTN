#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    printf("Hello world!\n");



    /// crear las pilas
    /// inicializar las pilas

    /// cargamos la pila dada (con muchos datos)

/// nucleo de la ordenacion por seleccion
    if(!pilavacia(&dada))
    {
/// buscar el menor

        apilar(&menor, desapilar(&dada));

        while(!pilavacia(&dada))
        {

            if(tope(&dada)<tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&dada));
            }
            else
            {
                apilar(&aux, desapilar(&dada));
            }
        }

        while(!pilavacia(&aux))
        {
            apilar(&dada, desapilar(&aux));
        }

/// fin buscar el menor
    }


    /// nucleo de la ordenacion  por insercion

    ///crear las pilas
/// iniciarlizar las pilas

///cargar dada de forma ordenada

    leer(&aInsertar);


    while(!pilavacia(&dada) && tope(&dada)<tope(&aInsertar) )
    {


        apilar(&aux, desapilar(&dada));
    }

    apilar(&dada, desapilar(&aInsertar));

    while(!pilavacia(&aux))
    {

        apilar(&dada, desapilar(&aux));
    }



    return 0;
}
