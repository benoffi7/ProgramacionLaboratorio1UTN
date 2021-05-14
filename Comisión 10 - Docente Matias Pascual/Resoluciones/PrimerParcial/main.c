#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
#include <conio.h>

/// --------------------------------------------------------------------------------------------

/** 1- Pedirle al usuario que ingrese tres numeros y mostrar por pantalla cual es el mayor de los tres */

void ejercicio_1()
{
    int numero_1;
    int numero_2;
    int numero_3;

    printf("ingrese tres numeros separados por un espacio \n");

    fflush(stdin);
    scanf("%d %d %d", &numero_1, &numero_2, &numero_3);

    int menor;
    if(numero_1 < numero_2 && numero_1 < numero_3)
    {
        menor = numero_1;
    }
    else if(numero_2 < numero_3 && numero_2 < numero_1)
    {
        menor = numero_2;
    }
    else
    {
        menor = numero_3;
    }

    printf("el menor es %d \n", menor);
}

/// --------------------------------------------------------------------------------------------

/** 2 - Realizar una funcion que cargue un arreglo enviado como parametro y devuelva la cantidad de elementos cargados.*/

void mostrarArreglo(int arreglo[], int validos);
int cargarArreglo(int arreglo[], int dimension);

void ejercicio_2()
{
    const int DIMENSION_ARREGLO = 10;

    int arreglo[DIMENSION_ARREGLO];

    int validos = cargarArreglo(arreglo, DIMENSION_ARREGLO);

    printf("la cantidad de elementos cargados es: %d \n", validos);

    printf("arreglo cargado: \n");

    mostrarArreglo(arreglo, validos);

}

int cargarArreglo(int arreglo[], int dimension)
{
    int validos = 0;

    const char TECLA_SALIR = 'n';
    char teclaUsuario = 0;

    while(teclaUsuario != TECLA_SALIR
    &&    validos < dimension)
    {
        printf("Ingrese un numero \n");

        fflush(stdin);
        scanf("%d", &arreglo[validos]);

        printf("\nPara salir ingrese n , para continuar ingrese s \n");

        fflush(stdin);
        scanf("%c", &teclaUsuario);

        printf("\n");

        validos++;
    }

    return validos;
}

void mostrarArreglo(int arreglo[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("[%d] ", arreglo[i]);
    }
    printf("\n");
}

/// --------------------------------------------------------------------------------------------

/** 3 - Hacer una función que encuentre el menor elemento de una pila y lo retorne */

int buscarMenorElementoEnPila(Pila* pila);

void ejercicio_3()
{
    Pila pila;
    inicpila(&pila);

    apilar(&pila, 10);
    apilar(&pila, 20);
    apilar(&pila, 30);
    apilar(&pila, 4);
    apilar(&pila, 50);
    apilar(&pila, 60);

    int menorElemento = buscarMenorElementoEnPila(&pila);

    printf("el menor elemento es: %d \n", menorElemento);

    mostrar(&pila);
}

int buscarMenorElementoEnPila(Pila* pila)
{
    int menor;

    /// COMPROBANDO QUE LA PILA NO ESTE VACIA
    /// si los alumnos no hacen esta comprobacion, igual el ejercicio lo consideramos bien.
    /// en el proximo examen, este tipo de errores baja puntos

    if(pilavacia(pila))
    {
        printf("la pila esta vacia \n");
        menor = -1;
    }
    else
    {
        menor = desapilar(pila);

        Pila aux;
        inicpila(&aux);

        /// busco el menor
        while(!pilavacia(pila))
        {
            if(tope(pila) < menor)
            {
                menor = tope(pila);
            }

            apilar(&aux, desapilar(pila));
        }

        /// reacomodo la pila original
        while(!pilavacia(&aux))
        {
            apilar(pila, desapilar(&aux));
        }
    }

    return menor;
}

/// --------------------------------------------------------------------------------------------

/** 4 - Utilizando la funcion creada en el ejercicio 2,
    cargar 10 numeros enteros en un arreglo, luego
    pasar todos los numeros a una Pila y luego realizar una funcion que calcule el promedio de todos
    sus elementos. Puede modularizar lo que considere necesario
*/

void pasarArregloEnPila(int arreglo[], int validos, Pila* pila);
int cantidadElementos(Pila* pila);
int sumarElementos(Pila* pila);
float calcularPromedio(Pila* pila);

void ejercicio_4()
{
    int arreglo[3];
    int validos = cargarArreglo(arreglo, 3);

    Pila pila;
    inicpila(&pila);

    pasarArregloEnPila(arreglo, validos, &pila);

    float promedio = calcularPromedio(&pila);

    printf("promedio: %.2f", promedio);
}

void pasarArregloEnPila(int arreglo[], int validos, Pila* pila)
{
    for(int i = 0; i < validos; i++)
    {
        apilar(pila, arreglo[i]);
    }
}

int cantidadElementos(Pila* pila)
{
    int cantidad = 0;

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pila))
    {
        apilar(&aux, desapilar(pila));
        cantidad++;
    }

    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return cantidad;
}

int sumarElementos(Pila* pila)
{
    int suma = 0;

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pila))
    {
        suma += tope(pila);
        apilar(&aux, desapilar(pila));
    }

    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return suma;
}

float calcularPromedio(Pila* pila)
{
    int suma = sumarElementos(pila);
    int cantidad = cantidadElementos(pila);

    float promedio = (float) suma/cantidad;

    return promedio;
}

/// --------------------------------------------------------------------------------------------

/** 5 - Realizar los siguientes ejercicios:

    A) Realizar una funcion que cuente la cantidad elementos de una pila.
    B) Realizar una funcion que pase todos los elementos de la pila a un arreglo. Debera utilizar
    la funcion anterior para saber la cantidad de elementos a pasar.
    C) Realizar una funcion que calcule la suma de los elementos de un arreglo.
    D) Crear una funcion que llame a las funciones creadas anteriormente. Esta funcion recibe
    una pila por parametro y un arreglo. Llama a las funciones creadas y le muestra al usuario
    el arreglo con todos los elementos y el valor de la suma de todos sus elementos
*/

/// A) realizada en ejercicio 4
int cantidadElementos(Pila* pila);

/// B)
void pasarPilaEnArreglo(Pila* pila, int arreglo[], int cantidadEnPila, int cantidadMaximaArreglo)
{
    /// de nuevo, estas comprobaciones no quitan puntos al examen
    /// pero se tendran en cuenta en el proximo

    if(cantidadEnPila > cantidadMaximaArreglo)
    {
        printf("la pila supera la capacidad del arreglo \n");
    }
    else
    {
        Pila aux;
        inicpila(&aux);

        int i = 0;
        while(!pilavacia(pila)
        &&    i < cantidadMaximaArreglo)
        {
            arreglo[i] = tope(pila);

            apilar(&aux, desapilar(pila));
            i++;
        }

        while(!pilavacia(&aux))
        {
            apilar(pila, desapilar(&aux));
        }
    }
}

/// C)
int sumarArreglo(int arreglo[], int validos)
{
    int suma = 0;

    for(int i = 0; i < validos; i++)
    {
        suma += arreglo[i];
    }

    return suma;
}

/// D)
void mostrarFuncionamiento(Pila* pila, int arreglo[], int dimensionArreglo)
{
    int cantidad = cantidadElementos(pila);

    pasarPilaEnArreglo(pila, arreglo, cantidad, dimensionArreglo);

    int suma = sumarArreglo(arreglo, cantidad);

    mostrarArreglo(arreglo, cantidad);

    printf("suma de sus elementos: %d", suma);
}

void ejercicio_5()
{
    Pila pila;
    inicpila(&pila);

    apilar(&pila, 10);
    apilar(&pila, 20);
    apilar(&pila, 30);
    apilar(&pila, 40);

    const int DIMENSION = 10;
    int arreglo[DIMENSION];

    mostrarFuncionamiento(&pila, arreglo, DIMENSION);
}

/// --------------------------------------------------------------------------------------------

/** 6 - Realizar un login de usuario. Para esto el programa debera indicarle al usuario que ingrese su
    nombre de usuario. Si el nombre de usuario es “alumno UTN”, se le indicara al usuario que ingrese
    su nombre y apellido reales y le mostrara la cantidad de letras de su nombre y apellido (sin contar
    espacios en blanco).
    Si el nombre de usuario es incorrecto, el programa le preguntara si quiere seguir ingresando su
    nombre de usuario o presionar una tecla a eleccion para salir del programa, por ejemplo ‘N’ o
    ESCAPE.
    Aclaracion: el programa no debera tener en cuenta las mayusculas ni minusculas. Si el usuario
    ingresa “alumno utn”, “Alumno Utn” o cualquier otra variante, el programa debera admitirlo igual.
*/

void ejercicio_6()
{
    char nombre[100];
    char letraUsuario = 0;
    const char LETRA_SALIR = 'n';

    while(strcmpi(nombre, "alumno utn") != 0
    &&   letraUsuario != LETRA_SALIR)
    {
        printf("ingrese su nombre \n");

        fflush(stdin);
        gets(nombre);

        if (strcmpi(nombre, "alumno utn") == 0)
        {
            printf("ingrese su nombre y apellido reales \n");
            gets(nombre);

            int cantidadCaracteres = strlen(nombre);

            /// quitando los espacios. Si no lo logran, no resta puntos. Pero si lo logran, suma decimales al examen
            int cantidadLetras = cantidadCaracteres;

            for(int i = 0; i < cantidadCaracteres; i++)
            {
                if(nombre[i] == ' ')
                {
                    cantidadLetras--;
                }
            }

            printf("su nombre es: %s \nLa cantidad de letras es: %d", nombre, cantidadLetras);

            letraUsuario = 'n'; /// para que salga del bucle al finalizar esta parte
        }
        else
        {
            printf("nombre incorrecto\nPara salir ingrese n. Para ingresar otro nombre ingrese otra letra \n");

            fflush(stdin);
            scanf("%c", &letraUsuario);
        }
    }
}

/// --------------------------------------------------------------------------------------------

int main()
{
    //ejercicio_1();
    //ejercicio_2();
    //ejercicio_3();
    //ejercicio_4();
    //ejercicio_5();
    //ejercicio_6();

    return 0;
}
