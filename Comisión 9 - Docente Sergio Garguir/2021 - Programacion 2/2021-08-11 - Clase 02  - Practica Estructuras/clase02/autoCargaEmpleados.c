#include <stdio.h>
#include <string.h>
#include <string.h>
#include <malloc.h>
#include "autoCargaEmpleados.h"

int getId(){
    static int id=0;
    id++;
    return id;
}

int getLegajo(){
    static int legajo=1000;
    legajo++;
    return legajo;
}

char *getCargo(){
    char *cargo = (char*)malloc(sizeof(char)*22);
    char cargos[][22]={"Developer","Developer Full Stack","Developer Front-End","Developer Java","Developer Back-End","Developer C"};

    strcpy(cargo, cargos[rand()%(sizeof(cargos)/22)]);
    return cargo;
}

char *getNombre(){
    char *nombre = (char*)malloc(sizeof(char)*30);
    char nombres[1000][30];
    int vNombres=0;

    vNombres = csv2arregloBis(30, "nombres.csv", nombres, 1000);

    strcpy(nombre, nombres[rand()%vNombres]);

    return nombre;
}

int csv2arreglo(int col, char archivo[], char n[][col], int dim){
    FILE* archi = fopen(archivo, "r");
    int i=0;
    if(archi){
        while(fgets(n[i], col, archi)){
            n[i][strlen(n[i])-1] = '\0';
            i++;
        }
        fclose(archi);
    }
    return i;
}

int csv2arregloBis(int col, char archivo[], char n[][col], int dim){
    FILE* archi = fopen(archivo, "r");
    int i=0;
    if(archi){
        while((fscanf(archi, "%s",&n[i])==1) && (i<dim)){
            i++;
        }
        fclose(archi);
    }
    return i;
}

void cargaArchivoEmpleados(char archivo[], int cantidad){
    stEmpleado e;
    int i;
    FILE* archi = fopen(archivo, "ab");
    if(archi){
        while(i<cantidad){
            e = cargaUnEmpleado();
            fwrite(&e, sizeof(stEmpleado), 1, archi);
            i++;
        }
        fclose(archi);
    }
}

/*
int empleadosCsv2arrV2(char archivo[], stEmpleado e[]){
    FILE* archi = fopen(archivo, "r");
    int i=0;
    if(archi){
        while(fscanf(archi, "%d,%[^,],%d,%d", &e[i].legajo, e[i].nombreApellido, &e[i].edad, &e[i].idDepartamento) == 4){
            muestraUnEmpleado(e[i]);
            i++;
        }
        fclose(archi);
    }
    return i;
}
*/

int palindromo(char arr[],int val){
    int i=0;
    int ul=val-1;
    int flag=1;
    while(i<ul && flag==1){
        if(arr[ul]!=arr[i]){
            flag=0;
        }
        i++;
        ul--;
    }
    return flag;
}


int cuentaGenero(stEmpleado e[], int v, char genero){
    int i=0;
    int cant=0;
    for(i=0; i<v; i++){
        if(e[i].persona.genero==genero){
            cant++;
        }
    }
    return cant;
}

void arreglo2arreglo(stEmpleado **z, int *k, stEmpleado e[], int v, char genero){
    int cantidad = cuentaGenero(e, v, genero);
    (*z) = (stEmpleado*)malloc(sizeof(stEmpleado)*cantidad);
    for(int i=0; i<v; i++){
        if(e[i].persona.genero==genero){
            (*z)[*k]=e[i];
            (*k)++;
        }
    }
}

int eliminoDatoArray(int a[], int v, int nro){
    for(int i=0; i<v; i++){
        if(a[i]==nro){
            for(int j=i; j<v; j++){
                a[j]=a[j+1];
            }
            v--;
        }
    }
    return v;
}

int potencia(int x, int factor){
    int rta=1;
    if(factor>0){
        rta=x*potencia(x,factor-1);
    }
    return rta;
}

void muestraArregloRecursivo1(int A[], int i, int cant){
    if(i<cant)
        printf(" %d", A[i]);
        muestraArregloRecursivo1(A, i+1, cant);
    }
}
