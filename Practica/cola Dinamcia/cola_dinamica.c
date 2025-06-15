#include <string.h>
#include <stdlib.h>
#include "cola_dinamica.h"
#define MIN(A,B) (((A)>(B))? (B):(A))


void crearCola(tCola* cola){
    cola->primero = NULL;
    cola->ultimo = NULL;
}

int colaVacia(const tCola* cola){
    return !cola->primero;
}

int colaLlena(const tCola* cola, unsigned cantBytes){
    return 1;
}

int ponerEnCola(tCola* cola, const void* dato, unsigned cantBytes){
    tNodo* entrante;

    //Creacion del nodo
    entrante = malloc(sizeof(tNodo));
    if(!entrante || !(entrante->dato = malloc(cantBytes))){
        free(entrante);
        return 0;
    }

    //Carga del nodo
    memcpy(entrante->dato,dato,cantBytes);
    entrante->tam = cantBytes;
    entrante->siguiente = NULL;

    if(cola->primero == NULL){
        cola->primero = entrante;
    } else {
        cola->ultimo->siguiente = entrante;
    }

    //Enlace
    cola->ultimo = entrante;

    return 1;
}

int desEncolar(tCola* cola, void* dato, unsigned cantBytes){
    tNodo* elim;

    //Cola vacia
    if(cola->primero == NULL) return 0;

    elim = cola->primero;

    //Paso la info
    memcpy(dato,elim->dato,MIN(cantBytes,elim->tam));

    //Re enlazo
    cola->primero = elim->siguiente;

    free(elim->dato);
    free(elim);
    return 1;
}

int verPrimero(const tCola* cola, void* dato, unsigned cantBytes){
    //Cola vacia
    if(cola->primero == NULL) return 0;

    memcpy(dato,cola->primero->dato,MIN(cantBytes,cola->primero->tam));

    return 1;
}

int vaciarCola(tCola* cola, unsigned cantBytes){
    tNodo* elim;

    //Cola vacia
    if(cola->primero == NULL) return 0;

    elim = cola->primero;
    while(cola->primero != NULL){
        free(elim->dato);
        free(elim);
        elim = cola->primero;
    }

    return 1;
}
