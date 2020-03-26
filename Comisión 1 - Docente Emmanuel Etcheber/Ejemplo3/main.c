#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Calcular un promedio
    int i=0; ///contador

    int suma=0; ///acumulador

    int valor=0; ///auxiliar

    float promedio=0;

    char control = 's';

    printf("Ingrese valores para realizar un promedio: \n\n");

    while (control == 's')
    {
        printf("Ingrese un valor\n");
        scanf ("%d", &valor);
        suma+=valor; ///suma=suma+valor;
        i++;

        printf("\nSi desea continuar, ingrese 's' ");
        fflush(stdin);
        scanf("%c", &control);
    }

    promedio = (float)suma / (float)i;

    printf("\nEl promedio de los valores ingresados es de: %.2f ", promedio);
    return 0;
}
