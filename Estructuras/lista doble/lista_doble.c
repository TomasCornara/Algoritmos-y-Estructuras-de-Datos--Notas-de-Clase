#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_doble.h"

void crearLista(tLista* p){
    *p = NULL;
}

int listaVacia(const tLista* p){
    return *p == NULL;
}

int listaLlena(const tLista* p, unsigned cantBytes){
    return 0;
}

int insertarAlComienzo(tLista* p, const void* dato, unsigned cantBytes) {
    tNodo* nue = malloc(sizeof(tNodo));
    if (!nue || !(nue->info = malloc(cantBytes))) {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, cantBytes);
    nue->ant = NULL;
    nue->sig = *p;

    if (*p)
        (*p)->ant = nue;

    *p = nue;
    return 1;
}


int insertarAlFinal(tLista* p, const void* dato, unsigned cantBytes) {
    tNodo* nue = malloc(sizeof(tNodo));
    if (!nue || !(nue->info = malloc(cantBytes))) {
        free(nue);
        return 0;
    }
    memcpy(nue->info, dato, cantBytes);
    nue->sig = NULL;
    nue->ant = NULL;

    if (*p == NULL) {
        *p = nue;
        return 1;
    }

    tNodo* aux = *p;
    while (aux->sig)
        aux = aux->sig;

    aux->sig = nue;
    nue->ant = aux;

    return 1;
}


int insertarOrdenado(tLista* p, const void* clave, const void* dato, unsigned cantBytes, int (*cmp)(const void*, const void*)) {
    tNodo* nue;
    int res;

    // Crear nuevo nodo
    nue = malloc(sizeof(tNodo));
    if (!nue) {
        return 0;
    }

    // Asignar memoria para los datos
    nue->info = malloc(cantBytes);
    if (!(nue->info)) {
        free(nue);
        return 0;
    }

    // Copiar los datos
    memcpy(nue->info, dato, cantBytes);
    nue->sig = NULL;
    nue->ant = NULL;

    // Si la lista está vacía
    if (*p == NULL) {
        *p = nue;
        return 1;
    }

    // Fase 1: Buscar hacia la derecha hasta encontrar un elemento >= clave
    // o llegar al final
    while ((*p)->sig != NULL && (res = cmp(clave, (*p)->info)) > 0) {
        *p = (*p)->sig;
    }

    // Fase 2: Si el elemento actual es > clave, retroceder hasta encontrar
    // la posición correcta
    while ((*p)->ant != NULL && (res = cmp(clave, (*p)->info)) < 0) {
        *p = (*p)->ant;
    }

    // Ahora tenemos tres casos:
    // 1. Insertar antes del nodo actual (clave < (*p)->info)
    // 2. Insertar después del nodo actual (clave >= (*p)->info)

    if (res < 0) {
        // Insertar antes del nodo actual
        nue->sig = *p;
        nue->ant = (*p)->ant;

        if ((*p)->ant != NULL) {
            (*p)->ant->sig = nue;
        }
        (*p)->ant = nue;

        // Si insertamos al principio, actualizar el puntero de la lista
        if (nue->ant == NULL) {
            *p = nue;
        }
    } else {
        // Insertar después del nodo actual
        nue->sig = (*p)->sig;
        nue->ant = *p;

        if ((*p)->sig != NULL) {
            (*p)->sig->ant = nue;
        }
        (*p)->sig = nue;
    }

    return 1;
}

int cmpInt(const void* a,const void* b){
    int elemA = *(int*)a;
    int elemB = *(int*)b;

    return elemA - elemB;
}


// Funciones auxiliares para testing
tNodo* encontrarInicio(tLista lista) {
    if (lista == NULL) return NULL;
    while (lista->ant != NULL) {
        lista = lista->ant;
    }
    return lista;
}

void imprimirLista(tLista lista) {
    tNodo* inicio = encontrarInicio(lista);
    printf("Lista: ");
    if (inicio == NULL) {
        printf("(vacía)\n");
        return;
    }

    tNodo* actual = inicio;
    while (actual != NULL) {
        printf("%d ", *(int*)(actual->info));
        actual = actual->sig;
    }
    printf("\n");
}

void imprimirListaReversa(tLista lista) {
    if (lista == NULL) {
        printf("Lista reversa: (vacía)\n");
        return;
    }

    // Ir al final
    tNodo* fin = lista;
    while (fin->sig != NULL) {
        fin = fin->sig;
    }

    printf("Lista reversa: ");
    tNodo* actual = fin;
    while (actual != NULL) {
        printf("%d ", *(int*)(actual->info));
        actual = actual->ant;
    }
    printf("\n");
}

void liberarLista(tLista* lista) {
    tNodo* inicio = encontrarInicio(*lista);
    tNodo* actual = inicio;

    while (actual != NULL) {
        tNodo* temp = actual;
        actual = actual->sig;
        free(temp->info);
        free(temp);
    }
    *lista = NULL;
}
