#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/**
Un cientifico necesita un sistema para ingresar tantas temperatura como sea necesario, se las debe contar, calcular el promedio
y la temperatura máxima y mínima.
*/

#define ESC 27

int main()
{
    char opcion;
    int temperatura;
    int cantidadDeTemperaturas = 0;
    int totalDeTemperaturas = 0;
    int tempMin;
    int tempMax;
    float promedio;

    do{
        printf("\n Ingrese una temperatura: ");
        scanf("%d", &temperatura);

        if(cantidadDeTemperaturas == 0){
            tempMin = temperatura;
            tempMax = temperatura;
        }else{
            if(temperatura < tempMin){
                tempMin = temperatura;
            }else{
                if(temperatura > tempMax){
                    tempMax = temperatura;
                }
            }
        }
        cantidadDeTemperaturas = cantidadDeTemperaturas + 1; // cantidadDeTemperaturas++
        totalDeTemperaturas = totalDeTemperaturas + temperatura;

        printf("\n\n ESC para salir - cualquier tecla para continuar");
        opcion = getch();
        system("cls");

    }while(opcion != ESC);

    promedio = (float)totalDeTemperaturas / cantidadDeTemperaturas;

    printf("\n\n");
    printf("\n La cantidad de temperaturas ingresadas es.........: %d \t", cantidadDeTemperaturas);
    printf("\n El total de temperaturas ingresadas es............: %d \t", totalDeTemperaturas);
    printf("\n El promedio de las temperaturas ingresadas es.....: %.2f \t", promedio);
    printf("\n La temperatura minima es..........................: %d \t", tempMin);
    printf("\n La temperatura maxima es..........................: %d \t", tempMax);

    return 0;
}
