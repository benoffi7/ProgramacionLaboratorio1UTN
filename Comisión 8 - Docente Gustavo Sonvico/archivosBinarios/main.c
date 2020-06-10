#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello archivossss!\n");

    printf("Hoy es VIERNES y se da teoria fuerte!!! ");

    char nombreArchivo[]= {"enteros.bin"};

    int valor, bytes, cant;


    FILE * bufferArchi=NULL;

    bufferArchi=fopen(nombreArchivo, "ab");

    if(bufferArchi!=NULL)
    {
        printf("\nIngrese un dato: ");
        scanf("%d", &valor);

        cant=fwrite(&valor, sizeof(int), 1, bufferArchi);

        printf("Se escribio %d elemento en el archivo\n", cant);

        cant=fclose(bufferArchi);

        printf("Cierre del archivo %d\n", cant);
    }
    else
    {
        printf("El archivo no se pudo abrir...");
    }



    bufferArchi=fopen(nombreArchivo, "rb");

    printf("Elementos del archivo: \n");

    if(bufferArchi!=NULL)
    {
        while(fread(&valor, sizeof(int), 1,bufferArchi)>0)
        {

            printf("%d ", valor);
        }

        cant=fclose(bufferArchi);

        printf("Cierre del archivo %d\n", cant);
    }
    else
    {
        printf("El archivo no se pudo CERRAR...");
    }


    return 0;
}
