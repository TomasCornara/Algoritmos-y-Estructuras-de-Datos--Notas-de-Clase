#include "pila_dinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearPila(tPila *pila){
    *pila = NULL;
}
/*
    int ponerPila(tPila *pl, void *dato, unsigned cantBytes)
{
    tNodo * nuevoElemento = (tNodo*)malloc(sizeof(tNodo));
    nuevoElemento->info = malloc(cantBytes);
    if(nuevoElemento == NULL || nuevoElemento->info == NULL)
    {
        free(nuevoElemento);
        return 0;
    }
    memcpy(nuevoElemento->info, dato, cantBytes);
    nuevoElemento->tamInfo = cantBytes;
    nuevoElemento->sig = *pl;
    *pl = nuevoElemento;
    return 1;
}

*/
int apilar(tPila *pila, const void *dato, unsigned tamDato){
    ///Ante todo chequeo que haya lugar
    //Chequeo para la estructura en si
    tNodo* nuevo = (tNodo*)malloc(sizeof(tNodo));
    if(!nuevo) return ERROR_MEMORIA;

    //Chequeo que haya lugar para el dato
    nuevo->dato = malloc(tamDato);
    if(!nuevo->dato){
        free(nuevo);
        return ERROR_MEMORIA;
    }

    ///Carga de los datos
    memcpy(nuevo->dato,dato,tamDato);

    //Si la pila esta vacia, cargo el primer nodo
    if(!pila){
        *pila = nuevo;
        return TODO_OK;
    }

    //Si la pila no esta vacia
    nuevo->sig = *pila;
    *pila = nuevo;
    return TODO_OK;

}
//int desapilar(tPila *pila, void *dato, unsigned tamDato){}
//int pilaLlena(const tPila *pila, unsigned tamDato){}

int pilaVacia(const tPila *pila){
    return *pila == NULL;
}

//void vaciarPila(tPila *pila){


//}

//int verTope(const tPila *pila, void *dato, unsigned tamDato){}
