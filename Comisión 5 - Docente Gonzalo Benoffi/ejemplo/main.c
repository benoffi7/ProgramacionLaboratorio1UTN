#include <stdio.h>
#include <stdlib.h>
//librerias que deben estar!!

int main()
{
    //aca ocurrira la magia!

    int numero1; //entero //declaracion

    numero1  = 1; //asignacion

    printf("hola mundo\n");
    //printf("el valor de numero 1 es ... %i\n",numero1);

    printf("ingrese un numero!\n");
    scanf("%i",&numero1);//sirve para guardar!
    printf("el valor de numero es ...  %i \n",numero1);

    /*
    if ((numero1 == 11) && (numero1 == 12) )//comparacion!
    {
        //si ambas son verdaderas entra
        printf("adivinaste");
    }
    */
    //7

    /*
    numero = numero++;
    numero = numero + 1;
    */

    if ( (numero1 == 11) || (numero1 == 12) )//comparacion!
    {
        //si alguna es verdadera entra
        printf("adivinaste");
    }
    else if (numero1 == 6) //entra lo que NO es 11 ni 12 pero ES 6
        {

            printf("no adivinaste pero cerca!");
        }
        else if (numero1 == 5)
        {
            printf("más cerca!");
        }
        else
            {
            printf("nadaaaa!");
        }


    return 0;
}
