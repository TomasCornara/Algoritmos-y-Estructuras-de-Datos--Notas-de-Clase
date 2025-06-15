#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista_circular.h"
#define MIN(A,B) (((A) > (B))? (B) : (A))

///FUNCIONES DE PILA
void crearPila(tPila* pila){
    *pila = NULL;
}

int pilaVacia(const tPila* pila){
    return *pila == NULL;
}

int pilaLlena(const tPila* pila){
    return 0;
}

int apilar(tPila* pila, const void* dato, unsigned cantBytes){
    tNodo* entrante;

    //Pedir espacio
    entrante = malloc(sizeof(tNodo));
    if(!entrante || !(entrante->dato = malloc(cantBytes))){
        free(entrante);
        return 0;
    }

    //Cargar nodo
    memcpy(entrante->dato,dato,cantBytes);
    entrante->tam = cantBytes;

    //Enlazar
    if(*pila == NULL){
        *pila = entrante;
        entrante->sig = entrante;
    } else {
        entrante->sig = (*pila)->sig;
        (*pila)->sig = entrante;
    }

    //Devolver
    return 1;
}


int desApilar(tPila* pila, void* dato, unsigned cantBytes){
    tNodo* elim;

    //Chequear que haya algo
    if(*pila == NULL) return 0;

    elim = (*pila)->sig;

    //Devuelvo la info
    memcpy(dato,elim->dato,MIN(cantBytes,elim->tam));

    //Desenlazar
    if(elim == *pila){
        *pila = NULL;
    } else {
        (*pila)->sig = elim->sig;

    }

    free(elim->dato);
    free(elim);
    return 1;
}

int verTope(const tPila* pila, void* dato, unsigned cantBytes){
    if(*pila == NULL) return 0;


    //Devuelvo la info
    memcpy(dato,(*pila)->dato,MIN(cantBytes,(*pila)->tam));

    return 1;
}

int vaciarPila(tPila* pila){
    tNodo* elim;

    if(*pila == NULL) return 0;

    while(*pila != NULL){
        elim = (*pila)->sig;

        if(elim == *pila){
            *pila = NULL;
        } else {
            (*pila)->sig = elim->sig;
        }

        free(elim->dato);
        free(elim);
    }

    return 1;
}


///FUNCIONES COLA
void crearCola(tCola* cola){
    *cola = NULL;
}

int colaVacia(const tCola* cola){
    return *cola == NULL;
}

int colaLlena(const tCola* cola){
    return 0;
}

int ponerEnCola(tCola* cola, const void* dato, unsigned cantBytes){
    tNodo* entrante;


    //Reservo memoria
    entrante = malloc(sizeof(tNodo));
    if(!entrante || !(entrante->dato = malloc(cantBytes))){
        free(entrante);
        return 0;
    }

    //Cargo el nodo
    memcpy(entrante->dato,dato,cantBytes);
    entrante->tam = cantBytes;


    ///Enlazo
    if(*cola == NULL){ //Si la cola esta vacia
        entrante->sig = entrante;
        *cola = entrante;
    } else { //Si no esta vacia
        entrante->sig = (*cola)->sig;
        (*cola)->sig = entrante;
    }
    *cola = entrante;

    //Devuelvo
    return 1;
}

int desEncolar(tCola* cola,void* dato,unsigned cantBytes){
    tNodo* elim;

    //Chequeo que cola no este vacia
    if(*cola == NULL) return 0;

    //Devuelvo la info
    elim = (*cola)->sig;
    memcpy(dato,elim->dato,MIN(cantBytes,elim->tam));

    //Desenlazo
    if(elim == *cola){
        *cola = NULL;
    } else {
        (*cola)->sig = elim->sig;
    }
    free(elim->dato);
    free(elim);

    //Salgo
    return 1;
}

int verPrimero(const tCola* cola, void* dato, unsigned cantBytes){
    //Verificar que no este vacia
    if(*cola == NULL) return 0;

    //Devuelvo la info
    memcpy(dato,(*cola)->sig->dato,MIN((*cola)->sig->tam,cantBytes));

    //Vuelvo al main
    return 1;
}

int vaciarCola(tCola* cola){
    tNodo* elim;

    //Verifico que no este vacia
    if(*cola == NULL) return 0;

    while(*cola != NULL){
        elim = (*cola)->sig;
        if(elim == *cola){
            *cola = NULL;
        } else {
            (*cola)->sig = elim->sig;
        }
        free(elim->dato);
        free(elim);
    }

    return 1;
}
