/**
Leer 10 números y obtener su cubo y su cuarta.

*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nro, i, cubo = 0, cuarta = 0, cubo1 = 0, cuarta1 = 0;

    for(i=0;i<10;i++){
        printf("\n Ingrese un nro: ");
        scanf("%d", &nro);

        /// calculo cubo y cuarta multiplicando el numero por si mismo
        cubo = nro * nro * nro;
        cuarta = cubo * nro;

        /**
         calculo cubo y cuarta usando la funcion pow(), traten de solucionar los errores que se generan
         con pow que no siempre da el resultado buscado
         */
        cubo1 = pow(nro,3);
        cuarta1 = pow(nro,4);

        printf("\n\n Sin pow() El cubo del numero %d es %d y su cuarta es %d\n\n",nro,cubo,cuarta);
        printf("\n Con pow() El cubo del numero %d es %d y su cuarta es %d\n\n",nro,cubo1,cuarta1);

        system("pause");
        system("cls");
    }

    printf("Bye Bye world!\n");
    return 0;
}
