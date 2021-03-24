#include <stdio.h>
#include <stdlib.h>
/**
--------- Algoritmo que ayuda a crear algoritmos -----------
1.	Detectar variables a utilizar
    a.	Datos que me da el problema
    b.	Datos que le pido al usuario
    c.	Datos que necesito para hacer cálculos y guardar resultados
    d.	Iniciar variables.

2.	Interactuar con el usuario
3.	Realizar tareas o cálculos
4.	Le muestro resultados
*/


/**
Leer 2 números; si son iguales que los multiplique, si el primero es mayor que el segundo que los reste y si no que los sume.
*/
int main()
{
    int n1 = 0;
    int n2 = 0;
    int total = 0;
    char op;

    printf("\n Ingrese dos numeros: ");
    scanf("%d", &n1);
    scanf("%d", &n2);
/*
    if(n1 == n2)
    {
        total = n1 * n2;
        op = 'x';
    }
    else
    {
        if(n1 > n2)
        {
            total = n1 - n2;
            op = '-';
        }
        else
        {
            total = n1 + n2;
            op = '+';
        }
    }
*/
    if(n1 == n2)
    {
        total = n1 * n2;
        op = 'x';
    }
    else if(n1 > n2)
        {
            total = n1 - n2;
            op = '-';
        }
        else
        {
            total = n1 + n2;
            op = '+';
        }
    }

    printf("\n El resultado de %d %c %d = %d", n1, op, n2, total);
    return 0;
}
