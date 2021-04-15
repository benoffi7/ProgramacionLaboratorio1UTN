#include <stdio.h>
#include <stdlib.h>

/// como trabajamos con constantes (dos formas)
const int unaConstanteInt=1000;
#define OTRACONSTANTE 100


/// prototipado de la funcion

int sumarDosEnteros(int valor1, int valor2);

int main()
{
    printf("Hello funciones!\n");


    /// suma, a y b son locales al main
    int suma = 0;

    int a=10;
    int b=20;


    printf("El valor de a %d y el valor de b %d\n\n", a, b);

    suma=sumarDosEnteros(a,b);  /// sumarDosEnteros(valor1=a, valor2=b);
    /// pasaje de parametros por valor

    printf("\n Ahora el valor de a %d y el valor de b %d", a, b);

    printf("\nEl resultado es %d", suma);


    return 0;
}

/// declaracion
int sumarDosEnteros(int valor1, int valor2)  /// valor1 y valor2 son locales a la fn
{
/// cuerpo de la funcion

    int resultado=0; /// es variable local a la fn

    valor1 = 1;
    valor2= 9;

    resultado=valor1+valor2;



    return resultado;
}
