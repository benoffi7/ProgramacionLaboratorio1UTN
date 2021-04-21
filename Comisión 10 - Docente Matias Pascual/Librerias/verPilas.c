#include "verPilas.h"

void verPilas(int cantidadPilas, ...)
{
    _mostrarCursor(0);
    system("cls");
    _gotoxy(0,16);  // tuve que ponerlo aca porque no lo podia acomodar dentro de la funcion _pilaEnVertical despues del "cls" en la primera posicion

    va_list pilas;
    va_start(pilas, cantidadPilas);

    for(int i = 0; i < cantidadPilas; i++)
    {
        _pilaEnVertical(va_arg(pilas, Pila*), i);
    }

    va_end(pilas);


    /// pongo el puntero en una nueva posicion y acomodo el color al default
    _gotoxy(0, 20);
    _setColor(7);
    _mostrarCursor(1);

    system("pause");
}

void _mostrarCursor(int visible)
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 1;
   info.bVisible = visible;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void _pilaEnVertical(Pila* pila, int posicion)
{
    int margenIzquierdo = 16 * posicion;
    int margenInferior = 16;
    int cantidadElementos = 0;
    int cantidadCaracteres = 0;

    if(!pilavacia(pila))
    {
        cantidadElementos = _contarElementosPila(pila);
        cantidadCaracteres = _contarCaracteresPila(pila);

        /// para recorrer la pila
        Pila aux;
        inicpila(&aux);

        /// escribo: base
        _setColor(_AZUL);
        _gotoxy(margenIzquierdo + cantidadCaracteres / 2 - 1, margenInferior);
        printf("[base]");

        /// doy vuelta la pila para mostrarla en orden
        _invertirPila(pila);

        /// recorro la pila mostrando sus valores
        int i = 1;  // base es posicion la primer posicion para mostrar
        while(!pilavacia(pila))
        {
            _setColor(_BLANCO);

            /// escribo el | derecho
            _gotoxy(margenIzquierdo, margenInferior - i);
            printf("|");

            /// muestro el numero en la pila
            _gotoxy(margenIzquierdo + 2, margenInferior - i);
            printf("%d", tope(pila));

            /// escribo el | izquierdo
            _gotoxy(margenIzquierdo + 3 + cantidadCaracteres, margenInferior - i);
            printf("|");

            /// recorro la pila
            apilar(&aux, desapilar(pila));

            i++;    // para mostrar el prox elemento arriba de la posicion anterior
        }

        /// escribo: tope
        _setColor(_ROJO);
        _gotoxy(margenIzquierdo + cantidadCaracteres / 2 - 1, margenInferior - cantidadElementos - 1);
        printf("[tope]");

        /// dejo la pila en su estado original
        _pasarPila(&aux, pila);
        _invertirPila(pila);
    }
    else
    {
        /// cuando la pila este vacia muestro...
        _setColor(_AMARILLO);
        _gotoxy(margenIzquierdo + cantidadCaracteres / 2 - 1, margenInferior);
        printf("[pila vacia]");

    }
}

void _gotoxy(int x, int y)
{
    COORD posicion;
    posicion.X = x;
    posicion.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posicion);
}

void _setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void _invertirPila(Pila* pila)
{
    Pila aux1;
    Pila aux2;

    inicpila(&aux1);
    inicpila(&aux2);

    _pasarPila(pila, &aux1);
    _pasarPila(&aux1, &aux2);
    _pasarPila(&aux2, pila);
}

void _pasarPila (Pila *origen, Pila *destino)
{
    while (!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}

int _contarElementosPila(Pila* pila)
{
    int cantidad = 0;

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pila))
    {
        apilar(&aux, desapilar(pila));
        cantidad++;
    }

    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return cantidad;
}

int _contarCaracteresPila(Pila* pila)
{
    int cantidadCaracteres = 1;

    int numeroMenor = _dameMenorPila(pila);
    int numeroMayor = _dameMayorPila(pila);

    int cantidadCaracteresMenor = _contarCaracteresNumero(numeroMenor);
    int cantidadCaracteresMayor = _contarCaracteresNumero(numeroMayor);

    cantidadCaracteres =
        (cantidadCaracteresMayor > cantidadCaracteresMenor) ?
        cantidadCaracteresMayor : cantidadCaracteresMenor;

    return cantidadCaracteres;
}

int _dameMenorPila(Pila* pila)
{
    Pila aux;
    inicpila(&aux);

    int menor = tope(pila);
    apilar(&aux, desapilar(pila));

    while(!pilavacia(pila))
    {
        if (tope(pila) < menor)
        {
            menor = tope(pila);
        }

        apilar(&aux, desapilar(pila));
    }

    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return menor;
}

int _dameMayorPila(Pila* pila)
{
    Pila aux;
    inicpila(&aux);

    int mayor = tope(pila);
    apilar(&aux, desapilar(pila));

    while(!pilavacia(pila))
    {
        if (tope(pila) > mayor)
        {
            mayor = tope(pila);
        }

        apilar(&aux, desapilar(pila));
    }

    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }

    return mayor;
}


int _contarCaracteresNumero (int numero)
{
    int caracteres = 1;

    /// sumo 1 a caracteres, porque tengo en cuento el signo - (menos)
    /// y paso el numero a positivo
    if (numero < 0)
    {
        caracteres++;
        numero *= -1;
    }

    while(numero / 10 > 0)
    {
        numero /= 10;
        caracteres++;
    }

    return caracteres;
}
