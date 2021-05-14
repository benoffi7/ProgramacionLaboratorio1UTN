#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "gotoxy.h"

#define DIM 100

int main()
{
    int legajos[DIM];
    int dnis[DIM];
    char apellidos[DIM][30];
    char nombres[DIM][30];
    int validos = 0;

    validos = cargaArreglos(legajos, dnis, apellidos, nombres, DIM);
    muestraAlumnos(legajos, dnis, apellidos, nombres, validos);

    printf("Hello world!\n");
    return 0;
}

void verColores(){
    for(int i=0;i<256;i++){
        color(i);
        printf("\nColor: %d", i);
    }
}

int cargaArreglos(int leg[], int dnis[], char ape[][30], char nom[][30], int dim){
    char opcion=0;
    int i=0;

    while(i<dim && opcion!=27){
        muestraFormulario();
        hidecursor(1);
        gotoxy(25,2);
        scanf("%d", &leg[i]);
        gotoxy(25,3);
        scanf("%d", &dnis[i]);
        gotoxy(25,4);
        scanf(" %s", ape[i]);
        gotoxy(25,5);
        scanf(" %s", nom[i]);

        hidecursor(0);
        gotoxy(15,7);
        printf("ESC para salir - cualquier tecla para continuar");

        opcion = getch();

        system("cls");
        i++;
    }
    return i;
}

void muestraFormulario(){
    gotoxy(10,2);
    printf("Legajo.......:");
    gotoxy(10,3);
    printf("DNI..........:");
    gotoxy(10,4);
    printf("Apellido.....:");
    gotoxy(10,5);
    printf("Nombre.......:");
}

void muestraAlumnos(int leg[], int dnis[], char ape[][30], char nom[][30], int v){
    system("cls");
    int j=2;
    for(int i=0;i<v;i++){
        gotoxy(10,j+1);
        printf("Legajo.......: %d", leg[i]);
        gotoxy(10,j+2);
        printf("DNI..........: %d", dnis[i]);
        gotoxy(10,j+3);
        printf("Apellido.....: %s", ape[i]);
        gotoxy(10,j+4);
        printf("Nombre.......: %s", nom[i]);
        gotoxy(5,j+5);
        printf("-----------------------------------------------------");
        j+=6;
    }

}
