/**
    Un arreglo es un conjunto de variables del mismo tipo de dato,
    almacenadas bajo el mismo nombre.

    Llamamos vector al arreglo de una sola dimension y matriz al arreglo de mas de una
    dimension.

    Vector:
        una sola fila: [0][1][2][3]


    Matriz:
                   0  1  2  columnas
        filas   0 [a][b][c]
                1 [d][e][f]
                2 [g][h][i]
*/

/// --------------------------------------------------------

/// prototipado de funciones
void mostrarArreglo(int arreglo[], int validos);
void explicandoArreglos();
void explicandoArreglos_2();

/// --------------------------------------------------------

/// definicion de funciones

void explicandoArreglos()
{
    /// DECLARANDO ARREGLOS

    /// esto es un arreglo que guarda 10 numeros de tipo int
    int arreglo[10];

    /// otros ejemplos con float y double
    float numerosReales[20];
    double numerosMasPrecisos[30];

    /// un arreglo de 20 char... esto nos permite guardar texto
    char nombre[20];

    /// otros ejemplos con char
    char apellido[30];
    char frase[150];

    /// --------------------------------------------------------

    /// INICIALIZANDO ARREGLOS

    /// le doy un valor a cada posicion del arreglo
    int muchosNumerosEnteros[10] = {1,2,3,4,5,6,7,8,9,10};

    /// puedo crear un arreglo e inicializarlo sin tener que completar todos sus espacios
    double muchosNumerosPrecisos[10] = {2.5, 2.6, 2.2};

    /// tambien puedo dejar que el programa calcule el tamaño segun la cantidad
    /// de valores iniciales

    int numeros[] = {10,20,30,40};  /// arreglo de 4 elementos
    float muchosNumerosReales[] = {10.4F, 24.3F, 21.2F}; /// arreglo de 3 elementos

    /// un arreglo de char me permite guardar texto
    char unNombre[50] = {"Raphael"};
    char otroNombre[100] = {"Leonardo Da Vinci"};
}

/// --------------------------------------------------------

void explicandoArreglos_2()
{
    /// PASANDO ARREGLOS COMO PARAMETROS

    /// los arreglos se pasan como referencia, es decir, pasamos su direccion de memoria

    /// podemos usar espacios y enters para que sea mas facil de leer la inicializacion
    int arreglo[10] = {
        34, 21, 16, 2, 90,
        14, 23, 21, 52, 6
    };

    /// --------------------------------------------------------

    /// usar & para pasar el arreglo como parametro es redundante
    /// por que el arreglo esta apuntando a la direccion de memoria de su
    /// primer elemento

    /// ejemplos:
    printf("arreglo:     %X \n", arreglo);
    printf("&arreglo:    %X \n", &arreglo);
    printf("&arreglo[0]: %X \n", &arreglo[0]);

    printf("\n\n");

    /// --------------------------------------------------------

    /// podemos pasar el arreglo escribiendo solo su nombre
    mostrarArreglo(arreglo, 10);
    mostrarArregloInvertido(arreglo, 10);
}

/// --------------------------------------------------------

void mostrarArreglo(int arreglo[], int validos)
{
    /// validos seria la cantidad de elementos usados

    for(int i = 0; i < validos; i++)
    {
        printf("i: %d -> valor: %d\n", i, arreglo[i]);
    }

    printf("\n");
}

/// --------------------------------------------------------

void verArreglo(int arreglo[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("[%d] ", arreglo[i]);
    }
    printf("\n");
}

/// --------------------------------------------------------

void mostrarArregloInvertido(int arreglo[], int validos)
{
    for(int i = validos; i > -1; i--)
    {
        printf("i: %d -> valor: %d\n", i, arreglo[i]);
    }

    printf("\n\n");
}
