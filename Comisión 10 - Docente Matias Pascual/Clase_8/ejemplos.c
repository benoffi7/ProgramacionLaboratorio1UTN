#include "Librerias/pila.h"

//{ TIPOS DE FUNCIONES

/// sin retorno y sin parametros
void saludar()
{
    printf("hola mundo! \n");
}

/// con retorno y sin parametros
int devolverRandom()
{
    srand(time(NULL));

    int random = rand() % 10;

    return random;
}

/// sin retorno y con parametros
void mostrarSuma(int numeroA, int numeroB)
{
    int resultado = numeroA + numeroB;

    printf("%d + %d = %d", numeroA, numeroB, resultado);
}

/// con retorno y con parametros
int devolverSuma(int numeroA, int numeroB)
{
   return numeroA + numeroB;
}
//}

/// ---------------------------------------------------------

//{ PASAJE DE PARAMETROS

/// por valor
int sumarValores(int numA, int numB)
{
    return numA + numB;
}

/// por referencia
void cambiarValor(int* a)
{
    *a = 20;
}

/// explicacion de por que esta funcion no cumple su objetivo
void cambiarValor_mal (int a)
{
    /**
        no estamos cambiando la variable A pasada por parametro,
        sino el valor de una nueva variable local
        tambien llamada a
    */

    a = 20;
}

/// en lugar de cambiar un valor, estamos devolviendo un nuevo valor
/// aunque tecnicamente no es incorrecto, el objetivo que buscamos es
/// modificar una variable desde dentro de la funcion
int cambiarValor_mal2 ()
{
    return 30;
}
//}

/// ---------------------------------------------------------

//{ FUNCIONES Y PILAS

/**
    Prestar atencion al pasaje de parametros de la pila.

    Si pasamos la direccion de memoria de la pila, no debemos volver a utilizar
    &pila dentro de la funcion.
*/

/// cargar una pila una cantidad de elementos
void cargarElementosEnPila(int cantidadElementos, Pila* pila)
{
    /**
        la pila debe estar iniciada, ya que esta funcion
        no tiene el objetivo de inicializarla
    */

    int i = 0;
    while(i < cantidadElementos)
    {
        leer(pila);
        i++;
    }
}

/// cargar una pila hasta que el usuario decida frenar
void cargarPilaUsandoTeclaSalir(Pila* pila)
{
    const int teclaSalir = 27; /// escape
    int teclaUsuario = 0;

    while(teclaUsuario != teclaSalir)
    {
        leer(pila);

        printf("para salir presione ESCAPE \n");
        printf("presione cualquier tecla para continuar \n");

        fflush(stdin);
        teclaUsuario = getch();
    }
}
//}

/// ---------------------------------------------------------

//{ ALGORITMOS

/// buscar elemento en una pila
int buscarElemento(int elemento, Pila* pila)
{
    Pila aux;
    inicpila(&aux);

    int flag = 0; /// este flag se pone en 1 cuando el elemento es encontrado

    while(!pilavacia(pila) && flag == 0)
    {
        /// si el tope de la pila es igual al elemento buscado...
        if (tope(pila) == elemento)
        {
            /// entonces encontramos el elemento
            flag = 1;
        }
        else
        {
            /// si no, desapilamos la pila y seguimos buscando
            apilar(&aux, desapilar(pila));

            /**
                nota:
                    cuando usamos la pila aux, como esta declarada dentro de la funcion,
                    debemos pasar su direccion de memoria.

                    por ejemplo al usar apilar(&aux ... )

                    cuando usamos desapilar(pila), no estamos usando el & , porque ya tenemos
                    su direccion de memoria cuando la pasamos como parametro.
            */
        }
    }

    /// vuelvo a dejar la pila como estaba
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    /// flag sera 0 o 1 segun haya encontrado el elemento o no
    return flag;
}
//}
