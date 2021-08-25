#ifndef AUTOCARGAEMPLEADOS_H_INCLUDED
#define AUTOCARGAEMPLEADOS_H_INCLUDED

#include "empleado.h"

int getId();
int getLegajo();
char* getCargo();
char* getCalle();
char* getCalleBis();
char* getNombre();
char* getApellido();
int csv2arreglo(int col, char archivo[], char n[][col], int dim);
int csv2arregloBis(int col, char archivo[], char n[][col], int dim);
void cargaArchivoEmpleados(char archivo[], int cantidad);

#endif // AUTOCARGAEMPLEADOS_H_INCLUDED
