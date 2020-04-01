#include <stdio.h>
#include <stdlib.h>


int main()
{
    ///Leer 10 numeros y obtener su cubo y su cuarta.

    int valor = 0;
    int contadorCubo = 0;
    int valorCubo, valorCuarta;

    for(contadorCubo = 0 ; contadorCubo < 10; contadorCubo++)
    {
        printf("\nIngrese valor \n");
        scanf("%d", &valor);

        valorCubo = valor * valor * valor;
        valorCuarta = valorCubo * valor;

        printf("El cubo de %d es: %d\n", valor, valorCubo);
        printf("La cuarta de %d es: %d\n", valor, valorCuarta);
    }
    return 0;
}
