#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

void muestra();
int mostrarResultado(int, int);
void cargaPila (Pila*);

int main()
{
    int res;
    Pila origen;
    inicpila(&origen);

    cargaPila(&origen);

    mostrar(&origen);
    /*int a, b;

    a=40;
    b=40;

    res= mostrarResultado(a,b);

    printf("Variable a: %d Variable b: %d",a,b);
*/
    return 0;
}

void muestra()
{
    int i;
    for (i=0;i<10;i++)
        printf("\n%d",i+1);
}

int mostrarResultado(int num1, int num2)
{
    int op,resultado=0;
    printf("Si desea sumar los numeros presione 1, o presione 2 para restarlos");
    scanf("%d",&op);
    if (op==1)
        resultado = num1+num2;
    else
    {
        if (op==2)
            resultado=num1-num2;
        else
            printf("Opcion incorrecta");
    }

    num1 = 80;
    num2 = 80; ///Al estar modificando una copia, el cambio no tendrá efectos sobre la variable original

    return resultado;
}

void cargaPila(Pila * dada)
{
    char control = 's';

    while (control=='s')
    {
        printf("\n");
        leer(dada); ///No necesito usar "&" dado que dada ya es un puntero

        printf("Presione s para seguir ingresando");
        fflush(stdin);
        scanf("%c",&control);

    }
}
