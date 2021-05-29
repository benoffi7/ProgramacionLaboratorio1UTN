#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

#include <stdio.h>

typedef struct
{
    int dni;
    char nombre[30];
    int valido;

} Persona;

Persona inicPersona(int dni, char nombre[30]);
void mostrarPersona(const Persona* persona);
int cargarPersonas(Persona personas[], const int dimension);
void guardarPersonas(const Persona personas[], const int validos, FILE* archivo);
void leerPersonas(Persona personas[], const int DIMENSION, FILE* archivo);
void mostrarPersonas(const Persona personas[], int validos);
void mostrarValidos(const Persona personas[], int validos);
void borrarRegistro(int numeroResgistro, FILE* archivo);

#endif // PERSONAS_H_INCLUDED
