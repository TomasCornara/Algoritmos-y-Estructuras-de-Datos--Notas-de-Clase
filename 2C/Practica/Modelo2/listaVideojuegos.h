#ifndef LISTAVIDEOJUEGOS_H_INCLUDED
#define LISTAVIDEOJUEGOS_H_INCLUDED

#include "listaDinamica.h"

#define MAX_REGISTROS 10
#define MAX_TAG 4

typedef struct{
    tLista lista_interna;
    unsigned cant;
    unsigned tope;
}tTop;

typedef struct{
    char tag[MAX_TAG];
    unsigned puntos;
}tRegistro;

void crearTop(tTop* top);
void randomizarReigstro(tRegistro* registro);
int ponerEnTop(tTop* top, tRegistro* nuevo_registro);
void mostrarRegistro(const void* registro);
int comparar_tRegistro(const void* elementoEntrante, const void* elementoPresente);
void mostrarTop(tTop* top);
void randomizarRegistro(tRegistro* registro);

#endif // LISTAVIDEOJUEGOS_H_INCLUDED
