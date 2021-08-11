#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define DIM_NOTAS 100
#define DIM_DNIS 1000

int main()
{
    Pila d, aux;
    inicpila(&d);
    inicpila(&aux);

    int cont[10]={0};
    int dnis[DIM_DNIS];
    int notas[DIM_NOTAS];
    int validosNotas=0;
    int validosDnis=0;

    validosNotas = cargaArregloUsuario(notas, validosNotas, DIM_NOTAS);

    printf("\n Arreglo de Notas\n");
    muestraArreglo(notas, validosNotas);

    system("pause");

    validosNotas=cargaArregloRandom(notas, validosNotas, DIM_NOTAS);
    validosDnis=cargaArregloRandomConLimite(dnis, validosDnis, DIM_DNIS, 40, 5100000, 50000000);

    printf("\n Arreglo de Notas\n");
    muestraArreglo(notas, validosNotas);

    printf("\n Arreglo de DNIs\n");
    muestraArreglo(dnis, validosDnis);

    int buscado = buscaNota(notas, validosNotas, 9);
    if(buscado !=-1){
        printf("\n La nota es: %d", notas[buscado]);
    }else{
        printf("\n La nota no existe!!!");
    }

    arreglo2pila(dnis, validosDnis, &d);

    printf("\n <<<<<<<<<<<<<<<< DNIs terminados en 1 - 3 y 5 >>>>>>>>>>>>>>>");
    while(!pilavacia(&d)){
        printf("\n DNI: %d", dnis[tope(&d)]);
        apilar(&aux, desapilar(&d));
    }

    cuentaDNIs(dnis, validosDnis, cont);

    printf("\n Cantidad de dnis \n");
    for(int i=0;i<10;i++){
        printf("\n DNIs terminados en %d: %d", i, cont[i]);
    }

    muestraArregloHasta(dnis, validosDnis, tope(&d));

    printf("\nHello world!\n");
    return 0;
}

int randomRango(int min, int max){
    return rand()%(max-min) + min;
}

int cargaArregloRandom(int arreglo[], int validos, int dim){
    int i;
    for(i=validos;i<dim;i++){
        arreglo[i]=rand()%100;
    }
    return i;
}

int cargaArregloRandomConLimite(int arreglo[], int v, int dim, int cant, int min, int max){
    int limite=v+cant;
    if((v+cant) < dim){
        for(;v<limite;v++){
            arreglo[v]=randomRango(min, max);
        }
    }
    return v;
}

void muestraArreglo(int arreglo[], int v){
    for(int i=0;i<v;i++){
        printf("%d - ", arreglo[i]);
    }
}

void muestraArregloHasta(int arreglo[], int v, int hasta){
    int i=0;
    int flag=0;

    while(i < v && flag==0){
        if(arreglo[i] != hasta){
            flag = 1;
        }
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

void arreglo2pila(int a[], int v, Pila *p){
    int i=0;
    while(i < v){
        if(a[i]%10==1 || a[i]%10==3 || a[i]%10==5){
            apilar(p, i);
        }
        i++;
    }
}

void cuentaDNIs(int d[], int v, int cont[]){
    int indice;
    for(int i=0;i<v;i++){
        indice=d[i]%10;
        cont[indice]++;
    }
}
