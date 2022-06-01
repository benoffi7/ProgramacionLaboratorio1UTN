#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{
    int id;
    int legajo;
    char nombre[30];
    char apellido[30];
    char dni[10];
}stEmpleado;

stEmpleado cargaUnEmpleado();
void muestraUnEmpleado(stEmpleado e);

#endif // EMPLEADO_H_INCLUDED
