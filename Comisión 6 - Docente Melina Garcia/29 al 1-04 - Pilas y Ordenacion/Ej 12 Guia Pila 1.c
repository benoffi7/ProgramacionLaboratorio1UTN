#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>


int main()
{
    Pila DADA;
    Pila MODELO;
    char seguir;
    inicpila(&DADA);
    inicpila(&MODELO);

///forma cargada por el programador
//    apilar(&DADA,2);
//    apilar(&DADA,0);
//    apilar(&DADA,0);
//    apilar(&DADA,2);
//
//    apilar(&MODELO,1);
//    apilar(&MODELO,3);
//    apilar(&MODELO,6);

///forma ingresada por el usuario
//      do {
//
//        leer(&DADA);
//        printf("Si desea seguir cargando s/n \n");
//        fflush(stdin);
//        scanf("%c",&seguir);
//      }while(seguir == 's');
//
//        do {
//
//        leer(&MODELO);
//        printf("Si desea seguir cargando s/n \n");
//        fflush(stdin);
//        scanf("%c",&seguir);
//      }while(seguir == 's');

///forma cargada de manera azarosa
//int numero;
//int cantidad;
//srand(time(NULL));
//numero = rand() % 10; //y = x + 1; 0 y 9
//printf("%i", numero);
//cantidad = rand() % 51; // 0 al 50 MAXIMO

//int cantidad;
//srand(time(NULL));
//cantidad = rand() % 51; /// 0... 50
//
//for (int i = 0; i < cantidad ; i++)
//{
//    apilar(&DADA, rand() % 10); ///cargara la pila con valores del 0 al 9
//}
//
//mostrar(&DADA);



    return 0;
}
