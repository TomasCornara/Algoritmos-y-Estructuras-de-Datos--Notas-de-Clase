#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaDinamica.h"

void crearLista(tLista* lista){
    *lista = NULL;
}

int listaVacia(const tLista* lista){
    return *lista == NULL;
}

int listaLlena(const tLista* lista, unsigned cantBytes){
    tNodo* aux;

    aux = malloc(sizeof(tNodo) + cantBytes);
    if(!aux) return 0;

    free(aux);
    return 1;
}

int ponerEnOrden(tLista* lista, const void* dato, unsigned cantBytes, cmp_gen cmp) {
    tNodo* nue;
    int c;

    while (*lista && (c = cmp(dato, (*lista)->dato)) > 0)
        lista = &(*lista)->sig;

    if (!c) return 0; // duplicado


    //Creacion del nodo
    nue = malloc(sizeof(tNodo) + cantBytes);
    if (!nue)
        return 0;


    //Carga
    nue->dato = nue + 1;
    memcpy(nue->dato, dato, cantBytes);
    nue->tam = cantBytes;

    //
    nue->sig = *lista;
    *lista = nue;

    return 1;
}


void mapLista(const tLista* lista,print_func prt){
    if(*lista){
        prt((*lista)->dato);
        mapLista(&(*lista)->sig,prt);
    }
}

void vaciarLista(tLista* lista) {
    if (*lista == NULL)
        return;

    vaciarLista(&(*lista)->sig);
    free(*lista);
    *lista = NULL;
}

void borrarUltimo(tLista* lista) {
    if (*lista == NULL)
        return; // lista vacía

    if ((*lista)->sig == NULL) {
        free(*lista);
        *lista = NULL;
        return;
    }

    borrarUltimo(&(*lista)->sig);
}
