#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello Files!\n");

    char nombreDeMiArchivo[]= {"miArchivoDeInts.dat"};

    char control = 's';

    int valor;

    FILE * pFile;

    /// abrimos en modo escritura (sobreescribe)
    pFile = fopen(nombreDeMiArchivo, "ab");

    if(pFile!=NULL)
    {
        while(control=='s')
        {
            printf("\nIngrese un valor entero: ");
            scanf("%d", &valor);

            fwrite(&valor, sizeof(int), 1, pFile);

            printf("\nDesea continuar? s/n");
            fflush(stdin);
            scanf("%c", &control);
        }
        fclose(pFile);
    }
    else
    {
        printf("No pudimos abrir el archivo, paso algo malo....");
    }

    /// abrimos en modo lectura
    pFile = fopen(nombreDeMiArchivo, "rb");

    if(pFile!=NULL)
    {

        while( fread(&valor, sizeof(int), 1, pFile) >0 )
        {

            printf("%d ", valor);

        }

        fclose(pFile);
    }
    else
    {
        printf("No pudimos abrir el archivo, paso algo malo....");
    }

    return 0;
}
