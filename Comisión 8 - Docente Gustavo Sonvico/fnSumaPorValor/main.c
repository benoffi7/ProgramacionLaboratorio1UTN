#include <stdio.h>
#include <stdlib.h>

void intercambio(int *, int *);


int main()
{
    int a=2;

//    printf("La direccion de memoria de la variable a es %p y su contenido es %d \n", &a, a);
//
//    system("pause");
//
//    int * pA=NULL;
//
//    pA=&a;  /// le asigno a quien va a apuntar
//
//    printf("La direccion de memoria que almacena la variable pA es %p y el contenido \n de la varibale a la que apunta es %d \n", pA, *pA);
//
//    *pA=200;  /// modifico el valor de la variable a la que apunta pA
//
//    system("pause");
//
//    printf("La direccion de memoria de la variable a es %p y su contenido es %d \n", &a, a);
//
//    system("pause");


    printf("Hello world!\n");

    int p=10, q=20;

    printf("En el main antes de llamar a la fn: p=%d q=%d\n\n", p, q);

    system("pause");

    intercambio(&p,&q);  ///intercambio(int * a=&p, int * b= &q);

    printf("En el main despues de llamar a la fn: p=%d q=%d\n\n", p, q);

    return 0;
}

void intercambio(int * a, int * b)
{

    int aux = *a;

    *a=*b;

    *b=aux;

    printf("En la fn *a=%d *b=%d aux=%d\n", *a, *b, aux);

    system("pause");
}
