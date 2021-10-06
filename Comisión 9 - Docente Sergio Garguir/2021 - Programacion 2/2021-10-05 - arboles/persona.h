#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct{
    int legajo;
    char nombre[20];
    int edad;
}stPersona;

void muestraUnaPersona(stPersona p);

#endif // PERSONA_H_INCLUDED
