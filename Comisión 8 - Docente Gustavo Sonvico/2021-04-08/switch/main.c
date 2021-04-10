#include <stdio.h>
#include <stdlib.h>



int main()
{
    int nro, aux;
    int cont;

    printf("\n Ingrese un numero entero: ");
    scanf("%d", &nro);
    aux = nro;

    while(aux>0){
        cont++;
        aux=aux/10;
    }
/*
    if(nro>=0 && nro <=9){
        cont=1;
    }else{
        if(nro>=10 && nro <=99){
            cont=2;
        }else{
            if(nro>=100 && nro <= 999){
                cont=3;
            }else{
                if(nro>=1000 && nro <= 9999){
                    cont=4;
                }
            }
        }
    }

*/
    switch(nro){
        case 0 ... 9:
                cont=1;
                break;
        case 10 ... 99:
                cont=2;
                break;
        case 100 ... 999:
                cont=3;
                break;
        case 1000 ... 9999:
                cont=4;
                break;
        default:
                cont=0;
    }



    printf("\n El nro %d tiene %d digitos", nro, cont);
    return 0;
}
