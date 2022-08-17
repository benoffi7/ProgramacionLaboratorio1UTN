#ifndef PILAEMPLEADOS_H_INCLUDED
#define PILAEMPLEADOS_H_INCLUDED

#include "empleado.h"

typedef struct{
    stEmpleado *e;
    int v;
    int dim;
}PilaEmpleados;

void inicPilaEmpleados(PilaEmpleados *p);
void apilarEmpleados(PilaEmpleados *p, stEmpleado e);
stEmpleado desapilarEmpleados(PilaEmpleados *p);
stEmpleado topeEmpleados(PilaEmpleados *p);
int pilaVaciaEmpleados(PilaEmpleados *p);

#endif // PILAEMPLEADOS_H_INCLUDED
