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
int sumaTopeYSiguiente(Pila p);
int sumaPilaLimite(Pila p, int limite);
int sumaPila(Pila p);
int cuentaPila(Pila p);
int randomRango(int min, int max);
float divide(int n1, int n2);
float promedioPila(Pila p);
float promedioPila2(Pila p);
int pila2decimal(Pila p);

#endif // FPILA_H_INCLUDED
