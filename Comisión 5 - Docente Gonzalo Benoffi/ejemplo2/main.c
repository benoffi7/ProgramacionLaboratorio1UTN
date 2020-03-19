#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1 ;

    int limite = 10;

    char seguir = 's';

    numero1 = 1;

    //prestar atencion al inicio con la variable para que entre

    /*while (numero1 <= 10)
    {
        printf("el valor de numero es ... %d\n",numero1);
        numero1 = numero1 + 1;

        //tener en cuenta para que no se haga infinito
    }*/

    /*
    while (seguir == 's')
    {
        printf("hola\n");
        fflush(stdin);
        scanf("%c",&seguir);
        printf("hola %c\n",seguir);
    }
    */

    seguir = 'n';

    /*
    do
    {
        printf("hola\n");
        fflush(stdin);
        scanf("%c",&seguir);

    }while (seguir == 's');
    */

    //PARA


    for (int i = 0; i < limite ;i++)
    {
            //REPITE
            //EVALUA
            //AUMENTA
              //printf("el valor de numero es ... %d\n",i);
              printf("ingrese un numero\\n");
              fflush(stdin);
              scanf("%d",&numero1);
              if (numero1 == 11) { printf("bien!\n");}
              else { printf("te queda una oportunidad menos\n");}

    }



    return 0;
}
