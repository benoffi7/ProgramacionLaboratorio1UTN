#include <stdio.h>
#include <stdio.h>
#include "../pila.h"


int main ()
{

    Pila a, b;
    inicpila(&a);
    inicpila(&b);

    apilar(&a, 1);
    apilar(&a, 2);
    apilar(&a, 3);
    apilar(&a, 4);
    apilar(&a, 5);

    apilar(&b, 1);
    apilar(&b, 3);
    apilar(&b, 6);
    apilar(&b, 5);
    apilar(&b, 4);

    printf("Pila a\n");
    mostrar(&a);

    printf("Pila b\n");
    mostrar(&b);

    Pila destino;
    inicpila(&destino);



    Pila aux, descarte;
    inicpila(&aux);
    inicpila(&descarte);

    while(!pilavacia(&a))
    {
        while(!pilavacia(&b)&& tope(&a)!=tope(&b))
        {
            apilar(&aux, desapilar(&b));
        }

        if(!pilavacia(&b)) /// encontramos coincidencia
        {
            apilar(&descarte, desapilar(&b));
        }

        /// volvemos a poner todo en b
        while (!pilavacia(&aux))
        {
            apilar(&b, desapilar(&aux));
        }

         /// sacamos el elemento ya procesado de a
        apilar(&destino, desapilar(&a));
    }

    /// si se vacio a, todo lo que quedo en b ya puede pasar al conjunto c sin mas evaluaciones
    while(!pilavacia(&b))
    {
        apilar(&destino, desapilar(&b));
    }


    printf("Pila destino\n");
    mostrar(&destino);

    printf("Pila a\n");
    mostrar(&a);

    printf("Pila b\n");
    mostrar(&b);
    return 0;
}
