#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include "estatica/pila.h"

#define EXITO 0

void cargarPila(tPila *pila, FILE* origen);
void sumarPilas(tPila *pila1, tPila *pila2, tPila *pila3);
void mostrarUnidad(int *unidad);

size_t mStrlen(const char *cadena);

#endif // MAIN_H_INCLUDED
