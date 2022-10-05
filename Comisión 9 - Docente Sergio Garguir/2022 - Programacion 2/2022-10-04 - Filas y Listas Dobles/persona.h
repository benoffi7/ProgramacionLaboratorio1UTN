#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    int edad;
    char sexo;
}stPersona;

stPersona cargaUnaPersona();
void muestraUnaPersona(stPersona p);

#endif // PERSONA_H_INCLUDED
