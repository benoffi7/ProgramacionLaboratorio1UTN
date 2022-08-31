#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arreglo[]={10,25,35,45};
    int v = 4;
    printf("Hello world!\n");
    printf("\n El factorial de 5 es: %d", factorial(5));
    printf("\n La potencia de 2 elevado al cubo es: %d", potencia(2, 3));
    printf("\n La potencia de 2 elevado al cubo es: %d", potencia2(2, 3));
    printf("\n");
    muestraArreglo(arreglo, v, 0);
    printf("\n");
    muestraArregloInvertido(arreglo, v, 0);
    return 0;
}

int factorial(int x){
    int rta;
    if(x==0){
        rta=1;
    }else{
        rta=x*factorial(x-1);
    }
    return rta;
}

int factorialTernario(int x){
    return (x==0)?1:x*factorialTernario(x-1);
}

/// Calcular la potencia de un número en forma recursiva.

int potencia(int nro, int factor){
    int rta;
    if(factor == 0){
        rta = 1;
    }else{
        rta = nro * potencia(nro, factor-1);
    }

    return rta;
}

int potencia2(int nro, int factor){
    int rta = 1;
    if(factor > 0){
        rta = nro * potencia2(nro, factor-1);
    }
    return rta;
}

void muestraArreglo(int a[], int v, int i){
    if(i < v){
        printf(" %d -", a[i]);
        muestraArreglo(a, v, i+1);
        printf(" %d -", a[i]);
    }
}

void muestraArregloInvertido(int a[], int v, int i){
    if(i < v){
        muestraArregloInvertido(a, v, i+1);
        printf(" %d -", a[i]);
    }
}

int menorEnArchivo(FILE * archi){
    int menor;
    int dato;

    if(fread(&menor, sizeof(int), 1, archi)==0){
        fseek(archi, sizeof(int)*(-1), SEEK_END);
        fread(&menor, sizeof(int), 1, archi);
    }else{
        dato=menorEnArchivo(archi);
        if(dato<menor){
            menor=dato;
        }
    }
    return menor;
}








