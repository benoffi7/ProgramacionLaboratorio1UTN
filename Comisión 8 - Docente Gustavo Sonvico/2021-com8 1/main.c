#include <stdio.h>
#include <stdlib.h>

#define LIMITE 255

int main()
{
    int i=500;

    printf("\nTabla ASCII con ciclo FOR\n");
    for(i=0;i<LIMITE;i++){
        if(i % 13 == 0){
            printf("\n");
        }
        printf("%d: %c - ", i, i);
    }

    i=0;
    printf("\nTabla ASCII con ciclo WHILE\n");
    while(i<LIMITE){
        if(i % 10 == 0){
            printf("\n");
        }
        printf("%d: %c - ", i, i);
        i++;
    }

    i=0;
    printf("\nTabla ASCII con ciclo DO WHILE\n");
    do{
        if(i % 10 == 0){
            printf("\n");
        }
        printf("%d: %c - ", i, i);
        i++;
    }
    while(i<LIMITE);


    printf("\nHello world! %d", i);
    return 0;
}
