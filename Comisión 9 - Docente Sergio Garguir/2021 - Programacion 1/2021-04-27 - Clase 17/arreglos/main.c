#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargaArregloRandom(int a[], int v, int dim);
void muestraArreglo(int a[], int v);
int buscaEnArreglo(int a[], int v, int aBuscar);

int main()
{
    char nombre[30]="Pepe"; /// para inicializarlo vacio nombre[30]="\0"
    char nom1[30];

    int arreglo[8]={156123,123545687,654698778,135487,468789,1561658,15641987,4687988};
    int vArreglo=8;

    int a1[100];
    int vA1=0;
    int encontrado;
    int buscado;
    int cont[10]={0};


    printf("\n El nombre es: %s", nombre);
    printf("\n Ingrese un numero: ");
    scanf("%d", &a1[0]);
    printf("\n Ingrese su nombre: ");
    scanf("%s", nombre);

    for(int i=0; i < strlen(nombre); i++){
        printf("%c", nombre[i]);
    }


    printf("\n El nombre es: %s y su largo es: %d", nombre, strlen(nombre));


    muestraArreglo(a1, vA1);

    printf("\n Una variable de tipo int pesa %d bytes", sizeof(int));
    printf("\n Mi arreglo pesa %d bytes", sizeof(arreglo));


    vArreglo=cargaArregloRandom(arreglo, vArreglo, 8);
    printf("\n");
    muestraArreglo(arreglo, vArreglo);

    cuentaTerminacionesDNI(arreglo, vArreglo, cont);
    for(int i=0;i<10;i++){
        printf("\n Hay %d dnis terminados en %d", cont[i], i);
    }

    buscado=0;
    encontrado=buscaEnArreglo(arreglo, vArreglo, buscado);

    if(encontrado > -1){
        printf("\n El numero %d se encuentra en la posicion %d - %d", buscado, encontrado, arreglo[encontrado]);
    }else{
        printf("\n El numero %d no se encuentra en el arreglo", buscado);
    }



    printf("\nHello world!\n");
    return 0;
}

int cargaArregloRandom(int a[], int v, int dim){
    int i;
    for(i=v; i<dim; i++){
        a[i]=rand()%100;
    }
    return i;
}

void muestraArreglo(int a[], int v){
    for(int i=0; i<v; i++){
        printf("[ %d ] ", a[i]);
    }
}

int buscaEnArreglo(int a[], int v, int aBuscar){
    int flag = -1;
    int i = 0;

    while(i < v && flag == -1){
        if(a[i] == aBuscar){
            flag = i;
        }
        i++;
    }

    return flag;
}

void cuentaTerminacionesDNI(int dnis[], int v, int cont[]){
    int indice;
    for(int i=0;i<v;i++){
        indice = dnis[i]%10;
        cont[indice]++;
    }
}


/**
1. Hacer una función de tipo entero que permita al usuario cargar en un arreglo
 de 50 enteros como máximo. Tantos valores como quiera el usuario, pero sin sobrepasar
 la cantidad de casillas del arreglo. La función debe ir contando la cantidad de
 elementos que se cargan en el arreglo y debe retornarlo.
*/

int cargaArregloUsuario(int a[], int v, int dim){
    char opcion=0;
    int dni;
    int verifica;

    while(v<dim && opcion!=27){
        printf("\n Ingrese un nro: ");
        scanf("%d", &dni);
        verifica=buscaEnArreglo(a, v, dni);
        while(verifica>-1){
            printf("\n DNI repetido intente nuevamente ");
            printf("\n Ingrese un nro: ");
            scanf("%d", &dni);
            verifica=buscaEnArreglo(a, v, dni);
        }
        a[v] = dni;
        v++;

        printf("\n ESC para salir");
        opcion=getch();
    }
    return v;
}

/**
2. Hacer una función que inserte en orden un elemento dentro de una
pila ordenada de números de mayor (tope) a menor (base).
Se debe conservar el orden en la pila. La función recibe la pila y el dato a insertar.
*/

void insertaEnPila(Pila *p, int dato){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p) && tope(p) < dato){
        apilar(&aux, desapilar(p));
    }
    apilar(p, dato);
    while(!pilavacia(&aux)){
        apilar(p, desapilar(&aux));
    }
}

/**
3. Hacer una función que recorra el arreglo y lo muestre por pantalla.
*/

/// ver mas arriba


/**
4. Hacer una función void que reciba como parámetro una pila (vacía),
un arreglo (de 50 enteros) y la cantidad de elementos cargados en el arreglo.
Esta función debe recorrer el arreglo y utilizar cada valor cargado en él para invocar a la
función 2, que insertará dicho valor en la pila recibida por parámetro.
De esta forma se obtiene una pila ordenada por inserción.
*/

void arreglo2pila(Pila *p, int a[], int v){
    for(int i=0;i<v;i++){
        insertaEnPila(p, a[i]);
    }
}

int sumaArreglo(int a[], int v){
    int suma=0;
    for(int i=0;i<v;i++){
        suma=suma+a[i];
    }
    return suma;
}

float promedioArreglo(int a[], int v){
    float prom=(float)sumaArreglo(a, v)/v;

    return prom;
}
