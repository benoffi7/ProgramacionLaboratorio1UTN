#ifndef REGISTROCLIENTE_H_INCLUDED
#define REGISTROCLIENTE_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "utilidades.h"

typedef struct{
    int id;   /// campo unico y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char email[30];
    char domicilio[45];
    int movil;
    int baja; /// 0 - 1
}stCliente;

typedef struct{
   int id;  /// campo único y autoincremental
   int idCliente;
   int anio;
   int mes; /// 1 a 12
   int dia; /// 1 a … dependiendo del mes
   int datosConsumidos;  /// expresados en mb.
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
