#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena[10]={97,98,99,121};
    int pos = buscaMayor(cadena, 4);

    printf("\n El caracter mayor es: %c y esta en la posicion: %d", cadena[pos], pos+1);


    for(int i=0;i<256;i++){
        if(i%20==0){
            printf("\n");
        }
        printf(" %d - %c | ", i, i);
    }


    return 0;
}

int buscaMayor(char c[], int v){
    int posMax=0;
    for(int i=1;i<v;i++){
        if(c[posMax]<c[i]){
            posMax=i;
        }
    }

    return posMax;
}
