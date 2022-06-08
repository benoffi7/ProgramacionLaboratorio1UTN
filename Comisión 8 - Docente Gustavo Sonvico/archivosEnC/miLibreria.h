#ifndef MILIBRERIA_H_INCLUDED
#define MILIBRERIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int legajo;
     char nombreYapellido [30];
     int edad;
     int anio;
///a�o que cursa, recordar que no podemos utilizar la � para definir variables
} stAlumno;

int cargarArregloAlumnos(stAlumno alumnos[], int dim);
stAlumno cargarUnAlumno();

void mostrarUnAlumno(stAlumno a);
void mostrarArregloDeAlumnos(stAlumno alumnos[], int validos);

#endif // MILIBRERIA_H_INCLUDED
