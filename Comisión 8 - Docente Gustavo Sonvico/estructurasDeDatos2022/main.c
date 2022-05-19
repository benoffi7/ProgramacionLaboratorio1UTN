#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int matricula;
    char nombreYApe[50];
    char genero; ///m, f, x
} stEstudiante;

int cargaDeEstudiantes(stEstudiante E[], int dim);
void mostrarUnEstudiante(stEstudiante e);
void mostrarEstudiantes(stEstudiante E[], int validos);


int main()
{
    printf("Hello estructuras!\n");
/*
    stEstudiante unEstudiante;
    stEstudiante otroEstudiante= {1025,"juan topo", 'm'};

    printf("Ingrese la matricula: ");
    scanf("%d", &unEstudiante.matricula);

    printf("Ingrese la nombre: ");
    fflush(stdin);
    gets(unEstudiante.nombreYApe);

    printf("Ingrese la genero: ");
    unEstudiante.genero=getch();

    mostrarUnEstudiante(unEstudiante);

    mostrarUnEstudiante(otroEstudiante);

    */

    /// arreglo de estudiantes

    stEstudiante miListaDeEstudiantes[105];
    int validos=0;

    /// ejemplos de administracion del arreglo
//    miListaDeEstudiantes[0]=unEstudiante;
//
//    otroEstudiante=miListaDeEstudiantes[0];

    /// carga del arreglo
    validos=cargaDeEstudiantes(miListaDeEstudiantes, 105);

    mostrarEstudiantes(miListaDeEstudiantes, validos);

    return 0;
}

int cargaDeEstudiantes(stEstudiante E[], int dim)
{
    int i=0;
    char control = 's';


    printf("Vamos a cargar el arreglo de estudiantes: \n");

    while(control=='s' && i<dim)
    {
        printf("Ingrese la matricula: ");
        scanf("%d", &E[i].matricula);

        printf("Ingrese la nombre: ");
        fflush(stdin);
        gets(E[i].nombreYApe);

        printf("Ingrese la genero: ");
        fflush(stdin);
        scanf("%c",&E[i].genero);

        printf("Desea continuar? s/n --->");
        control=getch();

        i++;
    }

    return i;
}

void mostrarUnEstudiante(stEstudiante e)
{
    printf("        Matricula: %d\n", e.matricula);
    printf("Nombre y apellido: %s\n", e.nombreYApe);
    printf("           Genero: %c\n", e.genero);
}

void mostrarEstudiantes(stEstudiante E[], int validos)
{
    int i=0;
    printf("Mostrando lista de estudiantes:\n\n");

    for(i=0; i<validos; i++)
    {
        printf("---------------\n");
        mostrarUnEstudiante(E[i]);
    }
    printf("---------------\n");
}
