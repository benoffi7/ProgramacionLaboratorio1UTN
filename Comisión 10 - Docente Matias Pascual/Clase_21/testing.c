typedef struct
{
    int x;
    int y;
} Pos;

typedef struct
{
    Pos pos;
    char* nombre;
    int dato;
} Persona;


void funcion()
{
    Persona persona;
    persona.dato = 33;
    persona.pos.x = 20;

    dibuja(&persona);

    printf("principal: %d", persona.pos.x);
}

void dibuja(Persona* persona)
{
    printf("%d", persona->pos.x);

    persona->pos.x = 40;
}
