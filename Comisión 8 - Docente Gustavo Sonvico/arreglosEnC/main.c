#include <stdio.h>
#include <stdlib.h>

int cargarArregloInt(int [], int);

void mostrarArregloInt(int [], int);

int existeDato(int [], int, int );

int posicionDelDato(int [], int, int );

int buscaPosMayor(int [], int, int);

int main()
{
    printf("Hello arreglos!\n");

    int cantMax=20, aux, posiMayor;

    int unArreglo[20]={45,23,45,67,12,67}; /// arreglo estatico

    int validosA=6;

    int * unArrayDinamico = malloc(20*sizeof(int));

    int otroValido=cargarArregloInt(unArrayDinamico, 20);

    mostrarArregloInt(unArrayDinamico, otroValido);
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

//   validosA=cargarArregloInt(unArreglo, cantMax);

    mostrarArregloInt(unArreglo, validosA);


    /* system("pause");

     /// existeDato(unArreglo, validosA, 8)==1

     if(existeDato(unArreglo, validosA, 8))
         printf("el valor se encuentra en el arreglo\n");
     else
         printf("el valor NO se encuentra en el arreglo\n");

     system("pause");

     int posi=posicionDelDato(unArreglo, validosA, 8);

     if(posi!=-1)
     {
         printf("el valor se encuentra en el arreglo en la posicion %d\n", posi);
         printf("%d", unArreglo[posi]);
     }
     else
     {
         printf("el valor NO se encuentra en el arreglo\n");
     }*/
/// primera pasada
    system("pause");

    posiMayor=buscaPosMayor(unArreglo, validosA, 0);

    printf("\nel valor mayor se encuentra en el arreglo en la posicion %d\n", posiMayor);
    printf("\n%d", unArreglo[posiMayor]);

    aux = unArreglo[posiMayor];
    unArreglo[posiMayor]=unArreglo[0];
    unArreglo[0]=aux;

    system("pause");
    mostrarArregloInt(unArreglo, validosA);

/// segunda pasada
    system("pause");

    posiMayor=buscaPosMayor(unArreglo, validosA, 1);

    printf("\nel valor mayor se encuentra en el arreglo en la posicion %d\n", posiMayor);
    printf("\n%d", unArreglo[posiMayor]);

    aux = unArreglo[posiMayor];
    unArreglo[posiMayor]=unArreglo[1];
    unArreglo[1]=aux;

    system("pause");
    mostrarArregloInt(unArreglo, validosA);
    return 0;
}

/// retorá 1 si el dato existe o 0 si no existe
int existeDato(int a[], int validos, int dato)
{
    int flag=0;  /// false
    int i=0;

    while(i<validos && !flag) /// flag ==0
    {
        if(a[i]==dato)
        {
            flag=1; /// true
        }
        else
        {
            i++;
        }
    }
    return flag;
}

/// retorá las posicion del dato o -1 si no lo encuentra
int posicionDelDato(int a[], int validos, int dato)
{
    int pos=-1;
    int i=0;

    while(i<validos && pos==-1)
    {
        if(a[i]==dato)
        {
            pos=i;
        }
        else
        {
            i++;
        }
    }

    return pos;
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

    for(i=0; i<validos; i++)
    {
        printf("[%d]", a[i]);
    }
}

/// invocar a esta fn si el arreglo tiene un elemento o mas

/// esto es el nucleo de la ordenacion por seleccion
int buscaPosMayor(int arreglo[], int validos, int posLimite)
{
    int i=posLimite; /// posicion inicial de trabajo

    /// inicializa los datos del mayor con el primer elemento del arreglo
    int mayorElemento=arreglo[i];
    int posDelMayor=i;
    ///

    for(i=posLimite+1; i<validos; i++)
    {
        if(arreglo[i]>mayorElemento)
        {
            mayorElemento=arreglo[i];
            posDelMayor=i;
        }
    }
    return posDelMayor;
}

int insertaEnOrden(int arreglo[], int validos, int aInsertar) {
	int u =validos-1;

	while(u>=0 && aInsertar< arreglo[u]){
		arreglo[u+1]=arreglo[u];
		u--;
	}

	arreglo[u+1]=aInsertar;

	return validos+1;
}

/// si queres ver ordenacion por burbujeo, pagina 358 del libro prog en c
/// buscar tb algoritmo burbuja mejorado

///    1. Ord x Selección.
int posicionMenor (int A[], int pos, int c)
{
    int menor = A[pos];
    int posmenor = pos;
    int i = pos +1;
    while (i<c)
    {
        if (menor > A[i])
        {
            menor = A[i];
            posmenor = i;
        }
        i++;
    }
    return posmenor;
}

void ordenacionSeleccion (int A[], int c)
{
    int posmenor;
    int aux;
    int i = 0;
    while (i<c-1)
    {
        posmenor = posicionMenor(A,i,c);

        aux = A[posmenor];
        A[posmenor]=A[i];
        A[i]= aux;
        i++;
    }
}

