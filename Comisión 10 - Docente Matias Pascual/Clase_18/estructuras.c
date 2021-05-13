/// son tipos de datos definidos por el usuario

struct
{
    int legajo;
    char nombre[100];
    float promedio;

} persona;

void ejemplo_estructuras()
{
    persona.legajo = 10;
    strcpy(persona.nombre, "juan garcia");
    persona.promedio = 8.6F;

    printf("%d \n", persona.legajo);
    printf("%s \n", persona.nombre);
    printf("%.2f \n", persona.promedio);
}

void usandoTypeDef()
{
    typedef unsigned short int usint;

    usint numero = 10;

    printf("%d", sizeof(numero));
}

void otroEjemploDeTypeDef()
{
    //usint otroNumero = 10; /// error: usint no pertenece a este ambito. Fue declarado en otra funcion,
                           /// por lo tanto es local a esa funcion
}

/// ------------------------------------------------------------------------

/// al declarar el struct fuera de una funcion, puedo usarlo de forma global

typedef struct
{
    int legajo;
    char nombre[100];
    float promedio;

} stPersona;

void ejemplo_persona()
{
    stPersona unaPersona;

    unaPersona.legajo = 33;
    strcpy(unaPersona.nombre, "roberto ricardo");
    unaPersona.promedio = 7.6F;

    stPersona otraPersona;

    otraPersona.legajo = 543;
    strcpy(otraPersona.nombre, "tadeo tamaro");
    otraPersona.promedio = 7.6F;

    muestraPersona(unaPersona);

    printf("\n");

    muestraPersona(otraPersona);
}

/// PARA RESOLVER EN CLASE:
/// Crear una funcion que muestre los datos de una persona pasada por parametro

void muestraPersona(stPersona persona)
{
    printf("legajo: %d \n", persona.legajo);
    printf("nombre: %s \n", persona.nombre);
    printf("promedio: %.2f \n", persona.promedio);
}
