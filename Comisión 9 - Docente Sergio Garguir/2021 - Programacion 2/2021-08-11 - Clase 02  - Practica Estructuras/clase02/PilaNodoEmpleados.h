#ifndef PILANODOEMPLEADOS_H_INCLUDED
#define PILANODOEMPLEADOS_H_INCLUDED

#include "empleado.h"

#define Pila nodo*

void inicPilaEmpleados(Pila* pila);
void apilarEmpleados(Pila* pila, stEmpleado e);
stEmpleado topePilaEmpleados(Pila* pila);
stEmpleado desapilarEmpleado(Pila* pila);


#endif // PILANODOEMPLEADOS_H_INCLUDED
