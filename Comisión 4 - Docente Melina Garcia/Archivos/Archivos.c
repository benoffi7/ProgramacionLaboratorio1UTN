#include <stdio.h>
#include <stdlib.h>
#define NOMARCH "numerito.bin"
#define CANT_MAX 10
#define ARRARCH "miarray.bin"

///archivos binarios
void lectura()
{
    int numerito;
    FILE* fp;
    fp = fopen(NOMARCH,"rb");
    if (fp != NULL)
    {
        fread(&numerito,sizeof(int),1,fp);
        printf("%i\t",numerito);
        fclose(fp);
    }
}

void lectura_arreglo(int arr2[], int validos)
{
    FILE* fp = fopen(ARRARCH,"rb");
    if (fp != NULL)
    {
        fread(arr2,sizeof(int),validos,fp);
        fclose(fp);

        for (int i = 0 ; i < validos ; i++)
        {
            printf("%i ",arr2[i]);
        }
    }

}

//void lectura_arreglo_celdaxcelda(int arr2[])
//{
//    FILE* fp = fopen(ARRARCH,"rb");
//    int num;
//    int validos=0;
//    if (fp != NULL)
//    {
//        while (fread(&num,sizeof(int),1,fp) > 0)
//        {
//            printf("%i ",num);
//            arr2[validos] = num;
//            validos++;
//        }
//        fclose(fp);
//        for (int i = 0 ; i < validos ; i++)
//        {
//            printf("%i ",arr2[i]);
//        }
//
//    }
//}


void escritura_arreglo(int arr[], int validos)
{
    FILE* fp = fopen(ARRARCH,"wb"); //si no existe lo crea
    if (fp != NULL)
    {
        fwrite(arr,sizeof(int),validos,fp);
        fclose(fp);
    }


}


void carga_arreglo(int arr[], int* validos)
{
    char seguir='s';
    while (*validos < CANT_MAX && seguir == 's')
    {
        printf("ingrese valor\n");
        scanf("%i",&arr[*validos]);
        printf("continuar\n");
        fflush(stdin);
        scanf("%c",&seguir);
        (*validos)++;
    }

}


int main()
{
    int arr[CANT_MAX];
    int arr2[CANT_MAX];
    int validos=0;
//   FILE* fp = fopen(NOMARCH, "wb"); ///si no existe lo crea, si existe lo reescribe
//   int dato;
//   dato = 5;
//    if (fp != NULL)
//    {
//        fwrite(&dato,sizeof(int),1,fp);
//        fclose(fp);///si no lo cierro corro riesgo de perder los datos que escribi en el budffer
//    }
//    lectura();
    carga_arreglo(arr,&validos);
    escritura_arreglo(arr,validos);
   // lectura_arreglo_celdaxcelda(arr2);

    return 0;
}
