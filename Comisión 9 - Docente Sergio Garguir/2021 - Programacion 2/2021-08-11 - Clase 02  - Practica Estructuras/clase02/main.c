#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "empleado.h"
#include "autoCargaEmpleados.h"
#include "pilaEmpleados.h"
#include "listaEmpleados.h"
#include "listaDobleEmpleados.h"

stEmpleado cargaUnEmpleado();
nodo* archivo2lista(nodo* lista, char archivo[]);
nodoDoble* archivo2listaDoble(nodoDoble* lista, char archivo[]);

int main()
{
    printf("\n Sizeof(stEmpleado) %d", sizeof(stEmpleado));
    printf("\n Sizeof(nodo) %d", sizeof(nodo));
    printf("\n Sizeof(nodo*) %d", sizeof(nodo*));

    printf("\n Sizeof(stEmpleado) %d", sizeof(stEmpleado));
    printf("\n Sizeof(nodoDoble) %d", sizeof(nodoDoble));
    printf("\n Sizeof(nodoDoble*) %d", sizeof(nodoDoble*));


    nodo* lista = inicLista();
    nodo* nuevo = inicLista();

    nodo* listaDoble = inicListaDoble();

    nuevo = crearNodo(cargaUnEmpleado());
    lista = agregarAlPrincipio(lista, nuevo);

    lista = archivo2lista(lista, "empleados.dat");

    printf("\n Lista de Empleados \n");
    mostrarListaDirecciones(lista);

    listaDoble = archivo2listaDoble(listaDoble, "empleados.dat");
    printf("\n Lista Doble de Empleados \n");
    muestraListaDobleDirecciones(listaDoble);


//    lista = agregarAlPrincipio(lista, crearNodo(cargaUnEmpleado()));

    nuevo = crearNodo(cargaUnEmpleado());
    lista = agregarAlPrincipio(lista, nuevo);

    printf("\n Muestra lista");
    mostrarLista(lista);

    //muestraUnNodo(buscaEmpleado(lista, "Juarez"));

    nodo* nodoEmpleado = buscaEmpleado(lista, "Perez");
    if (nodoEmpleado){
        muestraUnNodo(nodoEmpleado);
    }

    if(nodoEmpleado != NULL){
        muestraUnEmpleado(nodoEmpleado->dato);
    }

    char archivoEmpleados[]="empleados.dat";

    Pila pilita;
    inicpila(&pilita);

    srand(time(NULL));

    generaArchivoEmpleados(archivoEmpleados,100);
    muestraArchivoEmpleados(archivoEmpleados);


    printf("\n--- Factorial de 5 = %d ---", factorial(5));
    printf("\n--- Factorial de 6 = %d ---", factorial1(6));
    printf("\n--- Factorial de 7 = %d ---", factorial2(7));
    printf("\n--- 2 elevado a 4 = %d ---", potencia(2, 4));
    printf("\n--- 3 elevado a 4 = %d ---", potencia1(2, 4));

    char *s = NULL;

    agregaString(&s, " Algo ");
    printf("\n -- %s", s);

    agregaString(&s, " Otra cosa ");
    printf("\n -- %s", s);

    agregaString(&s, getApellido());
    printf("\n -- %s", s);

    agregaString(&s, getCargo());
    printf("\n -- %s", s);

    stEmpleado empleado = cargaUnEmpleado();

    printf("\n Pila de empleados");
    apilar(&pilita, empleado);
    empleado = cargaUnEmpleado();
    apilar(&pilita, empleado);

    muestraPilaEmpleados(pilita);

    printf("\n_________________________________________________");
    muestraUnEmpleado(desapilar(&pilita));
    printf("\n_________________________________________________");
    muestraUnEmpleado(desapilar(&pilita));
    printf("\n_________________________________________________");
    muestraUnEmpleado(desapilar(&pilita));
    printf("\n_________________________________________________");

    strcpy(empleado.cargo, (char*)getCargo());

    muestraUnEmpleado(empleado);

    getNombre();

    return 0;
}

void agregaString(char **a, char *b){
    if(*a){
        (*a) = (char*)realloc((*a), strlen(*a)+strlen(b)+1);
        strcat((*a), b);
    }else{
        (*a) = (char*)malloc(sizeof(b)+1);
        strcpy((*a), b);
    }
}

void muestraPilaEmpleados(Pila p){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p)){
        muestraUnEmpleado(tope(&p));
        apilar(&aux, desapilar(&p));
    }
}

/// Funciones Recursivas

int factorial(int x){
    int rta;
    if(x==0){
        rta=1;
    }else{
        rta=x*factorial(x-1);
    }
    return rta;
}

int factorial1(int x){
    int rta=1;
    if(x>0){
        rta=x*factorial1(x-1);
    }
    return rta;
}

int factorial2(int x){
    return (x>0)?x*factorial2(x-1):1;
}

int potencia(int x, int factor){
    int rta=1;
    if(factor>0){
        rta=x*potencia(x,factor-1);
    }
    return rta;
}

int potencia1(int x, int factor){
    return (factor>0)?x*potencia1(x, factor-1):1;
}

void muestraArregloRecursivo1(int A[], int i, int cant){
    if(i<cant){
        printf(" %d", A[i]);
        muestraArregloRecursivo1(A, i+1, cant);
    }
}

nodo* archivo2lista(nodo* lista, char archivo[]){
    FILE *archi = fopen(archivo, "rb");
    stEmpleado e;
    if(archi){
        while(fread(&e, sizeof(stEmpleado), 1, archi)>0){
            if(e.legajo<50000){
                nodo *nuevo = crearNodo(e);
                ///lista = agregarAlFinal(lista, nuevo);
                ///lista = agregarAlPrincipio(lista, nuevo);
                lista = agregarEnOrdenPorLegajo(lista, nuevo);
            }
        }
        fclose(archi);
    }

    return lista;
}

nodoDoble* archivo2listaDoble(nodoDoble* lista, char archivo[]){
    FILE *archi = fopen(archivo, "rb");
    stEmpleado e;
    if(archi){
        while(fread(&e, sizeof(stEmpleado), 1, archi)>0){
            if(e.legajo<50000){
                lista = agregarAlPrincipioDoble(lista, crearNodoDoble(e));
            }
        }
        fclose(archi);
    }

    return lista;
}



