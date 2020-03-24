#include <stdio.h>
#include <stdlib.h>

int main()
{
    /// Declaro e inicializo variables
    int nro1 = 0, nro2 = 0, resultado = 0;
    char operacion;

    /// Interactuo con el usuario
    printf("\n Ingrese un nro: ");
    scanf("%d", &nro1);
    printf("\n Ingrese otro nro: ");
    scanf("%d", &nro2);

    /// Proceso
    if(nro1 == nro2)
    {
        resultado = nro1 * nro2;
        operacion='x';
    }
    else
    {
        if(nro1 > nro2)
        {
        resultado = nro1 - nro2;
        operacion='-';
        }
        else
        {
            resultado = nro1 + nro2;
            operacion='+';
        }
    }

    /// muestro los datos

    printf("\n %d %c %d = %d",nro1, operacion, nro2, resultado);

    return 0;
}
