/**
    Una cadena de caracteres es un arreglos de caracteres con un ultimo elemento de valor NULL
    que representa el final de la cadena.

    Se los conoce con el nombre de String.
*/

/// ---------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

/// prototipado de funciones

void explicandoCadenasCaracteres();
void capturandoString();
void mostrarString(char arreglo[], int validos);
void mostrarString_v2(char arreglo[]);

/// ---------------------------------------------------------------

/// definicion de funciones

void explicandoCadenasCaracteres()
{
    char palabra[50] = "hola! buenos dias";

    mostrarString(palabra, 15);
    mostrarString_v2(palabra);

    /// mostrando un string desde printf
    printf("%s \n\n", palabra);

    /// cuidado con el valor 0, recordemos que es NULL y marca el final del String
    palabra[5] = '\0';
    mostrarString_v2(palabra);

    palabra[4] = 0;
    mostrarString_v2(palabra);
}

/// ---------------------------------------------------------------

void capturandoString()
{
    /// diferencia entre scanf() y gets()

    char nombreApellido[100];

    printf("ingrese su nombre y apellido \n");

    fflush(stdin);
    scanf("%s", &nombreApellido);   /// el & es redundante en esta linea de codigo

    printf("su nombre y apellido es: %s \n\n", nombreApellido);

    /// con scanf los espacios son interpretados como separadores de variables
    printf("ingrese su nombre y apellido... de nuevo. \n");

    fflush(stdin);
    gets(nombreApellido);

    printf("su nombre y apellido es: %s \n\n", nombreApellido);

    /**
        ATENCION!

        Mucho cuidado al usar scanf

        No confundir:
            scanf("%s" , arreglo);
            scanf("%s" , &arreglo);
            scanf("%s" , &arreglo[0]);

        Con:
            scanf("%s" , arreglo[0]);

        Si especificamos una posicion del arreglo, pero no usamos el &, tendremos un error.

        Esto sucede porque cuando usamos la posicion del arreglo, estamos devolviendo el valor
        que guarda el arreglo en dicha posicion y scanf nos pide una posicion de memoria.
    */
}

/// ---------------------------------------------------------------

void mostrarString(char arreglo[], int validos)
{/// muestra el arreglo hasta que i deja de ser menor a validos

    for(int i = 0; i < validos; i++)
    {
        printf("%c", arreglo[i]);
    }

    printf("\n\n");
}

/// ---------------------------------------------------------------

void mostrarString_v2(char arreglo[])
{/// muestra el string hasta que encuentra el valor 0 (NULL)

    printf("%s", arreglo);

    printf("\n\n");
}
