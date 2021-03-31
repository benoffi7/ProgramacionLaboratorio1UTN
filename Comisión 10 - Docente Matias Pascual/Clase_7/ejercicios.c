#include "Librerias/pila.h"

void ejercicios()
{
    copiarContenidoDeUnaPilaAOtraPila();
    quePasaSiIgualamosLasPilas();
    pilaCapicua();
    ejemploRandYsrand();
    ejercicio3guia0();
}

/// -------------------------------------------------

void copiarContenidoDeUnaPilaAOtraPila()
{
    /// el objetivo es copiar el contenido de la
    /// pila A en la pila B
    Pila pilaA;
    Pila pilaB;

    Pila auxA;   /// necesitamos dos auxiliares para recorrer las pilas
    Pila auxB;

    /// inicializamos todas las pilas
    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&auxA);
    inicpila(&auxB);

    /// damos datos a la pila A
    apilar(&pilaA, 10);
    apilar(&pilaA, 20);
    apilar(&pilaA, 30);
    apilar(&pilaA, 40);

    while(!pilavacia(&pilaA))
    {
        /// apilamos en auxB el tope de A
        apilar(&auxB, tope(&pilaA));

        /// apilamos en auxA lo que desapilamos de A
        /// de esta forma recorremos la pila sin perder informacion
        apilar(&auxA, desapilar(&pilaA));

        /**
            NOTA:
                si usaramos apilar(&auxB, desapilar(&a));
                estariamos perdiendo los datos de A
        */
    }

    /// volvemos a dejar la pila A en su forma original
    while(!pilavacia(&auxA))
    {
        apilar(&pilaA, desapilar(&auxA));
    }

    /// pasamos de auxB a la pila B
    /// de esta forma los datos quedan ordenados igual que pilaA
    while(!pilavacia(&auxB))
    {
        apilar(&pilaB, desapilar(&auxB));
    }

    /// comprobamos que ambas pilas estan copiadas y con los
    /// datos ordenados
    mostrar(&pilaA);
    mostrar(&pilaB);
}

/// -------------------------------------------------

void quePasaSiIgualamosLasPilas()
{
    /// al igualar las pilas, sus valores apuntan al
    /// mismo lugar en la memoria RAM.
    /// esto tendra mas sentido cuando veamos punteros.

    /// analicemos este codigo:

    /// creamos dos pilas, las inicializamos y les damos datos diferentes
    Pila pila1;
    inicpila(&pila1);

    Pila pila2;
    inicpila(&pila2);

    /// datos de pila1
    apilar(&pila1, 50);
    apilar(&pila1, 60);
    apilar(&pila1, 70);

    /// datos de pila2
    apilar(&pila2, 10);
    apilar(&pila2, 20);
    apilar(&pila2, 30);

    /// mostramos ambas pilas
    mostrar(&pila1);
    mostrar(&pila2);

    /// en estas dos lineas de codigo, estamos mostrando
    /// la direccion de memoria del primere valor almacenado
    /// en cada pila, tanto pila1 como pila2
    printf("%X \n\n", &pila1.valores[0]);
    printf("%X", &pila2.valores[0]);

    /// ahora igualamos pila1 a pila2
    pila1 = pila2;

    /// asignamos un valor al primer elemento de la pila2
    /**
        NOTA: esta no es la forma correcta de usar la pila,
            esta hecho asi para demostrar el problema de la
            asignacion de una pila a otra.
    */
    pila2.valores[0] = 33;

    /// mostramos el contenido de ambas pilas
    /// podemos notar que cambio el valor de la pila2, pero tambien
    /// el valor de la pila1. Esto no deberia haber pasado.
    mostrar(&pila1);
    mostrar(&pila2);

    /// al mostrar la direccion de memoria del primer valor de la pila
    /// luego de la asignacion pila1 = pila2, vemos que ambos valores
    /// son en realidad el mismo, ya que estan en el mismo lugar en la
    /// memoria
    printf("%X \n\n", &pila1.valores[0]);
    printf("%X", &pila2.valores[0]);

    /// por eso no debemos utilizar pila1 = pila2 para copiar los
    /// contenidos de las pilas, sino utilizar los algoritmos
    /// aprendidos en clase para recorrer y copiar pilas
}

/// -------------------------------------------------

void pilaCapicua()
{
    /// creamos una copia invertida de la pila
    /// y comparamos sus topes

    Pila pilaOriginal;
    inicpila(&pilaOriginal);

    /// apilamos datos en la pila
    apilar(&pilaOriginal, 10);
    apilar(&pilaOriginal, 20);
    apilar(&pilaOriginal, 30);
    apilar(&pilaOriginal, 20);
    apilar(&pilaOriginal, 10);

    /// copiamos la pila
    Pila pilaCopia;
    inicpila(&pilaCopia);

    /// utilizamos un auxiliar para recorrer la pila
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&pilaOriginal))
    {
        /// pila copia es donde guardamos la copia de los datos
        /// de la pila original
        apilar(&pilaCopia, tope(&pilaOriginal));
        apilar(&aux, desapilar(&pilaOriginal));
    }

    /// volvemos a dejar la pila original con sus datos
    /// como estaban antes de recorrerla
    /**
        NOTA: recordemos que al recorrer una pila,
            los datos quedan al reves de como estaban
            originalmente.
    */

    while(!pilavacia(&aux))
    {
        apilar(&pilaOriginal, desapilar(&aux));
    }

    /// utilizamos un flag que nos indica cuando la
    /// pila no es capicua
    int flag = 0;
    while(!pilavacia(&pilaOriginal) && flag == 0)
    {
        /// comparamos los topes de las pilas original y copia
        /// si son diferentes, la pila no es capicua
        if (tope(&pilaOriginal) != tope(&pilaCopia))
        {
            flag = 1;
        }
        else
        {
            /// si son iguales, desapilamos la pila original
            /// en un auxiliar para no perder su informacion
            apilar(&aux, desapilar(&pilaOriginal));
            desapilar(&pilaCopia);

            /**
                NOTA: en este ejemplo, no nos interesa si perdemos
                la informacion de pilaCopia, ya que fue creada solo
                para realizar comparaciones y ademas sus datos estan
                en la pila original.
            */
        }
    }

    /// al finalizar el while, si el flag es 1, entonces
    /// la pila no es capicua
    if (flag == 1)
    {
        printf("la pila no es capicua \n");
    }
    else
    {
        /// si el while termino pero el flag sigue siendo 0,
        /// entonces la pila es capicua
        printf("la pila es capicua \n");
    }

    /// volvemos a dejar la pila en su forma original
    while(!pilavacia(&aux))
    {
        apilar(&pilaOriginal, desapilar(&aux));
    }
}

/// -------------------------------------------------

void ejemploRandYsrand()
{
    /// rand() es una funcion que nos devuelve un numero aleatorio

    /// inicializamos un pila
    Pila pila;
    inicpila(&pila);

    /// srand(time(NULL)) es para que los valores de rand() sean
    /// siempre diferentes

    /// si no la utilizamos, veremos que los valores de rand(), aunque
    /// parezcan aleatorios, son en realidad una secuencia de numeros
    /// que se repiten cada vez que ejecutamos el programa

    srand(time(NULL));

    /// llenamos la pila con 10 valores aleatorios
    int i = 0;
    while(i < 10)
    {
        /// rand() nos devuelve un numero aleatorio
        /// usando % 11, le estamos diciendo que nos de un numero aleatorio
        /// entre 0 y uno antes de 11, es decir 10.
        apilar(&pila, rand() % 11);

        i++;
    }

    /// mostramos la pila
    mostrar(&pila);
}

/// -------------------------------------------------

void ejercicio3guia0()
{
    /// calculamos el salario de un trabajador

    int cantidadHorasTrabajadas = 0;
    int horasExtras = 0;
    int salario;

    /// guardamos la cantidad de horas que trabajo
    printf("ingrese cantidad de hs trabajadas \n");
    scanf("%d", &cantidadHorasTrabajadas);

    /// si trabajo mas de 40 hs, entonces hizo hs extras
    if (cantidadHorasTrabajadas > 40)
    {
        /// calculo cuantas hs extra trabajo
        horasExtras = cantidadHorasTrabajadas - 40;

        /// calculamos el salario
        salario = 12000 + (horasExtras * 400);

        /// 12.000 es el resultado de las 40 hs trabajadas
        /// multiplicado por el valor de esas hs
        /// 40 * 300 = 12.000
    }
    else
    {
        /// si no trabajo mas de 40 hs, calculamos el salario
        /// segun sus horas trabajadas
        salario = cantidadHorasTrabajadas * 300;
    }

    /// mostramos su salario
    printf("su salario sera de %d", salario);

    printf("\nud trabajo %d hs extras, con un valor de %d", horasExtras, horasExtras * 400);
    printf("\n y su salario por las 40hs semanales es de %d \n", 40 * 300);
}
