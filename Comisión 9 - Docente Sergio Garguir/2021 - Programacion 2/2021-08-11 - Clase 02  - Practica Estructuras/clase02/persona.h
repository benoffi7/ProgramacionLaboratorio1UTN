#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "domicilio.h"

typedef struct{
    int id;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char genero;
    stDomicilio domicilio;
}stPersona;

void muestraUnaPersona(stPersona p);
char *personaToString(stPersona p);
char *personaToCsv(stPersona p);
char *personaToJson(stPersona p);

#endif // PERSONA_H_INCLUDED
