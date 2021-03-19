#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    int numero;
    printf("Por favor ingrese un numero\n");
    scanf("%i", &numero);
    printf("Por favor ingrese una letra\n");
    fflush(stdin);
    scanf("%c", &letra);
    if (letra == 'A')
    {
        printf("La letra es una A\n");
    }
    else
    {
        printf("La letra es distinta de A\n");
    }
    return 0;
}


//SI LETRA = 'A' ENTONCES
//   ESCRIBIR "LA LETRA ES UNA A"
//FIN-SI
//SINO
//   ESCRIBIR "ES UNA LETRA DISTINTA DE A"
//FIN-SINO

