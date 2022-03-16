#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i=0;i<255;i++){
        printf("%d - %c\t",i, i);
        if(i%10==0){
            printf("\n");
        }
    }

    return 0;
}
