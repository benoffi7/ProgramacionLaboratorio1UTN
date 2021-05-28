#include "personas.h"

Persona inicPersona(int dni, char nombre[30])
{
    Persona persona;

    persona.dni = dni;

    strcpy(persona.nombre, nombre);

    persona.valido = 1; /// en este ejemplo, 1 seria verdadero.

    return persona;

    /// -> es una abreviatura de (*).
    /// ejemplo:
    ///     persona->dni = 10; es lo mismo que (*persona).dni = 10;
    ///     si usamos la forma de (*persona).dni, no debemos olvidar los parentesis

    /// NOTA: en los arreglos seguimos usando el punto, es decir: personas[1].dni = 20;
}

void mostrarPersona(const Persona* persona)
{
    /** al especificar que Persona es de tipo const Persona, estamos diciendo que
    la funcion no va a modificar los datos */

    // persona->dni = 10; esto arrojaria un error

    printf("nombre: %s \n", persona->nombre);
    printf("DNI: %i \n", persona->dni);
    printf("valido: %i \n\n", persona->valido);
}


/// cargar un arreglo de personas
int cargarPersonas(Persona personas[], const int dimension)
{
    int validos = 0;

    const int TECLA_SALIR = 27; /// ESC
    int teclaUsuario = 0;

    int i = 0;
    while(i < dimension && teclaUsuario != TECLA_SALIR)
    {
        fflush(stdin);
        printf("ingrese su nombre \n");
        gets(&personas[i].nombre);

        fflush(stdin);
        printf("ingrese su dni \n");
        scanf("%i", &personas[i].dni);

        personas[i].valido = 1;

        i++;

        printf("\npara continuar presione ENTER, para salir presione ESC \n");

        teclaUsuario = getch();

        printf("\n");
    }

    validos = i;

    return validos;
}

/// guardar un arreglo de personas en un archivo
void guardarPersonas(const Persona personas[], const int validos, FILE* archivo)
{
    for(int i = 0; i < validos; i++)
    {
        fwrite(&personas[i], sizeof(Persona), 1, archivo);
    }

    /**
        otra forma de hacer lo mismo, seria guardar el arreglo completo:
        fwrite(&personas, sizeof(personas), 1, archivo);
    */
}


void leerPersonas(Persona personas[], const int DIMENSION, FILE* archivo)
{
    int i = 0;
    while(fread(&personas[i++], sizeof(Persona), 1, archivo) > 0 && i < DIMENSION);

    /**
        tambien podemos leer todo el arreglo directamente, pero primero debemos
        asegurarnos que la cantidad de registros del archivo no supera la dimension
        del arreglo. Esto lo vimos en la clase anterior.

        comprobamos y luego...

        fread(personas, sizeof(personas), 1, archivo);
    */
}

void mostrarPersonas(const Persona personas[], int validos)
{
    printf("Personas del arreglo: \n\n");

    for(int i = 0; i < validos; i++)
    {
        mostrarPersona(&personas[i]); /// importante: como mostrarPersona nos pide un puntero
                                      /// debemos pasar la direccion de memoria del elemento
    }
}

void mostrarValidos(const Persona personas[], const int validos)
{
    printf("Personas del arreglo: \n\n");

    for(int i = 0; i < validos; i++)
    {
        if(personas[i].valido == 1)
        {
            mostrarPersona(&personas[i]);
        }
    }
}

void borrarRegistro(const int numeroResgistro, FILE* archivo)
{
    /** el archivo debe ser abierto en modo lectura y escritura (r+b) */

    /// buscamos la posicion
    fseek(archivo, sizeof(Persona) * numeroResgistro, SEEK_SET);

    /// leemos el registro del archivo y lo guardamos en una variable
    Persona personaAux;
    fread(&personaAux, sizeof(personaAux), 1, archivo);

    /// realizamos una baja logica
    personaAux.valido = 0;

    /// retrocedemos el puntero (cursor) del archivo un registro
    fseek(archivo, sizeof(Persona) * -1, SEEK_CUR);

    /// guardamos el registro modificado
    fwrite(&personaAux, sizeof(personaAux), 1, archivo);
}
