#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;

    printf("\nTabla ASCII con ciclo FOR");
    for(i=0; i<255; i++){
        if(i % 5 == 0){
            printf("\n");
        }
        printf("%d: %c - ", i, i);
    }

    i=0;
    printf("\nTabla ASCII con ciclo WHILE");
    while(i<255){
        if(i % 5 == 0){
            printf("\n%d: %c - ", i, i);
        }else{
            printf("%d: %c - ", i, i);
        }
        i++;
    }

    i=0;
    printf("\nTabla ASCII con ciclo DO WHILE");
    do{
        if(i % 5 == 0){
            printf("\n");
        }
        printf("%d: %c - ", i, i);
        i++;
    }
    while(i<255);


    return 0;
}
