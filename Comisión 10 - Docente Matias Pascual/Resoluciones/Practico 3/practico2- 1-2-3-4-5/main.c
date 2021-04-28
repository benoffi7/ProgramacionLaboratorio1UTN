#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*1. Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el
usuario.*/

int sumar (Pila pepe)
{
    Pila aux;
    inicpila(&aux);

    int suma=0;

    while(!pilavacia(&pepe))
    {
        suma = suma + tope(&pepe);

        apilar(&aux, desapilar(&pepe));
    }

    return suma;
}

void leerMuchos (Pila * pila)
{
    char letra='n';

    printf("Desea cargar un elemento? Ingrese s= si o n= no...\n");
    fflush(stdin);
    scanf("%c", &letra);

    while (letra=='s')
    {
        leer(pila);
        printf("Desea cargar un elemento? Ingrese s= si o n= no...\n");
        fflush(stdin);
        scanf("%c",&letra);
    }
}

// otra forma si variables..
void leerOtro (Pila *pila)
{
    Pila aux;
    inicpila(&aux);
    printf("Ingrese un elemento, si desea terminar ingrese 0 (cero) \n");
    while(tope(pila)!=0)
    {
        leer(pila);
    }
    apilar(&aux,desapilar(pila));
}


/*2. Hacer una función que pase todos los elementos de una pila a otra.*/

void pasarPila (Pila *origen, Pila *destino)
{
    while (!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}

/*3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el
orden.*/

void pasarOrdenado (Pila *origen, Pila *destino)
{
    Pila aux;
    inicpila(&aux);
    pasarPila(origen, &aux);
    pasarPila(&aux, destino);
}

/*4. Hacer una función que encuentre el menor elemento de una pila y lo retorne*/

int devuelveMenor (Pila *dada)
{
    Pila aux, menor;
    inicpila(&aux);
    inicpila(&menor);

    // ojo al invocar esta funcion!!!!
    // se debe verificar que la pila dada no este vacia
    // antes de invocarla
        apilar(&menor, desapilar(dada));

        while(!pilavacia(dada))
        {
            if (tope(dada)<tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(dada));
            }
            else
                apilar(&aux, desapilar(dada));
        }
        pasarPila(&aux, dada);

    return tope(&menor);
}

/*5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
nueva pila ordenada. Usar la función del ejercicio 4 */

void pasarPilaOrdenada(Pila * origen, Pila *destino)
{
    Pila orden;
    inicpila(&orden);
    while (!pilavacia(origen))
    {
        apilar(&orden, devuelveMenor(origen));
    }
    pasarPila(&orden, destino);
}

/* Comente el codigo para que no me molesten los resultados de los ejercicios anteriores ... */

int main()
{
    Pila p;

    inicpila(&p);

    leerMuchos(&p);

    // printf("\n Ejercicio 1\n");

   // leerOtro(&p);
    mostrar(&p);

    /*  printf("\n Ejercicio 2\n");

      Pila destination;
      inicpila(&destination);
      pasarPila(&p, &destination);
      printf("\nPila p\n");
      mostrar(&p);
      printf("\nPila destination\n");
      mostrar(&destination);

      printf("\n Ejercicio 3\n");

      pasarOrdenado(&destination, &p);

      printf("\nPila destination (ahora la uso como origen)\n");
      mostrar(&destination);
      printf("\nPila p (ahora es el destino)\n");
      mostrar(&p);
    */

    /*   printf("Ejercicio 4\n\n");

       printf("El menor elemento de la pila es: %d \n", devuelveMenor(&p));

       printf("Los elementos restantes son: \n");*/

    /* printf("Ejercicio 5\n\n");

     Pila destino;
     inicpila(&destino);

     pasarPilaOrdenada(&p, &destino);

     mostrar(&p);
     mostrar(&destino);*/






    return 0;
}
