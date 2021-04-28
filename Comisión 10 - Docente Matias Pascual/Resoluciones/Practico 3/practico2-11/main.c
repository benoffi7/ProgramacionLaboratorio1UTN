#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"

/*11. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de
quien usa el programa) y que transforme esos dígitos en un número decimal. Por ejemplo, la
pila:

1     Debe retornar el número: 14675
4
6
7
5   */

int funcionLoca (Pila dada)
{
    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);

    int decimal = 0;
    int multiplicador = 1;

    while (!pilavacia(&dada))
    {
        apilar(&aux, desapilar(&dada));
    }

    while (!pilavacia(&aux))
    {

        decimal = decimal + (tope(&aux)* multiplicador);
        apilar(&aux2, desapilar(&aux));
        multiplicador = multiplicador * 10;
    }

    return decimal;

}

int main()
{
    Pila pilita;
    inicpila(&pilita);
    leer(&pilita);
    leer(&pilita);
    leer(&pilita);
    leer(&pilita);
    leer(&pilita);

    mostrar(&pilita);

    int aux = funcionLoca(pilita);

    printf("Numero decimal %d\n", aux);
    return 0;
}
