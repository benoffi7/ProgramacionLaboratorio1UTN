#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void archivo2lista(nodo** lista, char nombreArchivo[]);

int main()
{
    char nombreInicial[25]="r";
    strcat(nombreInicial,".dat");
    nodo* lista = iniciLista();
    archivo2lista(&lista, "personas.dat");
    muestraNodo(buscaMenorEdad(lista));
    printf("\n Listado de Personas %d - %d - %d\n", sumaEdades(lista), sumaEdadesRecursiva(lista), sumaEdadesRecursivaTernario(lista));
    muestraLista(lista);

    lista2archivoV2(lista, nombreInicial, 'r');
    printf("\n Listado de Personas con inicial 'a' %d\n", cuentaNodosRecursivo(lista, 0));
    muestraArchivo(nombreInicial);

    return 0;
}

void archivo2lista(nodo** lista, char nombreArchivo[]){
    FILE* archi = fopen(nombreArchivo, "rb");
    stPersona p;
    if(archi){
        while(fread(&p, sizeof(stPersona), 1, archi)>0){
            agregarEnOrdenPorApellido(lista, crearNodo(p));
        }
        fclose(archi);
    }
}

void lista2archivo(nodo* lista, char nombreArchivo[], char letra){
    FILE* archi = fopen(nombreArchivo, "wb");
    stPersona p;
    if(archi){
        while(lista){
            if(toupper(lista->dato.apellido[0])==toupper(letra)){
                p=lista->dato;
                fwrite(&p, sizeof(stPersona), 1, archi);
            }
            lista=lista->siguiente;
        }
        fclose(archi);
    }
}

void lista2archivoV2(nodo* lista, char letra){
    char nombreArchivo[10];
    sprintf(nombreArchivo, "%c.dat",letra);
    FILE* archi = fopen(nombreArchivo, "wb");
    stPersona p;
    if(archi){
        while(lista){
            if(toupper(lista->dato.apellido[0])==toupper(letra)){
                p=lista->dato;
                fwrite(&p, sizeof(stPersona), 1, archi);
            }
            lista=lista->siguiente;
        }
        fclose(archi);
    }
}

void muestraArchivo(char nombreArchivo[]){
    FILE* archi = fopen(nombreArchivo, "rb");
    stPersona p;
    if(archi){
        while(fread(&p, sizeof(stPersona), 1, archi)>0){
            muestraUnaPersona(p);
        }
        fclose(archi);
    }
}

float promedio(nodo* lista, int edad){
    float pro=0;
    int totPersonas;
    int personasMayores;
    if(lista){
        totPersonas = cuentaNodosRecursivo(lista, 0);
        personasMayores = cuentaNodosRecursivo(lista, edad);
        pro = (float) personasMayores * 100 / totPersonas;
    }

    return pro;
}
