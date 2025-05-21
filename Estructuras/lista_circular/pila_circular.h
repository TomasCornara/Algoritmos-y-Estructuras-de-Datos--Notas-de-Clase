#ifndef LISTA_CIRCULAR_H_INCLUDED
#define LISTA_CIRCULAR_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#define VERDADERO 1

#define FALLO_MEMORIA -1

#define PILA_VACIA -2

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *siguiente;
} tNodo;

typedef tNodo *tPila;

void crearPila(tPila *pila);
unsigned char pilaVacia(const tPila *pila);
unsigned char pilaLLena(const tPila *pila, unsigned tamDato);
int apilar(tPila *pila, const void *dato, unsigned tamDato);
int desapilar(tPila *pila, void *dato, unsigned tamDato);
int verTope(const tPila *pila, void *dato, unsigned tamDato);
void vaciarPila(tPila *pila);

#endif // LISTA_CIRCULAR_H_INCLUDED
