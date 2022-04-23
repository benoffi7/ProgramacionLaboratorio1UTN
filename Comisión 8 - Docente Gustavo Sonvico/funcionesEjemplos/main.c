#include <stdio.h>
#include <stdlib.h>

/** \brief Funcion para sumar dos enteros
 *
 * \param int a
 * \param int b
 * \return int resultado
 *
 */
int sumar (int a, int b)
{
    int resultado =0;

    resultado = a + b;

    return resultado;
}

int main()
{

    int a=10;

    int * p = NULL;

    p=&a;

    printf("La posicion de memoria de la variable a es %p y su contenido es %d \n\n", p, *p);

    system("pause");

    int nro1=0, nro2=0, rta=0;
    printf("Hello funciones!\n");

    do
    {
        printf("\n\nIngrese dos valores enteros: \n");
        scanf("%d", &nro1);
        scanf("%d", &nro2);

/// en la invocacion, nro1 y nro2 son parametros actuales
/// copian su informacion en los parametros formales

        rta = sumar(nro1, nro2);

        printf("\nEL resultado obtenido es %d", rta);


    }
    while(rta!=100);

    return 0;
}

/// funciones
/// a y b son parametros formales




