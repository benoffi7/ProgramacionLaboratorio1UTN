#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct _nodoLista{
    int dato;
    struct _nodoLista* sig;
}nodoLista;

nodoLista* inicLista();
nodoLista* crearNodoLista(int dato);
nodoLista* agregarAlPrincipio(nodoLista* lista, nodoLista* nuevo);
void muestraLista(nodoLista* lista);
void muestraNodo(nodoLista* nodo);

#endif // LISTA_H_INCLUDED
