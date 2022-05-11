#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

int main()
{
    Pila temperaturas;
    Pila temperaturasMinimas;
    Pila temperaturasMaximas;
    inicpila(&temperaturas);
    inicpila(&temperaturasMinimas);
    inicpila(&temperaturasMaximas);
    int cantTemperaturas;
    int totalTemperaturas;
    int temp[100];
    int vTemp=0;


    cargaPilaUsuario(&temperaturas);
    printf("\n Temperaturas \n");
    muestraPila(temperaturas);

    pasaMayoresMenores(temperaturas, &temperaturasMinimas, &temperaturasMaximas);
    printf("\n Temperaturas Minimas \n");
    muestraPila(temperaturasMinimas);
    printf("\n Temperaturas Maximas \n");
    muestraPila(temperaturasMaximas);

    cantTemperaturas = cuentaPila(temperaturas, 20);
    totalTemperaturas = sumaPila(temperaturas, 20);

    printf("\n La cantidad de temperaturas mayores a 20 es: %d y el total es: %d", cantTemperaturas, totalTemperaturas);

    vTemp = pila2arreglo(temperaturas, temp, 100);
    muestraArreglo(temp, vTemp);

    return 0;
}


/**
1.	Hacer una función para cargar una pila de temperaturas con intervención del usuario
 validando que estén dentro del rango de valores elegido por el usuario.
 */

 void cargaPilaUsuario(Pila *p){
    char opcion;
    int temperatura;
    int tempMin;
    int tempMax;

    printf("\n Ingrese la temperatura minima: ");
    scanf("%d", &tempMin);
    printf("\n Ingrese la temperatura maxima: ");
    scanf("%d", &tempMax);

    do{
        do{
            system("cls");
            printf("\n Ingrese una temperatura: ");
            scanf("%d", &temperatura);
            if(temperatura < tempMin || temperatura > tempMax){
                printf("\n\n\t La temperatura no es valida intente nuevamente");
                getch();
            }else{
                apilar(p, temperatura);
            }
        }while(temperatura < tempMin || temperatura > tempMax);
        printf("\n\n ESC para salir o cualquier tecla para continuar");
        opcion=getch();

    }while(opcion!=ESC);
 }

 /**
 2.	Hacer una función que muestre la pila de las temperaturas (sin utilizar la función mostrar()
de la librería de pilas) Se deberán mostrar 15 temperaturas por línea.
*/

void muestraPila(Pila c){
    Pila aux;
    inicpila(&aux);
    int i=0;

    while(!pilavacia(&c)){
        if(i%15==0){
            printf("\n");
        }
        printf("%d - ", tope(&c));
        apilar(&aux, desapilar(&c));
        i++;
    }
}

/**
Hacer una función que copie a una pila menores las temperaturas <= 0 y a una pila mayores el resto de las temperaturas.
No se deben perder los datos de la pila original.
*/

void pasaMayoresMenores(Pila c, Pila *men, Pila *may){
    while(!pilavacia(&c)){
        if(tope(&c)<=0){
            apilar(men, desapilar(&c));
        }else{
            apilar(may, desapilar(&c));
        }
    }
}

/**
4.	Hacer una función que encuentre la temperatura mínima en la pila y la retorne
(la temperatura mínima debe quitarse de la pila).
*/

int buscaMenor(Pila *p){
    int menor;
    Pila aux;
    inicpila(&aux);

    if(!pilavacia(p)){
        menor = desapilar(p);
    }
    while(!pilavacia(p)){
        if(tope(p)<menor){
            apilar(&aux, menor);
            menor = desapilar(p);
        }else{
            apilar(&aux, desapilar(p));
        }
    }
    while(!pilavacia(&aux)){
        apilar(p, desapilar(&aux));
    }

    return menor;
}

/**
5.	Hacer una función que cuente las temperaturas de una pila, mayores a un valor dado y lo retorne. (el valor se recibe por parámetro).
*/

int cuentaPila(Pila c, int valor){
    Pila aux;
    inicpila(&aux);
    int cont=0;

    while(!pilavacia(&c)){
        if(tope(&c)>valor){
            cont++;
        }
        apilar(&aux, desapilar(&c));
    }

    return cont;
}

/**
6.	Hacer una función que sume las temperaturas de una pila, mayores a un valor dado y lo retorne. (el valor se recibe por parámetro).
*/
int sumaPila(Pila c, int valor){
    int total=0;
    int dato;

    while(!pilavacia(&c)){
        dato = desapilar(&c);
        if(dato>valor){
            total+=dato; /// es igual a esto  total = total + dato;
        }
    }

    return total;
}

/**
7.	Hacer una función que cargue un arreglo de temperaturas ordenado de menor a mayor a partir de la pila de temperaturas.
*/
int pila2arreglo(Pila c, int a[], int dim){
    int i=0;

    while(!pilavacia(&c) && i < dim){
        a[i] = buscaMenor(&c);
        i++;
    }

    return i;
}

/**
8.	Hacer una función que muestre un arreglo de temperaturas pero solo 20 por línea.
*/

void muestraArreglo(int a[], int v){
    for(int i=0;i<v;i++){
        if(i%20==0){
            printf("\n");
        }
        printf("%d | ", a[i]);
    }
}
