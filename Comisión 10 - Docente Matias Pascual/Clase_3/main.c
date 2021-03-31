/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 3:
        . VARIABLES LOCALES
        . CAPTURAR TECLA CON GETCH()
        . CAPTURAR CADENA DE CARACTERES
        . EJEMPLO DE ITERACION CON TECLA ESCAPE y FLAG
        . EJEMPLO DE CLS y SLEEP()
*/

/// ------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#define TECLA_PARA_SALIR 27
#define VERDADERO 1
#define FALSO 0
#define BORRAR_PANTALLA system("cls");

/// prototipo de funciones (de momento ignoren esta parte)
void ejemploVariablesLocales();
void ejemploSleep();
void ejemploFlag();
void ejemploIteracionConGetch();
void ejemploCapturandoCadenaDeCaracteres();

/// ------------------------------------------------------------------------

int main()
{
    /// ejemploVariablesLocales();
    /// ejemploSleep();
    /// ejemploFlag();
    /// ejemploIteracionConGetch();
    /// ejemploCapturandoCadenaDeCaracteres();

    return 0;
}

/// ------------------------------------------------------------------------

void ejemploVariablesLocales()
{
    /// EJEMPLO CON IF

    int numero = 0;

    if (numero < 0)
    {
        printf("el numero es negativo\n");

        int variableA = 10;
    }
    else
    {
        printf("el numero es positivo\n");

        //variableA = 10; /// error: la variableA no fue declarada en este scope
                        /// (ambito de aplicacion)

        int variableA = 10; /// esta variableA es diferente a la variableA declarada
                            /// en el if de arriba

        int variableB = 20;
    }

    printf("%d", variableA); /// error: la variableA no fue declarada en este scope
    printf("%d", variableB); /// error: la variableB no fue declarada en este scope

    /// ------------------------------------------------------------------------

    /// EJEMPLO CON WHILE

    int i = 0;
    while(i < 10)
    {
        int variableW = 0;
        variableW++;

        i++;
    }

    printf("%d", variableW); /// error: la variableW no fue declarada en este scope

    /// ------------------------------------------------------------------------

    /// EJEMPLO USANDO SOLO LLAVES

    {
        int a = 10;
        {
            int a = 20;  /// todo ok, no es la misma variable a de arriba
            printf("%d", a);    /// muestra 20
            int b;
        }

        b = 10; /// b no fue declarada en este scope
    }

    a = 10; /// error
    b = 10; /// error
}

/// ------------------------------------------------------------------------

void ejemploIteracionConGetch()
{
    int teclaUsuario = 0;
    int numeroIngresado = 0;
    int sumaTotal = 0;

    while(teclaUsuario != TECLA_ESCAPE)
    {
        /// system("cls");
        BORRAR_PANTALLA


        /// el usuario ingresa un numero

        printf("Ingrese un numero\n");

        scanf("%d", &numeroIngresado);


        /// lo sumo al total de la suma de los numeros ingresados

        sumaTotal += numeroIngresado;


        /// si toca escape, sale del bucle de repeticion

        printf("para salir presione ESC, de lo contrario presione cualquier tecla\n");

        fflush(stdin);
        teclaUsuario = getch();
    }

    printf("la suma total fue: %d", sumaTotal);
}

/// ------------------------------------------------------------------------

void ejemploFlag()
{
    /// int flag = 0;
    int flag = VERDADERO;
    int contador = 0;

    while (flag == VERDADERO)
    {
        contador++;
        if (contador > 10)
        {
            flag = FALSO;
        }

        printf("contador: %d \n", contador);

        /// flag = (contador > 10) ? VERDADERO : FALSO; // breve explicacion en clase
    }
}

/// ------------------------------------------------------------------------

void ejemploSleep()
{
    for(int i = 0; i < 10; i++)
    {
        Sleep(1000);
        printf("%d\n", i);
    }
}

/// ------------------------------------------------------------------------

void ejemploCapturandoCadenaDeCaracteres()
{
    char nombre[100];
    char apellido[100];

    printf("ingrese su nombre:\n");
    scanf("%s", &nombre);

    fflush(stdin);

    printf("ingrese su apellido:\n");
    scanf("%s", &apellido);

    printf("buenos dias %s %s \n", nombre, apellido);
}
