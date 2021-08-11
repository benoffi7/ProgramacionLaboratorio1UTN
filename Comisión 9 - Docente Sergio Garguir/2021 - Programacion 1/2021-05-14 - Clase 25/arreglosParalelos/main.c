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
    int pos;
    //music();
    //colores();

    validos = cargaAlumnos(legajos, dnis, apellidos, nombres, DIM);
    muestraAlumnos(legajos, dnis, apellidos, nombres, validos);

    pos = buscaPorDni(dnis, validos, 121212);
    if(pos>-1){
        system("cls");
        muestraUnAlumno(legajos[pos], dnis[pos], apellidos[pos], nombres[pos]);
    }

    printf("\n\nHello world!\n");
    return 0;
}

void colores(){
    for(int i=0;i<256;i++){
        color(i);
        printf("\nEl color es: %d", i);
    }
}

int cargaAlumnos(int leg[], int dnis[], char ape[][30], char nom[][30], int dim){
    char opcion=0;
    int i=0;

    while(i<dim && opcion!=27){
        mostrarFormulario();
        hidecursor(1);
        color(112);
        gotoxy(30,2);
        scanf("%5d", &leg[i]);
        gotoxy(30,3);
        scanf("%8d", &dnis[i]);
        gotoxy(30,4);
        scanf("%s", ape[i]);
        gotoxy(30,5);
        scanf("%s", nom[i]);
        color(7);
        i++;
        hidecursor(0);
        opcion=getch();
        system("cls");
    }

    return i;
}

void mostrarFormulario(){
    gotoxy(10,2);
    printf("Legajo............: ");
    replicante(219,5);
    gotoxy(10,3);
    printf("DNI...............: ");
    replicante(219,10);
    gotoxy(10,4);
    printf("Apellido..........: ");
    replicante(219,30);
    gotoxy(10,5);
    printf("Nombres...........: ");
    replicante(219,30);
    gotoxy(15,7);
    printf("ESC para salir - cualquier tecla para continuar");
}

void muestraAlumnos(int leg[], int dnis[], char ape[][30], char nom[][30], int v){
    system("cls");
    int x=2;
    int y=1;
    for(int i=0;i<v;i++){
        gotoxy(x,y);
        muestraUnAlumno(leg[i], dnis[i], ape[i], nom[i]);
        y=y+5;
    }
}

void muestraUnAlumno(int leg, int dni, char ape[], char nom[]){
    int x=whereX();
    int y=whereY();
    gotoxy(x,y);
    y++;
    printf("Legajo............: %d", leg);
    gotoxy(x,y);
    y++;
    printf("DNI...............: %d", dni);
    gotoxy(x,y);
    y++;
    printf("Apellido..........: %s", ape);
    gotoxy(x,y);
    y++;
    printf("Nombres...........: %s", nom);
    gotoxy(x,y);
    y++;
    replicante('-',40);
    y++;
}

int buscaPorDni(int dnis[], int v, int dni){
    int i=0;
    int pos=-1;

    while(i<v && pos==-1){
        if(dnis[i]==dni){
            pos = i;
        }
        i++;
    }
    return pos;
}

int cargaArregloRandom(char n[][20], int dim){
    for(int i=0;i<dim;i++){
        getNombre(n[i]);
    }
}

void getNombre(char n[]){
    char nombres[][20]={"Juan", "Martin", "Miguel", "Alfredo", "Juana"};

    strcpy(n,nombres[rand()%(sizeof(nombres)/20)]);
}

void music(){
    int i=0;
    while(i==0){
         Beep(rand()%1000,rand()%100);
         if(kbhit()){
            i=1;
         }
    }
}

void replicante(char c, int n){
    hidecursor(0);
    for(int i=0;i<n;i++){
        printf("%c",c);
    }
    hidecursor(1);
}
