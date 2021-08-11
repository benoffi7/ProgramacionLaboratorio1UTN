#include <stdio.h>
#include <string.h>
#include <string.h>
#include <malloc.h>
#include "autoCargaEmpleados.h"

int getId(){
    static int id=0;
    id++;
    return id;
}

int getLegajo(){
    static int legajo=1000;
    legajo++;
    return legajo;
}

char *getCargo(){
    char cargos[][20]={"Developer","Developer Full Stack","Developer Front-End","Developer Java","Developer Back-End","Developer C"};
    return cargos[rand()%(sizeof(cargos)/20)];
}

char *getNombre(){
    char nombres[][30]={"Maria","Jorge"};
    return nombres[rand()%(sizeof(nombres)/30)];
}
