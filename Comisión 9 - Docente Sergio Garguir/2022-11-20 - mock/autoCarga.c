#include <stdio.h>
#include <string.h>
#include <string.h>
#include <malloc.h>
#include "autoCarga.h"

#define NOMBRES_CSV "mocks/nombres.csv"
#define APELLIDOS_CSV "mocks/apellidos.csv"
#define DIM_ARRAY 100
#define DIM_STRING 30

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

int getDni(){
    return ((rand()%15999)*(rand()%1234))+1000000;
}

char *getNombre(){
    static int v=0;
    static char **nombres = NULL;
    static int j=0;
    j++;
    char *nombre = (char*)malloc(sizeof(char)*DIM_STRING);

    if(v==0){
        nombres = (char**) malloc(sizeof(char*)*DIM_ARRAY);

        for(int i=0;i<DIM_ARRAY;i++){
            nombres[i]=(char*)malloc(sizeof(char)*DIM_STRING);
        }

        v = csv2arreglo(NOMBRES_CSV, &nombres, DIM_ARRAY);
        printf("  ");
            //printf("\n %p", nombres);
    }
    strcpy(nombre, nombres[rand()%v]);
    printf("\n %2d - %30s - %p - %p", j, nombre, nombres, nombres[j]);
    return nombre;
}

char *getApellido(){
    static int v=0;
    static char **apellidos = NULL;
    static int j=0;
    j++;
    char *apellido = (char*)malloc(sizeof(char)*DIM_STRING);

    if(v==0){
        apellidos = (char**) malloc(sizeof(char*)*DIM_STRING*DIM_ARRAY);
        for(int i=0;i<DIM_ARRAY;i++){
            apellidos[i]= (char*)malloc(sizeof(char)*DIM_STRING);
        }
        v = csv2arreglo(APELLIDOS_CSV, &apellidos, DIM_ARRAY);
        printf(" 1a ");
    }
    strcpy(apellido, apellidos[rand()%v]);
    printf("\n %2d - %30s - %p - %p", j, apellido, apellidos, apellidos[j]);
    return apellido;
}

int csv2arreglo(char archivo[], char ***n, int dim){
    FILE* archi = fopen(archivo, "r");
    int i=0;
    //printf("\n %p", n);
    //printf("\n %p", *n);
    if(archi){
        while(fgets((*n)[i], 30, archi) && i < dim){
            (*n)[i][strlen((*n)[i])-1] = '\0';
            i++;
        }
        fclose(archi);
    }
    return i;
}

int csv2arregloBis(char archivo[], char **n, int dim){
    FILE* archi = fopen(archivo, "r");
    int i=0;
    if(archi){
        while((fscanf(archi, "%s",n[i])==1) && (i<dim)){
            i++;
        }
        fclose(archi);
    }
    return i;
}

void cargaArchivoPersonas(char archivo[], int cantidad){
    stPersona p;
    int i;
    FILE* archi = fopen(archivo, "ab");
    if(archi){
        while(i<cantidad){
            p = cargaUnaPersona();
            fwrite(&p, sizeof(stPersona), 1, archi);
            i++;
        }
        fclose(archi);
    }
}

void muestraArregloString(char s[][30], int v, int pos){
    if(pos < v){
        printf("\n %s",s[pos]);
        muestraArregloString(s,v,pos+1);
    }
}

void generaArchivoPersonas(char archivo[], int cant){

    FILE *archi = fopen(archivo, "wb");
    stPersona p;
    if(archi){
        for(int i=0;i<cant;i++){
            p = cargaUnaPersona();
            fwrite(&p,sizeof(stPersona), 1, archi);
        }
        fclose(archi);
    }
}

void muestraArchivoPersonas(char archivo[]){
    stPersona p;
    FILE *arch = fopen(archivo, "rb");
    if(arch){
        while(fread(&p, sizeof(stPersona), 1, arch)>0){
            muestraUnaPersona(p);
        }
        fclose(arch);
    }
}
