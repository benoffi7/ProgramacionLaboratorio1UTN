#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*12) Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el
    resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5*/

    int main()
    {
        Pila origen, aux, receptora;
        inicpila(&origen);
        inicpila(&aux);
        inicpila(&receptora);

        leer(&origen);
        leer(&origen);
        leer(&origen);
        leer(&origen);
        leer(&origen);
        leer(&origen);


        printf("Pila origen\n");
        mostrar(&origen);
///algoritmo de buscar un hueco para insertar (insercion)
        while(!pilavacia(&origen))
        {
            ///busco hueco
            while (!pilavacia(&receptora) && tope(&origen)>tope(&receptora))
            {
                apilar(&aux, desapilar(&receptora));
            }
            ///encontre hueco
            apilar(&receptora, desapilar(&origen));
            ///devuelvo valores a su lugar
            while(!pilavacia(&aux))
            {
                apilar(&receptora, desapilar(&aux));
            }
        }
       ///devuelvo valores a pila principal
        while(!pilavacia(&receptora))
        {
            apilar(&origen, desapilar(&receptora));
        }

        printf("Pila origen ahora\n");
        mostrar(&origen);
        return 0;
    }
