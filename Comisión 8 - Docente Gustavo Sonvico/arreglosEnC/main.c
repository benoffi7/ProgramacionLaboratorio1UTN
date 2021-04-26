#include <stdio.h>
#include <stdlib.h>

int cargarArregloInt(int [], int);

void mostrarArregloInt(int [], int);

int main()
{
    printf("Hello arreglos!\n");

    int cantMax=20;

    int unArreglo[cantMax];  /// arreglo estatico
    int validosA=0;

  /*
  /// arreglo dinamico, no se mentan con esto todavia

    int * unArreglo = malloc(cantMax * sizeof(int));

    realloc();
    calloc();

    /// ejemplos pedorros

    printf("%p\n", unArreglo);

    unArreglo[0]=12345;
    validosA++;

    printf("%p\n", &unArreglo[0]);
    printf("%d\n", unArreglo[0]);

    unArreglo[1]=6789;
    validosA++;

    printf("%p\n", &unArreglo[1]);
    printf("%d\n", unArreglo[1]);*/

   /*

   int i=0;

    /// estoy cargando el arreglo
    for(i=0; i<cantMax; i++)
    {
        unArreglo[i]=i+1;
    }

    /// estoy mostrando el arreglo
    for(i=0; i<validosA;i++)
    {
        printf("%d - ", unArreglo[i]);
    }*/

    validosA=cargarArregloInt(unArreglo, cantMax);



    mostrarArregloInt(unArreglo, validosA);


    return 0;
}

int cargarArregloInt(int a[], int dim)
{
    int i=0,aux;
    char control='s';

    printf("Cargando el arreglo de int \n");

    while(i<dim && control=='s')
    {
        printf("Ingrese un valor entero: ");

        ///scanf("%d", &aux);
        ///a[i]=aux;

        scanf("%d", &a[i]);

        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &control);

        i++;
    }

    return i;
}

void mostrarArregloInt(int a[], int validos)
{
    int i;

    printf("Mostrando el arreglo de int \n");

    for(i=0; i<validos;i++)
    {
        printf("[%d]", a[i]);
    }
}
