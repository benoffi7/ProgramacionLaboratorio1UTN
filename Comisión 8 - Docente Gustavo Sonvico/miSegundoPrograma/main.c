#include <stdio.h>
#include <stdlib.h>

int main()
{


    /// declaracion de variable e inicializacion
    int nro1, nro2, nro3;
    int control=0;

    do
    {
        control=0;
        printf("Ingrese tres valores diferentes:\n");
        scanf("%d", &nro1);
        scanf("%d", &nro2);
        scanf("%d", &nro3);

        if ((nro1==nro2) && (nro2==nro3))
        {
            printf("Los valores ingresados son iguales\n");
        }
        else
        {
            if((nro1>nro2)&& (nro1>nro3))
            {
                printf("El mayor es el nro1");
            }
            else
            {
                if((nro2>nro1)&& (nro2>nro3))
                {
                    printf("El mayor es el nro2");
                }
                else
                {
                    printf("El mayor es el nro3");
                }
            }
        }

        printf("Desea continuar? 1=si 0=no \n");
        scanf("%d", &control);
    }
    while(control==1);
    return 0;
}
