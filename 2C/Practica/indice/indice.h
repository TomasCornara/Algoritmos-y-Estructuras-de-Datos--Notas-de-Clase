#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#include "arbol.h"

typedef struct {
    void* clave;
    unsigned cantBytes;
    unsigned pos;
} tClavePos;

typedef tArbol tIndice;

void crearIndice(tIndice* indice);
void vaciarIndice(tIndice* indice);
int indexar(tIndice* indice, void* dato, unsigned cantBytes, unsigned pos, cmp_fun cmp);
int buscarIndice(const tIndice* indice, void* clave,cmp_fun cmp);

#endif // INDICE_H_INCLUDED
