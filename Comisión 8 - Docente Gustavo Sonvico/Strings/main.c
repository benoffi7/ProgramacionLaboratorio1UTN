#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Hello manejo de \"strings\" \n");

    char palabra1[20];

    char palabra2[30];
//
//    system("pause");
//    fflush(stdin);
//    scanf("%s", palabra1);
//
//    system("pause");
//    fflush(stdin);
//    scanf("%s", palabra2);
//
//    printf("Primer palabra %s \n", palabra1);
//    printf("Segunda palabra %s \n", palabra2);

    system("pause");
    fflush(stdin);
    gets(palabra1);

    int largo = strlen(palabra1);

    printf("El largo de la palabra %s es %d\n", palabra1, largo);

    system("pause");
    fflush(stdin);
    scanf("%s", palabra2);

    printf("\n\npalabra1:  %s", palabra1);
    printf("\n\npalabra2: %s\n", palabra2);

    system("pause");

/// strcmp ();

/// strcmpi ();
/// esta funcion SI hace distincion entre MAYUSCULAS y minusculas
/// si queremos evitar eso... utilizaremos strcmpi();

    int respuesta= strcmp(palabra1, palabra2);

    printf("\n\n%d", respuesta);
    if(respuesta<0)
    {
        printf("\n\npalabra 1 esta antes que palabra 2");
    }
    else if(respuesta>0)
    {
        printf("\n\npalabra 2 esta antes que palabra 1");
    }
    else
    {
        printf("\n\npalabra 1 y palabra 2 son iguales");
    }


/// strcpy(destino, origen);
    char palabraCopiada[50]="esto es una prueba";

/// palabra1=palabraCopiada; ----> OJO!!! no se puede hacer porque son arreglos

///        destino    origen
    strcpy(palabra1,palabraCopiada);

    printf("\n\npalabra1: %s",palabra1);
    printf("\n\npalabraCopiada: %s",palabraCopiada);




/// vamos a leer del teclado, utilizando las funciones scanf() y gets()

    char nombre[20];
    char nombreYapellido[30];

    printf("\n\nIngrese un nombre (sin espacios en blanco): ");


    scanf("%s", nombre);

    printf("\n\nAhora ingrese un nombre y apellido (con espacios en blanco): ");
    fflush(stdin);
    gets(nombreYapellido);

    printf("\n\nEl nombre es %s", nombre);
    printf("\n\nEl nombre y apellido es %s", nombreYapellido);


    printf("\n\n");
    return 0;
}
