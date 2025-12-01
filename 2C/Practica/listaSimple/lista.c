#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "lista.h"

void crearLista(tLista* lista){
    *lista = NULL;
}

int listaVacia(const tLista* lista){
    return *lista == NULL;
}

int listaLlena(const tLista* lista, unsigned cantBytes){
    char* aux;

    aux = malloc(sizeof(tNodo) + cantBytes);
    free(aux);

    return aux == NULL;
}

int ponerEnLista(tLista* lista, const void* dato, unsigned cantBytes,f_cmp cmp){
    tNodo* nue;

    nue = malloc(sizeof(tNodo) + cantBytes);
    if(!nue) return 0;


    while(*lista && cmp(dato, (*lista)->dato) > 0){
        lista = &(*lista)->sig;
    }

    nue->sig = *lista;
    nue->dato = nue + 1;
    memcpy(nue->dato, dato, cantBytes);
    nue->tam = cantBytes;
    *lista = nue;

    return 1;
}

void mapLista(const tLista* lista, f_ptr ptr){
    while(*lista){
        ptr((*lista)->dato);
        lista = &(*lista)->sig;
    }
}
