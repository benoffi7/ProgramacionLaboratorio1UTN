#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "empleado.h"
#include "autoCargaEmpleados.h"
#include "pilaEmpleados.h"


stEmpleado cargaUnEmpleado();

int main()
{
    Pila pilita;
    inicpila(&pilita);

    srand(time(NULL));

    char *s = NULL;

    agregaString(&s, " Algo ");
    printf("\n -- %s", s);

    agregaString(&s, " Otra cosa ");
    printf("\n -- %s", s);

    agregaString(&s, " algo mas ");
    printf("\n -- %s", s);

    agregaString(&s, getCargo());
    printf("\n -- %s", s);

    stEmpleado empleado = cargaUnEmpleado();

    printf("\n Pila de empleados");
    apilar(&pilita, empleado);


    muestraPilaEmpleados(pilita);

    strcpy(empleado.cargo, (char*)getCargo());

    muestraUnEmpleado(empleado);

    getNombre();

    return 0;
}

void agregaString(char **a, char *b){
    if(*a){
        (*a) = (char*)realloc((*a), strlen(*a)+strlen(b)+1);
        strcat((*a), b);
    }else{
        (*a) = (char*)malloc(sizeof(b)+1);
        strcpy((*a), b);
    }
}

void muestraPilaEmpleados(Pila p){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&p)){
        muestraUnEmpleado(tope(&p));
        apilar(&aux, desapilar(&p));
    }
}










