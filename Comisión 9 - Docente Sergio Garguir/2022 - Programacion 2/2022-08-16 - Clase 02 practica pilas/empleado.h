#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{
    int id;
    char nombre[25];
    char apellido[25];
    int edad;
}stEmpleado;

stEmpleado cargarUnEmpleado();
void muestraUnEmpleado(stEmpleado e);

#endif // EMPLEADO_H_INCLUDED
