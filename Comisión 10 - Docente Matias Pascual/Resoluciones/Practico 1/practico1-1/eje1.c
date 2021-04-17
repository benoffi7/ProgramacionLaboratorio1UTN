/*1.Cargar desde el teclado una pila DADA con 5 elementos.
Pasar los tres primeros elementos a la pila CJTO1 y los dos restantes a la pila CJTO2,
ambas pilas inicializadas en vacío.
*/

#include "..\Librerias\pila.h"

main()
{
    Pila dada;
    Pila cjto1;
    Pila cjto2;
    inicpila(&dada);
    inicpila(&cjto1);
    inicpila(&cjto2);
    apilar(&dada, 20);
    apilar(&dada, 30);
    apilar(&dada, 17);
    apilar(&dada, 2);
    apilar(&dada, 67);
    apilar(&dada, 45);
    apilar(&dada, 32);

    apilar(&cjto1, desapilar(&dada));
    apilar(&cjto1, desapilar(&dada));
    apilar(&cjto1, desapilar(&dada));
    apilar(&cjto2, desapilar(&dada));
    apilar(&cjto2, desapilar(&dada));

    mostrar(&cjto1);
    mostrar(&cjto2);
}
