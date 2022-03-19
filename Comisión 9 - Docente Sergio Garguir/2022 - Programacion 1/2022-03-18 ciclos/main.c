#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int i=0;
    int total;
    char opcion;

    do{
        system("cls");
        printf("\n Ingrese un numero: ");
        scanf("%d", &num);

        printf("\n Tabla de multiplicar del numero %d con ciclo for()", num);
        for(i=0; i<11; i++){
            total = num * i;
            printf("\n\t %d x %d = %d", num, i, total);
        }

        i=0;

        printf("\n Tabla de multiplicar del numero %d con ciclo while()", num);
        while(i<11){
            total = num * i;
            printf("\n\t %d x %d = %d", num, i, total);
            i = i + 1; /// i+=1;  i++;
        }

        i=0;

        printf("\n Tabla de multiplicar del numero %d con ciclo do while()", num);
        do{
            total = num * i;
            printf("\n\t %d x %d = %d", num, i, total);
            i = i + 1; /// i+=1;  i++;
        }while(i<11);

        fflush(stdin);
        printf("\n\n\n Desea continuar? s/n: ");
        scanf("%c", &opcion);
    }while(opcion=='s');

    printf("Hello world!\n");
    return 0;
}
