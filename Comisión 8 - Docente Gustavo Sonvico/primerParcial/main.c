#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"


/// 1
void cargarPrecipitaciones(Pila * P, int diasMes);
void cargarPrecipitacionesUsr(Pila * P, int diasMes);

///2
int separarPrecipitaciones(Pila P, Pila * A, int B[], int dim);
void mostrarArreglo(int B[], int validos);

///3.1
float promedioPrecipitaciones(int B[], int validos);
///3.2
float porcentajePrecipitacionesMenores(Pila A, int limite);
///3.3
void subProgramaPromedioAndPorcentaje(Pila A, int B[], int validos);

///4.1
int buscaPosValorMaximo(int B[], int validos);
///4.2
int buscaValorMinimo(Pila A);
///4.3
void subProgramaMaximoAndMinimo(Pila A, int B[], int validos);

void menu();

int main()
{
    printf("Hello primer parcial!\n");

    srand(time(NULL));

    Pila precipitaciones;
    inicpila(&precipitaciones);

    Pila precipInferiores;
    inicpila(&precipInferiores);

    int arregloPrecipSuperiores[30];
    int cantPrecipSup=0;

  //  menu();

    cargarPrecipitaciones(&precipitaciones, 30);
    //cargarPrecipitacionesUsr(&precipitaciones, 30);
    printf("Precipitaciones totales:\n");
    mostrar(&precipitaciones);

    printf("\n---------------\n");

    cantPrecipSup=separarPrecipitaciones(precipitaciones, &precipInferiores, arregloPrecipSuperiores, 30);

    printf("Precipitaciones inferiores:\n");
    mostrar(&precipInferiores);

    mostrarArreglo(arregloPrecipSuperiores, cantPrecipSup);

    printf("\n---------------\n");
    subProgramaPromedioAndPorcentaje(precipInferiores, arregloPrecipSuperiores, cantPrecipSup);

    printf("\n---------------\n");
    subProgramaMaximoAndMinimo(precipInferiores, arregloPrecipSuperiores, cantPrecipSup);

    return 0;
}

/// 1
void cargarPrecipitaciones(Pila * P, int diasMes)
{
    int i, valor;

    for(i=0; i<diasMes; i++)
    {
        valor=rand()%181;
        apilar(P, valor);
    }
}

void cargarPrecipitacionesUsr(Pila * P, int diasMes)
{
    int i, valor;

    printf("Cargando las precipitaciones del mes: \n");

    for(i=0; i<diasMes; i++)
    {
       printf("Ingrese precipitacion: ");
       scanf("%d", &valor);

       while(valor<0 || valor>180)
       {
           printf("Precipitacion imposible! Ingrese nuevamente: ");
           scanf("%d", &valor);
       }
        apilar(P, valor);
    }
}

///2
int separarPrecipitaciones(Pila P, Pila * A, int B[], int dim)
{
    int i=0;

    while(!pilavacia(&P) && i <dim)
    {
        if(tope(&P)<61)
        {
            apilar(A, desapilar(&P));
        }
        else
        {
            B[i]=desapilar(&P);
            i++;
        }
    }
    return i;
}

/// aux
void mostrarArreglo(int B[], int validos)
{
    int i;

    printf("Contenido del arreglo de precipipaciones superiores: ");

    for(i=0; i<validos; i++)
    {
        if(i%10==0)
            printf("\n");
        printf(" %d", B[i]);
    }
}

///3.1
float promedioPrecipitaciones(int B[], int validos)
{
    int i, suma=0;
    float promedio=0;

    for(i=0; i<validos; i++)
    {
        suma=suma+B[i];
    }

    if(validos>0)
    {
        promedio=(float)suma/(float)validos;
    }

    return promedio;
}
///3.2
float porcentajePrecipitacionesMenores(Pila A, int limite)
{
    int cantTotal=0, cantParcial=0, aux;
    float porcentaje=0;

    while(!pilavacia(&A))
    {
        if(tope(&A)<limite)
        {
            cantParcial++;
        }
        aux=desapilar(&A);
        cantTotal++;
    }

    porcentaje=(float)(cantParcial*100)/(float)cantTotal;

    return porcentaje;
}
///3.3
void subProgramaPromedioAndPorcentaje(Pila A, int B[], int validos)
{
    int valorReferencia;
    float promedio, porcentaje;

    printf("Ingrese la precipitacion para averiguar el porcentaje menor: ");
    scanf("%d", &valorReferencia);

    promedio=promedioPrecipitaciones(B, validos);

    porcentaje=porcentajePrecipitacionesMenores(A, valorReferencia);

    printf("El promedio de precipitaciones cargadas es de %.2f mm mensuales\n", promedio);

    printf("El porcentaje de precipitaciones menores a %d mm es de %.2f %%", valorReferencia, porcentaje);

}

///4.1
int buscaPosValorMaximo(int B[], int validos)
{
    int i=0;
    int maximo=B[i];
    int posMax=i;

    for(i=1; i<validos; i++)
    {
        if(B[i]>maximo)
        {
            maximo=B[i];
            posMax=i;
        }
    }

    return posMax;
}
///4.2
int buscaValorMinimo(Pila A)
{
    int minimo, aux;

    if(!pilavacia(&A))
    {
        minimo=desapilar(&A);

        while(!pilavacia(&A))
        {
            if(tope(&A)<minimo)
            {
                minimo=desapilar(&A);
            }
            else
            {
                aux=desapilar(&A);
            }
        }
    }
    return minimo;
}
///4.3
void subProgramaMaximoAndMinimo(Pila A, int B[], int validos)
{
    int menor, posMayor;

    menor=buscaValorMinimo(A);

    posMayor=buscaPosValorMaximo(B, validos);

    printf("El valor menor en la pila es %d\n", menor);

    printf("La posicion del valor mayor en el arreglo es %d y su valor es %d", posMayor, B[posMayor]);
}

void menu()
{
    system("cls");
    printf("Opciones del sistema de precipitaciones: \n");
    printf("1- Cargar precipitaciones \n");
    printf("2- Separar precipitaciones \n");
    printf("3- Promedio y porcentaje de precipitaciones \n");
    printf("4- Precipitaciones maxima y minima\n\n");
    printf("Seleccione una opcion: ");
}
