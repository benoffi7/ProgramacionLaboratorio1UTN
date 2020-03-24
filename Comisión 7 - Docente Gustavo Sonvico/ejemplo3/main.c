#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int i=0;  /// contador
    int suma=0;  /// acumulador
    int valor=0;  /// auxiliar
    float promedio=0;

    char control='s';

    printf("Ingrese valores para realizar un promedio: \n");

    while(control=='s')
    {
        printf("Ingrese una valor: ");
        scanf("%d", &valor );

        suma=suma+valor;

        i++;

        printf("Desea continuar? s/n");
        fflush(stdin);
        scanf("%c", &control);
    }

    promedio=suma/i;

    printf("El promedio de los valores ingresados es %f", promedio);


    return 0;
}
