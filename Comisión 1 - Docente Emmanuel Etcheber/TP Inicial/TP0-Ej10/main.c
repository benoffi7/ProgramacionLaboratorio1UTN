#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Leer 2 numeros; si son iguales que los multiplique,
    si el primero es mayor que el segundo que los reste y si no
    que los sume.*/

    int nro11, nro22, resultadoOperacion = 0;

    printf("Ingrese primer numero\n");
    fflush(stdin);
    scanf("%d", &nro11);

    printf("Ingrese segundo numero\n");
    fflush(stdin);
    scanf("%d", &nro22);

    if(nro11 == nro22)
    {
        resultadoOperacion = nro11 * nro22;
    }
    else{
        if(nro11 > nro22)
        {
            resultadoOperacion = nro11 - nro22;
        }
        else{
            resultadoOperacion = nro11 + nro22;
        }
    }

    printf("El resultado de la operacion es: %d\n", resultadoOperacion);

    return 0;
}
