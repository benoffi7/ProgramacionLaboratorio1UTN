#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domicilio.h"

void saludo(char name[]);

int main()
{
    /*
    char name[25];
    printf("\n Ingrese su nombre: ");
    fflush(stdin);
    scanf("%s",name);
    saludo(name);
    */
    char toString[200];
    char* toString2=malloc(200);
    printf("\n Peso de la estructura domicilio: %d\n", sizeof(stDomicilio));
    stDomicilio domicilio;
    domicilio = getDomicilio();
    muestraUnDomicilio(domicilio);
    domicilioToString(domicilio, toString);
    toString2=domicilioToString2(domicilio);
    printf("%s", toString);
    printf("%s", toString2);
    return 0;
}

void saludo(char name[]){
    printf("\nHello %s!",name);
}



