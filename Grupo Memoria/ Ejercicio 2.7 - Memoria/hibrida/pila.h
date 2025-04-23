#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdlib.h>

#define TAM_PILA 20

typedef struct
{
    void *dato;
    unsigned tamDato;
} tInformacion;

typedef struct
{
    tInformacion *pila[TAM_PILA];
    unsigned tope;
} tPila;

void crearPila(tPila *pila);
int apilar(tPila *pila, const void *dato, unsigned tamDato);
int desapilar(tPila *pila, void *dato, unsigned tamDato);
int pilaLlena(const tPila *pila);
int pilaVacia(const tPila *pila);
void vaciarPila(tPila *pila);
int verTope(const tPila *pila, void *dato, unsigned tamDato);


#endif // PILA_H_INCLUDED
