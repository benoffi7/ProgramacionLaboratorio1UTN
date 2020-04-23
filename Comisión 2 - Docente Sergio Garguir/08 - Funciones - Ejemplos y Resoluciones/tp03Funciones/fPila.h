#ifndef FPILA_H_INCLUDED
#define FPILA_H_INCLUDED

#define ESC 27

void cargaPila(Pila *p, char texto[]);
int randomRango(int min, int max);
void cargaPilaRandom(Pila *p, int limite, int min, int max);
void pasaPila(Pila *origen, Pila *destino);
void pasaPilaOrden(Pila *origen, Pila *destino);
void copiaPila(Pila origen, Pila *destino);
int buscaMenor(Pila origen);
int buscaMenorE(Pila *origen);
void ordenaPorSeleccion(Pila *p);
void insertaElemento(Pila *p, int e);
void ordenaPorInsercion(Pila *p);
void vaciarPila(Pila *p);
float dividir(int a, int b);
int sumaPila(Pila p);
int cuentaPila(Pila p);
float promedioPila(Pila p);
int sumaTopeyAnterior(Pila p);
int pila2decimal(Pila p);
int sumaFibo(Pila p);
void pilaFibonacci(Pila *p, int n);
#endif // FPILA_H_INCLUDED
