#include <conio.h>
#include <stdio.h>

/**
    Guia de arreglos - ejercicio 1.

    Hacer una función que

    reciba como parámetro un arreglo de números enteros y
    permita que el usuario ingrese valores al mismo por teclado.

    - La función debe retornar la cantidad de elementos cargados en el arreglo
    - (o pueden utilizar como puntero válidos)
*/

/// --------------------------------------------------------------------

void ejercicio_cargarNumerosEnArreglo()
{
    const int DIMENSION = 20;

    int arreglo[DIMENSION];

    int elementosCargados = 0;

    int validos = cargarNumerosEnArreglo(arreglo, DIMENSION, &elementosCargados);

    printf("validos: %d \n", validos);
    printf("cantidad de elementos cargados: %d \n", elementosCargados);

    for (int i = 0; i < validos; i++)
    {
        printf("[%d]: %d \n", i, arreglo[i]);
    }
}

/// --------------------------------------------------------------------

/// En este ejemplo devolvemos los validos y tambien modificamos los validos por referencia.
/// Lo correcto es usar una de las dos opciones
int cargarNumerosEnArreglo(int arreglo[], int dimension, int* validos)
{
    int cantidad = 0;

    const char TECLA_SALIR = 'n';
    char teclaUsuario = '0';

    int numero = 0;

    int i = 0;
    while(teclaUsuario != TECLA_SALIR &&
          i < dimension)
    {
        /// cargo elementos en arreglo

        printf("ingrese un numero \n");
        scanf("%d", &numero);

        arreglo[i] = numero;

        printf("quiere cargar otro elemento? \n\n");
        printf("presione n para salir u otra tecla para continuar \n");

        fflush(stdin);
        teclaUsuario = getch();

        printf("\n");
        i++;
    }

    cantidad = i;
    *validos = i;

    return cantidad;
}

/// --------------------------------------------------------------------

int cargarNumeros(int arreglo[], int dimension)
{
    int validos = 0; /// validos seria la cantidad de numeros cargados

    const int TECLA_SALIR = 27; /// ESCAPE es la tecla 27
    int teclaUsuario = 0;

    printf("cargando arreglo: \n\n");

    for(int i = 0; i < dimension && teclaUsuario != TECLA_SALIR; i++)
    {
        printf("\ningrese un numero \n");
        fflush(stdin);

        scanf("%d", &arreglo[i]);   /// atencion al &, no hay que olvidarlo

        printf("para salir presione ESC, para continuar presione cualquier otra tecla \n");
        teclaUsuario = getch();

        validos++;
    }

    return validos;
}

/// --------------------------------------------------------------------

void cargarNumerosConPuntero(int arreglo[], int dimension, int* validos)
{
    const int TECLA_SALIR = 27; /// ESCAPE es la tecla 27
    int teclaUsuario = 0;

    printf("cargando arreglo v2: \n\n");

    for(int i = 0; i < dimension && teclaUsuario != TECLA_SALIR; i++)
    {
        printf("\ningrese un numero \n");
        fflush(stdin);

        scanf("%d", &arreglo[i]);   /// atencion al &, no hay que olvidarlo

        printf("para salir presione ESC, para continuar presione cualquier otra tecla \n");
        teclaUsuario = getch();

        *validos = *validos + 1;
    }
}
