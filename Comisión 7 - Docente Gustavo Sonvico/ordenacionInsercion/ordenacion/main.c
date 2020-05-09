#include <stdio.h>
#include <stdlib.h>

float sumaArrayFloat(float a[], int v);
void mostrarArregloFloat(float a[], int v);


int main()
{
    float arr[100]={0.3,5.2,6.3,5.2,4.1,8.9,9.1,5.4,0.3,5.2,6.3,5.2,4.1,8.9,9.1,5.4,0.3,5.2,6.3,5.2,4.1,8.9,9.1,5.4};
    int vArr=24;

    mostrarArregloFloat(arr, vArr);
    printf("\n\n %.2f", sumaArrayFloat(arr, vArr));

    printf("\nHello world!\n");
    return 0;
}

/********************************************************************//**
*
* \brief Inserta un elemento en un arreglo ordenado de tipo Int
* \brief Es responsabilidad del programador verificar que hay espacio en el arreglo
* \param arreglo de tipo int
* \param sus validos
* \param el dato a insertar
* \return validos
*
***********************************************************************/
int insertarInt(int a[], int v, int dato){
    int i=v-1;
    while(i>=0 && a[i]>dato){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=dato;
    return v+1;
 }

 /********************************************************************//**
*
* \brief Inserta un elemento en un arreglo ordenado de tipo Int
* \brief Para ser usada para la ordenación por insercion
* \param arreglo de tipo int
* \param sus validos
* \param el dato a insertar
* \return v
*
***********************************************************************/
void insertarPOInt(int a[], int v, int dato){
    int i=v;
    while(i>=0 && a[i]>dato){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=dato;
 }

/********************************************************************//**
*
* \brief Ordena por insercion un arreglo de tipo Int
* \param arreglo de tipo int
* \param sus validos
* \return void
*
***********************************************************************/
void ordenaPorInsercionInt(int a[], int v){
    int i=0;
    while(i<v-1){
        insertarPOInt(a, i, a[i+1]);
        i++;
    }
}


/********************************************************************//**
*
* \brief Suma los elementos de un arreglo de tipo Float
* \param arreglo de tipo float
* \param sus validos
* \return float
*
***********************************************************************/
float sumaArrayFloat(float a[], int v){
    float suma=0;
    for(int i=0;i<v;i++){
        suma = suma + a[i];  /// suma += a[i];
    }
    return suma;
}

/********************************************************************//**
*
* \brief Muestra los elementos de un arreglo de tipo Float
* \param arreglo de tipo float
* \param sus validos
* \return void
*
***********************************************************************/
void mostrarArregloFloat(float a[], int v){
    for(int i=0; i<v;i++){
        if(i%15==0){
            printf("\n");
        }
        printf("%.2f - ",a[i]);
    }
}

/********************************************************************//**
*
* \brief Busca un elemento en un arreglo de tipo Int
* \param arreglo de tipo int
* \param sus validos
* \param dato a buscar
* \return 0 si no existe - 1 si existe
*
***********************************************************************/
int buscaElementoInt(int a[], int v, int dato){
    int flag = 0;
    int i=0;
    while(i<v && flag == 0){
        if(a[i] == dato){
            flag = 1;
        }
        i++;
    }
    return flag;
}


/********************************************************************//**
*
* \brief Busca un elemento en un arreglo de tipo Int
* \param arreglo de tipo int
* \param sus validos
* \param dato a buscar
* \return -1 si no existe - su posicion si existe
*
***********************************************************************/
int busca(int a[], int v, int dato){
    int encontrado = -1;
    int i=0;
    while(i<v && encontrado == -1){
        if(a[i] == dato){
            encontrado = i;
        }
        i++;
    }
    return encontrado;
}
