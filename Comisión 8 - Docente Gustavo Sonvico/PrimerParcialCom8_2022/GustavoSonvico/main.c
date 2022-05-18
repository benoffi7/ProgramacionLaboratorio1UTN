#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

/// 1
void cargarMinadoAutomatico(Pila * p, int veces, int modoSeguro);
void cargarMinadoUsuario(Pila * p, int veces, int modoSeguro);
void mostrarMinadoDiario(Pila minado);
int validaCoin(int coin, int modoSeguro);

/// 2
int separarCoins(Pila minadoDiario, Pila * valoresBajos, int arregloValoresAltos[], int dim);
void mostrarArreglo(int A[], int validos);

/// 3
int posMaximaCoin(int A[], int validos);

int menorCoin(Pila valoresBajos);

int gananciaTotalDia(Pila minadoDiario);

void subProgramaPunto3(Pila minadoDiario, Pila valoresBajos, int arregloValoresAltos[], int validos);

/// 4
float promedioEnArreglo(int A[], int validos);

float porcentajeEnPila(Pila valoresBajos);

void subprogramaPunto4(Pila valoresBajos, int arregloValoresAltos[], int validos);

/// 5

int main()
{
    srand(time(NULL));

    printf("Hello primer parcial!\n");

    Pila minadoDiario, minadosBajos;
    inicpila(&minadoDiario);
    inicpila(&minadosBajos);

    cargarMinadoAutomatico(&minadoDiario, 20, 1);

    cargarMinadoAutomatico(&minadoDiario, 20, 0);

    // cargarMinadoUsuario(&minadoDiario, 5, 0);

    printf("\n Punto 1");
    mostrarMinadoDiario(minadoDiario);

    printf("\n Punto 2");
    int minadosAltos[20];
    int validos=0;

    validos=separarCoins(minadoDiario, &minadosBajos, minadosAltos, 20);


    mostrarArreglo(minadosAltos, validos);

    mostrarMinadoDiario(minadosBajos);

    printf("\n Punto 3");

    subProgramaPunto3(minadoDiario, minadosBajos, minadosAltos, validos);

    printf("\n Punto 4");
    subprogramaPunto4(minadosBajos, minadosAltos, validos);

    return 0;
}

/// 1   modoSeguro on : 1 -- modoSeguro off: 0
void cargarMinadoAutomatico(Pila * p, int veces, int modoSeguro)
{
    int coin=0;

    /// corresponde limitar como maximo a 50 la carga por la implementacion
    /// que conocemos de la pila

    for(int i=0; i<veces && i<50; i++)
    {
        if(modoSeguro==1)
        {
            coin=(rand()%31)+10;   /// (0 a 30 ) + 10 = 10 a 40
        }
        else
        {
            coin=(rand()%121)-20;  /// (0 a 120) - 20 = -20 a 100
        }
        apilar(p,coin);
    }

}

int validaCoin(int coin, int modoSeguro)
{
    int rta =0;
    if(modoSeguro==1)
    {
        if(coin>=10 && coin<=40)
        {
            rta=1;
        }
    }
    else
    {
        if(coin>=-20 && coin<=100)
        {
            rta=1;
        }
    }
    return rta;
}

void cargarMinadoUsuario(Pila * p, int veces, int modoSeguro)
{
    int coin=0;
    for(int i=0; i<veces && i<50; i++)
    {
        printf("Ingrese una coin generada: ");
        scanf("%d", &coin);

        while(validaCoin(coin, modoSeguro)==0)
        {
            printf("Coin ingresada no valida, ingrese nuevamente: ");
            scanf("%d", &coin);
        }
        apilar(p, coin);
    }
}

void mostrarMinadoDiario(Pila minado)
{
    printf("\nMinado obtenido en el dia:\n");

    while(!pilavacia(&minado))
    {
        printf("|%d", desapilar(&minado));
    }
    printf("|\n");
}

/// 2
int separarCoins(Pila minadoDiario, Pila * valoresBajos, int arregloValoresAltos[], int dim)
{
    int i=0;

    while(!pilavacia(&minadoDiario)&& i< dim)
    {
        if(tope(&minadoDiario)<=40)
        {
            apilar(valoresBajos, desapilar(&minadoDiario));
        }
        else
        {
            arregloValoresAltos[i]=desapilar(&minadoDiario);
            i++;
        }
    }
    return i;
}

void mostrarArreglo(int A[], int validos)
{
    printf("\nContenido del arreglo de coins: \n");
    for(int i=0; i<validos; i++)
    {
        printf("|%d", A[i]);
    }
    printf("|\n");
}

/// 3
int posMaximaCoin(int A[], int validos)
{
    int i=0, posMax, maximaCoin;

    maximaCoin=A[i];
    posMax=i;

    for(i=1; i<validos; i++)
    {
        if(A[i]>maximaCoin)
        {
            maximaCoin=A[i];
            posMax=i;
        }
    }
    return posMax;
}

int menorCoin(Pila valoresBajos)
{
    int menor, deGoma;

    if(!pilavacia(&valoresBajos))
    {
        menor=desapilar(&valoresBajos);

        while(!pilavacia(&valoresBajos))
        {
            if(tope(&valoresBajos)<menor)
            {
                menor=desapilar(&valoresBajos);
            }
            else
            {
                deGoma=desapilar(&valoresBajos);
            }
        }
    }
    return menor;
}

int gananciaTotalDia(Pila minadoDiario)
{
    int ganancia=0;
    while(!pilavacia(&minadoDiario))
    {
        ganancia=ganancia+desapilar(&minadoDiario);
    }
    return ganancia;
}

void subProgramaPunto3(Pila minadoDiario, Pila valoresBajos, int arregloValoresAltos[], int validos)
{
    int posMax = posMaximaCoin(arregloValoresAltos, validos);
    int coinMenor=menorCoin(valoresBajos);
    int ganancia=gananciaTotalDia(minadoDiario);

    printf("\n La pos del mayor valor en el arreglo es %d y su valor es %d\n", posMax, arregloValoresAltos[posMax]);
    printf("\n La menor coin generada fue %d\n", coinMenor);
    printf("\n La ganancia total fue de %d coins\n", ganancia);
}

float promedioEnArreglo(int A[], int validos)
{
    int sumaTotal=0;
    float prom=0;

    for(int i=0; i<validos; i++)
    {
        sumaTotal+=A[i];
    }

    if(validos>0)
    {
        prom = (float)sumaTotal/validos;
    }

    return prom;
}

float porcentajeEnPila(Pila valoresBajos)
{
    int total=0;
    int negativos=0;
    int trash=0;
    float porcent;

    while(!pilavacia(&valoresBajos))
    {
        if(tope(&valoresBajos)<0)
        {
            negativos++;
        }
        trash=desapilar(&valoresBajos);
        total++;
    }

    if(total>0)
    {
        porcent = (float)(negativos*100)/total;
    }
    return porcent;
}

void subprogramaPunto4(Pila valoresBajos, int arregloValoresAltos[], int validos)
{
    float promedioArreglo=promedioEnArreglo(arregloValoresAltos, validos);
    float porcentajeNegativos=porcentajeEnPila(valoresBajos);

    printf("\n El promedio en el arreglo es de %.2f\n", promedioArreglo);
    printf("\n El porcentaje de valores negativos en la pila fue de %.2f", porcentajeNegativos);

}
