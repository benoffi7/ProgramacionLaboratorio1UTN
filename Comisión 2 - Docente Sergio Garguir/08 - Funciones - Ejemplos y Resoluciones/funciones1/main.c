#include <stdio.h>
#include <stdlib.h>

/// prototipados de funciones
int sumar(int n1, int n2);
void sumarReferencia(int n1, int n2, int *total);
int divide(int n1, int n2);
int multiplica(int n1, int n2);
void saludo();
int mayor0(int nro);
float promedio(int a, int b);

const int ALGO = 25;

int main()
{
    int numero1 = 0;
    int numero2 = 0;
    int suma = 0;
    int div = 0;
    int multi;
    int mayor;
    int total;

    printf("\n Ingrese un numero:");
    scanf("%d", &numero1);

    printf("\n Ingrese un numero:");
    scanf("%d", &numero2);

    suma = sumar(numero1, numero2);
    sumarReferencia(numero1, numero2, &total);
    mayor = mayor0(suma);


    saludo();
    printf("\n La suma de %d + %d es: %d - %d", numero1, numero2, suma, total);

    return 0;
}

/// funciones
int sumar(int n1, int n2){
    int total = 0;
    total = n1 + n2;

    return total;
}

void sumarReferencia(int n1, int n2, int *total){
    *total = n1 + n2;
}

void saludo(){
    printf("\n\n Hola, esta es mi primer funcion");
    printf("\n____________________________________________\n\n");
}

int mayor0(int nro){
    int respuesta=0;
    if(nro>0){
        respuesta = 1;
    }
    else{
        respuesta = 0;
    }

    return respuesta;
}

float promedio(int a, int b){
    float pro = (float) a / b;
    return pro;
}
