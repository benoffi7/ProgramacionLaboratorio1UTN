#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int cargarArreglo(int A[], int dim)
{
    int i;
    for(i=0; i<dim;i++)
    {
        A[i]=rand()%100;
    }
    return i;
}

void mostraArreglo(int A[], int validos)
{
    printf("\n-- %p ---------\n", A);
    for(int i =0; i<validos;i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n-----------\n");
}

int * redimenArreglo(int * A, int validos)
{
    A = realloc( A, sizeof(int)*(validos+10));
    return A;
}

int redimenArregloOtro(int ** A, int validos)
{
    *A = realloc( *A, sizeof(int)*(validos+10));
    return validos+10;
}

int main()
{
    srand(time(NULL));

    char micadena[]="mimail@dominio.com";

    char comparacion[]="pepe";

    char * resultado = strchr(micadena,'.');

    printf("%s", resultado);

    system("pause");

    printf("Hello world!\n");

    int unArreglo[5];  /// arreglo estatico

    int * otroArreglo= malloc(sizeof(int)*5);  /// arreglo dinamico de 5 int
    int validosA=0;
    int nuevaDim=0;

    /// cargar arreglo
    validosA=cargarArreglo(otroArreglo, 5);
    mostraArreglo(otroArreglo, validosA);


    otroArreglo = redimenArreglo(otroArreglo, 5);    /// arreglo dinamico de 10 int

    validosA=cargarArreglo(otroArreglo, 15);

    mostraArreglo(otroArreglo, validosA);

    nuevaDim= redimenArregloOtro(&otroArreglo, 15);

    validosA=cargarArreglo(otroArreglo, nuevaDim);

    mostraArreglo(otroArreglo, validosA);

    return 0;
}
