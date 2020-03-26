#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void ejercicio1();
void ejercicio2();
void ejercicio3();
void salida();

int main()
{

    int op = 0;

    do
    {
        printf ("GUIA NUMERO 1: Pilas \n");
        printf ("Ingrese el numero del ejercicio que desee ejecutar. Para salir, ingrese el numero 15\n");
        scanf ("%i", &op);

        switch (op)
        {
        case 1:
            ejercicio1();
            break;
        case 2:
            ejercicio2();
            break;

        case 3:
            ejercicio3();
            break;
        case 15:
            salida ();
            break;
        }

    }
    while (op < 15);

    return 0;
}

void ejercicio1()
{
    Pila dada,aux,aux1 ;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&aux1);

    for (int i=1; i <= 5 ; i++)
    {
        leer (&dada);
    }
    for (int i=1; i <= 2 ; i++)
    {
        apilar (&aux, desapilar (&dada));
    }
    while (!pilavacia(&dada))
    {
        apilar (&aux1, desapilar(&dada));
    }
    printf ("\n");
    printf ("Como quedo la pila DADA \n");
    mostrar (&dada);
    printf ("Como quedo la pilaAUX \n");
    mostrar (&aux);
    printf ("Como quedo la pila AUX1 \n");
    mostrar(&aux1);

    printf("\n");
    system ("pause");
    system ("cls");


}

void ejercicio2()
{
    Pila origen,destino;

    inicpila(&origen);
    inicpila(&destino);

    for (int i = 1; i <=5 ; i++)
    {
        leer(&origen);
    }

    printf ("Pila ORIGEN hasta el momento \n");

    mostrar(&origen);

    apilar(&destino, desapilar(&origen));

    printf ("Pila ORIGEN ahora mismo \n");

    mostrar(&origen);

    printf ("Y esta es la pila destino... \n");
    mostrar(&destino);



    printf("\n");
    system ("pause");
    system ("cls");
}

void ejercicio3()
{
    Pila origen,destino,descarte ;


    inicpila(&origen);
    inicpila(&destino);
    inicpila(&descarte);

    for (int i=1; i<=10 ; i++)
    {
        leer(&origen);
    }

    while (!pilavacia(&origen))
    {
        if (tope (&origen)!=8)
        {
            apilar (&destino,desapilar (&origen));
        }
        else
        {
            apilar (&descarte,desapilar(&origen));
        }
    }
    printf ("Pila ORIGEN \n");
    mostrar(&origen);
    printf ("Pila DESTINO \n");
    mostrar(&destino);
    printf ("Pila DESCARTE \n");
    mostrar(&descarte);

    printf("\n");
    system ("pause");
    system ("cls");

}










void salida()
{
    printf ("Hasta luego ! :)\n");
}
