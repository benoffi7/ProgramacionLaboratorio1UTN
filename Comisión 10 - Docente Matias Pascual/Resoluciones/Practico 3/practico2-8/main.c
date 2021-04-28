#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

/* 8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y
anterior), sin alterar su contenido.*/

int sumaTopeyAnterior (Pila dada)
{
    Pila aux;
    inicpila(&aux);
    int contador = 0;
    int respuesta = 0;
    while(!pilavacia(&dada)&&contador<2)
    {
        respuesta = respuesta + tope(&dada);
        apilar(&aux, desapilar(&dada));
        contador++;
    }
    return respuesta;
}

int main()
{
    Pila dada;
    inicpila(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);
    leer(&dada);

    mostrar(&dada);

    // paso los datos de la pila por valor... tonces no modifica la pila...
    int res = sumaTopeyAnterior(dada);

    mostrar(&dada);

    printf("El resultado de la suma del tope y el anterior es %d\n", res);
    return 0;
}
