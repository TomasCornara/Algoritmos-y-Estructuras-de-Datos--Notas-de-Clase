#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define LOTE_APROBADO 30
#define LOTE_FALLIDO 20
#define MAX_LOTE 5
#define MAX_PRODUCTO 5
#define MAX_CONTROL 6

#define MAX_BUFFER 18

#include "cola_dinamica.h"

typedef struct {
    char lote[MAX_LOTE];
    char producto[MAX_PRODUCTO];
    char control[MAX_CONTROL];
} producto;

void parseToProd(char buffer[MAX_BUFFER],producto* prod);
void procesarLote(tCola* lote,FILE* aprobados,FILE* observados);
int buscarFallosLote(tCola* lote);
int buscarFalloRecursivo(tNodo* nodo);

#endif // PRODUCTO_H_INCLUDED
