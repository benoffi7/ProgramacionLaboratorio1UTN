#include <stdio.h>
#include <stdlib.h>

int main()
{
//    printf("Hello world pedorros!\n");
//
//    int nro1, nro2, suma;
//
//    printf("Ingrese el primer numero: \n");
//    scanf("%d",&nro1);
//
//    printf("Ingrese el segundo numero: \n");
//    scanf("%d",&nro2);
//
//    suma = nro1+nro2;
//
//    printf("El primer valor es %d, el segundo valor es %d y la suma de ambos es %d\n", nro1, nro2, suma);
//
//    /// condicional simple
//
//    /* if(nro1>10){
//         printf("El valor ingresado es mayor que 10\n");
//     } */
//
//    /// condicional doble o compuesto
//    if(nro1>10)
//    {
//        printf("El valor ingresado es mayor que 10\n");
//    }
//    else
//    {
//        if(nro1<10)
//        {
//            printf("El valor ingresado es menor que 10\n");
//        }
//        else
//        {
//            printf("El valor ingresado es 10\n");
//        }
//    }
//
//    */


    /// mientras
    int i=0;

    while(i<10)
    {
        printf("Hola mundo desde while %d \n", i);
        i=i+1;
    }

    /// hacer-mientras

    do
    {
        printf("Hola mundo desde do-while %d \n", i);
        i++;
    }while(i<10);

    /// para

    int limite;
    printf("Cuatos saludos queres ver? ");
    scanf("%d", &limite);

/// para i=0 hasta 10 con paso 1 (no incluye al 10)
    for(i=0;i<limite;i++)
        /// i=0 inicializa la variable que controla el para
        /// i<10 condiciona el para (hasta que)
        /// i++ es el paso o incremento
    {
        printf("Hola mundo desde for %d \n", i);
    }


    return 0;
}
