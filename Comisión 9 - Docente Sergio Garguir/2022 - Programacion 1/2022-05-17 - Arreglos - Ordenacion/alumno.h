#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct{
    int matricula;
    char nombre[30];
    char apellido[30];
    int nota;
} stAlumno;

stAlumno cargaUnAlumno();
void muestraUnAlumno(stAlumno alumno);

#endif // ALUMNO_H_INCLUDED
