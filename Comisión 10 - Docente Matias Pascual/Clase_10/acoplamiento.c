#include <stdio.h>

/**
    Acoplamiento:
        Medida de interacción de los módulos
        que constituyen un programa.
*/

// EJEMPLOS

//{ acoplamiento de datos
void cargarNombreApellido(char* nombre, char* apellido)
{
    cargarNombre(nombre);

    printf("\n");

    cargarApellido(apellido);
}

void cargarNombre(char* nombre)
{
    printf("ingrese su nombre \n");

    fflush(stdin);
    scanf("%s", nombre);
}

void cargarApellido(char* apellido)
{
    printf("ingrese su apellido \n");

    fflush(stdin);
    scanf("%s", apellido);
}
//}

//{ acomplamiento de control
int cargarConControlDeCarga(char* nombre, char* apellido, int controlDeCarga)
{
    /// utilizamos un flag para saber si hubo un error
    int flag = 0;

    switch(controlDeCarga)
    {
    case -1:
        cargarNombre(nombre);
        break;
    case 0:
        cargarNombre(nombre);
        cargarApellido(apellido);
        break;
    case 1:
        cargarApellido(nombre);
        break;
    default:
        /// explicamos al usuario el uso correcto de la funcion
        printf("Error en funcion \"acoplamiento de control\" \n");
        printf("\nControl de carga invalido: \n");
        printf("\tingrese -1 para cargar nombre\n");
        printf("\tingrese 1 para cargar apellido\n");
        printf("\tingrese 0 para cargar ambos\n");

        /// ponemos el flag en 1 porque hubo un error
        flag = 1;
    }

    return flag;
}
//}

//{ acoplamiento externo

/// le decimos al compilador que existe una variable global con este nombre
extern int variableGlobal;

/// explicado en clase
void modificarVariable_1()
{
    variableGlobal = 30;
}

void modificarVariable_2()
{
    variableGlobal = 20;
}

//}
