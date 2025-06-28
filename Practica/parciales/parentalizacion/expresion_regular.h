#ifndef EXPRESION_REGULAR_H_INCLUDED
#define EXPRESION_REGULAR_H_INCLUDED

#include "pila.h"

int esCerrado(const char simbolo);
int esAbierto(const char simbolo);
int coinciden(const char abierto, const char cerrado);

#endif // EXPRESION_REGULAR_H_INCLUDED
