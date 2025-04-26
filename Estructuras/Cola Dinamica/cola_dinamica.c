#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola_dinamica.h"

#define MIN(A,B) (((A)>(B))? (B):(A))

void crearCola(tCola* cola){
    cola->primero = NULL;
    cola->ultimo = NULL;
}

int enColar(tCola *cola, const void *dato, unsigned cantBytes){
    tNodo* entrante;

    ///Chequeos memoria
    entrante = (tNodo*)malloc(sizeof(tNodo));
    if(!entrante) return ERROR_MEMORIA;

    entrante->dato = malloc(cantBytes);
    if(!entrante->dato){
        free(entrante);
        return ERROR_MEMORIA;
    }

    ///Carga de datos
    memcpy(entrante->dato,dato,cantBytes);
    entrante->tam = cantBytes;
    entrante->siguiente = NULL;

    ///Encolado
    //Si no hay nada, agrego y me voy
    if(!cola->primero){
        cola->primero = entrante;
        cola->ultimo = entrante;
    }

    //Si habia algo, lo agrego atras
    cola->ultimo->siguiente = entrante; //Enlazo
    cola->ultimo = entrante; //Piso el anterior

    return EXITO;
}

int desEncolar(tCola* cola, void *dato, unsigned cantBytes){
    tNodo* eliminar;

    //Chequeo que haya algo que sacar
    if(!cola->primero) return COLA_VACIA;

    eliminar = cola->primero;
    cola->primero = eliminar->siguiente;
    memcpy(dato,eliminar->dato,MIN(eliminar->tam,cantBytes));
    free(eliminar->dato);
    free(eliminar);

    return EXITO;
}

int verPrimero(const tCola *cola, void *dato, unsigned cantBytes){
    //Chequeo que haya algo
    if(!cola->primero) return COLA_VACIA;

    memcpy(dato,cola->primero->dato,MIN(cantBytes,cola->primero->tam));

    return EXITO;
}

void vaciarCola(tCola *cola){
    vaciarColaRecursivo(cola->primero);

    cola->primero = NULL;
    cola->ultimo = NULL;
}

void vaciarColaRecursivo(tNodo* nodo){
    if(!nodo) return;

    vaciarColaRecursivo(nodo->siguiente);

    free(nodo->dato);
    free(nodo);

    return;
}

int colaVacia(const tCola *cola){
    if(!cola->primero) return COLA_VACIA;
    return COLA_OCUPADA;
}

int colaLlena(const tCola *cola, unsigned cantBytes){
    tNodo* aux;

    aux = (tNodo*)malloc(cantBytes);
    if(!aux) return COLA_LLENA;

    free(aux);
    return EXITO;
}
