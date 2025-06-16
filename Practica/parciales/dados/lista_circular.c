#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_circular.h"
#define MIN(A,B) (((A)>(B))? (B):(A))

void crearLista(tLista* lista){
    *lista = NULL;
}

int listaVacia(const tLista* lista){
    return *lista == NULL;
}

int listaLlena(const tLista* lista){
    return 0;
}

int quedaUnoEnLista(const tLista* lista){
    return *lista == (*lista)->sig;
}

int encolar(tLista* lista, const void* dato, unsigned cantBytes){
    tNodo* entrante;

    //Pido memoria
    entrante = malloc(sizeof(tNodo));
    if(!entrante || !(entrante->dato = malloc(cantBytes))){
        free(entrante);
        return 0;
    }

    //Cargo el nodo
    memcpy(entrante->dato,dato,cantBytes);
    entrante->tam = cantBytes;

     // Encolo
    if(*lista == NULL){
        entrante->sig = entrante;
        *lista = entrante;
    } else {
        entrante->sig = (*lista)->sig;
        (*lista)->sig = entrante;
        *lista = entrante;
    }

    //Devuelvo
    return 1;
}

int girarUno(tLista* lista){
    if(*lista == NULL) return 0;

    if(*lista == (*lista)->sig) return 0;

    *lista = (*lista)->sig;
    return 1;
}

int verPrimero(const tLista* lista,void* dato, unsigned cantBytes){

    if(*lista == NULL) return 0;

    memcpy(dato,(*lista)->sig->dato,(*lista)->sig->tam);

    return 1;
}

int quitarPrimero(const tLista* lista){
    tNodo* elim;

    if(*lista == NULL) return 0;

    elim = (*lista)->sig;
    (*lista)->sig = elim->sig;

    free(elim->dato);
    free(elim);

    return 1;
}

int vaciarCola(tLista* lista) {
    tNodo* elim;

    if (*lista == NULL) return 0;

    while (*lista != NULL) {
        elim = (*lista)->sig;

        if (*lista == elim) {
            *lista = NULL;
        } else {
            (*lista)->sig = elim->sig;
        }

        free(elim->dato);
        free(elim);
    }

    return 1;
}
