#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 20
#define nomArch "arreglo.bin"

void carga(int arr[20],int* validos)
{
    char seguir='s';
    while (*validos < TAM_MAX && seguir == 's')
    {
        printf("ingrese un num\n");
        scanf("%i",&arr[*validos]);
        printf("desea seguir\n");
        fflush(stdin);
        scanf("%c",&seguir);
        (*validos)++;
    }

}

void persistirArreglo(int arr[],int validos)
{
    FILE* fp = fopen(nomArch,"wb");
    if (fp != NULL)
    {
        for (int i = 0 ; i < validos ; i++)
        {
            fwrite(&arr[i],sizeof(int),1,fp);
        }

        fclose(fp);
    }

}

void lecturaArreglo(int arr2[], int* validos)
{
    FILE* fp = fopen(nomArch,"rb");
    int num;
    int i=0;
    if (fp != NULL)
    {
        while (i < TAM_MAX && fread(&num,sizeof(int),1,fp) > 0) ///leo secuencial
        {
            arr2[i] = num;
            i++;
        }
        fclose(fp);
    }
    *validos = i;
}

void escrituraArr(int arr[],int validos)
{
    FILE* fp = fopen(nomArch,"wb");
    if (fp != NULL)
    {
        fwrite(arr,sizeof(int),validos,fp);
        fclose(fp);
    }

}
///sabiendo la cantidad de datos que hay en el archivo
void lecturaArr(int arr2[],int validos)
{
    FILE* fp = fopen(nomArch,"rb");

    if (fp != NULL)
    {
        fread(arr2,sizeof(int),validos,fp);
        fclose(fp);
    }
}


void muestra(int arr[],int validos)
{
    for (int i = 0 ; i < validos ; i++)
    {
        printf("%i ",arr[i]);

    }
}
//        ///fseek(fp,0,SEEK_SET);
//       ///SEEK_SET, desde el inicio se mueva una OFFSET cantidad de bytes
//        fseek(fp,sizeof(int)*4,SEEK_CUR);
//        fseek(fp,sizeof(int)*(-4),SEEK_CUR);
//       ///SEEK_CUR, desde la posicion actual, me muevo hacia derecha o izquierda
//        fseek(fp,sizeof(int)*(-2),SEEK_END);
//        fseek(fp,0,SEEK_END); ///se para en el final y no se mueve ningun byte
//       ///SEEK_END, desde el final, cuantos bytes me voy a mover HACIA LA IZQUIERDA (siempre es negativo)
int cantidadEnterosEnArchivo()
{
   FILE* fp = fopen(nomArch,"rb");
   int cantidadEnteros;
   if (fp != NULL)
   {
    fseek(fp,0,SEEK_END);
    cantidadEnteros = ftell(fp)/sizeof(int);
    fclose(fp);
   }

   return cantidadEnteros;
}


int main()
{
    int arr[20];
    int validos=0;
    int validos2;
    int arr2[TAM_MAX];
    carga(arr,&validos);
    //persistirArreglo(arr,validos);
    //lecturaArreglo(arr2, &validos2);
    escrituraArr(arr,validos);
    validos2 = cantidadEnterosEnArchivo();
    lecturaArr(arr2,validos2);
    muestra(arr2,validos);

    return 0;
}
