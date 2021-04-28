#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


/*9) Verificar si una pila DADA es capicúa. */


int main ()
{
    Pila dada;
    Pila aux1, aux2, aux3;
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&aux3);

// apilamos elementos para provar su "capicues" :p

    apilar(&dada, 1);
    //apilar(&dada, 2);
    apilar(&dada, 2);
    apilar(&dada, 3);
    apilar(&dada, 2);
    apilar(&dada, 1);

    mostrar(&dada);

////////////////////////////////////////////////////////////
/// VERSION ENROSCADA...
///////////////////////////////////////////////////////////

    // primero cuento los elementos
    int cuenta = 0;
    while(!pilavacia(&dada))
    {
        apilar(&aux1, desapilar(&dada));
        cuenta++;
    }

    /// paso a dada otra vez

    while(!pilavacia(&aux1))
    {
        apilar(&dada, desapilar(&aux1));
    }


    int control = cuenta/2;

    int aux=0;

    /// paso la mitad a aux1
    while(aux<control)
    {
        apilar(&aux1, desapilar(&dada));
        aux++;
    }

    /// verifico q la pila sea impar,
    /// si es asi... saco el valor que sobra
    if(cuenta%2!=0)
        apilar(&aux2, desapilar(&dada));

    // comparo los topes para constatar q sea capicua...
    // en dada me queda el resto de los elementos
    // en el mismo orden que en aux1
    while((!pilavacia(&dada)&&!pilavacia(&aux1))&&(tope(&dada)==tope(&aux1)))
    {
        apilar(&aux3, desapilar(&dada));
        apilar(&aux3, desapilar(&aux1));
    }

    if (pilavacia(&dada)&&pilavacia(&aux1))
       printf("La pila es capicua\n");
    else
        printf("La pila no es capicua\n");


////////////////////////////////////////////////////////////////
// VERSION MAS TRANQUI
// aqui lo que hacemos es crear una "copia" de la pila a evaluar
// pero de manera invertida... y luego comparamos los topes
// igual que al final de la funcion anterior..
////////////////////////////////////////////////////////////////


    // apilamos elementos para provar su "capicues" :p

    //apilar(&dada, 1);
    apilar(&dada, 2);
    apilar(&dada, 2);
    apilar(&dada, 3);
    apilar(&dada, 2);
    apilar(&dada, 1);

    mostrar(&dada);

    Pila copiaInvertida;
    inicpila(&copiaInvertida);

    Pila auxi;
    inicpila(&auxi);

    while(!pilavacia(&dada))
    {
        /// con esto copiamos el valor del tope de dada
        /// en la otra pila
        apilar(&copiaInvertida,tope(&dada));
        /// luego lo desapilamos en una pila auxiliar
        /// para ver lo que "hay abajo"
        apilar(&auxi, desapilar(&dada));
    }

    // ahora pasamos otra vez todo a dada
    while(!pilavacia(&auxi))
    {
        apilar(&dada, desapilar(&auxi));
    }

    // ahora tenemos la data en las dos pilas
    // y podemos empezar a evaluar si es capicua..

    while((!pilavacia(&dada)&&!pilavacia(&copiaInvertida))&&(tope(&dada)==tope(&copiaInvertida)))
    {
        apilar(&auxi, desapilar(&dada));
        apilar(&auxi, desapilar(&copiaInvertida));
    }

// si las dos pilas se vaciaron... significa que las pilas
// eran iguales, por ende, dada es capicua

    if (pilavacia(&dada)&&pilavacia(&copiaInvertida))
        printf("La pila es capicua\n");
    else
        printf("La pila no es capicua\n");

    return 0;
}
