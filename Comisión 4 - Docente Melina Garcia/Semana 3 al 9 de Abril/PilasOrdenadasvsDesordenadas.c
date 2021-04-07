#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
///consideraciones en insercion, busqueda y eliminacion en pilas ordenadas y desordenadas

int main()
{

///Pilas desordenadas
    Pila a;
    Pila aux;
    int i;
    int cantidad;
    int num;
    int descarte;
    int flag;
    inicpila(&a);
    inicpila(&aux);
    srand(time(NULL));
    cantidad = rand() % 51;
    while (cantidad > 0)
    {
        apilar(&a,rand() % 30);
        cantidad--;
    }
///insercion
    printf("Ingrese un valor a insertar en la pila\n");
    scanf("%i",&num);
    apilar(&a,num);
    ////todo esto es lo mismo que hacer leer(&a);

///busqueda de un valor en la pila
    printf("Ingrese un valor a BUSCAR en la pila desordenada\n");
    scanf("%i",&num);
    while ((!pilavacia(&a)) && (num != tope(&a))) //mientras no este vacia la pila y no encontre el dato, sigo buscando
    {
        apilar(&aux,desapilar(&a)); ///si debo conservar la pila original
        ///descarte = desapilar(&a); ///si no la debo conservar a la pila original
    }
    if (!pilavacia(&a))
    {
        printf("se encontro el dato\n");
    }
    else
    {
        printf("No se encontro el dato\n");
    }
///cuando evalua las condiciones que hicieron cortar al bucle
///debo pensar que alguna de los operandos depende del otro y puede romper el programa
///debemos solo utilizar el operando de la izquierda en estas situaciones


///eliminacion
///en el caso de la elimminacion de un dato claramente debemos conservar el resto de la pila
///sin ese dato
    printf("Ingrese un valor a ELIMINAR en la pila desordenada\n");
    scanf("%i",&num);
    while (!pilavacia(&a) && tope(&a) != num)
    {
        apilar(&aux,desapilar(&a));
    }
    if (!pilavacia(&a))
    {
        descarte = desapilar(&a); ///desapilamos ese valor que encontro en descarte
        printf("El dato se elimino exitosamente\n");
    }
    else
    {
        printf("No se encontro el dato a eliminar\n");
    }
    while (!pilavacia(&aux))
    {
        apilar(&a,desapilar(&aux));
    }

///eliminacion de un dato QUE SE REPITE EN LA PILA
///en el caso de la elimminacion de un dato claramente debemos conservar el resto de la pila
///sin ese dato
///debemos eliminar todos los datos que correspondan a ese numero
///EL FLAG SOLO TOMA VALORES VERDADERO O FALSO (1 o 0)
    flag = 0; //inicializo la banderita/indicador como falso por defecto
    printf("Ingrese un valor a ELIMINAR en la pila desordenada\n");
    scanf("%i",&num);
    while (!pilavacia(&a))
    {
        while (!pilavacia(&a) && tope(&a) != num)
        {
            apilar(&aux,desapilar(&a));
        }
        if (!pilavacia(&a))
        {
            descarte = desapilar(&a); ///desapilamos ese valor que encontro en descarte
            if (flag == 0) ///!flag
            {

                flag = 1; /// cambio el indicador a VERDADERO una vez que encontre algun numero igual

            }

        }
    }
    if (flag)
    {
        printf("Se encontro al menos un valor IGUAL a eliminar\n");
    }
    else
    {
        printf("No se encontro ningun valor en la pila coincidente\n");
    }
    while (!pilavacia(&aux))
    {
        apilar(&a,desapilar(&aux));
    }



///eliminacion de un dato QUE SE REPITE EN LA PILA y contar la cantidad de eliminados
///en el caso de la elimminacion de un dato claramente debemos conservar el resto de la pila
///sin ese dato
///debemos eliminar todos los datos que correspondan a ese numero

    i = 0; //contador inicializado
    printf("Ingrese un valor a ELIMINAR en la pila desordenada\n");
    scanf("%i",&num);
    while (!pilavacia(&a))
    {
        while (!pilavacia(&a) && tope(&a) != num)
        {
            apilar(&aux,desapilar(&a));
        }
        if (!pilavacia(&a))
        {
            descarte = desapilar(&a); ///desapilamos ese valor que encontro en descarte
            i++; ///i=i+1;
        }
    }
    if (i>0)
    {
        printf("Se encontraron %i valores iguales\n", i);
    }
    else
    {
        printf("No se encontro ningun valor en la pila coincidente\n");
    }
    while (!pilavacia(&aux))
    {
        apilar(&a,desapilar(&aux));
    }

///PILAS ORDENADAS

    Pila b;
    Pila aux2;
    inicpila(&b);
    inicpila(&aux2);
    apilar(b,1);
    apilar(b,2);
    apilar(b,3);
    apilar(b,4);
    apilar(b,5);
//  5
//  4
//  4
//  3
//  2
//  1 base
    ///pila ordenada de mayor a menor

///INSERCION DE UN DATO

    printf("Ingrese un valor a insertar\n");
    scanf("%i",&num);
    while (!pilavacia(&b) && tope(&b) > num)
    {
        apilar(&aux2,desapilar(&b));
    }
    apilar(&b,num);
    while(!pilavacia(&aux2))
    {
        apilar(&b,desapilar(&aux2));
    }

///BUSQUEDA DE UN DATO
    ///flag =0; inicializo el flag en 0 como no encontrado
    printf("Ingrese un valor a buscar en la pila ORDENADA de mayor a menor\n");
    scanf("%i", &num);
    while (!pilavacia(&b) && tope(&b) > num)
    {
        apilar(&aux2,desapilar(&b))
    }

    if (!pilavacia(&b) && tope(&b) == num)
    {
        printf("Se encontro el dato"); ///flag =1 indico que se encontro
    }
    else
    {
        printf("No se encontro el dato");
    }


///ELIMINACION DE UN DATO (EN LA PILA HAY TODOS VALORES DISTINTOS)

//5
//4    eliminar el 4
//2
//1
    printf("Ingrese un valor a buscar en la pila ORDENADA de mayor a menor\n");
    scanf("%i", &num);
    while (!pilavacia(&b) && tope(&b) > num)
    {
        apilar(&aux2,desapilar(&b));
    }
    if (!pilavacia(&b) && tope(&b) == num)
    {
        descarte = desapilar(&b);
        printf("Se elimino exitosamente el elemento\n")
    }
    else
    {
        printf("No se elimino ningun valor coincidente\n");
    }
    while (!pilavacia(&aux2))
    {
        apilar(&b,desapilar(&aux2));
    }


///ELIMINACION DE UN DATO (PUEDE HABER REPETIDOS)

//5
//4    eliminar el 4
//4
//4
//2
//1
    flag=0;
    printf("Ingrese un valor a buscar en la pila ORDENADA de mayor a menor\n");
    scanf("%i", &num);
    while (!pilavacia(&b) && tope(&b) > num)
    {
        apilar(&aux2,desapilar(&b));
    }
    while (!pilavacia(&b) && tope(&b) == num)
    {
        descarte = desapilar(&b);
        if (flag == 0)
        {
            flag = 1;
        }
    }
    if (flag ==1 ) //(flag)
    {
        printf("Elimine al menos un valor coincidente de la pila\n");
    }
    else
    {
        printf("No se elimino ningun valor coincidente\n");
    }
    while (!pilavacia(&aux2))
    {
        apilar(&b,desapilar(&aux2));
    }



    return 0;
}
