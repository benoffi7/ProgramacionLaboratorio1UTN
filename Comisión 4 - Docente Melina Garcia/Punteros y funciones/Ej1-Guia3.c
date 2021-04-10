#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///1. Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el usuario

///prototipado
void cargaPila(Pila*); /// funcion que carga una pila hasta que quiera el usuario
int suma(Pila);

int main()
{
    Pila a;
    Pila b;
    int resultado;
    inicpila(&a);
    //inicpila(&b);


    /////
    cargaPila(&a); // cargaPila(0x44);
    //cargaPila(&b);
    resultado = suma(a);
    mostrar(&a);
    printf("La suma es %i\n", resultado);
    return 0;
}


int suma(Pila p)
{
    int sum = 0;
    while (!pilavacia(&p))
    {
        sum = sum + desapilar(&p);
    }

    return sum;
}


void cargaPila(Pila* p)// p = 0x44 /// p = &a
{
    char continuar;
    do
    {
        leer(p); ///leer(&a)
        printf("desea seguir?s/n \n");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    while(continuar == 's');
}


Pila* crearYCargar()
{
    Pila p;/// &p 0x23
    inicpila(&p);

    return &p;
}

