#include <stdio.h>

#include "empleado.h"

void muestraUnEmpleado(stEmpleado e){
    printf("\nId.........................: %6d", e.id);
    printf("\nLegajo.....................: %6d", e.legajo);
    printf("\nCargo......................: %s", e.cargo);
    muestraUnaPersona(e.persona);
    printf("\nDomicilio laboral:");
    muestraUnDomicilio(e.domicilioLaboral);
}

stEmpleado cargaUnEmpleado(){
    stEmpleado e;
    static int id=0;
    id++;

    e.id = id;
    e.legajo = getLegajo();
    strcpy(e.cargo, getCargo());
    strcpy(e.persona.dni, "42515623");
    strcpy(e.persona.nombre, getNombre());
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
