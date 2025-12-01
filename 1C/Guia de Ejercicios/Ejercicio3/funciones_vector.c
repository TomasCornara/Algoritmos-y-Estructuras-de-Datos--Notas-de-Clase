#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

#define CAPACIDAD_INICIAL 4

t_vector* t_vector_crear(int tam_elemento) {
    t_vector* v = (t_vector*) malloc(sizeof(t_vector));
    if (!v) return NULL;

    v->datos = malloc(CAPACIDAD_INICIAL * tam_elemento);
    if (!v->datos) {
        free(v);
        return NULL;
    }

    v->tam = 0;
    v->capacidad = CAPACIDAD_INICIAL;
    v->tam_elemento = tam_elemento;
    return v;
}

void t_vector_destruir(t_vector* v) {
    if (!v) return;
    free(v->datos);
    free(v);
}

int t_vector_agregar(t_vector* v, void* elem) {
    if (!v) return 0;

    if (v->tam == v->capacidad) {
        int nueva_cap = v->capacidad * 2;
        void* nuevo = realloc(v->datos, nueva_cap * v->tam_elemento);
        if (!nuevo) return 0;

        v->datos = nuevo;
        v->capacidad = nueva_cap;
    }

    void* destino = (char*)v->datos + v->tam * v->tam_elemento;
    memcpy(destino, elem, v->tam_elemento);
    v->tam++;
    return 1;
}

int t_vector_obtener(const t_vector* v, int indice, void* destino) {
    if (!v || indice < 0 || indice >= v->tam) return 0;
    void* origen = (char*)v->datos + indice * v->tam_elemento;
    memcpy(destino, origen, v->tam_elemento);
    return 1;
}

int t_vector_set(t_vector* v, int indice, void* fuente) {
    if (!v || indice < 0 || indice >= v->tam) return 0;
    void* destino = (char*)v->datos + indice * v->tam_elemento;
    memcpy(destino, fuente, v->tam_elemento);
    return 1;
}

int t_vector_tamanio(const t_vector* v) {
    if (!v) return -1;
    return v->tam;
}

void t_vector_mostrar(const t_vector* v, void (*mostrar)(const void*)) {
    if (!v || !mostrar) return;
    printf("[");
    for (int i = 0; i < v->tam; i++) {
        void* elem = (char*)v->datos + i * v->tam_elemento;
        mostrar(elem);
        if (i < v->tam - 1) printf(", ");
    }
    printf("]\n");
}
