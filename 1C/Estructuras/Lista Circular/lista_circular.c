#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista_circular.h"
#define MIN(A,B) (((A) > (B))? (B):(A))

void crearCola(tCola* cola){
    *cola = NULL;
}

int colaVacia(const tCola* cola){
    return *cola == NULL;
}

int colaLlena(const tCola* cola, unsigned tamDato){
    return 1;
}

int encolar(tCola* cola, void* dato, unsigned tamDato){
    tNodo* entrante;

    //Memoria
    entrante = malloc(sizeof(tNodo));
    if(!entrante || !(entrante->info = malloc(tamDato))){
        free(entrante);
        return 0;
    }

    //Carga del nodo
    memcpy(entrante->info,dato,tamDato);
    entrante->tam = tamDato;



    //Chequeo cola vacia
    if(*cola == NULL){
        entrante->sig = entrante;
        *cola = entrante;
        return 1;
    }


    entrante->sig = (*cola)->sig;
    (*cola)->sig = entrante;
    *cola = entrante;
    return 1;
}

int desEncolar(tCola* cola, void* destino, unsigned cantBytes){
    tNodo* elim;

    //Chequeo que haya algo
    if(*cola == NULL){
        return 0;
    }

    elim = (*cola)->sig;

    //Si habia algo, paso la data mediante el ultimo
    memcpy(destino,elim->info, MIN(elim->tam,cantBytes));

    //Re enlazo
    if(elim == *cola){
        *cola = NULL;
    } else {
        (*cola)->sig = elim->sig;
    }


    free(elim->info);
    free(elim);

    return 1;
}

int verTopeCola(tCola* cola, void* destino, unsigned cantBytes){
    tNodo* aux;

    //Chequeo que haya algo
    if(*cola == NULL){
        return 0;
    }

    aux = (*cola)->sig;

    //Si habia algo, paso la data mediante el ultimo
    memcpy(destino,aux->info, MIN(aux->tam,cantBytes));

    return 1;
}

void vaciarCola(tCola *cola){
    tNodo* elim;

    if(*cola == NULL)
        return;

    while((*cola)->sig != *cola){
        elim = (*cola)->sig;
        (*cola)->sig = elim->sig;
        free(elim->info);
        free(elim);
    }

    free((*cola)->info);
    free(*cola);
    *cola = NULL;
}

void mostrarCola(const tCola cola) {
    int i = 0;
    if (!cola) {
        printf("Cola vacia\n");
        return;
    }

    tNodo* inicio = cola->sig;
    tNodo* aux = inicio;

    do {
        printf("%d", *(int*)(aux->info));
        aux = aux->sig;
        if (aux != inicio) {
            printf(" -> ");
            i += 6;
        }
    } while (aux != inicio);

    printf("\n^");
    for(int x = 0; x < i; x++) {
        printf("-");
    }
    printf("\n");
}

void mapCola(const tCola* cola, void (*accion)(const void*)) {
    tNodo* actual;

    if (*cola == NULL)
        return;

    actual = (*cola)->sig;

    do {
        accion(actual->info);
        actual = actual->sig;
    } while (actual != (*cola)->sig);
}

void imprimirInt(const void* dato) {
    printf("%d\n", *(int*)dato);
}


