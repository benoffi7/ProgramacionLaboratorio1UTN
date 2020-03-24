#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota, contNotas=0, totalNotas=0; /// declaro 3 variables enteras e inicializo solo dos, el contador y el acumulador
    float promedio=0;
    char opcion;    /// Declaro una variable de tipo caracter para saber si el usuario quiere continuar o no

    do
    {
        printf("\nIngrese una nota: ");
        scanf("%d",&nota);
        contNotas = contNotas + 1; /// contNotas++  /// contNotas+=1
        totalNotas = totalNotas + nota;

        fflush(stdin);   /// Limpio el Buffer del teclado antes de escanear una variable de tipo char
        printf("\nDesea continuar? s/n ");
        scanf("%c",&opcion);
    }
    while(opcion=='s');

    promedio = (float)totalNotas / contNotas;  /// calculo el promedio haciendo un casteo (le digo al compilador que esa operacion
                                                /// la convierta a float

    printf("\nEl total de notas es %d, la cantidad de notas ingresadas es %d y el promedio es %f",totalNotas, contNotas, promedio);

    return 0;
}
