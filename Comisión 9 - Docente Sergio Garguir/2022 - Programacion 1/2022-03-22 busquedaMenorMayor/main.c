#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/**
Un cientifico necesita ingresar una cantidad indeterminada de temperaturas, se necesita saber
el promedio, la temperatura minima y la maxima.
*/

#define ESC 27

int main()
{
    int temp;
    int tempMin;
    int tempMax;
    int cantTemp = 0;
    int totalTemp = 0;
    float promedio;

    char opcion;

    do{
        printf("\n Ingrese una temperatura: ");
        scanf("%d", &temp);
        if(cantTemp == 0){
            tempMin = temp;
            tempMax = temp;
        }else{
            if(temp < tempMin){
                tempMin = temp;
            }else if(temp > tempMax){
                tempMax = temp;
            }
        }

        cantTemp++;
        totalTemp = totalTemp + temp; /// totalTemp+=temp;

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion = getch();

        system("cls");
    }while(opcion != ESC);

    promedio = (float)totalTemp/cantTemp;

    printf("\n\n");
    printf("\n La cantidad de temperaturas ingresadas es.............: \t%d", cantTemp);
    printf("\n El total de temperaturas es...........................: \t%d", totalTemp);
    printf("\n La temperatura minima es..............................: \t%d", tempMin);
    printf("\n La temperatura maxima es..............................: \t%d", tempMax);
    printf("\n El promedio de las temperaturas es....................: \t%.2f", promedio);
    printf("\n\n");

    return 0;
}
