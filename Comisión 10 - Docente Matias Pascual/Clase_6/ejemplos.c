/// ESTE ARCHIVO CONTIENE FUNCIONES
/**
    Al igual que la funcion main, las funciones nos permiten escribir codigos
    que luego seran ejecutados cuando llamemos a esa funcion.

    Para llamar a esa funcion tenemos que escribir su nombre seguido de ();

    Funciones es un tema que veremos mas adelante en las clases. De momento
    vamos a utilizar funciones simples para entrar en tema y organizar
    los ejercicios que vayamos haciendo.

    A diferencia de los archivos .h , los archivos .c no es necesario incluirlos
    utilizando #include. Pero si debemos agregarlos al proyecto usando Proyect/Add Files
    o crearlos usando File/New File y seleccionando C/C++ source.

    Recuerden marcar las opciones DEBUG y RELEASE.

    Importante: prestar atencion a donde guardaremos el archivo en el proyecto.
    Al lado del main seria, en esta etapa de aprendizaje, lo ideal.
*/

#include "Librerias/pila.h" /// IMPORTANTE: para que esto no genere error
                            /// debemos agregar las lineas 5, 6 y 28 escritas
                            /// en Librerias/pila.h de esta version utilizada
                            /// en la clase.

void sumarElementosDePila()
{
    Pila pila;
    inicpila(&pila);

    Pila aux;
    inicpila(&aux);

    int sumatoria = 0;

    /// agrego datos a la pila
    leer(&pila);
    leer(&pila);
    leer(&pila);
    leer(&pila);

    /// muestro la pila
    mostrar(&pila);

    /// recorro la pila sumando sus elementos
    /**
        Usamos tope para sumar el numero en sumatoria
        y luego usamos una pila auxiliar para desapilar la pila,
        asi podemos pasar al siguiente numero.

        si hicieramos sumatoria += desapilar(&pila);
        estariamos realizando la sumatoria correctamente, pero
        perderiamos los valores de la pila en el proceso.
    */

    while(!pilavacia(&pila))
    {
        sumatoria += tope(&pila);
        apilar(&aux, desapilar(&pila));
    }

    /// uso aux para dejar la pila como estaba antes del proceso anterior
    while(!pilavacia(&aux))
    {
        apilar(&pila, desapilar(&aux));
    }

    printf("la sumatoria es: %d \n\n", sumatoria);

    /// muestro la pila nuevamente para comprobar que no perdi ningun dato
    mostrar(&pila);
}

/// ------------------------------------------------------------------------

void buscarElementoYFinalizar()
{
    /// version simple. Todo hardcodeado.
    /** una siguiente version seria que el usuario ingrese el numero a buscar */

    Pila pila;
    inicpila(&pila);

    Pila aux;
    inicpila(&aux);

    apilar(&pila, 10);
    apilar(&pila, 20);
    apilar(&pila, 30);
    apilar(&pila, 40);
    apilar(&pila, 50);

    int elementoBuscado = 40;
    int flag = 0;   /// otros nombres correctos podrian ser:
                    ///     elementoEncontrado
                    ///     flagElementoEncontrado
                    ///     elementoEncontradoFlag

    while(!pilavacia(&pila) && flag == 0)
    {
        if (tope(&pila) == elementoBuscado)
        {
            flag = 1;   /// recordemos que el while analiza tambien que flag sea 0 para continuar
        }
        else
        {
            apilar(&aux, desapilar(&pila));
        }
    }

    /// informo al usuario si el elemento se encontro o no
    if (flag == 1)
    {
        /**
            si al finalizar el while, el flag es 1, entonces el elemento
            fue encontrado
        */

        printf("elemento %d encontrado!", elementoBuscado);
    }
    else
    {
        /**
            si al finalizar el while, el flag es 0, entonces el elemento
            no fue encontrado
        */

        printf("no se encontro el elemento %d", elementoBuscado);
    }

    /// dejamos la pila como estaba antes de recorrerla
    while(!pilavacia(&aux))
    {
        apilar(&pila, desapilar(&aux));
    }
}
