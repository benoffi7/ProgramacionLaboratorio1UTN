#include <stdio.h>
#include <stdlib.h>

/* 12. Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos
de los dos primeros intercalados, de manera que quede un arreglo también ordenado
alfabéticamente.*/


int quitarPrimero (char A[], int *comienzo, int cant)
{
    int aux = A[*comienzo];
    (*comienzo)++;
    return aux;
}

// la hice pero no la use.. me pa q no anda bien

int vacio (char A[], int *comienzo, int cant)
{
    int flag;

    if(A[*comienzo]<A[cant-1])
        flag = 1;
    else
        flag = 0;

    return flag;
}


int pedorro (char A[], int cantA, char B[], int cantB, char C[], int dimC)
{

    // indice del arreglo A
    int iA =0;

    // indice del arreglo B
    int iB=0;

    // indice del arreglo C
    int indexC=0;

    int pri1 = quitarPrimero(A, &iA, cantA);
    int pri2 = quitarPrimero(B, &iB, cantB);

    if(pri1<pri2)
    {
        C[indexC++]=pri1;
        pri1=quitarPrimero(A,&iA,cantA);
    }
    else
    {
        C[indexC++]=pri2;
        pri2=quitarPrimero(B, &iB, cantB);
    }


    while(iA<cantA && iB<cantB)
    {
        if(pri1<pri2)
        {
            C[indexC++]=pri1;
            pri1=quitarPrimero(A, &iB,cantA);
        }
        else
        {
            C[indexC++]=pri2;
            pri2=quitarPrimero(B, &iB, cantB);
        }
    }

    // para q pase lo que quedo en lo arreglos
    while(iA<cantA)
    {
        C[indexC++]=pri1;
        pri1=quitarPrimero(A, &iA,cantA);
    }

    while(iB<cantB)
    {
        C[indexC++]=pri2;
        pri2=quitarPrimero(B, &iB, cantB);
    }

    return indexC;
}


// funciones auxiliares

int cargaArregloChar (char A[10])
{
    char control = 's';
    int i = 0;
    while(control=='s'&& i<9)
    {
        printf("Ingrese un char para el arreglo:\n");
        fflush(stdin);
        scanf("%c", &A[i]);
        i++;
        printf("Desea ingresar otro char? (s/n)\n");
        fflush(stdin);
        scanf("%c", &control);
    }
    A[i]='\0';
    return i+1;
}

void mostraArregloChar (char A[], int c)
{
    int i=0;
    while(i<c)
    {
        printf("%c ", A[i]);
        i++;
    }
}

int main()
{

    char unArreglo[10];
    int cantA;
    char otroArreglo[10];
    int cantB;
    char final[20];

    printf("Cargamos el primer arreglo:\n ");
    cantA = cargaArregloChar(unArreglo);

    printf("Cargamos el segundo arreglo:\n ");
    cantB = cargaArregloChar(otroArreglo);

    printf("\nContenido del primer arreglo: ");
    mostraArregloChar(unArreglo, cantA);

    printf("\nContenido del segundo arreglo: ");
    mostraArregloChar(otroArreglo, cantB);


    int f = pedorro(unArreglo, cantA, otroArreglo, cantB, final);


    printf("\nContenido final: ");
    mostraArregloChar(final, f);


    return 0;
}
