#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i; /// declaro una variable de tipo entero que voy a usar de contador


    for(i=0;i<10;i++){
        printf("\n%d",i);
    }

    printf("\n%d",i);

    for(int j=0;j<10;j++){
        printf("\n%d",j);
    }
    //printf("\n%d",j);

    return 0;
}
