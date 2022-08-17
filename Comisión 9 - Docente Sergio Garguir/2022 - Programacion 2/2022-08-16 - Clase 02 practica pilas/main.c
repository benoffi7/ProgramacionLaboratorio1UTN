#include <stdio.h>
#include <stdlib.h>
#include "pilaEmpleados.h"

int main()
{
    stEmpleado e;
    PilaEmpleados p;
    inicPilaEmpleados(&p);

    for(int i=0;i<49;i++){
        apilarEmpleados(&p, cargarUnEmpleado());
    }
    printf("\n %d", sizeof(p));

    for(int i=0;i<49;i++){
        apilarEmpleados(&p, cargarUnEmpleado());
    }
    printf("\n %d", sizeof(p));

    while(!pilaVaciaEmpleados(&p)){
        muestraUnEmpleado(desapilarEmpleados(&p));
    }

    return 0;
}
