#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/// trabajo con una constante para declarar el tamaño de las
/// columnas... asi puedo utilizarlo en los parametros
/// de las funciones (para indicar columnas de las matrices)
/// asi mis funciones son mas dinamicas y puedo enviarle
/// matrices de tamaño variable

/// para matrices de enteros
const int maxC = 5;

/// para arreglo de palabras
const int maxCP=30;


//////////////////////////////////////////////////////////////////////


/// 1. Hacer una función que reciba como parámetro una matriz de
/// números enteros y permita que el usuario ingrese valores al mismo
/// por teclado. La función debe cargar la matriz por completo.

void cargaMatriz (int M[][maxC], int dimF, int dimC)
{
    int f=0; /// filas
    int c=0; /// columnas

    printf("\nCargando la matriz: \n");
    for(f=0; f<dimF; f++)
    {
        for(c=0; c<dimC; c++)
        {
            printf("\nIngrese un valor entero: ");
            scanf("%d", &M[f][c]);
        }
    }
}

/// 2. Hacer una función que reciba como parámetro una matriz de números
/// enteros y la muestre por pantalla (en formato matricial)

void mostrarMatriz (int M[][maxC], int valF, int valC)
{
    int f=0;
    int c=0;

    printf("\nContenido de la matriz: \n");
    for(f=0; f<valF; f++)
    {
        for(c=0; c<valC; c++)
        {
            printf("%d ", M[f][c]);
        }
        printf("\n");
    }
}

/// esto es para mostrarla un poquito mas linda jeje
void mostrarMatrizTabulada (int M[][maxC], int valF, int valC)
{
    int f=0;
    int c=0;

    printf("\nContenido de la matriz: \n");
    for(f=0; f<valF; f++)
    {
        for(c=0; c<valC; c++)
        {
            switch(M[f][c])
            {
            case 0 ... 9:
                printf("   ");
                break;
            case 10 ... 99:
                printf("  ");
                break;
            case 100 ... 999:
                printf(" ");
            }
            printf("%d", M[f][c]);
        }
        printf("\n");
    }
}

/// 3. Hacer una función que reciba como parámetro una matriz de números
/// enteros y que cargue la misma con números aleatorios (sin intervención
/// del usuario). La función debe cargar la matriz por completo.

void cargaMatrizAutomatico(int M[][maxC], int valF, int valC)
{
    int f=0;
    int c=0;

    srand(time(NULL));


    printf("\nCargando la matriz de forma automatica con valores de 0 a 100\n");
    for(f=0; f<valF; f++)
    {
        for(c=0; c<valC; c++)
        {
            M[f][c]=rand()%101;
        }
    }
}


/// 4. Hacer una función tipo int que sume el contenido total de una matriz de números enteros.
int sumaMatriz(int M[][maxC], int valF, int valC)
{
    int f=0;
    int c=0;
    int suma=0;

    for(f=0; f<valF; f++)
    {
        for(c=0; c<valC; c++)
        {
            suma +=M[f][c];
        }
    }

    return suma;
}

int sumaArreglo(int A[], int validos)
{
    int i=0;
    int suma=0;

    for(i=0; i<validos; i++)
    {
        suma+=A[i];
    }
    return suma;
}

int sumaMatrizBis (int M[][maxC], int valF, int valC)
{
    int f=0;

    int suma=0;

    for(f=0; f<valF; f++)
    {
        /// utiliza la funcion sumaArreglo
        /// y trabaja cada fila de la matriz
        /// como si fuera un arreglo de dimension valC

        /// esta bueniiiiisimo!!!

        suma +=sumaArreglo(M[f], valC);
    }
    return suma;
}

/// 5. Hacer una función tipo float que calcule el promedio de una matriz de números enteros.

float promedioMatriz (int M[][maxC], int valF, int valC)
{
    int suma=0;
    int cantidad=0;
    float promedio=0;

    suma=sumaMatriz(M, valF, valC);
    cantidad=valF*valC;

    if(cantidad!=0)
        promedio=(float)suma/(float)cantidad;

    return promedio;
}
/// 6. Hacer una función que determine si un elemento se encuentra dentro de una matriz de
/// números enteros. La función recibe la matriz y el dato a buscar.

int buscaDatoEnMatriz (int M[][maxC], int valF, int valC, int dato)
{
    int f=0;
    int c=0;

    int flag=0;

    for(f=0; f<valF && flag==0; f++)
    {
        for(c=0; c<valC&& flag==0; c++)
        {
            if(M[f][c]==dato)
                flag=1;
        }
    }

    return flag;
}
/// 7. Hacer una función que cargue un arreglo de palabras (strings).
/// La función debe retornar cuantas palabras se cargaron.

int cargaMatrizPalabras(char P[][maxCP], int dimF)
{

    int f=0;
    char control='s';

    printf("\nCargando palabras al arreglo de palabras\nEn realidad es una matriz de char :P\n");
    while(f<dimF && control=='s')
    {
        printf("\nIngrese una palabra, no sea pedorro... \n maximo 30 caracteres: ");
        scanf(" %s", P[f]);

        /// tambien podemos usar gets

        /// gets(&P[f]);

        printf("\nSeguis??");
        scanf(" %c", &control);

        f++;
    }

    return f;
}

/// 8. Hacer una función que muestre un arreglo de palabras.

void muestraMatrizPalabras(char P[][maxCP], int valF)
{
    int f=0;

    printf("\nMostrando las palabras:\n -----------------------\n");
    for(f=0; f<valF; f++)
    {
        printf("%s\n", P[f]);
    }
    printf("-----------------------\n");
}
/// 9. Hacer una función que determine si una palabra se encuentra dentro de un
/// arreglo de palabras. La función recibe el arreglo, la cantidad de palabras que contiene y la palabra a cargar.

int encuentraPalabra (char P[][maxCP], int valF,char palabra[])
{
    int f=0;
    int buscado=0;


    for(f=0; f<valF&&buscado==0; f++)
    {
        /// strcmp retorna cero si las palabras son iguales
        if(strcmp(P[f],palabra)==0)
            buscado=1;
    }

    return buscado;

}
/// 10. Hacer una función (o varias) que ordene un arreglo de palabras por
/// orden alfabético. (Por selección o inserción, el que más te guste)

int buscaPosMenorPalabra(char P[][maxCP], int valF, int pos)
{
    char menorPalabra[maxCP];

/// guardo la palabra menor y su posicion
    strcpy(menorPalabra, P[pos]);
    int posMenor=pos;

    int i;

    for(i=pos+1; i<valF; i++)
    {
        if(strcmp(menorPalabra, P[i])>0)
        {
            strcpy(menorPalabra, P[i]);
            posMenor=i;
        }
    }
    return posMenor;
}

void intercambioPalabra(char P[][maxCP], int i, int j)
{
    char aux[maxCP];
    strcpy(aux, P[i]);
    strcpy(P[i],P[j]);
    strcpy(P[j],aux);
}

void ordenaPalabras (char P[][maxCP], int valF)
{
    int f=0;
    int menor=0;

    for(f=0;f<valF-1;f++)
    {
        menor=buscaPosMenorPalabra(P,valF, f);
        intercambioPalabra(P, menor, f);
    }
}

int main()
{
    printf("Hello matrices!\n");

    /// vamos a trabajar con la matriz completa
    int unaMatrix [5][maxC];

   // cargaMatriz(unaMatrix, 5, maxC);

   // mostrarMatriz(unaMatrix, 5, maxC);

    int otraMatriz[5][maxC];

    cargaMatrizAutomatico(otraMatriz, 5,maxC);

    mostrarMatriz(otraMatriz, 5,maxC);

    mostrarMatrizTabulada(otraMatriz, 5 ,maxC);

    /// probamos ambas posibilidades
    ///  int suma=sumaMatriz(otraMatriz, 5, maxC);
    int suma=sumaMatrizBis(otraMatriz, 5, maxC);

    printf("\nLa suma de la matriz es %d", suma);

    float prom = promedioMatriz(otraMatriz, 5, maxC);

    printf("\nEl promedio de la matriz es %.2f", prom);

    if(buscaDatoEnMatriz(otraMatriz, 5, maxC, 45))
        printf("\nEl valor se encuentra en la matriz");
    else
        printf("\nEl valor NO se encuentra en la matriz");

    /// matriz de caracteres o arreglo de palabras

    char palabrassss[20][maxCP];
    int validosPalabras=0;

    validosPalabras=cargaMatrizPalabras(palabrassss, 20);

    muestraMatrizPalabras(palabrassss, validosPalabras);

    if(encuentraPalabra(palabrassss, validosPalabras, "pedorro"))
        printf("\nLa palabra esta en el listado");
    else
        printf("\nLa palabra NO esta en el listado");


    ordenaPalabras(palabrassss, validosPalabras);

    printf("\nAhora ordenada por seleccion\n");
    muestraMatrizPalabras(palabrassss, validosPalabras);

    /// falta el punto 11... me dijo gonza que lo va a hacer jejejje
    return 0;
}
