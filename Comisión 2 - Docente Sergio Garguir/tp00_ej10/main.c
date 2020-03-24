#include <stdio.h>
#include <stdlib.h>

int main()
{
    /// declaro e inicializo variables
    int nro1 = 0, nro2 = 0, nro3 = 0, mayor = 0, error = 0;

    /// interactuo con el usuario
    printf("\n Ingrese un numero: ");
    scanf("%d", &nro1);
    printf("\n Ingrese un numero: ");
    scanf("%d", &nro2);
    printf("\n Ingrese un numero: ");
    scanf("%d", &nro3);

    /// proceso datos
    if((nro1 > nro2) && (nro1 > nro3))
    {
        mayor = nro1;
    }
    else
    {
        if((nro2 > nro1) && (nro2 > nro3))
        {
            mayor = nro2;
        }
        else
        {
            if((nro3 > nro1) && (nro3 > nro2))
            {
                mayor = nro3;
            }
            else
            {
                error = 1;
            }
        }
    }

    /// Muestro los datos
    if(error == 1)
    {
        printf("ERROR - Datos incorrectos");
    }
    else
    {
        printf("\n El mayor entre %d - %d - %d es el numero %d",nro1, nro2, nro3, mayor);
    }

    return 0;
}
