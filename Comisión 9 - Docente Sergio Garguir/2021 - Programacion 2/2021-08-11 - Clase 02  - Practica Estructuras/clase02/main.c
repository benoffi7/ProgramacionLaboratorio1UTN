#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "domicilio.h"
//#include "persona.h"
#include "empleado.h"

stEmpleado cargaUnEmpleado();

int main()
{
    srand(time(NULL));

    stEmpleado empleado = cargaUnEmpleado();

    muestraUnEmpleado(empleado);

    return 0;
}

stEmpleado cargaUnEmpleado(){
    stEmpleado e;
    static int id=0;
    id++;

    e.id = id;
    e.legajo = 100 + id;
    strcpy(e.cargo, "Developer");
    strcpy(e.persona.dni, "42515623");
    strcpy(e.persona.nombre, "Pepe");
    strcpy(e.persona.apellido, "Argento");
    e.persona.genero = 'M';
    strcpy(e.persona.domicilio.calle, "San Lorenzo");
    strcpy(e.persona.domicilio.nro, "1536");
    strcpy(e.persona.domicilio.cpos, "7600");
    strcpy(e.persona.domicilio.localidad, "Mar del Plata");
    strcpy(e.persona.domicilio.provincia, "Buenos Aires");
    strcpy(e.domicilioLaboral.calle, "Belgrano");
    strcpy(e.domicilioLaboral.nro, "3625");
    strcpy(e.domicilioLaboral.cpos, "7600");
    strcpy(e.domicilioLaboral.localidad, "Mar del Plata");
    strcpy(e.domicilioLaboral.provincia, "Buenos Aires");

    return e;
}
