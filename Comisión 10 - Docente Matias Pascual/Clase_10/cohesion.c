#include <stdio.h>

/// EJEMPLOS DE COHESION FUERTE
int sumarNumeros(int primerNumero, int segundoNumero)
{
    return primerNumero + segundoNumero;
}

/// EJEMPLOS DE COHESION DEBIL
/**
    Si la funcion dice que suma dos numeros,
    no deberia borrar la pantalla,
    luego cambiar el color y despues decirme que
    presione una tecla para continuar.

    Deberia sumar numeros y devolvere el resultado
*/
void sumarNumeros(int primerNumero, int segundoNumero)
{
    system("cls");
    system("color 1f");

    int resultado = primerNumero + segundoNumero;

    printf("la suma es: %d \n\n", resultado);

    system("pause");
}

/**
    La siguiente funcion calcula la suma de muchos numeros, pero si quisiera cambiar
    la forma en que se comunica con el usuario (por ejemplo si fuera para usuarios en Francia),
    tendria que modificar la funcion para escribir todos los printf en Frances.

    Si la funcion dice que suma muchos numeros, lo correcto seria que hiciera
    solo eso. Dejando la interaccion con el usuario en otra funcion o en el main.
*/
int sumarMuchosNumeros()
{
    int cantidadNumeros = 0;
    int numero = 0;
    int total = 0;

    printf("ingrese la cantidad de numeros que desea sumar \n");

    fflush(stdin);
    scanf("%d", &cantidadNumeros);

    for(int i = 0; i < cantidadNumeros; i++)
    {
        printf("ingrese un numero y presione ENTER\n");

        fflush(stdin);
        scanf("%d", &numero);

        total += numero;

        printf("\n");
    }

    return total;
}

