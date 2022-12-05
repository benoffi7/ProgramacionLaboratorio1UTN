#ifndef AUTOCARGA_H_INCLUDED
#define AUTOCARGA_H_INCLUDED

#include "persona.h"

int getId();
int getLegajo();
char* getNombre();
char* getApellido();
int csv2arreglo(char archivo[], char ***n, int dim);
int csv2arregloBis(char archivo[], char **n, int dim);
void cargaArchivoEmpleados(char archivo[], int cantidad);

#endif // AUTOCARGA_H_INCLUDED
