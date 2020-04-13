#include <stdio.h>
#include <stdlib.h>

/// prototipados de funciones
int sumar(int n1, int n2);
void sumarReferencia(int n1, int n2, int *total);
int divide(int n1, int n2);
int multiplica(int n1, int n2);
void saludo();
float promedio(int a, int b);
void intercambio(int *n1, int *n2);


const int ALGO = 25;

int main()
{
    int numero1 = 10; /// #1024
    int numero2 = 20; /// #2048
    int sumaCopia = 0;
    int sumaRef = 0;   /// #128
    int div = 0;
    int multi;
    int mayor;
    int total;
/*
    printf("\n Ingrese un numero:");
    scanf("%d", &numero1);

    printf("\n Ingrese un numero:");
    scanf("%d", &numero2);
*/

    intercambio(&numero1, &numero2);
    sumaCopia = sumar(numero1, numero2); /// pasaje de parametros por copia
    sumarReferencia(numero1, numero2, &sumaRef); /// pasaje de parametros por referencia
           ///        10      20        #128
    saludo();
    printf("\n Resultados usando pasaje de parametros por copia");
    printf("\n La suma de %d + %d es: %d - %p\n", numero1, numero2, sumaCopia, &sumaRef);

    printf("\n Resultados usando pasaje de parametros por referencia");
    printf("\n La suma de %d + %d es: %d \n", numero1, numero2, sumaRef);

    return 0;
}

/// funciones
/// numero1 #512
int sumar(int n1, int n2){
    int total = 0;
    total = n1 + n2;

    return total;
}
///                      10      20        #128
void sumarReferencia(int n1, int n2, int *total){
    *total = n1 + n2;
}

void saludo(){
    printf("\n\n Hola, esta es mi primer funcion");
    printf("\n____________________________________________\n\n");
}

float promedio(int a, int b){
    float pro = (float) a / b;
    return pro;
}

void intercambio(int *n1, int *n2){
    int aux;
    aux=*n1;
    *n1=*n2;
    *n2=aux;
    printf("\n En la funcion intercambio");
    printf("\n Las variables %d + %d\n", *n1, *n2);
    system("pause");
}
