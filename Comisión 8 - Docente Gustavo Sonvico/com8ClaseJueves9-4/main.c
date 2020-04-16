#include <stdio.h>
#include <stdlib.h>

/// prototipado de funciones
void saludo ();

void imprimeEntero(int);

int suma(int, int );

void intercambio(int * a, int * b);

int main( )
{
    int unDato;

    printf("Hello world de funciones!\n");
    system("pause");

    saludo(); /// invocacion a la funcion

    printf("Ingrese un valor entero: ");
    scanf("%d", &unDato);

    imprimeEntero(unDato);
system("pause");
    int a=3;
    int b=8;

    int resultado = 0;

    resultado= suma(a, b);

    printf("La suma de %d mas %d es igual a %d\n",a,b,resultado);

    system("pause");
    int p=10,q=20;
    printf("p=%d q=%d\n",p,q);
    system("pause");

    intercambio(&p ,&q);
    system("pause");

    printf("p=%d q=%d\n",p,q);
    system("pause");

    a=2;

    printf("La posicion de memoria de a es %p y su contenido es %d\n", &a, a);

    int * pA=&a;

    printf("p contine %p\n", p);
system("pause");

    int x;
    printf("x sin inicializar %d\n", x);
    system("pause");

    int * pX=NULL;
    printf("p  %p\n", pX);
    system("pause");

    pX=&x;

    printf("p con asignacion  %p\n", pX);
    system("pause");

    x=10;
    printf("x %d\n", x);
    system("pause");

    *pX=20;

    printf("x %d\n", x);
    system("pause");

    printf("p  %p\n", pX);
    system("pause");
    printf("Fin del programa\n");

    return 0;
}

void saludo ( )
{
    printf("Estoy saludando desde la funcion\n");
    system("pause");
    printf("Chau desde la funcion \n");
    system("pause");

}

void imprimeEntero(int x)
{

    printf("Desde la funcion muestro el valor %d\n", x);

}

int suma(int x, int y)
{
    int respuesta=0;

    respuesta= x + y;

    return respuesta;
}

void intercambio(int * a, int * b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    printf("* a=%d * b=%d temp=%d\n",*a,*b,temp);

}

