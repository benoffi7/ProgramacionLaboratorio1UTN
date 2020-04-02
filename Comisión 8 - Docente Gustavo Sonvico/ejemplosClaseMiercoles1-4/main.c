#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main()
{
    /// ejercicio 3
    Pila dada, iguales, distintos;
    inicpila(&dada);
    inicpila(&iguales);
    inicpila(&distintos);

    char control;

    do
    {
        leer(&dada);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        printf("%c", control = getch());
        printf("\n");
    }
    while(control == 's');


    while(!pilavacia(&dada))
    {
        if(tope(&dada)!=8)
        {
            apilar(&distintos, desapilar(&dada));
        }
        else
        {
            apilar(&iguales, desapilar(&dada));
        }
    }

    while(!pilavacia(&distintos))
    {
        apilar(&dada, desapilar(&distintos));
    }

    mostrar(&dada);

    printf(".:EJERCICIO 6:.\n");
    printf("Pasar el primer elemento (tope) de la pila DADA a su ultima posicion (base),\ndejando los restantes elementos en el mismo orden\n\n");

    Pila dada6, aux6, top;
    inicpila(&dada6);
    inicpila(&aux6);
    inicpila(&top);

    char cont4;

    do
    {
        leer(&dada6);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &cont4);
        //printf("%c", cont4 = getch());
        printf("\n");
    }
    while(cont4 == 's');

    system("cls");
    printf("Pila DADA cargada");
    mostrar(&dada6);
    system("pause");

    if(!pilavacia(&dada6))
    {
        apilar(&top, desapilar(&dada6));
    }

    while(!pilavacia(&dada6))
    {
        apilar(&aux6, desapilar(&dada6));
    }

    if(!pilavacia(&top))
    {
        apilar(&dada6, desapilar(&top));
    }

    while(!pilavacia(&aux6))
    {
        apilar(&dada6, desapilar(&aux6));
    }
    printf("DADA con el tope como base\n");
    mostrar(&dada6);

    system("pause");

    printf(".:EJERCICIO 7:.\n");
    printf("Pasar el ultimo elemento (base) de la pila DADA a su primera\nposicion (tope), dejando los restantes elementos en el mismo orden\n\n");

    Pila dada7, base, aux7;
    inicpila(&dada7);
    inicpila(&base);
    inicpila(&aux7);

    do
    {
        leer(&dada7);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        printf("%c", cont4 = getch());
        printf("\n");
    }
    while(cont4 == 's');

    system("cls");
    printf("DADA cargada\n");
    mostrar(&dada7);

    while(!pilavacia(&dada7))
    {
        apilar(&aux7, desapilar(&dada7));
    }
    if(!pilavacia(&aux7))
    {
        apilar(&base, desapilar(&aux7));
    }

    while(!pilavacia(&aux7))
    {
        apilar(&dada7, desapilar(&aux7));
    }

    if(!pilavacia(&base))
    {
        apilar(&dada7, desapilar(&base));
    }
    system("pause");
    printf("\nDADA con su base como tope\n");
    mostrar(&dada7);

    system("pause");

    printf(".:EJERCICIO 8:.\n");
    printf("Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa\n\n");

    Pila mazo, jug1, jug2;
    inicpila(&mazo);
    inicpila(&jug1);
    inicpila(&jug2);


    /// rutina de carga random

    srand(time(NULL)); ///inicializo la semilla

    int cant = rand()%40; ///el random va de 0 a 39;

    cant++; ///le sumo para que minimo valga 1 y maximo valga 40;
    int  i;

    printf("Se cargaran %i elementos en el mazo\n", cant);

    for(i = 0; i<cant; i++) ///va a cargar minimo 1 elemento en la pila y como maximo 40
    {
        apilar(&mazo, (rand()%100) + 1); ///apilo valores aleatorios de 1 a 100 inclusive
    }
    /// fin de rutina de carga random

    ///si quiero cargar datos con intervencion del usuario, uso el ciclo de carga normal
    /*do{
        leer(&mazo);
        printf("Desea continuar? s/n: ");
        fflush(stdin);
        //scanf("%c", &cont4);
        printf("%c", cont4 = getch());
        printf("\n");
    }while(cont4 == 's');*/


    system("pause");
    system("cls");
    printf("Repartiendo...\n\n");

    while(!pilavacia(&mazo))
    {
        apilar(&jug1, desapilar(&mazo));
        if(!pilavacia(&mazo))
        {
            apilar(&jug2, desapilar(&mazo));
        }
    }


    system("pause");
    printf("\n\nListo!\n");
    system("pause");

    system("cls");
    printf("Cartas del jugador 1\n");
    mostrar(&jug1);
    printf("\nCartas del jugador 2\n");
    mostrar(&jug2);
    system("pause");

    printf(".:EJERCICIO 10:.\n");
    printf("Comparar las pilas A y B. Mostrar por pantalla el resultado\n\n");

    Pila A10, B10, auxA10, auxB10;
    inicpila(&A10);
    inicpila(&B10);
    inicpila(&auxA10);
    inicpila(&auxB10);

    printf("Cargando pila A\n");
    do
    {
        leer(&A10);
        printf("\nDesea continuar? s/n ");
        printf("%c", cont4 = getch());
        printf("\n");
    }
    while(cont4 == 's');

    system("pause");
    printf("\nCargando pila B\n");
    do
    {
        leer(&B10);
        printf("\nDesea continuar? s/n ");
        printf("%c", cont4 = getch());
        printf("\n");
    }
    while(cont4 == 's');
    system("cls");

    while(!pilavacia(&A10) && !pilavacia(&B10) && tope(&A10)==tope(&B10))
    {
        apilar(&auxA10, desapilar(&A10));
        apilar(&auxB10, desapilar(&B10));
    }

    printf("Procesando...\n");
    system("pause");
    printf("\nListo...\n");
    system("pause");
    system("cls");

    if(pilavacia(&A10) && pilavacia(&B10))
    {
        printf("\nLas pilas SON identicas\n");
    }
    else
    {
        printf("\nLas pilas NO son iguales\n");
    }


    printf(".:EJERCICIO 11:.\n\n");
    printf("Suponiendo la existencia de una pila MODELO que no este vacia, eliminar\nde la pila DADA todos los elementos que sean iguales al tope de la pila MODELO\n\n");

    Pila dada11, modelo11, aux11, descarte11, auxModelo;
    inicpila(&dada11);
    inicpila(&modelo11);
    inicpila(&aux11);
    inicpila(&descarte11);
    inicpila(&auxModelo);


    printf("Cargando pila DADA\n");
    do
    {
        leer(&dada11);
        printf("Desea continuar? s/n ");
        printf("%c", cont4 = getch());
        printf("\n");
    }
    while(cont4 == 's');

    system("cls");
    printf("Cargando pila MODELO\n");
    do
    {
        leer(&modelo11);
        printf("\nDesea continuar? s/n ");
        printf("%c", cont4 = getch());
        printf("\n");
    }
    while(cont4 == 's');

    printf("Asi quedo cargada DADA\n");
    mostrar(&dada11);

    printf("\n\nNOTA: se van a eliminar de dada el tope de modelo que es: %i\n\n", tope(&modelo11));
    system("pause");
    system("cls");



    while (!pilavacia(&modelo11))
    {
        /// ejercicio 11
        while(!pilavacia(&dada11))
        {
            if(tope(&dada11) == tope(&modelo11))
            {
                apilar(&descarte11, desapilar(&dada11));
            }
            else
            {
                apilar(&aux11, desapilar(&dada11));
            }
        }

        while(!pilavacia(&aux11))
        {
            apilar(&dada11, desapilar(&aux11));
        }
        /// fin ejercicio 11

        apilar(&auxModelo, desapilar(&modelo11));

    }

    while(!pilavacia(&auxModelo))
    {
        apilar(&modelo11, desapilar(&auxModelo));
    }

    printf("DADA con los elementos eliminados\n");
    mostrar(&dada11);

    system("pause");

    return 0;
}
