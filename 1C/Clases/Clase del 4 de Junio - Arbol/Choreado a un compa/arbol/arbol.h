#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodo{
    void *dato;
    unsigned tam;
    struct sNodo* izq;
    struct sNodo* der;
}tNodo;

typedef tNodo* tArbol;
typedef int (*tCMP)(const void *dato1, const void *dato2);

void crearArbol(tArbol *p);
int insertarArbolIte(tArbol *p, const void *dato, unsigned tam, tCMP cmp);
int insertarArbolRec(tArbol *p, const void *dato, unsigned tam, tCMP cmp);

int compararInt(const void* dato1, const void *dato2);

#endif // ARBOL_H_INCLUDED
