#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila origen, auxOrigen;
    inicpila(&origen);
    inicpila(&auxOrigen);
    int contUno=0;
    int contDos=0;
    int contTres=0;
    int contCuatro=0;
    int contCinco=0;

    for(int i=0; i<50; i++){
        apilar(&origen, rand()%10);
    }

    printf("\n Pila Origen");
    mostrar(&origen);
/**
    while(!pilavacia(&origen)){
        if(tope(&origen)==1){
            contUno++;
        }else{
            if(tope(&origen)==2){
                contDos++;
            }else{
                if(tope(&origen)==3){
                    contTres++;
                }else{
                    if(tope(&origen)==4){
                        contCuatro++;
                    }else{
                        if(tope(&origen)==5){
                            contCinco++;
                        }
                    }
                }
            }
        }
        apilar(&auxOrigen, desapilar(&origen));
    }*/

    while(!pilavacia(&origen)){

        switch(tope(&origen)){
            case 1:
                    contUno++;
                    break;
            case 2:
                    contDos++;
                    break;
            case 3:
                    contTres++;
                    break;
            case 4:
                    contCuatro++;
                    break;
            case 5:
                    contCinco++;
                    break;
            case 11..20:
                    cont20++;
                    break;
            case 21..30;
                    break;
            default:
                    contOtros++;
        }
        apilar(&auxOrigen, desapilar(&origen));
    }

    while(!pilavacia(&auxOrigen)){
        apilar(&origen, desapilar(&auxOrigen));
    }

    printf("\n Pila Origen");
    mostrar(&origen);

    printf("\n En la pila Origen hay : ");
    printf("\n %d numeros 1", contUno);
    printf("\n %d numeros 2", contDos);
    printf("\n %d numeros 3", contTres);
    printf("\n %d numeros 4", contCuatro);
    printf("\n %d numeros 5", contCinco);

    return 0;
}
