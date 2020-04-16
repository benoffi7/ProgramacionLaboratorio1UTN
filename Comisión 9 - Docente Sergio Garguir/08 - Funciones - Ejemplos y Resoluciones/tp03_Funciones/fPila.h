#ifndef FPILA_H_INCLUDED
#define FPILA_H_INCLUDED

#define ESC 27

void cargaPila(Pila *p, char texto[]);
void pasaPila(Pila *origen, Pila *destino);
void copiaPila(Pila origen, Pila *destino);
void cargaPilaRandom(Pila *p, int cantidad, int minimo, int maximo);
int buscaMenor(Pila p);
int buscaMenorEliminandolo(Pila *p);
void ordenaPorSeleccion(Pila origen, Pila *ordenada);
void ordenaPorInsercion(Pila origen, Pila *ordenada);
void ordenaPorInsercion2(Pila *origen);


int randomRango(int min, int max);

#endif // FPILA_H_INCLUDED
