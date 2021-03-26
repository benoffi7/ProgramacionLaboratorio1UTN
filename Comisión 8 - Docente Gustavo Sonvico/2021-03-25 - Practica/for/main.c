#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    int nro;
    char op;

    printf("\Ingrese un nro: ");
    scanf("%d", &nro);

    for(i=0; i<11;i++){
        printf("\n %d x %d = %d", nro, i, nro*i);
    }

    system("pause");
    return 0;
}
