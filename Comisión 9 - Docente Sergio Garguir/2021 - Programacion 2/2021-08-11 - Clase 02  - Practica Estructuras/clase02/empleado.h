#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "persona.h"

typedef struct{
    int id;
    int legajo;
    char cargo[20];
    stPersona persona;
    stDomicilio domicilioLaboral;
}stEmpleado;

void muestraUnEmpleado(stEmpleado e);

#endif // EMPLEADO_H_INCLUDED
