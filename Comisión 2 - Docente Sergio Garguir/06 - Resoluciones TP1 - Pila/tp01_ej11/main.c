/**
11. Suponiendo la existencia de una pila MODELO que no esté vacía,
eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main()
{
    Pila MODELO, DADA, AUXDADA, IGUALES;
    inicpila(&MODELO);
    inicpila(&DADA);
    inicpila(&AUXDADA);
    inicpila(&IGUALES);

    srand(time(NULL));

    int limite;

    limite = rand()%25+1;
    for(int i=0;i<limite;i++){
        apilar(&MODELO,rand()%10);
    }

    limite = rand()%10+1;
    for(int i=0;i<limite;i++){
        apilar(&DADA,rand()%10);
    }

    printf("Pila MODELO ...........");
    mostrar(&MODELO);

    printf("Pila DADA ............");
    mostrar(&DADA);

    if(!pilavacia(&MODELO)){
        while(!pilavacia(&DADA)){
            if(tope(&DADA) == tope(&MODELO)){
                apilar(&IGUALES, desapilar(&DADA));
            }
            else{
                apilar(&AUXDADA, desapilar(&DADA));
            }
        }

        while(!pilavacia(&AUXDADA)){
            apilar(&DADA, desapilar(&AUXDADA));
        }
    }

    printf("Pila MODELO ...........");
    mostrar(&MODELO);

    printf("Pila DADA ............");
    mostrar(&DADA);

    return 0;
}
