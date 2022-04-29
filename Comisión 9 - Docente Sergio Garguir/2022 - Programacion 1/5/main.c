#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

void arreglo2pila(int a[], int v, Pila *p){
    for(int i=0;i<v;i++){
        if(a[i]>0 && a[i]%2==0){
            apilar(p, a[i]);
        }
    }
}

int buscaEnArreglo(int a[], int v, int dato){
    int flag=-1;
    int i=0;
    while(i<v && flag==-1){
        if(a[i] == dato){
            flag=i;
        }else{
            i++;
        }
    }

    return flag;
}

int cargaArregloUser(int a[], int v, int dim, int validacion){
    char opcion = 0;

    while(v<dim && opcion != 27){
        do{
            system("cls");
            printf("\n Ingrese una nota: ");
            scanf("%d", &a[v]);
            if(a[v]<1){
                printf("\n dato no valido, ingrese nuevamente");
            }
        }while(a[v]<validacion);

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion = getch();
        v++;
    }

    return v;
}
