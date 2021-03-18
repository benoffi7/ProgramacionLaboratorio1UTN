#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    printf("Ingrese un numero entero\n");
    scanf("%i", &numero1);///leer numero
    printf("Ingrese otro numero entero\n");
    scanf("%i", &numero2);
    if (numero1 > numero2)
    {
        printf("%i es mayor a %i\n",numero1,numero2);
    }
    else
    {
        if (numero2 > numero1) ///numero2 supera a numero1
        {
            if (numero2 < 50 && numero2 % 2 == 0) ///si el numero es menor a 50 y es par
            {
               printf("%i es mayor a %i y es menor a 50 y es par",numero2,numero1);
            }
            else
            {
                printf("%i es mayor %i y no se cumplen las condiciones\n",numero2,numero1);
            }

        }
        else
        {
            printf("son iguales\n");
        }
    }




    return 0;
}
///alternativa a if con AND
//            if (numero2 < 50) ///numero2 es menor a 50
//            {
//                if (numero2 % 2 == 0) /// operacion de mod (RESTO) para saber si numero2 es par
//                {
//                    printf("%i es mayor a %i y es menor a 50 y es par",numero2,numero1);
//                }
//
//            }




//SI numero1 > numero2 ENTONCES
//  escribir numero1 " es mayor a " numero2
//SINO
//  si numero2 > numero1 ENTONCES
//     escribir numero2 " es mayor a "numero1
//  SINO
//     escribir "Son iguales"
//  FIN-SI
//FIN-SI
