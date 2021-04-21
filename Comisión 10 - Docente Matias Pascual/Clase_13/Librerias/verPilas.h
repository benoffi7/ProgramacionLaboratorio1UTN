#ifndef VERPILAS_H_INCLUDED
#define VERPILAS_H_INCLUDED

#define _AZUL 9
#define _ROJO 4
#define _BLANCO 7
#define _AMARILLO 6

/// aca va la ruta donde tenes los archivos de pilas
#include "pila.h"
#include <stdarg.h>
#include <windows.h>

void verPilas(int cantidadPilas, ...);

/// funciones auxiliares
void _gotoxy(int x, int y);
void _setColor(int color);
void _pilaEnVertical(Pila* pila, int posicion);
void _invertirPila(Pila* pila);
void _pasarPila(Pila *origen, Pila *destino);
int _contarElementosPila(Pila* pila);
int _contarCaracteresPila(Pila* pila);
int _contarCaracteresNumero (int numero);
int _dameMenorPila(Pila* pila);
int _dameMayorPila(Pila* pila);
void _mostrarCursor(int visible);

#endif // VERPILAS_H_INCLUDED
