int main()
{
    ///un puntero es un tipo de variable que almacena una direccion de memoria
    int* puntero;
    char* punteritoavariabledetipochar;
    float* punteritoavariabledetipofloat;
    int numerito; //0xf45
    int otronumero;
    numerito = 5;

    puntero = &numerito; ///puntero esta apuntando a numerito, es decir, esta almacenando la dir de memoria de esa variable
    /// puntero = 0xf45

    *puntero = 8;/// al contenido de la direccion de memoria que almacena puntero le asigno un 8

    /// *puntero = 8

    printf("%i\n", *puntero);///imprimo el contenido de la direccion de memoria que almacena puntero
    printf("numerito: %i\n", numerito);
    printf("%p\n" ,puntero); ///imprimiendo el valor del puntero

    ///puntero = &otronumero; ///puntero esta apuntando a otronumero

    *puntero = *puntero + 25;

    return 0;
}