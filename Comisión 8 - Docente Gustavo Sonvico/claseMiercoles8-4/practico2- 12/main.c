#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


/*12) Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el
resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5*/

int main()
{
    Pila origen, aux, receptora;
    inicpila(&origen);
    inicpila(&aux);
    inicpila(&receptora);

    printf("Cargando pila origen: ");
    leer(&origen);
    leer(&origen);
    leer(&origen);
    leer(&origen);
    leer(&origen);
    leer(&origen);


    printf("Pila origen\n");
    mostrar(&origen);

    while(!pilavacia(&origen))
    {

        while (!pilavacia(&receptora) && tope(&receptora)<tope(&origen))
        {
            apilar(&aux, desapilar(&receptora));
        }

        apilar(&receptora, desapilar(&origen));

        while(!pilavacia(&aux))
        {
            apilar(&receptora, desapilar(&aux));
        }

    }

    while(!pilavacia(&receptora))
    {
        apilar(&origen, desapilar(&receptora));
    }

    printf("Pila origen ahora\n");
    mostrar(&origen);
    return 0;
}
