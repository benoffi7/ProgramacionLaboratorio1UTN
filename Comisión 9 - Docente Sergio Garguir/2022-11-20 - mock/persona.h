#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct{
    int id;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char genero;
}stPersona;

void muestraUnaPersona(stPersona p);
stPersona cargaUnaPersona();

#endif // PERSONA_H_INCLUDED
