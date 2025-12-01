#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista_doble.h"

void crearLista(tLista* lista){
    *lista = NULL;
}

int colaVacia(const tLista* lista){
    return *lista == NULL;
}

int listaLlena(const tLista* lista){
    return 0;
}

int ponerEnLista(tLista* lista, const void* dato, unsigned cantBytes, comparacion cmp) {
    int resultado;
    tNodo* entrante;
    tNodo* aux = *lista;

    // Crear el nuevo nodo
    entrante = malloc(sizeof(tNodo));
    if(!entrante) return 0;

    // Reservar memoria para el dato
    entrante->dato = malloc(cantBytes);
    if(!entrante->dato) {
        free(entrante);
        return 0;
    }

    // Cargar el dato en el nodo
    memcpy(entrante->dato, dato, cantBytes);
    entrante->tam = cantBytes;

    // Si la lista está vacía
    if(*lista == NULL) {
        entrante->ant = NULL;
        entrante->sig = NULL;
        *lista = entrante;
        return 1;
    }

    // Verificar si el elemento ya existe
    resultado = cmp(dato, aux->dato);
    if(resultado == 0) {
        // El elemento ya existe, liberar memoria y salir
        free(entrante->dato);
        free(entrante);
        return 0;
    }

    // Buscar la posición correcta para insertar
    if(resultado < 0) {
        // El nuevo dato es menor, buscar hacia la izquierda (ant)
        while(aux->ant && cmp(dato, aux->ant->dato) < 0) {
            aux = aux->ant;
        }
        // Insertar antes de aux
        entrante->sig = aux;
        entrante->ant = aux->ant;
        if(aux->ant) {
            aux->ant->sig = entrante;
        }
        aux->ant = entrante;
    } else {
        // El nuevo dato es mayor, buscar hacia la derecha (sig)
        while(aux->sig && cmp(dato, aux->sig->dato) > 0) {
            aux = aux->sig;
        }
        // Insertar después de aux
        entrante->ant = aux;
        entrante->sig = aux->sig;
        if(aux->sig) {
            aux->sig->ant = entrante;
        }
        aux->sig = entrante;
    }

    return 1;
}



int cmp_int(const void* elemA, const void* elemB){
    int A = *(int*)elemA;
    int B = *(int*)elemB;

    return A - B;
}

