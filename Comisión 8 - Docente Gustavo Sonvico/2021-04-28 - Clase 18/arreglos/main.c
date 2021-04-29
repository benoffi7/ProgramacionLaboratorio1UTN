#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

int cargaArregloIntUsuario(int a[], int v, int dim);
void muestraArregloInt(int a[], int v);
void muestraArregloIntW(int a[], int v);
int buscaNota(int a[], int v, int aBuscar);

#define DIM_NOTAS 100


int main()
{
    int notas[DIM_NOTAS]={10,5,3};
    int vNotas=3;
    int aBuscar=5;
    int encontrado;
    int cont[10]={0};


    vNotas = cargaArregloIntRandom(notas, 10);
    vNotas=cargaArregloIntUsuario(notas, vNotas, DIM_NOTAS);
    muestraArregloInt(notas, vNotas);
    encontrado=buscaNota(notas, vNotas, aBuscar);

    if(encontrado == -1){
        printf("\n La nota %d no existe en el arreglo", aBuscar);
    }else{
        printf("\n La nota %d se encuentra en la posicion %d y es %d", aBuscar, encontrado, notas[encontrado]);
    }

    cuentaTerminacionesDNI(notas, vNotas, cont);

    for(int i=0;i<10;i++){
        printf("\n Hay %d notas terminadas en %d\n",cont[i],i);
    }

    printf("\nHello world!\n");
    return 0;
}

int cargaArregloIntRandom(int a[], int dim){
    int i;
    for(i=0;i<dim;i++){
        a[i]=rand()%11;
    }
    return i;
}

int cargaArregloIntUsuario(int a[], int v, int dim){
    int i=v;
    char opcion=0;

    while(i<dim && opcion!=27){
        printf("\n Ingrese una nota: ");
        scanf("%d", &a[i]);
        i++;

        printf("\n ESC para salir - cualquier tecla para continuar\n");
        opcion=getch();
    }
    return i;
}

void muestraArregloInt(int a[], int v){
    for(int i=0;i<v;i++){
        printf("[%d] ", a[i]);
    }
}

void muestraArregloIntW(int a[], int v){
    int i=0;
    while(i<v){
        printf("[%d] ", a[i]);
        i++;
    }
}

int buscaNota(int a[], int v, int aBuscar){
    int flag=-1;
    int i=0;

    while(i<v && flag==-1){
        if(a[i]==aBuscar){
            flag=i;
        }
        i++;
    }

    return flag;
}

void cuentaTerminacionesDNI(int d[], int v, int cont[]){
    int terminacion;
    for(int i=0;i<v;i++){
        terminacion = d[i]%10;
        cont[terminacion]++;
    }
}
