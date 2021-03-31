/**
    UTN
    Tecnicatura Universitaria en Programacion
    Programacion 1 y Laboratorio de computacion 1
    Comision 10
    Prof. Matias Pascual
*/

/**
    CLASE 2:
        . CONDICIONES LOGICAS
            IF
            ELSE
            ELSE IF
            SWITCH
            IF TERNARIO

        . OPERADORES RELACIONALES
            >   mayor
            <   menor
            =>  mayor igual
            <=  menor igual
            ==  igual
            !=  distinto

        . OPERADORES LOGICOS
            &&  y   (and)
            ||  o   (or)
            !   no  (not)

        . BUCLES DE ITERACION
            WHILE
            DO WHILE
            FOR
*/

/// ------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /// CONDICIONES LOGICAS
    /**
        Nos permiten tomar decisiones durante la ejecucion del programa

        Si la condicion que se evalua es verdadera, se ejecuta lo que esta
        entre las llaves.
    */

    /// EJEMPLO DE IF y ELSE

    int variableA = 0;

    if (variableA < 0)
    {
        printf("la variable A es negativa");
    }
    else
    {
        printf("la variable A es positiva");
    }

    /// ------------------------------------------------------------------------

    /// EJEMPLO DE IF, ELSE IF Y ELSE

    int variableB = 10;

    if (variableB == 0)
    {
        printf("la variable B es cero");
    }
    else if (variableB == variableA)
    {
        printf("la variable B es igual a la variable A");
    }
    else
    {
        printf("la variable B no es cero ni es igual a la variable A");
    }

    /// ------------------------------------------------------------------------

    /// EJEMPLPO DE IF ANIDADOS
    /** Averiguar si la variable c es la mas grande, la menor o la del medio */

    variableA = 0;
    variableB = 10;
    int variableC = 20;

    printf("ingrese el valor de la variable C");
    scanf("%d", &variableC);

    if (variableC > variableB)
    {/// entonces: C > B

        if (variableC > variableA)
        {/// entonces: C > A y C > B

            printf("la variable C es la mas grande");
        }
        else
        {/// entonces: A > C > B
            printf("la variable C es la del medio");
        }
    }
    else
    {/// entonces: B > C

        if (variableC > variableA)
        {/// entoncees: B > C > A

            printf("la variable C es la del medio");
        }
        else
        {/// entonces: B > C y A > C
            printf("la variable C es la mas chica");
        }
    }

    /// ------------------------------------------------------------------------

    /// EJEMPLO DE SWITCH
    char tecla = '0';

    printf("ingrese una tecla en minuscula y presione enter")
    scanf("%c", &tecla);

    switch(tecla)
    {
    case 'a':
        printf("la tecla es a");
        break;
    case 'b':
        printf("la tecla es b");
        break;
    case 'c':
        printf("la tecla es c");
        break;
    case 'd':
        printf("la tecla es d");
        break;
    default:
        printf("no se reconoce la tecla presionada");
    }

    /// ------------------------------------------------------------------------

    /// EJEMPLO DE IF TERNARIO

    int variableD = (variableA == 0) ? variableA : variableB;

    /**
        Esto se lee de la siguiente manera:
            si el valor de la variable A es 0,
            entonces asignar a la variable D el valor de la variable A,
            si no, asignarle el valor de la variable B
    */

    /// ------------------------------------------------------------------------

    /// OPERADORES RELACIONALES
    /**
        Permiten hacer diferentes comparaciones
    */

    /// mayor
    if (variableA > variableB)
    {
        /// se ejecuta este codigo
    }

    /// menor
    if (variableA < variableB)
    {
        /// se ejecuta este codigo
    }

    /// mayor igual
    if (variableA >= variableB)
    {
        /// se ejecuta este codigo
    }

    /// menor igual
    if (variableA <= variableB)
    {
        /// se ejecuta este codigo
    }

    /// igual
    if (variableA == variableB)
    {
        /// se ejecuta este codigo
    }

    /// distinto
    if (variableA != variableB)
    {
        /// se ejecuta este codigo
    }

    /// ------------------------------------------------------------------------

    /// OPERADORES LOGICOS
    /**
        permiten realizar comparaciones logicas
        utiles cuando quiero combinar comparaciones
    */

    /// y   (and)
    if ((variableA == variableB) && (variableA != variableC))
    {
        /// se ejecuta este codigo solo si las dos comparaciones
        /// son verdaderas
    }

    /// o   (or)
    if ((variableA == variableB) || (variableA != variableC))
    {
        /// se ejecuta este codigo si al menos una de las dos
        /// comparaciones es verdadera
    }

    /// no  (not)
    if (!(variableA == 0))
    {
        /// se ejecuta este codigo si la condicion es verdadera luego
        /// de ser negada
    }

    /// BUCLES DE ITERACION
    /**
        permiten realizar una misma tarea varias veces hasta una
        condicion de corte

        generalmente se componen de un contador, un condicional (que sirve
        como condicion de corte) y el codigo que se va a ejecutar
    */

    /// ------------------------------------------------------------------------

    /// EJEMPLO WHILE
    int contador = 0;
    while(contador < 10)
    {
        printf("el contador va por el: %d \n", contador);

        contador++;     /// es lo mismo que poner contador = contador + 1;
    }

    printf("fin del while \n");

    /// ------------------------------------------------------------------------

    /// EJEMPLO DO WHILE
    /// el do while se ejecuta siempre al menos una vez
    int contador = 11;
    do
    {
        printf("el contador va por el: %d \n", contador);

        contador++;     /// es lo mismo que poner contador = contador + 1;
    }
    while(contador < 10);

    printf("fin del while \n");

    /// ------------------------------------------------------------------------

    /// EJEMPLO FOR
    /// en el for ponemos el contador, el condicional y el incremento del contador,
    /// en la misma linea

    for(int contador = 0; contador < 10; contador++)
    {
        printf("el contador va por el: %d \n", contador);
    }

    return 0;
}
