#ifndef NOTAALUMNO_H_INCLUDED
#define NOTAALUMNO_H_INCLUDED

typedef struct {
   int nota;
   int legajo;
   char nombreApe[40];
} stNotaAlumno;

void muestraUnaNota(stNotaAlumno nota);

#endif // NOTAALUMNO_H_INCLUDED
