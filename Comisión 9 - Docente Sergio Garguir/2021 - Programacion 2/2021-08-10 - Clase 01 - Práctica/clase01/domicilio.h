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

void saludo();
void muestraUnDomicilio(stDomicilio);
stDomicilio getDomicilio();
void domicilioToString(stDomicilio d, char s[150]);
char* domicilioToStringPuntero(stDomicilio d);
char* domicilioToCsv(stDomicilio d);
char* domicilioToJson(stDomicilio d);

#endif // DOMICILIO_H_INCLUDED
