#include "arbol.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void crearArbol(tArbol* arbol){
    *arbol = NULL;
}

void vaciarArbol(tArbol* arbol){
    tNodo* actual = *arbol;

    if(!actual) return;

    vaciarArbol(&actual->izq);
    vaciarArbol(&actual->der);

    free(actual);
}

int insertarArbol(tArbol* arbol, const void* dato, unsigned cantBytes,cmp_fun cmp){
    int c;
    tNodo*nue;

    while(*arbol){
        c = cmp(dato,(*arbol)->dato);
        if(!c) return 0;
        if(c > 0){
            arbol = &(*arbol)->der;
        } else {
            arbol = &(*arbol)->izq;
        }
    }

    nue = malloc(sizeof(tNodo) + cantBytes);
    if(!nue) return 0;

    nue->dato = nue + 1;
    memcpy(nue->dato,dato,cantBytes);
    nue->cantBytes = cantBytes;
    nue->der = NULL;
    nue->izq = NULL;

    *arbol = nue;
    return 1;
}

tNodo* buscarArbol(const tArbol* arbol, const void* key, cmp_fun cmp){
    int c;

    if(*arbol == NULL) return 0;

    c = cmp(key,(*arbol)->dato);

    if(!c) return *arbol;

    if(c > 0){
        return buscarArbol(&(*arbol)->der,key,cmp);
    } else {
        return buscarArbol(&(*arbol)->izq,key,cmp);
    }
}
