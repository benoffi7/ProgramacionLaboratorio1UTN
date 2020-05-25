#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"

#define ESC 27
#define DIM_SALARIOS 50

int existeArreglo(int a[], int v, int dato);
int cargaSalarios(int a[], int v, int dim);
void muestraSalarios(int a[], int v);
void muestraSalariosPila(Pila p);
void arreglo2Pilas(int a[], int v, Pila *p1, Pila *p2);
void cuentaBilletes1(Pila p, int a[]);
int denominacion(int i;);
void muestraCantBilletes(int a[]);
int main()
{
    Pila mayores, menores;
    inicpila(&mayores);
    inicpila(&menores);
    int salarios[DIM_SALARIOS];
    int vSalarios=0;
    int contador[6]={0};

    vSalarios=cargaSalarios(salarios,vSalarios,DIM_SALARIOS);
    printf("\n\n Listado de Salarios");
    muestraSalarios(salarios,vSalarios);

    arreglo2Pilas(salarios, vSalarios, &menores, &mayores);

    printf("\n\n Salarios Mayores a 15000");
    muestraSalariosPila(mayores);

    printf("\n\n Salarios Menores a 15000");
    muestraSalariosPila(menores);

    cuentaBilletes1(mayores, contador);
    muestraCantBilletes(contador);

    printf("\n\nHello UTN!\n");
    return 0;
}

/****************************************************************************//*****
*
* \brief Función que busca un elemento en un arreglo de tipo INT
* \param int arreglo
* \param int validos
* \param int el dato a buscar
* \return int 0 si no existe ó 1 si existe
*
**********************************************************************************/
int existeArreglo(int a[], int v, int dato){
    int i=0;
    int flag=0;
    while(i<v && !flag){
        if(a[i]==dato){
            flag=1;
        }
        i++;
    }

    return flag;
}

/*********************************************************************************
*
* \brief Función que carga un arreglo de tipo int de manera aleatoria
* \param int arreglo
* \param int validos
* \param int dimension
* \return void
*
**********************************************************************************/
int cargaSalarios(int a[], int v, int dim){
    int salario;
    for(int i=0;i<50;i++){
        salario=rand()%40000+10000;
        if(!existeArreglo(a,v,salario)){
            a[v]=salario;
            v++;
        }
    }
    return v;
}

/*********************************************************************************
*
* \brief Función que muestra un arreglo de tipo INT
* \param int arreglo
* \param int validos
* \return void
*
**********************************************************************************/
void muestraSalarios(int a[], int v){
    for(int i=0;i<v;i++){
        if(i%10==0){
            printf("\n");
        }
        printf("%d - ",a[i]);
    }
}

/*********************************************************************************
*
* \brief Función que muestra una pila
* \param Pila
* \return void
*
**********************************************************************************/
void muestraSalariosPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int i=0;
    while(!pilavacia(&p)){
        if(i%10==0){
            printf("\n");
        }
        printf("%d - ",tope(&p));
        apilar(&aux, desapilar(&p));
        i++;
    }
}

/*********************************************************************************
*
* \brief Función que copia el arreglo en 2 pilas
* \param int arreglo
* \param int validos
* \param Pila *menores
* \param Pila *mayores
* \return void
*
**********************************************************************************/
void arreglo2Pilas(int a[], int v, Pila *p1, Pila *p2){
    for(int i=0;i<v;i++){
        if(a[i]>15000){
            apilar(p2,a[i]);
        }else{
            apilar(p1,a[i]);
        }
    }
}

/*********************************************************************************
*
* \brief Función que cuenta la cantidad de billetes
* \param Pila p
* \param int arreglo
* \return void
*
**********************************************************************************/
void cuentaBilletes1(Pila p, int a[]){
    Pila aux;
    inicpila(&aux);
    int sueldo=0;

    while(!pilavacia(&p)){
        sueldo=tope(&p);
        if(sueldo>1000){
            a[0]+=sueldo/1000;
            sueldo=sueldo%1000;
        }
        if(sueldo>500){
            a[1]+=sueldo/500;
            sueldo=sueldo%500;
        }
        if(sueldo>200){
            a[2]+=sueldo/200;
            sueldo=sueldo%200;
        }
        if(sueldo>100){
            a[3]+=sueldo/100;
            sueldo=sueldo%100;
        }
        if(sueldo>50){
            a[4]+=sueldo/50;
            sueldo=sueldo%50;
        }
        if(sueldo>10){
            a[5]+=sueldo/10;
            sueldo=sueldo%10;
        }
        apilar(&aux, desapilar(&p));
    }
}


/*********************************************************************************
*
* \brief Función que calcula el total de billetes
* \param int arreglo
* \return int
*
**********************************************************************************/
int sumaBilletes(int a[]){
    int total=0;
    for(int i=0;i<6;i++){
        total += a[i];
    }
    return total;
}

/*********************************************************************************
*
* \brief Función que retorna la denominacion del billete
* \param int indice
* \return int denominacion
*
**********************************************************************************/
int denominacion(int i){
    int deno=0;
    switch(i){
        case 0: deno=1000;
                break;
        case 1: deno=500;
                break;
        case 2: deno=200;
                break;
        case 3: deno=100;
                break;
        case 4: deno=50;
                break;
        case 5: deno=10;
    }
    return deno;
}

/*********************************************************************************
*
* \brief Función que muestra la cantidad de billetes de cada denominacion
* \param int arreglo
* \return void
*
**********************************************************************************/
void muestraCantBilletes(int a[]){
    int d;
    int total = sumaBilletes(a);
    float porcentaje;
    printf("\n\nTotal de billetes necesarios por denominacion:\n");
    for(int i=0;i<6;i++){
        d = denominacion(i);
        porcentaje = (float)a[i]*100/total;
        printf("\n Billetes de $%d: %d - %.2f%%", d, a[i], porcentaje);
    }
    printf("\n\n El total de billetes necesarios es: %d", total);
}
