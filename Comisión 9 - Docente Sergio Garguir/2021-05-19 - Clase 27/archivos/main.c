#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DIM 100

typedef struct {
    int legajo;
    int dni;
    char apellido[30];
    char nombre[30];
}stAlumno;

void cargaArchivoAlumnos(char archivo[]);
void muestraArchivoAlumnos(char archivo[]);
void muestraUnAlumno(stAlumno a);


int main()
{
    cargaArchivoAlumnos("alumnos.dat");

    printf("\n\t\tListado de Alumnos!\n");
    muestraArchivoAlumnos("alumnos.dat");

    return 0;
}

void cargaArchivoAlumnos(char archivo[]){
    char opcion = 0;
    stAlumno a;

    FILE *pArchiAlumnos = fopen(archivo,"ab");
    if(pArchiAlumnos != NULL){
        do{
            printf("\n Legajo...........: ");
            scanf("%d", &a.legajo);
            printf(" DNI..............: ");
            scanf("%d", &a.dni);
            fflush(stdin);
            printf(" Apellido.........: ");
            scanf("%s", a.apellido);
            fflush(stdin);
            printf(" Nombre...........: ");
            scanf("%s", a.nombre);

            fwrite(&a, sizeof(stAlumno), 1, pArchiAlumnos);

            printf("\n ESC para salir - cualquier tecla para continuar");
            opcion=getch();
            system("cls");
        }
        while(opcion!=27);

        fclose(pArchiAlumnos);
    }else{
        printf("\n ERROR DE APERTURA DE ARCHIVO ");
    }
}

void muestraArchivoAlumnos(char archivo[]){
    stAlumno a;
    FILE *pArchiAlumnos = fopen(archivo, "rb");

    if(pArchiAlumnos != NULL){
        while(fread(&a, sizeof(stAlumno), 1, pArchiAlumnos) > 0){
            muestraUnAlumno(a);
        }
        fclose(pArchiAlumnos);
    }else{
        printf("\n ERROR DE APERTURA DE ARCHIVO ");
    }
}

void muestraUnAlumno(stAlumno a){
    printf("\n Legajo..........: %d", a.legajo);
    printf("\n DNI.............: %d", a.dni);
    printf("\n Apellido........: %s", a.apellido);
    printf("\n Nombre..........: %s", a.nombre);
    printf("\n--------------------------------------");
}



















