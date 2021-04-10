#include <stdio.h>
#include <stdarg.h> /// para usar parametros infinitos.
                    /// solo es un ejemplo, no los usamos en ningun examen
                    /// ni trabajo practico

/// EJEMPLOS DE COHESION FUERTE
int sumarNumeros(int primerNumero, int segundoNumero)
{
    return primerNumero + segundoNumero;
}

/// Esta es la misma funcion que esta en acoplamiento.c
/// Le cambie el nombre para poder mostrarla en este archivo tambien
void cargarNombreApellido_v2(char* nombre, char* apellido)
{
    cargarNombre(nombre);

    printf("\n");

    cargarApellido(apellido);
}

/// EJEMPLOS DE COHESION DEBIL
/**
    si la funcion dice que suma dos numeros,
    no deberia borrar la pantalla,
    luego cambiar el color y despues decirme que
    presione una tecla para continuar
*/
void sumarNumeros_v2(int primerNumero, int segundoNumero)
{
    system("cls");
    system("color 1f");

    int resultado = primerNumero + segundoNumero;

    printf("la suma es: %d \n\n", resultado);

    system("pause");
}

/**
    los ... son para pasar argumentos sin limite,
    esto es solo un ejemplo para que vean como se escriben
    este tipo de funciones
*/

/// esta funcion suma muchos numeros y devuelve el resultado
int sumarMuchosNumeros(int cantidadNumeros, ...)
{
    int total = 0;
    va_list numeros;

    va_start(numeros, cantidadNumeros);

    for(int i = 0; i < cantidadNumeros; i++)
    {
        total += va_arg(numeros, int);
    }

    va_end(numeros);

    return total;
}

/**
    esta funcion tambien calcula la suma de muchos numeros, pero si quisiera
    cambiar la forma en que se comunica con el usuario, tendria que modificar
    la funcion

    si la funcion dice que suma muchos numeros, lo correcto seria que hiciera
    solo eso
*/

int sumarMuchosNumeros_v2()
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

