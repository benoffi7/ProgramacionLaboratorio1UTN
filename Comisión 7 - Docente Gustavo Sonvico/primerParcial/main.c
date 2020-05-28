#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pila.h"
/// 1
int cargarTemperaturasAutomatico(int T[], int cantMax);
int cargarTemperaturasUsr(int T[], int cantMax);
void mostrarTemperaturasArreglo(int T[], int validos);

///2.1
void separarTemperaturas(int T[], int validos, Pila * A, Pila * B, Pila *C);
///2.2
void mostrarTempsPila(Pila aMostrar);

/// 3.1
int contarTemps(Pila aux, int limite);
/// 3.2
int sumarTemps(Pila aux, int limite);
/// 3.3
void subProgramaPromedioPila(Pila aux);

/// 4.1
float porcentajeMenores(int T[], int validos, int limite);
/// 4.2
void subProgramaPorcentajeArreglos(int T[], int validos);

void menu();

int main()
{
    printf("Hello primer parcial!\n");

    srand(time(NULL));

    int arregloDeTemperaturas[90];
    int tempsCargadas=0;

    Pila menores;
    Pila intermedias;
    Pila mayores;

    inicpila(&menores);
    inicpila(&intermedias);
    inicpila(&mayores);


    tempsCargadas=cargarTemperaturasAutomatico(arregloDeTemperaturas, 90);
    //tempsCargadas=cargarTemperaturasUsr(arregloDeTemperaturas, 90);

    mostrarTemperaturasArreglo(arregloDeTemperaturas, tempsCargadas);


    separarTemperaturas(arregloDeTemperaturas, tempsCargadas, &menores, &intermedias, &mayores);

    printf("\n-----------\n");

    printf("\nTemperaturas menores:\n");
    mostrarTempsPila(menores);

    puts("\nTemperaturas intermedias:\n");
    mostrarTempsPila(intermedias);

    puts("\nTemperaturas mayores:\n");
    mostrarTempsPila(mayores);

    printf("\n-----------\n");

    subProgramaPromedioPila(mayores);

    printf("\n-----------\n");

    subProgramaPorcentajeArreglos(arregloDeTemperaturas, tempsCargadas);


    return 0;
}

/// 1
int cargarTemperaturasAutomatico(int T[], int cantMax)
{
    int i =0;
    for (i=0; i<cantMax; i++)
    {
        T[i]=(rand()%32)-1;
    }
    return i;
}

int cargarTemperaturasUsr(int T[], int cantMax)
{
    int i =0, dato;

    printf("Cargando el arreglo de temperaturas: \n");

    for (i=0; i<cantMax; i++)
    {
        printf("Ingrese una temperatura: ");
        scanf("%d", &dato);

        while(dato<-1 || dato > 31)
        {
            printf("Temperatura incorrecta, ingrese nuevamente: ");
            scanf("%d", &dato);
        }

        T[i]=dato;
    }
    return i;
}

/// aux 1
void mostrarTemperaturasArreglo(int T[], int validos)
{
    int i=0;
    printf("Temperaturas totales\n ");
    for(i=0; i<validos; i++)
    {
        if(i%10==0)
            printf("\n");
        printf(" %d", T[i]);

    }
}
/// 2.1
void separarTemperaturas(int T[], int validos, Pila * A, Pila * B, Pila *C)
{
    int i=0;
    for(i=0; i<validos; i++)
    {
        if(T[i]<10) /// menores a 10
        {
            apilar(A, T[i]);
        }
        else if(T[i]>20)  /// mayores a 20
        {
            apilar(C, T[i]);
        }
        else /// entre 10 y 20
        {
            apilar(B, T[i]);
        }
    }
}

/// 2.2
void mostrarTempsPila(Pila aMostrar)
{
    int dato;

    printf("Contenido de la franja de temperaturas: \n");
    while(!pilavacia(&aMostrar))
    {
        dato=desapilar(&aMostrar);
        printf("%d ", dato);
    }
}

/// 3.1
int contarTemps(Pila aux, int limite)
{
    int trash;
    int cantidad=0;

    while(!pilavacia(&aux))
    {
        if(tope(&aux)>limite)
        {
            cantidad++;
        }
        trash=desapilar(&aux);
    }
    return cantidad;
}

/// 3.2
int sumarTemps(Pila aux, int limite)
{
    int trash;
    int suma=0;

    while(!pilavacia(&aux))
    {
        if(tope(&aux)>limite)
        {
            suma=suma+tope(&aux);
        }
        trash=desapilar(&aux);
    }
    return suma;
}

/// 3.3
void subProgramaPromedioPila(Pila aux)
{
    int valorReferencial=0, suma, cant;

    float promedio=0;

    printf("Ingrese la temperatura referencial para calcular el promedio superior: ");
    scanf("%d",&valorReferencial);

    suma=sumarTemps(aux, valorReferencial);

    cant=contarTemps(aux, valorReferencial);

    if(cant>0)
    {
        promedio=(float)suma/(float)cant;
    }

    printf("El promedio de los valores superiores a %d grados fue de %.2f", valorReferencial, promedio);
}

/// 4.1
float porcentajeMenores(int T[], int validos, int limite)
{
    int i=0, cantidad=0;

    float porcent=0;

    for(i=0; i<validos; i++)
    {
        if(T[i]<limite)
        {
            cantidad++;
        }
    }

    porcent= (float)(cantidad*100)/(float)validos;

    return porcent;
}

/// 4.2
void subProgramaPorcentajeArreglos(int T[], int validos)
{
    int valorReferencial=0;

    float porcent=0;

    printf("Ingrese la temperatura referencial para calcular el porcentaje: ");
    scanf("%d",&valorReferencial);

    porcent=porcentajeMenores(T, validos, valorReferencial);

    printf("El porcentaje de temperaturas inferiores a %d grados fue de %.2f %%", valorReferencial, porcent);

}

void menu()
{
    system("cls");
    printf("Opciones del sistema de temperaturas: \n");
    printf("1- Cargar temperaturas \n");
    printf("2- Separar temperaturas \n");
    printf("3- Promedio temperaturas superiores \n");
    printf("4- Porcentaje temperaturas inferiores \n\n");
    printf("Seleccione una opcion: ");
}
