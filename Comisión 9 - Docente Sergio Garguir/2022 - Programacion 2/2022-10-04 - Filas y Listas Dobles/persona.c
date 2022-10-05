#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stPersona cargaUnaPersona(){
    static int id=0;
    id++;
    stPersona p;
    p.id=id;
    strcpy(p.nombre, "Pepe");
    p.edad=rand()%100;
    //p.edad=10;
    p.sexo='m';
    return p;
}

void muestraUnaPersona(stPersona p){
    printf("\n ID...........: %d", p.id);
    printf("\n Nombre.......: %s", p.nombre);
    printf("\n Edad.........: %d", p.edad);
    printf("\n Sexo.........: %c", p.sexo);
    printf("\n _________________________________________");
}
