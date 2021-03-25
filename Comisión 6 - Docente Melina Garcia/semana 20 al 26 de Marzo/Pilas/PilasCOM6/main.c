#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila mipila; ///creo la pila
    int var1;
    int numero;
    inicpila(&mipila);  //la inicializo (lista para usar)
    apilar(&mipila, 3); ///inserto un 3 en la pila
    apilar(&mipila,5);
    apilar(&mipila,9);
    leer(&mipila); ///muestra un texto y pide ingresar un valor
    var1=desapilar(&mipila); ///retira el valor que esta en tope
    printf("El tope de la pila tiene %i", );
   /// un reemplazo a la funcion leer(&mipila)
//    printf("Ingrese un valor entero \n");
//    scanf("%i", &numero);
//    apilar(&mipila,numero);


    Pila variable ///creando una pila

    ///FUNCIONES PARA TRABAJAR CON MI PILA

    ///debo poner la pila lista para usar
    inicpila(&mipila);

    ///apilar un valor en la pila
    apilar(&mipila,3);

    ///leer un valor por el usuario desde la consola
    leer(&mipila);

    ///desapilar un valor de la pila
    var1=desapilar(&mipila);
    ///nos tira un valor que debemos agarrarlo con alguna variable, o simplemente mostrarlo en un printf

    ///funcion que nos permite obtener una fotocopia (copia) del elemento que esta en el tope de la pila
    var1=tope(&mipila);
    ///NO LO DESAPILA, lo devuelve por lo tanto debemos agarrarlo con una variable o usar printf.

    ///una funcion que me permite saber si mi pila tiene datos aun
    pilavacia(&mipila); /// 1: esta vacia o 0: no esta vacia

    ///una funcion que me permite ver todos los elementos de la pila ingresados (por consola)
    mostrar(&mipila);





    return 0;
}
