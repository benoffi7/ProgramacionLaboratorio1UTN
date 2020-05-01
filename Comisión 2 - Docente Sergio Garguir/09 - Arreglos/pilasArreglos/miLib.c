#include <stdio.h>
#include <stdlib.h>

/****************************************************//**
*
* \brief Muestra un arreglo de a 10 elementos por linea
* \param arreglo int
* \param sus validos
* \return es de tipo void
*
******************************************************/
void muestraArregloInt(int a[], int v){
    printf("\n___________________________________________________________________________\n");
    for(int i=0;i<v;i++){
        printf("%d - ", a[i]);
        if(i>0 && i%15==0){
            printf("\n");
        }
    }
    printf("\n____________________________________________________________________________\n");
}

/****************************************************//**
*
* \brief Carga el usuario un arreglo de tipo Int
* \param arreglo int
* \param sus validos
* \param la dimension
* \return retorna la cantidad de datos validos
*
******************************************************/
int cargaArregloInt(int a[], int v, int dim){
    char opcion=0;
    while(v<dim && opcion!=27){
        system("cls");
        printf("\n\nCarga de arreglo de enteros\n");
        printf("\n Ingrese un dato: ");
        scanf("%d",&a[v]);
        v++;

        printf("\n ESC para salir ......");
        opcion=getch();
    }
    return v;
}

/****************************************************//**
*
* \brief Carga un arreglo ordenado de tipo Int
* \param arreglo int
* \param sus validos
* \param la dimension
* \return retorna la cantidad de datos validos
*
******************************************************/
int cargaArregloOrdenadoInt(int a[], int v, int dim){
    int i;
    for(i=v; i<dim; i++){
        a[i]=i;
    }
    return i;
}
