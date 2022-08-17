#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

typedef struct{
    int id;
    char calleNombre[25];
    char calleNumero[6];
    char localidad[25];
    char cpos[9];
    char provincia[25];
}stDomicilio;

void muestraUnDomicilio(stDomicilio d);
stDomicilio getDomicilio();
void domicilioToString(stDomicilio d, char s[]);
char* domicilioToString2(stDomicilio d);
stDomicilio cargarUno();


#endif // DOMICILIO_H_INCLUDED
