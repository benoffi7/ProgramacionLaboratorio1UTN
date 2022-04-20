#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"
#include "gotoxy.h"

#define ESC 27

int randomRango(int min, int max);
void cargaPilaRandomRango(Pila *p, int min, int max, int cant);
void muestraPila(Pila c);
void cargaPilaUsuario(Pila *p, char titulo[]);
void muestraMenu();
void replicaChar(char c, int cant);

int main()
{
    Pila algo;
    inicpila(&algo);
    char opcion;

    do{
        system("cls");
        muestraMenu();

        opcion=getch();

        switch(opcion){
            case 49:
                cargaPilaRandomRango(&algo, -10, 25, 30);
                printf("\n Pila cargada con exito!!!!!!!");
                break;

            case 50:
                cargaPilaUsuario(&algo, "Ingrese una temperatura: ");
                printf("\n Pila cargada con exito!!!!!!!");
                break;

            case 51:
                if(!pilavacia(&algo)){
                    printf("\n\t\t <<<<<<<<<<< Mostrando la pila de temperaturas >>>>>>>>>>\n");
                    muestraPila(algo);
                }else{
                    printf("\n La pila no esta cargada \n");
                }
                break;
            case 27:
                printf("\n Bye Bye ...........");
                break;
        }
        getch();

    }while(opcion!=ESC);

    return 0;
}

int randomRango(int min, int max){
    return rand()%(max-min)+min;
}

/** \brief Funcion que carga una pila con una cantidad N de numeros aleatorio entre un rango
 *
 * \param Pila * - puntero a pila
 * \param int min - rango minimo
 * \param int max - rango maximo
 * \param int cant - cantidad de datos a cargar
 * \return sin retorno
 *
 */
void cargaPilaRandomRango(Pila *p, int min, int max, int cant){
    for(int i=0;i<cant;i++){
        apilar(p, randomRango(min, max));
    }
}

void cargaPilaUsuario(Pila *p, char titulo[]){
    char opcion;
    int num;

    do{
        printf("\n %s", titulo);
        scanf("%d", &num);

        apilar(p, num);

        printf("\n ESC para salir o cualquier tecla para continuar ");
        opcion=getch();
        system("cls");
    }while(opcion != ESC);
}

void muestraPila(Pila c){
    Pila aux;
    inicpila(&aux);
    int cont = 0;
    while(!pilavacia(&c)){
        if(cont%15==0){
            printf("\n");
        }
        printf("%d | ", tope(&c));
        apilar(&aux, desapilar(&c));
        cont++;
    }
}

void muestraMenu(){
    printf("\n");
    replicaChar('=',80);
    printf("\n\t\t <<<<<<<<<<< Menu Guia 3 >>>>>>>>>>>\n\n");

    printf("\n 1 - Carga pila random rango");
    printf("\n 2 - Carga pila con intervencion del usuario");
    printf("\n 3 - Muestra la pila");
    printf("\n ESC para salir \n");

    printf("\n");
    replicaChar('=',80);
}

void replicaChar(char c, int cant){
    for(int i=0;i<cant;i++){
        printf("%c", c);
    }
}
