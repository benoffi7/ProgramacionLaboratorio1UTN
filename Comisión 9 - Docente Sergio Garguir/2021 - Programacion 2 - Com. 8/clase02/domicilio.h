#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

typedef struct{
    int id;
    char calle[30];
    char nro[8];
    char localidad[30];
    char cpos[8];
    char provincia[30];
}stDomicilio;

void muestraUnDomicilio(stDomicilio d);
stDomicilio cargaUnDomicilio();
char* getCalle();
char* domicilioToString(stDomicilio d);
char* domicilioToCsv(stDomicilio d);

#endif // DOMICILIO_H_INCLUDED
