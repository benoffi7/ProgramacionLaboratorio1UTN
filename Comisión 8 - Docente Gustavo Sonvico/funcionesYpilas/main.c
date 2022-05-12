#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

void cargarPila(Pila * p)
{
    int i;

    for(i=0; i<10; i++)
    {
        apilar(p, rand()%10);
    }
}

void pasarPila(Pila * origen, Pila * destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}

/*
10- Hacer una funci�n que reciba una pila con n�meros de un solo
 d�gito (es responsabilidad de quien usa el programa) y que
 transforme esos d�gitos en un n�mero decimal. Por ejemplo, la pila: 14675

*/

int devuelveValorDecimal(Pila copia)
{
    Pila aux;
    inicpila(&aux);

    float nroDecimal=0;
    int multiplicador=1;
    int auxTope=0;

    /// invierto la pila original
    pasarPila(&copia, &aux);

    while(!pilavacia(&aux))
    {
        auxTope=desapilar(&aux);

        auxTope=auxTope*multiplicador;

        nroDecimal=nroDecimal+auxTope;

        multiplicador=multiplicador*10;
    }
    return nroDecimal;
}

int main()
{
    srand(time(NULL));

    Pila pilita, pilota;

    inicpila(&pilita);
    inicpila(&pilota);

    cargarPila(&pilita);
//   cargarPila(&pilota);


    puts("desde el main pilita");
    mostrar(&pilita);

    int valorDecimal = devuelveValorDecimal(pilita);

    printf("El valor decimal es %d\n", valorDecimal);

    system("pause");

    pasarPila(&pilita, &pilota);

    puts("desde el main pilita");
    mostrar(&pilita);

    puts("desde el main pilota");
    mostrar(&pilota);
    return 0;
}
