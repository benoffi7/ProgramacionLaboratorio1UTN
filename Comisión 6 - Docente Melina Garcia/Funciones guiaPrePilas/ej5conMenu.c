#include <stdio.h>
#include <stdlib.h>

/**
Realice una pequeña calculadora, utilizando funciones
(una función de suma, una de multiplicación, una de resta, una de división…)
**/

///prototipados
int suma(int,int);
int resta(int,int);
int multiplicacion(int,int);
float division(int,int);



int main()
{
    int operandoizq;
    int operandoder;
    int opcion;
    float resultado;
    char seguir;
    printf("Bienvenido a la calculadora de enteros de utn\n");

    do
    {
        printf("ingrese operando izquierda: ");
        scanf("%i",&operandoizq);
        printf("\ningrese operando derecha: ");
        scanf("%i",&operandoder);
        do
        {
            printf("Elija una opcion....\n");
            printf("1. Suma\n");
            printf("2. Resta\n");
            printf("3. Multiplicacion\n");
            printf("4. Division\n");
            scanf("%i",&opcion);
            if (opcion < 1 || opcion > 4)
            {
                printf("Ingresaste una opcion incorrecta\n");
                system("pause"); ///espera a que se ingrese una tecla
                system("cls"); ///limpia las letras de la consola
            }
        }
        while (opcion < 1 || opcion > 4);
        //la sentencia switch CASO 1 CASO 2 ... solo acepta enteros
        switch(opcion)
        {
        case 1:
            resultado = suma(operandoizq,operandoder);
            break;
        case 2:
            resultado = resta(operandoizq,operandoder);
            break;
        case 3:
            resultado = multiplicacion(operandoizq,operandoder);
            break;
        case 4:
            if (operandoder == 0)
            {
                printf("que haces, no podes dividir por 0\n");
            }
            else
            {
                resultado = division(operandoizq,operandoder);
            }
            break;
        }

        printf("El resultado es %.2f", resultado);
        printf("\nDesea realizar otra operacion?S/N \n");
        fflush(stdin);
        scanf("%c",&seguir);
        system("cls"); //me borra las letras de la consola

    }
    while(seguir == 's');

    return 0;
}

///implementacion de funciones

int suma(int opizq,int opder)
{
    int resultado;
    resultado = opizq + opder;

    return resultado;
}


int resta(int opizq,int opder)
{
    int resultado;
    resultado = opizq - opder;

    return resultado;
}


int multiplicacion(int opizq,int opder)
{
    int resultado;
    resultado = opizq * opder;

    return resultado;

}


float division(int opizq,int opder)
{
    float resultado;
    resultado = (float)opizq/opder;

    return resultado;

}
