#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila bajoCero, sobreCero;
    inicpila(&bajoCero);
    inicpila(&sobreCero);

    char caracteres[50]={'n','e','u','q','u','e','n'};
    int vCar = 7;

    int temperaturas[100]={-10,2,8,2,-10};
    int vTemp=5;

    int notas[100]={100,90,80,70,60};
    int vNotas=5;
    int capicua;
    int palindromo;

    char palabra[30]={"neuquen"};


    printf("\n Mostrar palabra\n");
    muestraArregloInt(palabra, strlen(palabra));

    printf("\n Arreglo de temperaturas\n");
    muestraArregloInt(temperaturas, vTemp);

    printf("\n Arreglo de temperaturas invertido\n");
    muestraArregloIntInvertido(temperaturas, vTemp);

    printf("\n Arreglo de notas\n");
    muestraArregloInt(notas, vNotas);

    invierteArregloInt(notas, vNotas);

    printf("\n Arreglo de notas\n");
    muestraArregloInt(notas, vNotas);


    capicua = esCapicua(temperaturas, vTemp);
    if(capicua==1){
        printf("\n El arreglo es capicua");
    }else{
        printf("\n El arreglo NO es capicua");
    }

    capicua = esCapicua(notas, vNotas);
    if(capicua){
        printf("\n El arreglo es capicua");
    }else{
        printf("\n El arreglo NO es capicua");
    }

    palindromo = esPalindromo(caracteres, vCar);
    if(palindromo){
        printf("\n La palabra es un palindromo");
    }else{
        printf("\n La palabra NO es un palindromo");
    }

    printf("\nHello world!\n");

    arreglo2pila(temperaturas, vTemp, &bajoCero, &sobreCero);
    mostrar(&bajoCero);
    mostrar(&sobreCero);

    return 0;
}

void muestraArregloInt(int a[], int v){
    for(int i=0;i<v;i++){
        printf("[%d]", a[i]);
    }
}

void muestraArregloIntInvertido(int a[], int v){
    for(int i=v-1;i>=0;i--){
        printf("[%d]", a[i]);
    }
}

/// -10   2    2   -10
///   0   1    2    3    4
int esCapicua(int a[], int v){
    int i = 0;
    int f = v-1;
    int flag = 1;

    while(i<f && flag==1){
        if(a[i]==a[f]){
            i++;
            f--;
        }else{
            flag=0;
        }
    }

    return flag;
}

int esPalindromo(char a[], int v){
    int i = 0;
    int f = v-1;
    int flag = 1;

    while(i<f && flag==1){
        if(a[i]==a[f]){
            i++;
            f--;
        }else{
            flag=0;
        }
    }

    return flag;
}

///  100  90   80   70   60
///   0   1    2    3    4    5
void invierteArregloInt(int a[], int v){
    int i=0;
    int f=v-1;
    int aux;

    while(i<f){
        intercambio(&a[i], &a[f]);
        i++;
        f--;
    }
}

void intercambio(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void arreglo2pila(int t[], int v, Pila *b, Pila *s){
    for(int i=0;i<v;i++){
        if(t[i]>0){
            apilar(s, t[i]);
        }else{
            apilar(b, t[i]);
        }
    }
}

int pila2arreglo(Pila p, int a[], int dim){
    Pila aux;
    inicpila(&aux);
    int i=0;
    while(!pilavacia(&p) && i<dim){
        if(tope(&p)%2==0){
            a[i]=tope(&p);
            i++;
        }
        apilar(&aux, desapilar(&p));
    }

    return i;
}
