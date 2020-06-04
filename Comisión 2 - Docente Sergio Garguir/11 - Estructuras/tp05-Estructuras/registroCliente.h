#ifndef REGISTROCLIENTE_H_INCLUDED
#define REGISTROCLIENTE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "utilidades.h"

typedef struct {
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char calle[50];
    int calleNro;
}stCliente;

typedef struct{
    int id;   /// campo unico y autoincremental
    char nombre[30];
    char apellido[30];
    int dni;
    char email[30];
    char domicilio[45];
    int movil;
    int baja; /// 0 - 1
}stClienteFinal;

typedef struct{
    int id; /// campo unico y autoincremental
    int idCliente;

    int baja;
}stConsumos;

#define arCliente "archivoClientes.dat"

int getNroCliente();
void getNombre(char n[]);
void getApellido(char a[]);
int getDNI();
void getCalle(char c[]);
int getCalleNro();
stCliente cargoRegistroClienteRandom();

#endif // REGISTROCLIENTE_H_INCLUDED
