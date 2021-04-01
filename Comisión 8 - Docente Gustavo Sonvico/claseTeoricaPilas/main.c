#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main()
{

    printf("Hello pilas!\n");

//    int unNumero;
//    unNumero=0;

    Pila pilita, pilota;
    inicpila(&pilita);
    inicpila(&pilota);

//    unNumero=0;
//
//    /// es similar a la asignacion por = de una variable
//    apilar(&pilita, 1);
//    apilar(&pilita, 2);
//    apilar(&pilita, 3);
//    apilar(&pilita, 4);
//    apilar(&pilita, 5);
//    apilar(&pilita, 6);
//    apilar(&pilita, 7);
//    apilar(&pilita, 8);
//
//    printf("Ingrese un valor a la variable: ");
//    scanf("%d", &unNumero);
//
//    /// es similar a realizar un scanf en una variable
//    leer(&pilita);
//    leer(&pilita);
//    leer(&pilita);
//    leer(&pilita);
//    leer(&pilita);
//    leer(&pilita);
//    leer(&pilita);
//    leer(&pilita);


/// debemos incluir la libreria #include <time.h>
/// seteamos la semilla para modifcar la secuencia random generada
    srand(time(NULL));

    int i=0, aux;

    for(i=0;i<50;i++)
    {
        apilar(&pilita, rand()%100);  /// entre 0 y 99
    }

    /// no esta permitido igualar (copiar) pilas de la siguiente manera
  //  pilota=pilita;
  /// pedorro en extremo


    printf("Contenido de pilita\n");
    mostrar(&pilita);

    system("pause");

    printf("Contenido de pilota\n");
    mostrar(&pilota);

    while(!pilavacia(&pilita))
    {
        apilar(&pilota, desapilar(&pilita));
    }

    printf("Contenido de pilita\n");
    mostrar(&pilita);

    printf("Contenido de pilota\n");
    mostrar(&pilota);



    return 0;
}
