#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define DIM_NOTAS 100
#define DIM_DNIS 1000

int main()
{
    int dnis[DIM_DNIS];
    int notas[DIM_NOTAS];
    int validosNotas=0;
    int validosDnis=0;

    validosNotas = cargaArregloUsuario(notas, validosNotas, DIM_NOTAS);

    printf("\n Arreglo de Notas");
    muestraArreglo(notas, validosNotas);

    system("pause");

    validosNotas=cargaArregloRandom(notas, validosNotas, DIM_NOTAS);
    validosDnis=cargaArregloRandom(dnis, validosDnis, DIM_DNIS);

    printf("\n Arreglo de Notas");
    muestraArreglo(notas, validosNotas);

    printf("\n Arreglo de DNIs");
    muestraArreglo(dnis, validosDnis);

    int buscado = buscaNota(notas, validosNotas, 9);
    if(buscado !=-1){
        printf("\n La nota es: %d", notas[buscado]);
    }else{
        printf("\n La nota no existe!!!");
    }

    printf("\nHello world!\n");
    return 0;
}

int cargaArregloRandom(int arreglo[], int validos, int dim){
    int i;
    for(i=validos;i<dim;i++){
        arreglo[i]=rand()%100;
    }
    return i;
}

int cargaArregloRandomConLimite(int arreglo[], int v, int dim, int cant){
    int limite=v+cant;
    if((v+cant) < dim){
        for(;v<limite;v++){
            arreglo[v]=rand()%1000;
        }
    }

    return v;
}

void muestraArreglo(int arreglo[], int v){
    for(int i=0;i<v;i++){
        printf("%d - ", arreglo[i]);
    }
}

int buscaNota(int arreglo[], int v, int nota){
    int flag=-1;
    int i=0;
    while(i<v && flag==-1){
        if(arreglo[i]==nota){
            printf("Lo encontre");
            flag=i;
        }
        i++;
    }
    return flag;
}

int cargaArregloUsuario(int a[], int v, int dim){
    char opcion=0;

    while(opcion!=27 && v < dim){
        printf("\n Ingrese una nota: ");
        scanf("%d", &a[v]);
        v++;

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion=getch();
    }
    return v;
}

