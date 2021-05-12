#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 20

void carga(char arregloPalabras[][COLS], int* validos)
{
    int i = *validos;
    char seguir = 's';
    while (i < ROWS && seguir == 's')
    {
        printf("Ingrese palabra o frase\n");
        fflush(stdin);
        gets(arregloPalabras[i]);
        printf("ddesea continuar\n");
        fflush(stdin);
        scanf("%c",&seguir);
        i++;
    }

    *validos = i;

}

void muestra(char arregloPalabras[][COLS], int validos)
{
    for (int i = 0 ; i < validos ; i++)
    {
        printf("%s\n",arregloPalabras[i]);
    }

}

int busquedaPalabra(char arregloPalabras[][COLS],int validos, char palabra[])
{
    int i=0;
    while (i < validos && strcmpi(arregloPalabras[i],palabra) != 0)
    {
        i++;
    }

    if (i < validos)
    {
        return i;
    }
    else
        return -1;

}




int main()
{
    char arregloPalabras[ROWS][COLS] = {"Pedro Gomez", "Pablo Lopez", "Luciano gimenez"};
    char arregloPalabras2[ROWS][COLS];
//     0 1 2 3 4 5 6 7 8 9 10 11
//   0 p e d r o  g o m e z \0
//   1 p a b l o  l o p e z \0
//   2 l u c i a n o  g i m e n e z \0
//

   //carga completa
    for (int i = 0 ; i < ROWS ; i++)
    {
        printf("Ingrese una palabra o frase\n");
        fflush(stdin);
       // scanf("%s",arregloPalabras2[i]);
        gets(arregloPalabras2[i]);
    }

   //muestra
    for (int i = 0 ; i < ROWS; i++)
    {
        //printf("%s\n",arregloPalabras2[i]);
        puts(arregloPalabras2[i]);
    }

    ///Con validos
    int i=0;
    int validos;///validos
    char seguir;
    do
    {
        printf("Ingrese palabra o frase\n");
        fflush(stdin);
        gets(arregloPalabras2[i]);
        printf("desea continuar\n");
        fflush(stdin);
        scanf("%c",&seguir);
        i++;
    }while(i<ROWS && seguir == 's');

    validos = i;

    //muestra
    for (int i = 0; i < validos ; i++)
    {
        printf("%s\n",arregloPalabras2[i]);
        //puts(arregloPalabras2[i]);
    }

    return 0;
}
