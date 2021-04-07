#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

int main()
{
    Pila MODELO;
    Pila AUX1;
    Pila AUX2;
    Pila DADA;
    int cant;
    int descarte;

    inicpila(&MODELO);
    inicpila(&AUX1);
    inicpila(&AUX2);
    inicpila(&DADA);


    srand(time(NULL));
    cant = rand() % 51; ///cantidad de datos que voy a ingresar en la pila

    ///ojo que la maxima cantidad de valores que puede haber en la pila es 50
    ///CARGA DE DADA
    for (int i=1; i<=cant; i++)
    {
        apilar(&DADA, (rand() % 11));
    }
    mostrar(&DADA);

    ///CARGA DE MODELO
    cant = rand() % 51;
    for (int = 1; i<= cant; i++)
    {
        apilar(&MODELO, (rand() %11));
    }


//CARGA POR EL USUARIO
//    printf("PILA MODELO\n");
//    do
//    {
//        leer(&MODELO);
//        printf("desea cargar otro valor S/N\n");
//        fflush(stdin);
//        scanf("%c",&seguir);
//    }
//    while(seguir == 's');
//
//    printf("PILA DADA\n");
//    do
//    {
//        leer(&DADA);
//        printf("desea cargar otro valor S/N\n");
//        fflush(stdin);
//        scanf("%c",&seguir);
//    }
//    while(seguir == 's');

//CARGA BRUTA POR EL PROGRAMADOR
//    apilar(&MODELO,3);
//    apilar(&MODELO,5);
//    apilar(&MODELO,7);
//    apilar(&MODELO,1);
//
//    apilar(&DADA,2);
//    apilar(&DADA,1);
//    apilar(&DADA,3);
//    apilar(&DADA,7);


//    ///cargar con valores random generados por una funcion matematica
//    int numero;
//    srand(time(NULL));
//    numero = (rand() % 122);  ///yo acoto los valores del rand() a un rango de 0 a 121.
//    printf("%i", numero);


    return 0;
}

