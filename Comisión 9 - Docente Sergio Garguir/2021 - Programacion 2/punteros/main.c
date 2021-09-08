#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *punt,i;
    int x[5]= {1,2,3,4,5};
    punt=&x[0]+3;
    *(punt-2)=9;
    punt--;
    *(punt)=7 ;
    punt[1]=11 ;
    punt=x;
    for(i=0; i<5; i++)
        printf("%d,",punt[i]); // ¿qué imprime?
}
