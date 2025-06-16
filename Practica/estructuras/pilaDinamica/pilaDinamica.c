#include <string.h>
#include <stdlib.h>
#include "pilaDinamica.h"
#define MIN(A,B) (((A) > (B))? (B) : (A))

void crearPila(tPila* pila){
    *pila = NULL;
}

int pilaLlena(const tPila* pila){
    return 1;
}

int pilaVacia(const tPila* pila){
    return *pila == NULL;
}

int apilar(tPila* pila, const void* dato, unsigned cantByte){
    tNodo* entrante;

    //Pido el lugar
    entrante = malloc(sizeof(tNodo));
    if(!entrante || !(entrante->dato = malloc(cantByte))){
        free(entrante);
        return 0;
    }

    //Paso la info
    entrante->tam = cantByte;
    memcpy(entrante->dato,dato,cantByte);

    //Enlazo con el nodo anterior
    entrante->siguiente = *pila;
    *pila = entrante;

    return 1;
}

int desApilar(tPila* pila, void* buffer, unsigned cantBytes){
    tNodo* elim;

    //Verifico que haya algo
    if(*pila == NULL) return 0;

    //Copio la info
    memcpy(buffer,(*pila)->dato,MIN((*pila)->tam,cantBytes));

    //Desenlazo
    elim = *pila;
    *pila = elim->siguiente;

    //Libero memoria
    free(elim->dato);
    free(elim);

    return 1;
}

int verTope(const tPila* pila, void* buffer, unsigned cantBytes){
    //Verifico que haya algo
    if(*pila == NULL) return 0;

    //Copio la info
    memcpy(buffer,(*pila)->dato,MIN(cantBytes,(*pila)->tam));

    return 1;
}
