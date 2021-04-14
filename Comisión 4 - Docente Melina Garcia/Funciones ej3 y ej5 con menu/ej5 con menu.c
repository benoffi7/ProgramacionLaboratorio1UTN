#include <stdio.h>
#include <stdlib.h>

/**Realice una pequeña calculadora de numeros enteros,
utilizando funciones
(una función de suma, una de multiplicación, una de resta, una de división…**/

//prototipados
int suma(int,int);
int resta(int,int);
int multiplicacion(int,int);
float division(int,int);


int main()
{
    int operandoIZQ;
    int operandoDER;
    int opcion;
    float resultado;
    char seguir;
    printf("Bienvenido a la calculadora de la utn\n");
    do
    {
        printf("Ingrese los numeros a realizar la operacion\n");
        printf("OPERANDO IZQ: ");
        scanf("%i",&operandoIZQ);
        printf("\noperando derecho: ");
        scanf("%i",&operandoDER);
        do
        {
            printf("Ingrese la opcion que desea realizar...\n");
            printf("1. suma\n");
            printf("2. resta\n");
            printf("3. multiplicacion\n");
            printf("4. division\n");
            scanf("%i", &opcion);
            if (opcion < 1 || opcion > 4 )
            {
                system("cls");
                printf("Esa opcion es invalida..\n");
            }

        }
        while (opcion < 1 || opcion > 4);

        switch(opcion)
        {
        case 1:
            resultado = suma(operandoIZQ,operandoDER);
            break;
        case 2:
            resultado = resta(&operandoIZQ,&operandoDER);
            break;
        case 3:
            resultado = multiplicacion(operandoIZQ,operandoDER);
            break;
        case 4:
//            if (operandoDER == 0)
//            {
//                printf("No existe la division por 0...\n");
//            }
//            else
//            {
                resultado = division(operandoIZQ,operandoDER);
//            }
            break;
        }

        printf("El resultado de la operacion es %.2f\n", resultado);
        printf("Desea realizar otra operacion? s/n \n");
        fflush(stdin);
        scanf("%c",&seguir);
        system("cls");
    }
    while(seguir == 's');

    printf("saliendo del programa...");
    return 0;
}

int suma(int N1,int N2)
{
    int resultado; //variable local a la funcion suma
    resultado = N1 + N2;
    return resultado;
}


int resta(int N1,int N2)
{
    int resultado;//variable local a la funcion resta
    resultado = N1 - N2;
    return resultado;

}

int multiplicacion(int N1,int N2)
{
    int resultado; ///local a la funcion multiplicacion
    resultado = N1*N2;

    return resultado;

}

float division(int N1,int N2)
{
    float resultado; //local a  la funcion divison
    resultado = (float)N1/N2;

    return resultado;
}
