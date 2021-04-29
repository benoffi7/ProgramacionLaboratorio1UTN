int main()
{
    Pila pilaA, pilaB;
    inicpila(&pilaA);
    inicpila(&pilaB);

    apilar(&pilaA, 20);

    pasarPila(pilaA, &pilaB);

    int arreglo[10];
    mostrarArreglo(arreglo);

    printf("%d", arreglo[2]);
}

void mostrarArreglo(int arreglo[])
{
    arreglo[2] = 30;
}

void pasarPila(Pila pilaOrigen, Pila* pilaDestino)
{
    /// Pila* pilaDestino = A1FD34;
    apilar(pilaDestino, desapilar(&pilaOrigen));
}
