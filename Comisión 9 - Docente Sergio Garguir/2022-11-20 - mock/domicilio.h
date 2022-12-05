#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

typedef struct{
    int id;
    char calle[30];
    char nro[6];
    char localidad[30];
    char cpos[8];
    char provincia[20];
}stDomicilio;

void muestraUnDomicilio(stDomicilio d);
char *domicilioToString(stDomicilio);
char *domicilioToCsv(stDomicilio);
char *domicilioToJson(stDomicilio);

#endif // DOMICILIO_H_INCLUDED
