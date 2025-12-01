#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdlib.h>

#define CAPACIDAD_PILA 500

#define PILA_SIN_LUGAR -4
#define PILA_VACIA -3
#define PILA_LLENA -2
#define FALLO_MEMORIA -1
#define EXITO_PILA_APILADA 1
#define EXITO_PILA_DESAPILADA 2
#define PILA_NO_LLENA 3
#define PILA_NO_VACIA 4
#define EXITO_VER_TOPE 5


#define MIN(X,Y) (((X) > (Y))? (Y):(X))

typedef struct tPila {
    char pila[CAPACIDAD_PILA];
    unsigned tope;
} tPila;

void crearPila(tPila *pila);
int apilar(tPila *pila, const void *dato, unsigned tamDato);
int desapilar(tPila *pila, void *dato, unsigned tamDato);
int pilaLlena(const tPila *pila, unsigned tamDato);
int pilaVacia(const tPila *pila);
void vaciarPila(tPila *pila);
int verTope(const tPila *pila, void *dato, unsigned tamDato);

#endif // PILA_H_INCLUDED

