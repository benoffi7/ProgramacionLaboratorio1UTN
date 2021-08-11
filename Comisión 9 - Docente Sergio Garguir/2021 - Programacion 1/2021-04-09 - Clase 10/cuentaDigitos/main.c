#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nro;
    int aux;
    int cont=0;

    printf("\n Ingrese un nro: ");
    scanf("%d", &nro);
    aux = nro;

    /// Por si el numero ingresado es negativo
    if(aux<0){
        aux = aux * (-1);
    }

    while(aux>0){
        cont++;
        aux = aux / 10;
        ///printf("\n cont %d - aux %d", cont, aux);
    }



    /*
    if(nro>=0 && nro <=9){
        cont = 1;
    }else{
        if(nro>=10 && nro<=99){
            cont = 2;
        }
    }
    */
    /*
    switch(nro){
        case 0 ... 9:
            cont = 1;
            break;
        case 10 ... 99:
            cont = 2;
            break;
        case 100 ... 999:
            cont = 3;
            break;
        case 1000 ... 9999:
            cont = 4;
    }
*/
    printf("\n El numero %d tiene %d digitos", nro, cont);

    return 0;
}
