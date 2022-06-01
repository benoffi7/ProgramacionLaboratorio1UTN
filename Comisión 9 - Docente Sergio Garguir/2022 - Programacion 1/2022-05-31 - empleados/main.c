#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "empleado.h"

#define ESC 27
#define ARCHIVO_EMPLEADOS "empleados.dat"

int main()
{
    stEmpleado empleados[100];
    int vEmpleados = 0;
/**
    vEmpleados=cargaArregloEmpleados(empleados, 100);
    printf("\n Arreglo de Empleados \n");
    muestraArregloEmpleados(empleados, vEmpleados);
*/

    vEmpleados=arch2arreglo(ARCHIVO_EMPLEADOS, empleados, 100, vEmpleados);
    printf("\n Arreglo de Empleados \n");
    muestraArregloEmpleados(empleados, vEmpleados);

    ordenaEmpleadosPorSeleccionPorLegajo(empleados, vEmpleados);
    printf("\n Arreglo de Empleados por Legajo \n");
    muestraArregloEmpleados(empleados, vEmpleados);

    ordenaEmpleadosPorSeleccionPorApellido(empleados, vEmpleados);
    printf("\n Arreglo de Empleados por Apellido \n");
    muestraArregloEmpleados(empleados, vEmpleados);

//    cargaArchivoEmpleados(ARCHIVO_EMPLEADOS);
    printf("\n Archivo de empleados \n");
    muestraArchivoEmpleados(ARCHIVO_EMPLEADOS);

    return 0;
}

int cargaArregloEmpleados(stEmpleado e[], int dim){
    char opcion = 0;
    int i = 0;

    while(i<dim && opcion != ESC){
        system("cls");
        e[i] = cargaUnEmpleado();
        i++;

        printf("\n ESC para salir o cualquier tecla para continuar ");
        opcion = getch();
    }

    return i;
}

void muestraArregloEmpleados(stEmpleado e[], int v){
    for(int i=0;i<v;i++){
        muestraUnEmpleado(e[i]);
    }
}

void cargaArchivoEmpleados(char nombreArchivo[]){
    stEmpleado e;
    char opcion;
    FILE *archi = fopen(nombreArchivo, "ab");
    if(archi){  /// if(archi != NULL)
        do{
            system("cls");
            e = cargaUnEmpleado();
            fwrite(&e, sizeof(stEmpleado), 1, archi);

            printf("\n ESC para salir o cualquier tecla para continuar ");
            opcion = getch();
        }while(opcion != ESC);
        fclose(archi);
    }
}

void muestraArchivoEmpleados(char nombreArchivo[]){
    stEmpleado e;
    FILE *archi = fopen(nombreArchivo, "rb");
    if(archi){
        while(fread(&e, sizeof(stEmpleado), 1, archi) > 0){
            muestraUnEmpleado(e);
        }
        fclose(archi);
    }
}

int arch2arreglo(char nombreArchivo[], stEmpleado e[], int dim, int v){
    FILE *archi = fopen(nombreArchivo, "rb");
    stEmpleado emp;

    if(archi){
        while(v<dim && fread(&e[v], sizeof(stEmpleado), 1, archi) > 0){
            v++;
        }
        /**
        while(v<dim && fread(&emp, sizeof(stEmpleado), 1, archi) > 0){
            e[v]=emp;
            v++;
        }
        */
        fclose(archi);
    }
    return v;
}

int buscaPosMenorPorLegajo(stEmpleado e[], int v, int pos){
    int posMenor = pos;
    pos++;
    while(pos<v){
        if(e[pos].legajo < e[posMenor].legajo){
            posMenor = pos;
        }
        pos++;
    }

    return posMenor;
}

void intercambioEmpleados(stEmpleado *a, stEmpleado *b){
    stEmpleado aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordenaEmpleadosPorSeleccionPorLegajo(stEmpleado e[], int v){
    int posMenor;
    int i=0;
    while(i<v-1){
        posMenor=buscaPosMenorPorLegajo(e, v, i);
        intercambioEmpleados(&e[posMenor],&e[i]);
        i++;
    }
}

int buscaPosMenorPorApellido(stEmpleado e[], int v, int pos){
    int posMenor = pos;
    pos++;
    while(pos<v){
        if(strcmp(e[pos].apellido, e[posMenor].apellido)<0){
            posMenor = pos;
        }
        pos++;
    }

    return posMenor;
}

void ordenaEmpleadosPorSeleccionPorApellido(stEmpleado e[], int v){
    int posMenor;
    int i=0;
    while(i<v-1){
        posMenor=buscaPosMenorPorApellido(e, v, i);
        intercambioEmpleados(&e[posMenor],&e[i]);
        i++;
    }
}
