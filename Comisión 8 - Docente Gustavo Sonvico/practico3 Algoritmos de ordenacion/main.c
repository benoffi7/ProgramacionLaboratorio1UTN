#include <stdio.h>
#include <stdlib.h>
#include "../pila.h"


void leerMuchos (Pila *);
void pasarPila (Pila *, Pila *);
void pasarOrdenado (Pila *, Pila *);
int devuelveMenor (Pila *);
void pasarPilaOrdenada(Pila *, Pila *);
void insertaEnOrden (Pila *, Pila *);
void insertarPilaEnOtraPilaOrdenada (Pila *, Pila *);
int sumaTopeyAnterior (Pila);

int main()
{

    /* Comente el codigo para que no me molesten los resultados de los ejercicios anteriores ... */
    /// vayan construyendo el main para probar el funcionamiento de los modulos
    /// aqui le dejo las invocaciones a cada fn
    /* Pila p;

     inicpila(&p);

     leerMuchos(&p);

       printf("\n Ejercicio 1\n");

       leerOtro(&p);
       mostrar(&p);

       printf("\n Ejercicio 2\n");

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


       printf("Ejercicio 4\n\n");

       printf("El menor elemento de la pila es: %d \n", devuelveMenor(&p));

       printf("Los elementos restantes son: \n");

       printf("Ejercicio 5\n\n");

     Pila destino;
     inicpila(&destino);

     pasarPilaOrdenada(&p, &destino);

     mostrar(&p);
     mostrar(&destino);

     ///

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

     ///

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

     */


    return 0;
}

/*1. Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el
usuario.*/
void leerMuchos (Pila * ppila)
{
    char letra='n';

    printf("Desea cargar un elemento? Ingrese s= si o n= no...\n");
    fflush(stdin);
    scanf("%c", &letra);

    while (letra=='s')
    {
        leer(ppila);
        printf("Desea cargar un elemento? Ingrese s= si o n= no...\n");
        fflush(stdin);
        scanf("%c",&letra);
    }
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

    /// ojo al invocar esta funcion!!!!
    /// se debe verificar que la pila dada no este vacia
    /// antes de invocarla

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
    int menor;
    while (!pilavacia(origen))
    {
        menor=devuelveMenor(origen);
        apilar(destino, menor);
    }
}

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

/* 8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y
anterior), sin alterar su contenido.*/
int sumaTopeyAnterior (Pila dada)
{
    /// comentamos las lineas para hacer mas eficiente el algoritmo
///    Pila aux;
///    inicpila(&aux);
    int contador = 0;
    int respuesta = 0;

    while(!pilavacia(&dada)&&contador<2)
    {

        respuesta += desapilar(&dada);
        ///respuesta = respuesta + tope(&dada);
        /// apilar(&aux, desapilar(&dada));
        ///   contador++;
    }
    return respuesta;
}
