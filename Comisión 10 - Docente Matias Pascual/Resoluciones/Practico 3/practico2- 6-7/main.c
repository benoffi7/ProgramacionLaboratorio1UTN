#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


/*6. Hacer una función que inserte en una pila ordenada un nuevo elemento, conservando el orden...?? */
void insertaEnOrden (Pila *dada, Pila *dato)
{
    Pila aux;
    inicpila(&aux);

    while ((!pilavacia(dada)) && (tope(dato)<tope(dada)))
    {
        apilar(&aux, desapilar(dada));
    }
    apilar(dada, desapilar(dato));

    while (!pilavacia(&aux))
    {
        apilar(dada, desapilar(&aux));
    }
}
/*7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
nueva pila ordenada. Usar la función del ejercicio 6.*/

void insertarPilaEnOtraPilaOrdenada (Pila *dada, Pila *datos)
{
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(datos))
    {
        apilar(&aux, desapilar(datos));
        insertaEnOrden(dada, &aux);
    }
}


int main()
{
    Pila dada, dato;
    inicpila(&dada);
    inicpila(&dato);

   apilar(&dada, 1);
    apilar(&dada, 3);
    apilar(&dada, 5);
    apilar(&dada, 7);
    apilar(&dada, 9);
    apilar(&dada, 11);

    printf("Ejercicio 6\n");
    printf("Pila dada\n");
    mostrar(&dada);

    leer(&dato);

    insertaEnOrden(&dada, &dato);

    printf("Pila dada ahora\n");
    mostrar(&dada);

    printf("Ejercicio 7\n");

    Pila datos;
    inicpila(&datos);


    leer(&datos);
    leer(&datos);
    leer(&datos);
    leer(&datos);
    leer(&datos);
    leer(&datos);

    printf("Pila de datos a insertar en dada\n");
    mostrar(&datos);

    insertarPilaEnOtraPilaOrdenada(&dada, &datos);

    printf("Pila dada ahora\n");
    mostrar(&dada);

    return 0;
}
