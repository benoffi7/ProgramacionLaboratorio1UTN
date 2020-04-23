#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"
#include "fPila.h"

int main()
{
    srand(time(NULL));
    Pila dada, otra, auxDada, desordenada;
    inicpila(&dada);
    inicpila(&otra);
    inicpila(&auxDada);
    inicpila(&desordenada);

    float promedio;
    printf("\n\n Direccion de memoria de la pila dada %p\n\n",&dada);

/**
    cargaPila(&dada,"Ingrese una temperatura");
    cargaPilaRandom(&otra,25);
    printf("\n\n Mostrando Temperaturas ");
    mostrar(&dada);
    system("pause");

    pasaPila(&dada,&auxDada);
    printf("\n\n Mostrando pila dada ");
    mostrar(&dada);
    printf("\n\n Mostrando pila auxDada ");
    mostrar(&auxDada);
    system("pause");

    copiaPila(auxDada, &dada);
    printf("\n\n Mostrando pila dada ");
    mostrar(&dada);
    printf("\n\n Mostrando pila auxDada ");
    mostrar(&auxDada);

    cargaPila(&otra, "Ingrese otra cosa");

    printf("\n\n Mostrando pila otra ");
    mostrar(&otra);
*/
    cargaPilaRandom(&dada,10, 1,9);
    pilaFibonacci(&otra, 15);
    printf("\n Pila otra ..........\n");
    mostrar(&otra);
    system("pause");

   // printf("----%d-----",desapilar(&dada));
    system("pause");
    copiaPila(dada, &auxDada);

    promedio = promedioPila(dada);
    printf("\n El promedio de los elementos de la pila dada es: %.2f\n", promedio);

    printf("\n La suma del tope y el segundo elemento es: %d", sumaTopeyAnterior(dada));
    printf("\n La suma del tope hasta la varible limite.: %d", sumaTopeHastaLimite(dada,4));
    printf("\n Convierto la pila a un numero decimal....: %d", pila2decimal(dada));


    printf("\n Pila desordenada ..........\n");
    mostrar(&dada);
    system("pause");

    ordenaPorSeleccion(&dada);
    printf("\n Pila dada ORDENADA por Seleccion ..........\n");
    mostrar(&dada);

    vaciarPila(&dada);
    pasaPila(&auxDada, &dada);
    ordenaPorInsercion(&dada);
    printf("\n Pila dada ORDENADA por Insercion ..........\n");
    mostrar(&dada);


    return 0;
}

void muestraMenu(){
    printf("\n\t\t TITULO\n");
    printf("\n\n 1. Ejercicio 1");
    printf("\n\n 2. Ejercicio 2");
    printf("\n\n 3. Ejercicio 3");
    printf("\n\n 4. Ejercicio 4");
    printf("\n\n 5. Ejercicio 5");

    printf("\n\t ESC para salir .....");
}
