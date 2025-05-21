#ifndef COLA_CIRCULAR_H_INCLUDED
#define COLA_CIRCULAR_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#define VERDADERO 1

#define FALLO_MEMORIA -1

#define COLA_VACIA -2

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *siguiente;
} tNodo;

typedef tNodo *tCola;

void crearCola(tCola *cola);
unsigned char colaVacia(const tCola *cola);
unsigned char colaLlena(const tCola *cola, unsigned tamDato);
int acolar(tCola *cola, const void *dato, unsigned tamDato);
int desacolar(tCola *cola, void *dato, unsigned tamDato);
int verTopeCola(const tCola *cola, void *dato, unsigned tamDato);
void vaciarCola(tCola *cola);

#endif // COLA_CIRCULAR_H_INCLUDED
