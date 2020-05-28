#include <stdio.h>
#include <stdlib.h>

void funcion1(int * a, int * b)
{
    int * paux;
    paux=a;
    a=b;
    b=paux;
}

int main()
{
    int variable1=20, variable2=10;

    funcion1(&variable1, &variable2);

    printf("Var 1 %d\n", variable1);
    printf("Var 2 %d\n", variable2);

    return 0;
}
