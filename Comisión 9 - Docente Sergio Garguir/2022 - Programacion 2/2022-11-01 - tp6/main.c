#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "celda.h"

typedef struct {
   int nota;
   int legajo;
   char nombreApe[40];
   char materia[40];
   int idMateria;
} registroArchivo;

#define NOMBRE_ARCHIVO "registroArchivo.dat"

int cargaADL(celda adl[], int dim, char nombreArchivo[]);
int alta(celda adl[], int v, stMateria materia, stNotaAlumno nota);
int buscaPosMateria(celda adl[], int v, int id);
int agregarCelda(celda adl[], int v, stMateria materia);
stMateria getMateria(registroArchivo r);
stNotaAlumno getNotaAlumno(registroArchivo r);

int main()
{
    printf("Hello world!\n");
    return 0;
}

int cargaADL(celda adl[], int dim, char nombreArchivo[]){
    registroArchivo r;
    stMateria materia;
    FILE *archi = fopen(nombreArchivo, "rb");
    int validos=0;
    if(archi){
        while(validos<dim && fread(&r, sizeof(registroArchivo), 1, archi)>0){
            materia = getMateria(r);
            validos=alta(adl, validos, materia, getNotaAlumno(r));
        }

        fclose(archi);
    }

    return validos;
}

int alta(celda adl[], int v, stMateria materia, stNotaAlumno nota){
    int pos = buscaPosMateria(adl, v, materia.idMateria);
    if(pos == -1){
        v = agregarCelda(adl, v, materia);
        pos = v - 1;
    }
    adl[pos].listaDeNotas = agregarAlFinalD(adl[pos].listaDeNotas, crearNodoD(nota));
    return v;
}

int buscaPosMateria(celda adl[], int v, int id){
    int i=0;
    int flag=-1;
    while(i<v && flag == -1){
        if(adl[i].dato.idMateria == id){
            flag = i;
        }
        i++;
    }

    return flag;
}

int agregarCelda(celda adl[], int v, stMateria materia){
    adl[v].dato = materia;
    adl[v].listaDeNotas = inicListaD();
    v++;
    return v;
}

stMateria getMateria(registroArchivo r){
    stMateria m;
    m.idMateria = r.idMateria;
    strcpy(m.materia, r.materia);
    return m;
}

stNotaAlumno getNotaAlumno(registroArchivo r){
    stNotaAlumno nota;
    nota.legajo = r.legajo;
    strcpy(nota.nombreApe, r.nombreApe);
    nota.nota = r.nota;

    return nota;
}
/*
nodoDoble* altaLDL(nodoDoble* ldl, stMateria materia, stNotaAlumno nota){
    nodoDoble* nuevo = crearNodoMateria(materia);
    nodoDoble* buscado = buscaNodoMateria(ldl, materia.idMateria);
    if(!buscado){
        ldl = agregarAlFinalMateria(ldl, nuevo);
        buscado = nuevo;
    }
    buscado->listaNotas = agregarAlFinalNotas(buscado->listaNotas, crearNodoNota(nota));

    return ldl;
}


arbol* altaLDL(arbol* adl, stMateria materia, stNotaAlumno nota){
    arbol* buscado = inicArbol();
    buscado = buscaNodoMateria(ldl, materia.idMateria);
    if(!buscado){
        buscado = crearNodoMateria(materia);
        adl = agregarNodoArbol(adl, buscado);
    }
    buscado->listaNotas = agregarAlFinalNotas(buscado->listaNotas, crearNodoNota(nota));

    return adl;
}

*/
