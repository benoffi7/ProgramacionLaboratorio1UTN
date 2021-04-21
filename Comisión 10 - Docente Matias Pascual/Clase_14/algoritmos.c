/// prototipado de funciones

void ejemplo_algoritmos_menorMayor();
int posicionMenorElemento(int arreglo[], int validos);
int posicionMayorElemento(int arreglo[], int validos);
int posicionMenorDesdePosicionInicial(int arreglo[], int validos, int posicionInicial);
int posicionMayorDesdePosicionInicial(int arreglo[], int validos, int posicionInicial);

void ejemplo_algoritmos_ordenamientoPorSeleccion();
void ordenarPorSeleccion(int arreglo[], int validos);

void ejemplo_algoritmos_ordenacionPorInsercion();
int insertarOrdenado(int arreglo[], int validos, int dato);

/// --------------------------------------------------------------------

/// encontrar la posicion del menor elemento del arreglo
int posicionMenorElemento(int arreglo[], int validos)
{
    int menorElemento = arreglo[0];
    int posicionMenor = 0;

    for (int i = 0; i < validos; i++)
    {
        if (arreglo[i] < menorElemento)
        {
            menorElemento = arreglo[i];
            posicionMenor = i;
        }
    }

    return posicionMenor;
}

/// --------------------------------------------------------------------

int posicionMenorDesdePosicionInicial(int arreglo[], int validos, int posicionInicial)
{
    int menorElemento = arreglo[posicionInicial];
    int posicionMenor = posicionInicial;

    for (int i = posicionInicial; i < validos; i++)
    {
        if (arreglo[i] < menorElemento)
        {
            menorElemento = arreglo[i];
            posicionMenor = i;
        }
    }

    return posicionMenor;
}

/// --------------------------------------------------------------------

int posicionMayorElemento(int arreglo[], int validos)
{
    int mayorElemento = arreglo[0];
    int posicionMayor = 0;

    for (int i = 0; i < validos; i++)
    {
        if (arreglo[i] > mayorElemento)
        {
            mayorElemento = arreglo[i];
            posicionMayor = i;
        }
    }

    return posicionMayor;
}

/// --------------------------------------------------------------------

int posicionMayorDesdePosicionInicial(int arreglo[], int validos, int posicionInicial)
{
    int mayorElemento = arreglo[posicionInicial];
    int posicionMayor = posicionInicial;

    for (int i = posicionInicial; i < validos; i++)
    {
        if (arreglo[i] > mayorElemento)
        {
            mayorElemento = arreglo[i];
            posicionMayor = i;
        }
    }

    return posicionMayor;
}

/// --------------------------------------------------------------------

void ejemplo_algoritmos_menorMayor()
{
    int arreglo[10] = {
        10 , 55, 30, 2, 10
        -60, 30, -10, 40, 20
    };

    int validos = 10;

    /// mostrando valor y posicion del menor y mayor elemento del arreglo

    int posicionDelMenor = posicionMenorElemento(arreglo, 10);
    int posicionDelMayor = posicionMayorElemento(arreglo, 10);

    int menorElemento = arreglo[posicionDelMenor];
    int mayorElemento = arreglo[posicionDelMayor];

    printf("menor elemento: %d \n", menorElemento);
    printf("posicion del menor: %d \n\n", posicionDelMenor);

    printf("mayor elemento: %d \n", mayorElemento);
    printf("posicion del mayor: %d \n\n", posicionDelMayor);

    printf("arreglo: \n");
    mostrarArreglo(arreglo, 10);

    /// -----------------------------------------------------

    int posicionInicial = 6;

    posicionDelMenor = posicionMenorDesdePosicionInicial(arreglo, 10, posicionInicial);
    posicionDelMayor = posicionMayorDesdePosicionInicial(arreglo, 10, posicionInicial);

    menorElemento = arreglo[posicionDelMenor];
    mayorElemento = arreglo[posicionDelMayor];

    printf("---------------------------------\n\n");
    printf("usando posicion inicial: %d \n\n", posicionInicial);

    printf("menor elemento: %d \n", menorElemento);
    printf("posicion del menor: %d \n\n", posicionDelMenor);

    printf("mayor elemento: %d \n", mayorElemento);
    printf("posicion del mayor: %d \n\n", posicionDelMayor);

    printf("arreglo: \n");
    mostrarArreglo(arreglo, 10);
}

/// --------------------------------------------------------------------

void ejemplo_algoritmos_ordenamientoPorSeleccion()
{
    int arreglo[10] = {
        10 , 55, 30, 2, 10
        -60, 30, -10, 40, 20
    };

    int validos = 10;

    verArreglo(arreglo, validos);
    ordenarPorSeleccion(arreglo, validos);

    printf("\nordenado: \n");
    verArreglo(arreglo, validos);
}

/// --------------------------------------------------------------------

void ordenarPorSeleccion(int arreglo[], int validos)
{
    int auxiliar; /// esta variable la voy a usar para intercambiar datos

    int posicionMenor = 0;
    int i = 0;

    while(i < validos - 1)
    {
        /// guardo la posicion del menor elemento a partir de la posicion i
        posicionMenor = posicionMenorDesdePosicionInicial(arreglo, validos, i);

        /// intercambio los valores
        auxiliar = arreglo[posicionMenor];
        arreglo[posicionMenor] = arreglo[i];
        arreglo[i] = auxiliar;

        i++;
    }
}

/// --------------------------------------------------------------------

void ejemplo_algoritmos_ordenacionPorInsercion()
{
    int arreglo[10] = { 10, 20, 30, 40, 50, 60 };

    int validos = 6;

    validos = insertarOrdenado(arreglo, validos, 57);

    printf("ordenar por seleccion: \n\n");

    verArreglo(arreglo, validos);

    printf("\nvalidos: %d\n", validos);

    /// -----------------------------------------------------------------

    int arregloDesordenado[10] = { 20, 10, 40, 60, 30, 50 };
    validos = 6;

    ordenarPorInsercion(arregloDesordenado, validos);

    printf("\n------------------------\n\n");
    printf("ordenar por insercion: \n\n");

    verArreglo(arregloDesordenado, validos);
}

/// --------------------------------------------------------------------

void ordenarPorInsercion(int arreglo[], int validos)
{
    int i = 0;
    while(i < validos)
    {
        insertarOrdenado(arreglo, i, arreglo[i]);
        i++;
    }
}

/// --------------------------------------------------------------------

int insertarOrdenado(int arreglo[], int validos, int dato)
{
    int i = validos - 1;

    /// recorro desde el ultimo al primero
    while(i >= 0 &&
          dato < arreglo[i])
    {
        /// muevo cada elemento un lugar a la derecha
        arreglo[i + 1] = arreglo[i];

        i--;
    }

    arreglo[i + 1] = dato;

    validos += 1;

    return validos;
}
