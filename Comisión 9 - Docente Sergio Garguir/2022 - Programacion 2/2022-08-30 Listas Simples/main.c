#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

nodo* archivo2lista(char archivo[], nodo* lista, int edad);
nodo* archivo2listaPorNombre(char archivo[], nodo* lista, char nombre[]);

int main()
{
    Pila p;
    inicPila(&p);
    nodo* lista;
    lista=iniciLista();
    cargaArchivo("personas.dat");

    //lista = archivo2lista("personas.dat", lista, 0);
    lista = archivo2listaPorNombre("personas.dat", lista, "Pepe");
    agregarAlPpioPunteroDoble(&lista, crearNodo(cargaUnaPersona()));
    printf("\nLista de Personas Original!\n");
    muestraLista(lista);
    lista = invertirLista(lista);

    /*
    for(int i=0;i<50;i++){
       // lista=agregarAlPrincipioPro(lista, crearNodo(cargaUnaPersona()));
        lista=agregarEnOrdenPorEdad(lista, crearNodo(cargaUnaPersona()));
    }

    lista = agregarAlFinal(lista, crearNodo(cargaUnaPersona()));
*/
    printf("\nLista de Personas Invertida!\n");
    muestraLista(lista);

    return 0;
}

void cargaArchivo(char archivo[]){
    FILE* archi = fopen(archivo, "wb");
    stPersona p;
    if(archi){
        for(int i=0;i<10;i++){
            p = cargaUnaPersona();
            fwrite(&p, sizeof(stPersona), 1, archi);
        }
        fclose(archi);
    }
}

nodo* archivo2lista(char archivo[], nodo* lista, int edad){
    FILE* archi = fopen(archivo, "rb");
    stPersona p;
    if(archi){
        while(fread(&p, sizeof(stPersona), 1, archi)>0){
            if(p.edad>=edad){
                lista=agregarEnOrdenPorEdad(lista, crearNodo(p));
            }
        }

        fclose(archi);
    }
    return lista;
}

nodo* archivo2listaPorNombre(char archivo[], nodo* lista, char nombre[]){
    FILE* archi = fopen(archivo, "rb");
    stPersona p;
    if(archi){
        while(fread(&p, sizeof(stPersona), 1, archi)>0){
            if(strcmp(p.nombre,nombre)==0){
                lista=agregarEnOrdenPorEdad(lista, crearNodo(p));
            }
        }

        fclose(archi);
    }
    return lista;
}

void lista2archivo(nodo* lista, char archivo[]){
    FILE* archi = fopen(archivo, "ab");
    stPersona p;
    if(archi){
        while(lista){
            p = lista->dato;
            fwrite(&p, sizeof(stPersona), 1, archi);
            lista=lista->siguiente;
        }

        fclose(archi);
    }
}

/**

            tenga datos       como me muevo                 datoActual
pila        !pilavacia()        desapilar()                 tope()
arreglo     i<v                 i++                           arreglo[i]
archivo     fread()>0           fread()                        lo leido
lista       lista!=NULL         lista=lista->siguiente          lista

*/
