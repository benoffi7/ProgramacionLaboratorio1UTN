#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota, contNotas=0, totalNotas=0;
    float promedio=0;
    char opcion;

    do
    {
        printf("\nIngrese una nota: ");
        scanf("%d",&nota);
        contNotas = contNotas + 1; /// contNotas++  /// contNotas+=1
        totalNotas = totalNotas + nota;

        fflush(stdin);
        printf("\nDesea continuar? s/n ");
        scanf("%c",&opcion);
    }
    while(opcion=='s');

    promedio = (float)totalNotas / contNotas;

    printf("\nEl total de notas es %d, la cantidad de notas ingresadas es %d y el promedio es %f",totalNotas, contNotas, promedio);

    return 0;
}
