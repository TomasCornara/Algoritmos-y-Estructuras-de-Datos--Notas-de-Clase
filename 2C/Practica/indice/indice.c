#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "indice.h"

void liberarClaves(tIndice* indice);

void crearIndice(tIndice* indice){
    crearArbol(indice);
}

void vaciarIndice(tIndice* indice){
    liberarClaves(indice);
    vaciarArbol(indice);
}

int indexar(tIndice* indice, void* dato, unsigned cantBytes, unsigned pos, cmp_fun cmp){
    tClavePos nue;

    //Memoria
    nue.clave = malloc(cantBytes);
    if(!nue.clave) return 0;

    //Carga del nodo
    memcpy(nue.clave,dato,cantBytes);
    nue.cantBytes = cantBytes;
    nue.pos = pos;

    //Poner en arbol
    return insertarArbol(indice,&nue,sizeof(tClavePos),cmp);
}

void liberarClaves(tIndice* indice){
    tNodo* actual = *indice;
    tClavePos* elim;

    if(actual == NULL) return;

    liberarClaves(&actual->izq);
    liberarClaves(&actual->der);

    elim = (tClavePos*)actual->dato;
    free(elim->clave);
}

int buscarIndice(const tIndice* indice, void* clave,cmp_fun cmp){
    tNodo* busq;
    tClavePos* result;

    busq = buscarArbol(indice,clave,cmp);
    if(!busq) return -1;

    result = (tClavePos*)busq->dato;
    return result->pos;
}
