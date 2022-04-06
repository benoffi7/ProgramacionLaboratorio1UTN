#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

#define ESC 27

int main()
{
    srand(time(NULL));
    Pila notas, auxNotas;
    inicpila(&notas);
    inicpila(&auxNotas);

    int nota;
    int contador = 0;
    int totalNotas = 0;
    float promedio;

    char opcion;

    /// ciclo de carga con intervención del usuario
    do{
        printf("\n Ingrese una nota: ");
        scanf("%d", &nota);

        apilar(&notas, nota);

        printf("\n ESC para salir o cualquier tecla para continuar ");
        opcion = getch();

    }while(opcion != ESC);

    /// ciclo de carga random
    for(int i=0;i<15;i++){
        apilar(&notas, rand()%11);
    }

    /// Contar los elementos de una pila (usar variables enteras)
    while(!pilavacia(&notas)){
        apilar(&auxNotas, desapilar(&notas));
        contador++;
    }

    while(!pilavacia(&auxNotas)){
        apilar(&notas, desapilar(&auxNotas));
    }

    /// Sumar los elementos de una pila (usar variables enteras)
    while(!pilavacia(&notas)){
        totalNotas += tope(&notas);
        /// totalNotas = totalNotas + tope(&notas);
        apilar(&auxNotas, desapilar(&notas));
    }

    while(!pilavacia(&auxNotas)){
        apilar(&notas, desapilar(&auxNotas));
    }

    printf("\n\n <<<<<<<<<<<< Notas >>>>>>>>>>>> \n");
    while(!pilavacia(&notas)){
        printf("%d - ", tope(&notas));
        apilar(&auxNotas, desapilar(&notas));
    }

    while(!pilavacia(&auxNotas)){
        apilar(&notas, desapilar(&auxNotas));
    }

    promedio = (float)totalNotas / contador;

    printf("\n\n La cantidad de notas ingresadas es....: \t %d", contador);
    printf("\n El total de notas ingresadas es.......: \t %d", totalNotas);
    printf("\n El promedio de las notas ingresadas es: \t %.2f", promedio);

    return 0;
}
