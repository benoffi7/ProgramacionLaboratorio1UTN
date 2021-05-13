#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cargaArregloRandom(int n[], int dim);
void muestraArreglo(int n[], int v);
int buscaPosMenor(int n[], int v);
int buscaPosMenorParaOrdenar(int n[], int c, int v);
void ordenaPorSel(int n[], int v);
void intercambio(int *a, int *b);
int cargaArreglo(int a[], int v, int dim);
void cargaMatriz(int fil, int col, int m[fil][col]);
void muestraMatriz(int fil, int col, int m[fil][col]);

int main()
{
    srand(time(NULL));
    char nombres[100][30];
    int vNombres=0;

    int matriz[10][10];

    int notas[100];
    int vNotas=0;
    int posMenor;

    vNotas = cargaArregloRandom(notas, 20);
    printf("\n Notas recien cargadas\n");
    muestraArreglo(notas, vNotas);

    vNotas = cargaArreglo(notas, vNotas, 100);

    posMenor = buscaPosMenor(notas, vNotas);
    printf("\n La nota menor es: %d y esta en la posicion: %d\n", notas[posMenor], posMenor);

    ordenaPorSel(notas, vNotas);

    printf("\n Notas ordenadas\n");
    muestraArreglo(notas, vNotas);

    printf("\n Carga y Muestra matriz\n");
    cargaMatriz(10, 10, matriz);
    muestraMatriz(10, 10, matriz);

    vNombres = cargaNombres(nombres, 100);
    printf("\n Listado de Nombres\n");
    muestraNombres(nombres, vNombres);

    return 0;
}

int cargaArregloRandom(int n[], int dim){
    int i;
    for(i=0;i<dim;i++){
        n[i]=rand()%110;
    }

    return i;
}

void muestraArreglo(int n[], int v){
    for(int i=0;i<v;i++){
        printf("[%d]", n[i]);
    }
}

int buscaPosMenor(int n[], int v){
    int i=0;
    int posMenor=i;
    i++;

    while(i<v){
        if(n[i]<n[posMenor]){
            posMenor = i;
        }
        i++;
    }

    return posMenor;
}

int buscaPosMenorParaOrdenar(int n[], int c, int v){
    int i=c;
    int posMenor=i;
    i++;

    while(i<v){
        if(n[i]<n[posMenor]){
            posMenor = i;
        }
        i++;
    }

    return posMenor;
}

void ordenaPorSel(int n[], int v){
    int posMenor;
    int i=0;
    while(i<v-1){
        posMenor = buscaPosMenorParaOrdenar(n, i, v);
        intercambio(&n[i], &n[posMenor]);
        i++;
    }
}

void intercambio(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int cargaArreglo(int a[], int v, int dim){
    char opcion=0;

    while(v<dim && opcion!=27){
        printf("\n Ingrese una nota: ");
        scanf("%d", &a[v]);

        while(a[v] < 0 || a[v] > 10){
            printf("\n Ingrese una nota: ");
            scanf("%d", &a[v]);
        }
        v++;

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion = getch();
        system("cls");
    }

    return v;
}

void cargaMatriz(int fil, int col, int m[fil][col]){
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            m[i][j]=rand()%100;
        }
    }
}

void muestraMatriz(int fil, int col, int m[fil][col]){
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            printf("[%d]", m[i][j]);
        }
        printf("\n");
    }
}

int cargaNombres(char nombres[][30], int dim){
    int i=0;
    char opcion=0;

    while(i<dim && opcion!=27){
        printf("\n Ingrese un nombre: ");
        scanf("%s", nombres[i]);
        i++;

        printf("\n ESC para salir ...");
        opcion = getch();
        system("cls");
    }
    return i;
}

void muestraNombres(char nombres[][30], int v){
    for(int i=0;i<v;i++){
        if(strcmp(nombres[i],"Sergio")==0){
            strcpy(nombres[i],"otra cosa");
        }
        printf("\n %s", nombres[i]);
    }
}
