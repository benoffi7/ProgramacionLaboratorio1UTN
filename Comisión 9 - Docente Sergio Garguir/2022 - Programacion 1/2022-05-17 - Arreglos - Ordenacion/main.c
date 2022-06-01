#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

#define DIM 100
#define ARCHI_ALUMNOS "alumnos.dat"
#define ARCHI_ALUMNOS_APROBADOS "alumnos_aprobados.dat"

int main()
{
    stAlumno alumnos[DIM];
    int vAlumnos = 0;

    cargaArchivoAlumnos(ARCHI_ALUMNOS_APROBADOS);
    printf("\n Archivo Alumnos \n");
    muestraArchivoAlumnos(ARCHI_ALUMNOS);
    printf("\n Archivo Alumnos Aprobados \n");
    muestraArchivoAlumnos(ARCHI_ALUMNOS_APROBADOS);

    printf("\n");
    system("pause");
    printf("\n");

    vAlumnos = cargaAlumnos(alumnos, DIM);
    printf("\n Listado de Alumnos sizeof stAlumno = %d", sizeof(alumnos));
    muestraAlumnos(alumnos, vAlumnos);

    printf("\n");
    system("pause");
    printf("\n");

    ordenaArregloSeleccionStAlumnoPro(alumnos, vAlumnos);
    printf("\n Listado de Alumnos Ordenado por apellido");
    muestraAlumnos(alumnos, vAlumnos);

    printf("\n");
    system("pause");
    printf("\n");

    ordenacionPorInsercion(alumnos, vAlumnos);
    printf("\n Listado de Alumnos Ordenado por matricula");
    muestraAlumnos(alumnos, vAlumnos);

    int notas[100];
    int vNotas=0;

    vNotas = cargaArregloRandom(notas, 50);

    printf("\n Listado de Notas");
    muestraArreglo(notas, vNotas);

    system("pause");

    ordenaArregloSeleccionPro(notas, vNotas);

    printf("\n Listado de Notas");
    muestraArreglo(notas, vNotas);

    return 0;
}

int cargaArregloRandom(int a[], int dim){
    int i;
    for(i=0;i<dim;i++){
        a[i] = rand()%100;
    }
    return i;
}

void muestraArreglo(int a[], int v){
    for(int i=0;i<v;i++){
        if(i%10==0){
            printf("\n");
        }
        printf("%d | ", a[i]);
    }
}

int buscaPosicionMenorInt(int a[], int v, int pos){
    int i=pos;
    int menor = a[i];
    int posMenor = i;
    i++;
    while(i<v){
        if(a[i] < menor){
            menor = a[i];
            posMenor = i;
        }
        i++;
    }

    return posMenor;
}

int buscaPosicionMenorIntPro(int a[], int v, int pos){
    int posMenor = pos;
    pos++;
    while(pos<v){
        if(a[pos] < a[posMenor]){
            posMenor = pos;
        }
        pos++;
    }

    return posMenor;
}

void ordenaArregloSeleccion(int a[], int v){
    int posMenor;
    int aux;
    int i = 0;
    while(i<v-1){
        posMenor=buscaPosicionMenorIntPro(a, v, i);
        /// hago el intercambio de datos
        /// intercambio(&a[posMenor], &a[i]);
        aux = a[posMenor];
        a[posMenor] = a[i];
        a[i] = aux;
        i++;
    }
}

void ordenaArregloSeleccionPro(int a[], int v){
    int posMenor;
    int i = 0;
    while(i<v-1){
        posMenor=buscaPosicionMenorIntPro(a, v, i);
        intercambio(&a[posMenor], &a[i]);
        i++;
    }
}

void intercambio(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int cargaAlumnos(stAlumno a[], int dim){
    char opcion = 0;
    int i = 0;
    while(i<dim && opcion != 27){
        system("cls");
        a[i] = cargaUnAlumno();
        i++;

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion = getch();
    }

    return i;
}


void muestraAlumnos(stAlumno a[], int v){
    for(int i=0;i<v;i++){
        muestraUnAlumno(a[i]);
    }
}

int buscaPosicionMenorStAlumnoPro(stAlumno a[], int v, int pos){
    int posMenor = pos;
    pos++;
    while(pos<v){
        if(strcmpi(a[pos].apellido, a[posMenor].apellido)<0){
            posMenor = pos;
        }
        pos++;
    }

    return posMenor;
}

void ordenaArregloSeleccionStAlumnoPro(stAlumno a[], int v){
    int posMenor;
    int i = 0;
    while(i<v-1){
        posMenor=buscaPosicionMenorStAlumnoPro(a, v, i);
        intercambioStAlumno(&a[posMenor], &a[i]);
        i++;
    }
}

void intercambioStAlumno(stAlumno *a, stAlumno *b){
    stAlumno aux = *a;
    *a = *b;
    *b = aux;
}

void insertarOrdenado(stAlumno a[], int v, stAlumno dato){
    int i = v;
    while(i>=0 && dato.matricula < a[i].matricula){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=dato;
}

void ordenacionPorInsercion(stAlumno a[], int v){
    int i = 0;
    while(i < v-1){
        insertarOrdenado(a, i, a[i+1]);
        i++;
    }
}

void cargaArchivoAlumnos(char nombreArchivo[]){
    FILE *archi = fopen(nombreArchivo, "ab");
    stAlumno alumno;
    char opcion;

    if(archi){ /// if(archi != NULL)
        do{
            system("cls");
            alumno = cargaUnAlumno();
            fwrite(&alumno, sizeof(stAlumno), 1, archi);

            printf("\n ESC para salir o cualquier tecla para continuar");
            opcion = getch();
        }while(opcion != 27);
    }
    fclose(archi);
}

void muestraArchivoAlumnos(char nombreArchivo[]){
    FILE *archi = fopen(nombreArchivo, "rb");

    stAlumno a;

    if(archi){
        while(fread(&a, sizeof(stAlumno), 1, archi)>0){
            muestraUnAlumno(a);
        }
    }
    fclose(archi);
}








