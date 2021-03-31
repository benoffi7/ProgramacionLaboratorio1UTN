#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/// La consigna es cargar una pila e invertir su contenido
int main()
{
    Pila origen, aux1, aux2;
    inicpila(&origen);
    inicpila(&aux1);
    inicpila(&aux2);

    int nro;
    char opcion;

    /// Ciclo de ingreso de datos
    do{
        printf("\n Ingrese un nro: ");
        scanf("%d", &nro);
        apilar(&origen, nro);
        printf("\n Cualquier tecla para continuar - ESC para salir ");
        opcion=getch();
        apilar(&origen, opcion);
        system("cls");
    }
    while(opcion!=27);

    printf("\n Muestro pila Origen");
    mostrar(&origen);

    /// Muestro la pila origen
    while(!pilavacia(&origen)){
        printf("\n %d", tope(&origen));
        apilar(&aux1, desapilar(&origen));
    }

    /// Vuelvo a poner los datos de aux1 en origen
    while(!pilavacia(&aux1)){
        apilar(&origen, desapilar(&aux1));
    }
    /// Paso la pila origen a la pila aux1
    while(!pilavacia(&origen)){
        apilar(&aux1, desapilar(&origen));
    }
    /// Paso la pila aux1 a la pila aux2
    while(!pilavacia(&aux1)){
        apilar(&aux2, desapilar(&aux1));
    }
    /// Paso la pila aux2 a la pila origen
    while(!pilavacia(&aux2)){
        apilar(&origen, desapilar(&aux2));
    }

    printf("\n Muestro pila Origen");
    mostrar(&origen);

    printf("\n Muestro pila Aux1");
    mostrar(&aux1);

    printf("\n Muestro pila Aux2");
    mostrar(&aux2);

    printf("Hello world!\n");
    return 0;
}
