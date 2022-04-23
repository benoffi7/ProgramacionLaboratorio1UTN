#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define DIM_NOTAS 100
#define DIM_DNIS 50

int cargaArregloRandom(int a[], int dim);
void muestraArreglo(int a[], int v);
int cargaArregloUsuario(int a[], int dim, int v);
int sumaArreglo(int a[], int v);
float promedioArreglo(int a[], int v);

int main()
{
    int notas[DIM_NOTAS];
    int validosNotas=0;
    int dnis[DIM_DNIS];
    int validosDnis=0;
    int totalNotas;
    int totalDnis;


    validosNotas = cargaArregloRandom(notas, 25);
    validosDnis = cargaArregloRandom(dnis, 5);
    totalNotas = sumaArreglo(notas, validosNotas);
    totalDnis = sumaArreglo(dnis, validosDnis);

    printf("\n Arreglo de Notas %p - validos = %d - total = %d - promedio = %.2f\n", notas, validosNotas, totalNotas, promedioArreglo(notas, validosNotas));
    muestraArreglo(notas, validosNotas);
    printf("\n Arreglo de DNIs %p - validos = %d - total = %d - promedio = %.2f\n", dnis, validosDnis, totalDnis, promedioArreglo(dnis, validosDnis));
    muestraArreglo(dnis, validosDnis);

    validosNotas = cargaArregloUsuario(notas, DIM_NOTAS, validosNotas);
    validosDnis = cargaArregloUsuario(dnis, DIM_DNIS, validosDnis);

    printf("\n Arreglo de Notas %p - validos = %d\n", notas, validosNotas);
    muestraArreglo(notas, validosNotas);
    printf("\n Arreglo de DNIs %p - validos = %d\n", dnis, validosDnis);
    muestraArreglo(dnis, validosDnis);

    return 0;
}

int cargaArregloRandom(int a[], int dim){
    int i;
    for(i=0;i<dim;i++){
        a[i]=rand()%100;
    }
    return i;
}

int cargaArregloUsuario(int a[], int dim, int v){
    char opcion=0;
    while(opcion!=27 && v<dim){
        printf("\n Ingrese un numero: ");
        scanf("%d", &a[v]);

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion=getch();
        system("cls");
        v++;
    }
    return v;
}

void muestraArreglo(int a[], int v){
    for(int i=0;i<v;i++){
        printf("%d | ", a[i]);
    }
}

int sumaArreglo(int a[], int v){
    int total=0;
    for(int i=0;i<v;i++){
        total = total + a[i];
    }
    return total;
}

float promedioArreglo(int a[], int v){
    return (float)sumaArreglo(a, v)/v;
}
