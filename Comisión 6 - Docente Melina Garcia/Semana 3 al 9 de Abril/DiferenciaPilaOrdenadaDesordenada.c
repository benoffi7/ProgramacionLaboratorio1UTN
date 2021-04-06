#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///insercion, busqueda y eliminacion
///PILA ORDENADA Y CASO PILA DESORDENADA
int main()
{
///PILA DESORDENADA
    Pila a;
    Pila aux;
    int cant;
    int num;
    int descarte;
    srand(time(NULL));
    inicpila(&a);
    inicpila(&aux);
    cant = rand() % 50;
    while (cant > 0) ///for (int i=cant; i>0; i--)
    {
        apilar(&a,rand() % 31); ///valores que voy a ingresar, estan en el rango de 0 a 30
        cant--;
    }

    ///insercion
    printf("Ingrese un numero a insertar en la pila\n");
    scanf("%i", &num);
    apilar(&a,num);


    ///busqueda
    int flag=0; ///indicador de evento // posee valores verdadero o falso (1 o 0 )
    printf("Ingrese un numero a BUSCAR en la pila\n");
    scanf("%i", &num);

    while (!pilavacia(&a) && tope(&a)!= num)
    {
        apilar(&aux,desapilar(&a)); //si debemos conservarla
        ///descarte = desapilar(&a) // si no debemos conservarla o no dice
    }

    ///el while corta por 2 razones
    ///1 : la pila esta vacia
    ///2 : tope(&a) == num
    ///si un operando depende exclusivamente de otro, debemos usar el INDEPENDIENTE para preguntar luego
    if (!pilavacia(&a)) ///no podemos hacer tope(&a)==num!!!
    {
        printf("LO ENCONTRASTE!"); ///flag = 1
    }
    else
    {
        printf("No lo encontraste\n");
    }

    while (!pilavacia(&aux))
    {
        apilar(&a,desapilar(&aux));
    }




    ///busqueda en una pila desordenada y contar cantidad de valores que coinciden
    ///con mi numero
    int i=0 ///contador
    printf("Ingrese un valor\n");
    scanf("%i",&num);
    while (!pilavacia(&a))
    {
        if (tope(&a) == num)
        {
            i++; //i=i+1;
        }
        apilar(&aux,desapilar(&a));

    }
    while (!pilavacia(&aux))
    {
        apilar(&a,desapilar(&aux));
    }
    if (i > 0)
    {
        printf("se encontre el elemento %i veces\n", i);
        ///hare lo que tenga que hacer con la cantidad
    }
    else
    {
        printf("No se encontro el dato\n");
        ///no hago nada
    }





///eliminacion de un dato en una pila con valores distintos
///o simplemente elimino el primmer valor coincidente
///debemos conservar la pila siempre
///busqueda con eliminacion
    printf("Ingrese un valor a eliminar de la pila\n");
    scanf("%i",&num);
    while (!pilavacia(&a) && tope(&a) != num)
    {
        apilar(&aux,desapilar(&a));
    }
    if (!pilavacia(&a))
    {
        descarte = desapilar(&a);
    }
    while(!pilavacia(&aux))
    {
        apilar(&a,desapilar(&aux));
    }


 ///eliminacion en una pila DESORDENADA que puede contener valores repetidos
    printf("Ingrese un valor\n");
    scanf("%i", &num);
    while (!pilavacia(&a))
    {
        if (tope(&a) == num)
        {
            descarte = desapilar(&a);
        }
        else
        {
            apilar(&aux,desapilar(&a));
        }
    }
    while (!pilavacia(&aux))
    {
        apilar(&a,desapilar(&aux));
    }



///CASO PILA ORDENADA

        Pila b;
        Pila aux2;
        inicPila(&b);
        inicpila(&aux2);
// 5
// 4
// 4
// 3
// 2      num = 4;
// 1
        apilar(&b,1);
        apilar(&b,2);
        apilar(&b,3);
        apilar(&b,4);
        apilar(&b,5);  ///ordenada de mayor a menor

    ///insercion
        printf("Ingrese un numero a insertar en la pila\n");
        scanf("%i", &num);
        while(!pilavacia(&b) && tope(&b) > num)
        {
            apilar(&aux2,desapilar(&b));
        }
        apilar(&b,num);
        while (!pilavacia(&aux2))
        {
            apilar(&b,desapilar(&aux2));
        }

    ///busqueda

//
//
// 2      num = 3;
// 1
        printf("Ingrese un numero a BUSCAR en la pila\n");
        scanf("%i", &num);
        while (!pilavacia(&b) && tope(&b) > num)
        {
            apilar(&aux2,desapilar(&b)); ///conservar la pila
        }
        if (!pilavacia(&b) && tope(&b) == num)
        {
            printf("se encontro el dato\n"); ///flag =1
        }
        else
        {
            printf("No se encontro el dato\n");
        }

    ///eliminacion de un valor en una pila ORDENADA con todos valores distintos

        while (!pilavacia(&b) && tope(&b) > num)
        {
            apilar(&aux2,desapilar(&b));
        }
        if (!pilavacia(&b) && tope(&b) == num)
        {
            descarte = desapilar(&b);
        }
        else //opcional
        {
            printf("El valor no se encuentra\n");
        }
        while(!pilavacia(&aux2))
        {
            apilar(&b,desapilar(&aux2));
        }
        mostrar(&b); //opcional


    ///TAREA CON UNA PILA ORDENADA DE MAYOR A MENOR

    ///1) busqueda en una pila ORDENADA DE MAYOR A MENOR y contar cantidad de valores que coinciden
    ///con mi numero  (pueden repetirse)

    ///2)eliminar TODOS los valores coincidentes (pueden repetirse) con mi numero en la pila ORDENADA

    return 0;
}
