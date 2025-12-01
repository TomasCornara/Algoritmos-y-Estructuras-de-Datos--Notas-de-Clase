#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilaDinamica.h"

void crearPila(tPila* pila){
    *pila = NULL;
}

int pilaVacia(const tPila* pila){
    return *pila == NULL;
}

int pilaLlena(const tPila* pila, unsigned cantBytes){
    tNodo* nue;

    nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue || !(nue->dato = malloc(cantBytes))){
        free(nue);
        return 1;
    }
    free(nue->dato);
    free(nue);
    return 0;
}

void vaciarPila(tPila* pila){
    tNodo* elim;

    while(*pila){
        elim = *pila;
        *pila = elim->sig;
        free(elim->dato);
        free(elim);
    }
}

int apilar(tPila* pila, const void* dato, unsigned cantBytes){
    tNodo* nue;

    //Creo que elemento
    nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue || !(nue->dato = malloc(cantBytes))){
        free(nue);
        return 0;
    }

    //Lo cargo
    memcpy(nue->dato,dato,cantBytes);
    nue->tam = cantBytes;

    //Si es el primer elemento, lo coloco de una y cargo null
    if(*pila == NULL){
        nue->sig = NULL;
    } else { //Sino, enlazo con el siguiente
        nue->sig = *pila;
    }
    *pila = nue;
    return 1;
}

int desApilar(tPila* pila, void* dato, unsigned cantBytes){
    tNodo* elim;

    //Chequeo que haya algo
    if(*pila == NULL){
        return 0;
    }

    //Señalo el primero al ser eliminado
    elim = *pila;

    //Devuelvo la info
    memcpy(dato,elim->dato,MIN(elim->tam,cantBytes));

    //Re enlazo
    *pila = elim->sig;

    //Libero
    free(elim->dato);
    free(elim);

    //Devuelvo
    return 1;
}

int verTope(const tPila* pila, void* dato, unsigned cantBytes){
    //Chequeo que haya algo
    if(*pila == NULL){
        return 0;
    }

    //Devuelvo la info
    memcpy(dato,(*pila)->dato,MIN(cantBytes,(*pila)->tam));

    //Devuelvo
    return 1;
}
