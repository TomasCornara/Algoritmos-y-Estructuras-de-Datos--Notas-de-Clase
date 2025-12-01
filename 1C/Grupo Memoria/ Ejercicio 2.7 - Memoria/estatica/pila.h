#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stddef.h>

#define TAM_PILA 1024

#define EXITO_PILA_APILADA 1
#define EXITO_PILA_DESAPILADA 1
#define EXITO_PILA_VISTA_TOPE 1

#define FALLO_PILA_LLENA -1
#define FALLO_PILA_VACIA -2

#define PILA_VACIA 1
#define PILA_NO_VACIA 0
#define PILA_LLENA 1
#define PILA_NO_LLENA 0

typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
} tPila;

void crearPila(tPila *pila);
int pilaLlena(const tPila *pila, unsigned tamDato);
int apilar(tPila *pila, const void *dato, unsigned tamDato);
int pilaVacia(const tPila *pila);
int verTope(const tPila *pila, void *dato, unsigned tamDato);
int desapilar(tPila *pila, void *dato, unsigned tamDato);
void vaciarPila(tPila *pila);

/** Funciones auxiliares **/
void *mMemcpy(void *a, const void *b, unsigned tam);

#endif // PILA_H_INCLUDED
