#include "pila.h"
#include "fPila.h"

void cargaPila(Pila *p, char texto[]){
    char opcion;
    int e;

    do{
        printf("\n %s: ",texto);
        scanf("%d",&e);
        apilar(p,e);

        printf("\n\n ESC para salir ");
        opcion=getch();
        system("cls");
    }while(opcion!=ESC);
}

void cargaPilaRandom(Pila *p, int limite){
    for(int i=0;i<limite;i++){
        apilar(p, rand()%100);
    }
}

/// Pasa pila
void pasaPila(Pila *origen, Pila *destino){
    while(!pilavacia(origen)){
        apilar(destino, desapilar(origen));
    }
}

/// Pasa pila en orden
void pasaPilaOrden(Pila *origen, Pila *destino){
    Pila aux;
    inicpila(&aux);

    pasaPila(origen, &aux);
    pasaPila(&aux, destino);
}

/// copia una pila
void copiaPila(Pila origen, Pila *destino){
    Pila aux;
    inicpila(&aux);
    pasaPila(&origen, &aux);                /// paso la pila usando la funcion

    /*while(!pilavacia(&origen)){           /// paso la pila usando un while
        apilar(&aux, desapilar(&origen));
    }*/

    pasaPila(&aux, destino);
    /*while(!pilavacia(&aux)){
        apilar(destino, desapilar(&aux));
    }*/
}

/// Busca y retorna sin elimar el menor elemento de una pila
int buscaMenor(Pila origen){
    Pila aux;
    inicpila(&aux);
    int menor;

    if(!pilavacia(&origen)){
        menor=desapilar(&origen);
        while(!pilavacia(&origen)){
            if(tope(&origen)<menor){
                menor=desapilar(&origen);
            }
            else{
                apilar(&aux, desapilar(&origen));
            }
        }
    }

    return menor;
}

/// Busca y retorna eliminando el menor elemento de una pila
int buscaMenorE(Pila *origen){
    Pila aux;
    inicpila(&aux);
    int menor;

    if(!pilavacia(origen)){
        menor=desapilar(origen);
        while(!pilavacia(origen)){
            if(tope(origen)<menor){
                apilar(&aux, menor);
                menor=desapilar(origen);
            }
            else{
                apilar(&aux, desapilar(origen));
            }
        }
        pasaPila(&aux, origen);
    }

    return menor;
}

